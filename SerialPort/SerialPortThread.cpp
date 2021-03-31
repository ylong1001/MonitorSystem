#include "SerialPortThread.h"

SerialPortThread::SerialPortThread(QObject *parent) :
    QThread(parent)
{
    //QextSerialPort * port = new QextSerialPort();
}


/////////////////////////////////////////////////////////////
// 功能描述：打开一个串口
//
// nComm:串口号从0开始
// nBaud:波特率，如9600等
// nCheck:校验，0无校验，1奇校验，2偶检验
/////////////////////////////////////////////////////////////
bool SerialPortThread::OpenComm(int nPort, int nBaud, int nCheck)
{
    int nSerialOpt = 0;
    char devsName[20];
#if defined(VXWORKS)
    //设置串口设备名称
    sprintf(devsName, "/tyCo/%d", nPort);
    serial_fd[nPort] = open(devsName,2,0644);
    if(serial_fd[nPort]== ERROR)
    {
        printf("open comm error\n");
        return false;
    }

    //设置波特率
    if(ioctl(serial_fd[nPort], FIOBAUDRATE, nBaud) == ERROR)
    {
        printf("can not set BAUDRATE!/n");
        return false;
    }

    //设置数据位，停止位，和校验
    if(nCheck == 0)
    {
        nSerialOpt |= (CLOCAL|CREAD|CS8);
    }
    else if(nCheck == 1)
    {
        nSerialOpt |= (CLOCAL|CREAD|CS8|PARENB|PARODD);
    }
    else
    {
        nSerialOpt |= (CLOCAL|CREAD|CS8|PARENB);
    }

    if(ioctl(serial_fd[nPort], SIO_HW_OPTS_SET, nSerialOpt))
    {
        printf("can not set OPT!/n") ;
        return ERROR ;
    }
    //清空缓冲区
    ioctl(serial_fd[nPort],FIOFLUSH,0);
#endif
    return true;
}

/////////////////////////////////////////////////////////////
// 功能描述：串口接收数据,是阻塞式的函数，执行到本函数后一直
//			等待数据到来后才向下执行
//
// buffer:接收数据的缓冲区
// nLength:数据的缓冲区长度
// 返回值：返回实际接收的长度
/////////////////////////////////////////////////////////////
int  SerialPortThread::ReceiveData(int nPort, char *buffer, int nLength)
{
    int nReadLen = 0;
    int width;

#if defined(VXWORKS)
    fd_set fdsData;

    //位码置0
    FD_ZERO(&fdsData);
    //初始化位码
    FD_SET(serial_fd[nPort], &fdsData);
    width = m_nSerialFD + 1;

    //阻塞读，一直等到有数据后才往下执行
    if(select(width, &fdsData, NULL, NULL, NULL) == ERROR)
    {
        return -1;
    }
    nReadLen = read(serial_fd[nPort], buffer, nLength);
#endif
    return nReadLen;
}

/////////////////////////////////////////////////////////////
// 功能描述：发送串口数据
//
// buffer:发送数据的缓冲区
// nLength:数据的缓冲区长度
// 返回值：返回实际发送的长度
/////////////////////////////////////////////////////////////
int	 SerialPortThread::SendData(int nPort, char *buffer, int nLength)
{
    int nSendLen = 0;
#if defined(VXWORKS)
    nSendLen = write(serial_fd[nPort], buffer, nLength);
#endif
    return nSendLen;
}

//关闭串口
void SerialPortThread::CloseComm(int nPort)
{
    if((nPort<0)||(nPort>=SERIAL_PORT_NUMS))
    {
        printf("serial port index Error");
        return;
    }
#if defined(VXWORKS)
    close(serial_fd[nPort]);
#endif
}
