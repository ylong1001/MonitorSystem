/**********************************************/
/* canDevIO.h - CAN Device I/O Interface header file. */
/* Copyright 2009-2012 SBS, Inc. */

/*modification history
--------------------
01a,19Jul09,CWY  created*/

/*DESCRIPTION

This file contains the type and function definitions of the Device I/O 
Interface feature of CAN. 

NOTE

RESTRICTIONS

INCLUDE FILES*/
/**********************************************/


#ifndef __INCcanDevh
#define __INCcanDevh


#ifdef __cplusplus
extern "C" {
#endif

#include "SysConfig.h"
/* ==== Include files ==== */
#if !defined(VXWORKS)
typedef char                INT8;
typedef int                 INT16;
typedef unsigned char       UINT8;
typedef unsigned int        UINT16;
typedef unsigned long       UINT32;
typedef unsigned long long  UINT64;
typedef unsigned int        UINT;
typedef unsigned char       UCHAR;
typedef unsigned long       ULONG;
typedef int                 STATUS;
#define  OK                  0
#define  ERROR               -1
#endif

/* ==== CAN DevIO interface ioctl() commands ==== */

/* Base command code	*/
#define DEVIO_CANCMD_BASE        100

/* Device commands		*/
#define CAN_HALT		(DEVIO_CANCMD_BASE + 1)
#define CAN_START		(DEVIO_CANCMD_BASE + 2)
#define CAN_SLEEP		(DEVIO_CANCMD_BASE + 3)
#define CAN_WAKE		(DEVIO_CANCMD_BASE + 4)
#define CAN_TX_ABORT		(DEVIO_CANCMD_BASE + 5)
#define CAN_SET_FILTER		(DEVIO_CANCMD_BASE + 6)
#define CAN_GET_FILTER		(DEVIO_CANCMD_BASE + 7)
#define CAN_GET_BUSINFO		(DEVIO_CANCMD_BASE + 8)
#define CAN_GET_SJASTATUS	(DEVIO_CANCMD_BASE + 9)
#define CAN_GET_BAUDRATE	(DEVIO_CANCMD_BASE + 10)
#define CAN_SET_BAUDRATE	(DEVIO_CANCMD_BASE + 11)
#define CAN_SET_INTERRUP	(DEVIO_CANCMD_BASE + 12)
#define CAN_SET_FILTERMODE	(DEVIO_CANCMD_BASE + 13)
#define CAN_SET_LISTENMODE	(DEVIO_CANCMD_BASE + 14)
#define CAN_SET_SELFTSMODE	(DEVIO_CANCMD_BASE + 15)
#define CAN_RESET			(DEVIO_CANCMD_BASE + 16)
#define CAN_CLR_RECBUF		(DEVIO_CANCMD_BASE + 17)
#define CAN_CLR_TXBUF		(DEVIO_CANCMD_BASE + 18)

/* Additinal Device commands	*/
#define CAN_REG_SET            (DEVIO_CANCMD_BASE + 20)
#define CAN_REG_GET            (DEVIO_CANCMD_BASE + 21)
#define CAN_GET_INTTXCOUNT     (DEVIO_CANCMD_BASE + 22)



/*## Timing values   //16Mhz*/
#define CAN_TIM0_5K           0x7f
#define CAN_TIM1_5K           0xff
#define CAN_TIM0_10K          0x5f
#define CAN_TIM1_10K          0xff
#define CAN_TIM0_20K          0x4f
#define CAN_TIM1_20K          0xff
#define CAN_TIM0_40K          0x47   
#define CAN_TIM1_40K          0xff   
#define CAN_TIM0_80K          0x43   
#define CAN_TIM1_80K          0xff   


#define CAN_TIM0_100K         0xc4  
#define CAN_TIM1_100K         0x3a  
#define CAN_TIM0_125K         0x43
#define CAN_TIM1_125K         0x1c
#define CAN_TIM0_160K         0x41
#define CAN_TIM1_160K         0xff


#define CAN_TIM0_250K         0x41
#define CAN_TIM1_250K         0x1c
#define CAN_TIM0_320K         0x40  
#define CAN_TIM1_320K         0xff
#define CAN_TIM0_500K         0x41
#define CAN_TIM1_500K         0x14
#define CAN_TIM0_800K         0x40
#define CAN_TIM1_800K         0x34
#define CAN_TIM0_1000K        0x40
#define CAN_TIM1_1000K        0x14  

#define	PCI_CFG_BASE_ADDRESS_0	0x10
#define	PCI_CFG_BASE_ADDRESS_1	0x14
#define	PCI_CFG_BASE_ADDRESS_2	0x18
#define	PCI_CFG_BASE_ADDRESS_3	0x1c
#define	PCI_CFG_BASE_ADDRESS_4	0x20
#define	PCI_CFG_BASE_ADDRESS_5	0x24
#define	PCI_CFG_DEV_INT_LINE	0x3c

#define	VENDER_IDSBS			0x12df
#define	VENDER_10B5				0x10B5
#define	VENDER_1525				0x1414
#define	DEVICE_ID9052			0x1517	 /*CDM1517*/
#define	DEVICE_ID954			0x9511   /*CDM1525*/
#define	DEVICE_ID9030			0x1602   /**/
#define	DEVICE_ID9050			0x9050   /*CDM1442*/

#define MAX_BUFSIZE  			1000

#define CAN_MAX_DATA_LEN	8	/* max #bytes in CAN message data */

/* CAN bus error type */
#define CAN_ERR_NONE    	0
#define CAN_ERR_BIT     	0x1
#define CAN_ERR_ACK     	0x2
#define CAN_ERR_CRC     	0x4
#define CAN_ERR_FORM    	0x8
#define CAN_ERR_STUFF   	0x10
#define CAN_ERR_UNKNOWN 	0x20

/* status code returned by CAN_GetBusStatus */
#define CAN_BUS_OK   		0
#define CAN_BUS_WARN 		1
#define CAN_BUS_OFF  		2


/*Macro definitions to be used with filtering*/
#define COMPARE_ALL_STD_IDS 0x7FF
#define COMPARE_ALL_EXT_IDS 0x1FFFFFFF
#define ACCEPT_ALL_STD_IDS  0
#define ACCEPT_ALL_STD_IDS  0



extern unsigned char UserTIM0;
extern unsigned char UserTIM1;




enum baudr {B1000,B800,B500,B320,B250,B160,B125,B100,B80,B40,B20,B10,B5,USR}; 

typedef struct{
	unsigned char sendtype;/*0-normal tx, 1-- tx only once time,2--slef to self, 3--self to self onlyonce time*/
	unsigned char frameinfor; /*Basic: bit4(RTR--1  DATA--0) PeilCan:frameinfor == Bit7(SFF EFF--1) bit6(RTR--1  DATA--0)  bit[3:0]byte_len( <= 8)*/
	ULONG id;		
	/*  
	CAN ID id10-0(Basic:bit10--bit0) or bit28-0
	(PeilCan SFF:id28--id18(bit28--bit18) 
	 PeilCan EFF:id28--id0(bit28--bit0) */
	UCHAR data[CAN_MAX_DATA_LEN];/* message data */
}CAN_PACKET;

/*offadr  bit7----bitx	
17--------ID28----ID21
18--------ID20----ID18

17--------ID28----ID21
18--------ID20----ID13
19--------ID12----ID5
20--------ID4 ----ID0
*/

/*offadr  bit7----bitx
16--------ACR0[7----0]	17--------ACR1[7----5]	18--------ACR2[7----0]	19--------ACR3[7----0]
20--------AMR0[7----0]	21--------AMR1[7----5]	22--------AMR2[7----0]	23--------AMR3[7----0]
----------ID28----ID21	----------ID20----ID18	----------DB1.7--DB1.0	----------DB2.7--DB2.0
*/

/*offadr  bit7----bitx
16--------ACR0[7----0]	17--------ACR1[7----5]	18--------ACR2[7----0]	19--------ACR3[7----3]
20--------AMR0[7----0]	21--------AMR1[7----5]	22--------AMR2[7----0]	23--------AMR3[7----3]
----------ID28----ID21  ----------ID20----ID13  ----------ID12----ID5   ----------ID4----ID0
*/

/* CAN bus information		*/
typedef struct can_businfo
{
    UINT	busStatus;  /* bus status */
    UINT	busError;   /* bus error */
}  CAN_BUSINFO;

/* CAN device register get/set configuration */
typedef struct can_reg
{
    UINT	offset;		/* Register offset from base to access */
    UCHAR 	pData;		/* Pointer to data buffer for read/write */
}  CAN_REG;

typedef struct Filter_Struct
{
	/*unsigned char code[4];*/
	/*unsigned char mask[4];*/
	unsigned int codes;
	unsigned int masks;

} CAN_FILTER;

typedef struct Can_Status
{	
	unsigned char reg_status;   /*Basic only it*/	
	unsigned char reg_interrupt;	 		
	unsigned char reg_ALCaputer;	
	unsigned char reg_ECCaputer;	
	unsigned char reg_EWLimit;	
	unsigned char reg_RECounter;	
	unsigned char reg_TECounter;
	unsigned char reg_RMC;	
	unsigned char resetIntStat;
	unsigned int resetCount;	
}CAN_STATUS;

typedef struct CAN_INTTX_COUNTSUM
{	
	unsigned int     TInterruptlastcoun;
	unsigned int     TInterruptsum;
	unsigned int     TRtFramsum;
}CAN_INTTXCOUSUM;

typedef struct Can_Init_Cfg
{	
    unsigned int codes;/*unsigned char code[4]; Peli :*/
    unsigned int masks;/*unsigned char mask[4]; Basic:[ ID.10-ID.3  ==  AC.7-AC.0 ] OR (AM.7-AM.0)  === 11111111*/
	unsigned char bittiming0;	
	unsigned char bittiming1;	
}CAN_INIT_CFG;
  

typedef struct tagCANPBUF
{
	CAN_PACKET * pBuf;
	CAN_PACKET * pWriteBuf; 	/*ptr to write position*/
	CAN_PACKET * pReadBuf; 		/*ptr to reBd position*/

	unsigned long ulSize; 		/*Buff size*/
	unsigned long ulWrite;		/*Write count*/
	unsigned long ulRead;		/*ReBd count*/
	unsigned long ulSumOver;	/*Over lBp count*/
}TAGCANPBUF;


int	kbhitcan();
STATUS canDrv(void);
STATUS canDevCreate(UINT32 venIdoBase, UINT32 devIdoIrq, char *devName, UINT32 driver,enum baudr initbaudrate);
void CanVer();

#ifdef __cplusplus
}
#endif

#endif /* __INCcanDevIOh */
