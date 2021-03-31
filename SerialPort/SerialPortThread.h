#ifndef SERIALPORTTHREAD_H
#define SERIALPORTTHREAD_H

#include <QThread>
#include <stdio.h>
#include "SysConfig.h"

class SerialPortThread : public QThread
{
    Q_OBJECT
public:
    explicit SerialPortThread(QObject *parent = 0);

    bool OpenComm(int nPort, int nBaud, int nCheck);	//打开串口，nPort是串口号，nCheck为0无校验，nCheck为1奇校验，nCheck为2偶检验
    void CloseComm(int nPort);									//关闭串口
    int  ReceiveData(int nPort,char *buffer, int nLength);		//接收数据
    int	 SendData(int nPort, char *buffer, int nLength);			//发送数据

private:
    int  serial_fd[SERIAL_PORT_NUMS];			//串口的ID
signals:

public slots:

};

#endif // SERIALPORTTHREAD_H
