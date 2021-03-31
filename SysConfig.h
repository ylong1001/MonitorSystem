#ifndef SYSCONFIG_H
#define SYSCONFIG_H

//when use QtCreator as IDE Compiler, undef this,
//when use workbench3.2 as IDE Compiler, define this.
#undef VXWORKS

#if defined(VXWORKS)
#include <vxWorks.h>
#include <ioLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <rngLib.h>
#include <semLib.h>
#include <string.h>
#include <selectLib.h>
#endif


#define	 CAN_CHANNEL		 2
#define  SERIAL_PORT_NUMS    2

#endif // SYSCONFIG_H
