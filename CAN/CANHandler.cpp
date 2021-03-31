#include "CANHandler.h"
#include <stdio.h>

/* Create CAN Devics CreatCANDev() is invoked by OS kernel first */

CANHandler::CANHandler()
{
    for(int i=0; i<CAN_CHANNEL; i++)
    can_fd[i] = 0;
}


CANHandler::~CANHandler()
{
#if defined(VXWORKS)
    for(int i=0; i<CAN_CHANNEL; i++)
    {
        if(can_fd[i])
        close(can_fd[i]);
    }
#endif

}


int CANHandler::open_can(int channel)
{
    if((channel<0)||(channel>=CAN_CHANNEL))
    {
        printf("can channel index Error");
        return ERROR;
    }

#if defined(VXWORKS)
    char canName[10]={0};
    sprintf(canName,"/CAN/%d",channel);
    can_fd[channel] = open(canName, O_RDWR, 0);
    if(can_fd[channel] == ERROR)
    {
        printf("open CAN%d failed!\n",channel);
        close(can_fd[channel]);
        return ERROR;
    }
#endif
}


int CANHandler::close_can(int channel)
{
    if((channel<0)||(channel>=CAN_CHANNEL))
    {
        printf("can channel index Error");
        return ERROR;
    }

#if defined(VXWORKS)
    if(can_fd[channel])
    {
        printf("close CAN%d now!\n",channel);
        close(can_fd[channel]);
        return OK;
    }
#endif
    return ERROR;
}

int CANHandler::init_can(int channel)
{

    if((channel<0)||(channel>=CAN_CHANNEL))
    {
        printf("can channel index Error");
        return ERROR;
    }

#if defined(VXWORKS)

    UCHAR intmask = 0x81;/*0xff:全部中断*//*0x83:收+发中断  0x81:接收中断*/
    CAN_FILTER	filter;

    ioctl(can_fd[channel] , CAN_SET_FILTERMODE, 1);   	/*设置CAN 滤波器的工作方式 0:双滤波  1:单滤波*/
    ioctl (can_fd[channel] , CAN_SET_INTERRUP, (int)(intmask));    /*设置CAN 中断接收*/
    ioctl (can_fd[channel] , CAN_SET_BAUDRATE, (int)(B1000));       /*设置CAN 设备波特率*/

    (&filter)->codes=0x15540000;	/*0x1732e000; 设置ID及掩码；最高的3位不需设置(ID29,ID30,ID31)*/
    /*(&filter)->masks=0x0003ffff;	掩码为0的位对应的code位才有效；最高的3位不需设置(ID29,ID30,ID31)*/
    (&filter)->masks=0xffffffff;    /*掩码*/
    ioctl(can_fd[channel] , CAN_SET_FILTER, (int)(&filter));        /*设置CAN 设备滤波FILTER*/
    ioctl(can_fd[channel] , CAN_SET_SELFTSMODE, 0);    /*取消自测模式，恢复普通模式   0:取消   1:使能*/
    /*ioctl(can_fd[channel] , CAN_SET_LISTENMODE, 0);     取消侦听模式    0:取消   1:使能*/
    return OK;
#endif
}

int CANHandler::reset_can(int channel)
{
    if((channel<0)||(channel>=CAN_CHANNEL))
    {
        printf("can channel index Error");
        return ERROR;
    }

#if defined(VXWORKS)
    if(can_fd[channel])
    /*reset CAN*/
    ioctl(can_fd[channel], CAN_RESET, 0);
#endif
}

int CANHandler::send_can(int channel,CAN_PACKET &msg)
{
    int result = 0;
    if((channel<0)||(channel>=CAN_CHANNEL))
    {
        printf("can channel index Error");
        return ERROR;
    }
#if defined(VXWORKS)
    result = write (can_fd[channel], (char*)(&msg),1);
#endif
    return result;
}


int CANHandler::recv_can(int channel,CAN_PACKET* msg)
{
    int result = 0;

    if((channel<0)||(channel>=CAN_CHANNEL))
    {
        printf("can channel index Error");
        return ERROR;
    }
#if defined(VXWORKS)
    result = read(can_fd[channel], (char*)msg, 1);
#endif
    return result;
}
