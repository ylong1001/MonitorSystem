#pragma execution_character_set("utf-8")
#include <QWidget>
#include <QtNetwork>
#include "networkUDP.h"

//big endian高尾端：数据的尾端字节存储在内存的高地址 (网络字节序，协议约定此字节序)
//small endian低尾端：数据的尾端字节存储在内存的低地址

//支持组播UDP socket
NetworkUDP::NetworkUDP(QObject* parent) : QThread(parent)
{
    stopped = false;

	InitQUdpSocket();

}
NetworkUDP::~NetworkUDP()
{
	QMutexLocker locker(&m_lock);
	stopped = true;
	udpSocket->leaveMulticastGroup(groupAddress);
	udpSocket->close();
	delete udpSocket;
	delete m_timer;
}


void NetworkUDP::InitQUdpSocket()
{
    ipLocal = "192.168.100.70";
    portLocal = "29952";
    ipRemote = "192.168.100.100";
    portRemote = "29952";
    groupAddress = QHostAddress("230.1.1.70");

	udpLocalPort = portLocal.toUInt();
	udpRemotePort = portRemote.toUInt();
	ipAddrLocal.setAddress(ipLocal);
	ipAddrRemote.setAddress(ipRemote);

	udpSocket = new QUdpSocket(this);
	if (udpSocket->bind(ipAddrLocal, udpLocalPort, QUdpSocket::ShareAddress))
	{
		qDebug() << "udp server bind OK!,ip address:" << ipLocal << "bind port:" << portLocal;
		udpSocket->joinMulticastGroup(groupAddress);
		//connect(udpSocket,&QUdpSocket::readyRead,this, &NetworkUDP::slot_UdpReadyToRead);
	}
	else
	{
		qDebug() << "qudpsocket bind failed!\n";
		udpSocket->close();
		udpSocket = NULL;
	}
}
//UDP是基于报文发送，不存在粘包和拆包
void NetworkUDP::run()
{
	while (!stopped)
	{
		while (udpSocket != NULL && udpSocket->hasPendingDatagrams())  //拥有等待的数据报文
		{
			QByteArray datagram;
			datagram.resize(udpSocket->pendingDatagramSize());
			udpSocket->readDatagram(datagram.data(), datagram.size());
            //qDebug()<<helpItem::ByteArrayToHexStr(datagram);
			packetReadyUDP(datagram);
		}

		msleep(10);
	}
}

//每1s发送数据到JKT
void NetworkUDP::initTimers_sendpackage_toJKT()
{
    timer_1000ms = new QTimer(this);
    timer_1000ms->setInterval(1000);
    connect(timer_1000ms, SIGNAL(timeout()), this, SLOT(packageData_io()));//1000ms发送一次数据
    timer_1000ms->start();
}


// udp packet ready to be read from connection with the UDP socket
void NetworkUDP::packetReadyUDP(QByteArray data)
{

	LAN_PDU apdu;
	memset(&apdu, 0, sizeof(LAN_PDU));
    if((data.at(0) != UDP_HEAD_1) || (data.at(1) != UDP_HEAD_2))
    {
        qDebug()<<"frame header is not 0x0516";
        return;
    }
    //2
    apdu.type.PPP = data.at(2) &0x07;
    apdu.type.RR = data.at(2)>>3 &0x03;  //0,保留
    apdu.type.X = data.at(2)>>5 &0x01;   //0,不需要扩展头
    apdu.type.VV = data.at(2)>>6 &0x03;
    //3 报文类型
    apdu.packType = data.at(3);
    //4 报文长度
    apdu.packLen = (data.at(4)<<8 & 0xFF00 | data.at(5) & 0x00FF);

    //5 序列号
    apdu.packSeqNo = (data.at(6)<<24 & 0xFF000000 | data.at(7)<<16 & 0x00FF0000 | data.at(8)<<8 & 0x0000FF00 | data.at(9) & 0x000000FF);

    //6 确认号
    apdu.packAckNo = (data.at(10)<<24 & 0xFF000000| data.at(11)<<16 & 0x00FF0000 | data.at(12)<<8 & 0x0000FF00| data.at(13) & 0x000000FF);

    //7 事物标识
    apdu.transactId =  (data.at(14)<<8 & 0xFF00 | data.at(15)& 0x00FF);

    //8 时戳
    apdu.time.secs  = (quint8(data.at(16))<<24 & 0xFF000000 |  \
                       quint8(data.at(17))<<16 & 0x00FF0000 |  \
                       quint8(data.at(18))<<8 & 0x0000FF00 |  \
                       quint8(data.at(19)) & 0x000000FF);
    apdu.time.mSecs = (quint8(data.at(20))<<24 & 0xFF000000 |  \
                       quint8(data.at(21))<<16 & 0x00FF0000 |  \
                       quint8(data.at(22))<<8 & 0x0000FF00 |  \
                       quint8(data.at(23)) & 0x000000FF);
    QDateTime debugDt;
    getDateTimeFromTimeStamp(apdu.time,debugDt);


    //apdu.msgCnt   = data.at(24);


	//数据报文包序和时戳判断处理 to be continued

	//解析信息单元块数据(多个块)
//    QByteArray info;
//    info.resize(data.size() - 24);
//    info = data.mid(24,-1);
//    parseInfoBlockData(info);
    QByteArray info_float;
    if(apdu.packLen ==0x29)
    {
        apdu.marker_ID = (data.at(28)<<8 & 0xFF00 | data.at(29) & 0x00FF);
        if(apdu.marker_ID == 0x4001)
        {
            info_float.resize(data.size() - 32);
            info_float = data.mid(32,-1);
            //parseInfoData_CB(info_float);
        }
    }


}

