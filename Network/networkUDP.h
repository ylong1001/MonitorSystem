#ifndef NETWORKUDP_H
#define NETWORKUDP_H

#include <QThread>
#include <QMutex>
#include <QHostAddress>
#include <QTimer>
#include <QDateTime>
#include <QtNetwork/QUdpSocket>

QT_BEGIN_NAMESPACE
class QUdpSocket;
QT_END_NAMESPACE


#pragma pack(push)
#pragma pack(1)

#define UDP_HEAD_1  0x05
#define UDP_HEAD_2  0x16

typedef struct timeStamp {
quint32 secs;
quint32 mSecs;
}TIMESTAMP;

//信息点ID由4字节来标识
typedef struct info_id{
  quint32 infoCode : 16;    // 信号编码值
  quint32 srcDest : 12;     // 源/宿设备名称
  quint32 systemId : 4;     // 信息所属的系统名称
}INFO_ID; 

//信息块的格式采用TLV形式
typedef struct info_block{
    quint8  msgId;		 // 信息单元标识
    quint16	msgLen; 	 // 信息单元长度
	info_id  infoId;        // 信息点ID
    union{                  // 信息数据
        quint8 info_io[2];
        quint8 info_float[5];
        quint8 info_double[9];
        quint8 info_event[5];
    };
}INFO_BLOCK;


typedef struct pduType{
  quint8 PPP : 3;	// 操作码
  quint8 RR : 2; 	// 保留
  quint8 X : 1;		// 是否有扩展头
  quint8 VV : 2; 	// 版本号
}PDUType;

typedef struct lan_pdu 
{
  quint16 head;         // 协议标识0516H
  pduType        type;
  quint8  packType;     // 报文类型
  quint16 packLen;      // 报文总长度
  quint32   packSeqNo;    // 报文序列号
  quint32   packAckNo;    // 报文确认号
  quint16 transactId;   // 事务标识
  timeStamp      time;  // 时间戳
  quint16 marker_ID;    //设备标识ID
  quint8  msgCnt;       // 信息单元个数
  info_block     tlv;
}LAN_PDU;


enum INFO_PACK_OP_CODE
{
    PACK_TYPE_not_07H = 0x0, 
    PACK_OpCode_IO_MSG = 0x1, 
    PACK_OpCode_QUERY_REQ = 0x2,
    PACK_OpCode_QUERY_ACK = 0x3,
    PACK_OpCode_AUTO_SEND = 0x4,
    PACK_OpCode_DATA_CFG = 0x5,
    PACK_OpCode_DUMP = 0x6
};


#pragma pack(pop)


class NetworkUDP : public QThread
{
    Q_OBJECT

public:
    explicit NetworkUDP(QObject *parent = 0);
	~NetworkUDP();

    QTimer* timer_1000ms;


    void InitQUdpSocket();
    void run();
	bool stopped;
    void packetReadyUDP(QByteArray data);

    //拆包处理
    void parseInfoData(QByteArray data);
    void parseInfoBlockData(QByteArray data);


    void getCurrentTimeStamp(TIMESTAMP& currentStamp);

    //封包处理  
    void packageData_io(QByteArray data);


    //定时器
    void initTimers_sendpackage_toJKT();


    void getDateTimeFromTimeStamp(TIMESTAMP infoStamp, QDateTime& packetDataTime);

    void send_poweroff_msg();             //各设备关机前需要发送关机报文
    void send_heart_beat_msg_per_5s();    //默认为每5秒发送一次心跳报文
    void send_status_query_request_msg(); //状态查询报文

private:
    QMutex m_lock;
    QUdpSocket *udpSocket;
    QHostAddress groupAddress;
    QString ipLocal;
    QString ipRemote;
    QString portLocal;
    QString portRemote;
    QHostAddress ipAddrLocal;
    QHostAddress ipAddrRemote;
    quint16 udpLocalPort;
    quint16 udpRemotePort;
    QTimer *m_timer;
signals:
        //发送给主UI更新界面数据信号
       void send_mainUi_luojujiao1_singal(QByteArray data);

private slots:
    void slot_UdpReadyToRead();


};

#endif
