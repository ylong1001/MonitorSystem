#ifndef CANHANDLER_H
#define CANHANDLER_H

#include "canDeva.h"

class CANHandler
{
public:
    CANHandler();
    ~CANHandler();
    int open_can(int channel);

    int close_can(int channel);

    int init_can(int channel);

    int reset_can(int channel);

    int send_can(int channel,CAN_PACKET &msg);

    int recv_can(int channel,CAN_PACKET* msg);

private:
    int can_fd[CAN_CHANNEL];  //CAN文件句柄
};

#endif // CANHANDLER_H