void NetworkUDP::parseInfoBlockData(QByteArray data)
{
	// 第一个字节（信息单元块个数）
	quint8 cnt = data.at(0);
	quint16 length;
	quint32  index = 1;
	QByteArray info;
	while (cnt--)
	{
		length = (data.at(index + 1) << 8 | data.at(index + 2));   //信息单元长度

		info.resize(length);
		info = data.mid(index, length);
		parseInfoData(info);

		index += length;	//移动到下一个信息单元块		
	}
}


void NetworkUDP::parseInfoData(QByteArray data)
{
	switch (data.at(0))
	{
	case 01://开关量数据
		break;

	default:
		break;
	}

}


void NetworkUDP::packageData_io(QByteArray data)
{
	QByteArray info;
	info.resize(0x22);
	info[0] = UDP_HEAD_1;
	info[1] = UDP_HEAD_2;

	info[2] = 0x41;

	info[3] = 0x07;

	info[4] = 0x00;
	info[5] = 0x22;

	info[6] = 0x00;
	info[7] = 0x00;
	info[8] = 0x00;
	info[9] = 0x01;

	info[10] = 0x00;
	info[11] = 0x00;
	info[12] = 0x00;
	info[13] = info[9] + 1;

	info[14] = 0x00;
	info[15] = 0x00;

	TIMESTAMP current_time;
	getCurrentTimeStamp(current_time);
	info[16] = quint8((current_time.secs & 0xFF000000) >> 24);
	info[17] = quint8((current_time.secs & 0x00FF0000) >> 16);
	info[18] = quint8((current_time.secs & 0x0000FF00) >> 8);
	info[19] = quint8((current_time.secs & 0x000000FF));
	info[20] = quint8((current_time.mSecs & 0xFF000000) >> 24);
	info[21] = quint8((current_time.mSecs & 0x00FF0000) >> 16);
	info[22] = quint8((current_time.mSecs & 0x0000FF00) >> 8);
	info[23] = quint8((current_time.mSecs & 0x000000FF));

	info[24] = 0x01;

	info[25] = data[0];
	info[26] = data[1];
	info[27] = data[2];
	info[28] = data[3];
	info[29] = data[4];
	info[30] = data[5];
	info[31] = data[6];
	info[32] = data[7];
	info[33] = data[8];

	udpSocket->writeDatagram(info, QHostAddress("192.168.2.100"), 30001);
}



void NetworkUDP::getCurrentTimeStamp(TIMESTAMP& currentStamp)
{
	QDateTime dt = QDateTime::currentDateTime();
	currentStamp.secs = dt.toTime_t();       //1970年至今的秒数
    //qDebug() << "total secs from 1970" << currentStamp.secs;
	//qint64 epochTime = dt.toMSecsSinceEpoch();   //1970年至今的毫秒数0
	int ms = dt.time().msec();      // 获取毫秒值
	currentStamp.mSecs = ms;
    //qDebug() << "current msec :" << currentStamp.mSecs;
}

void NetworkUDP::getDateTimeFromTimeStamp(TIMESTAMP infoStamp, QDateTime& packetDataTime)
{
	qint64 total_msecs = quint64(quint64(infoStamp.secs) * 1000 + quint64(infoStamp.mSecs));
    //qDebug("time stamp sec: %16d, msec:%16d, calc msecs total: %16ld",infoStamp.secs,infoStamp.mSecs,total_msecs);
    packetDataTime =  QDateTime::fromTime_t((qint64)total_msecs);

	QString showTime = packetDataTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
    //qDebug()<<showTime;
}

//设备关机前需要发送关机报文
void NetworkUDP::send_poweroff_msg()
{
	LAN_PDU apdu;
	memset(&apdu, 0, sizeof(LAN_PDU));
}
//默认为每5秒发送一次心跳报文
void NetworkUDP::send_heart_beat_msg_per_5s()
{
	LAN_PDU apdu;
	memset(&apdu, 0, sizeof(LAN_PDU));
	//qDebug()<<"112333344"<<endl;
}

//状态查询报文
void NetworkUDP::send_status_query_request_msg()
{
	LAN_PDU apdu;
	memset(&apdu, 0, sizeof(LAN_PDU));
}

void NetworkUDP::slot_UdpReadyToRead()
{
	QByteArray datagram;
	datagram.resize(udpSocket->pendingDatagramSize());
	udpSocket->readDatagram(datagram.data(), datagram.size());
	packetReadyUDP(datagram);
}




