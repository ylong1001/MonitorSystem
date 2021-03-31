# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PENTIUM4gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/MonitorSystem



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = -DVXWORKS
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = pentium
CPU = PENTIUM4
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mtune=pentium4 -march=pentium4 -nostdlib -fno-builtin -fno-defer-pop
VSB_DIR = $(WIND_BASE)/target/lib
VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h/wrn/coreip -IC:/WindRiver/workspace/qtp1dkm/include/Qt -IC:/WindRiver/workspace/qtp1dkm/include/QtNetwork -IC:/WindRiver/workspace/qtp1dkm/include/QtSql -IC:/WindRiver/workspace/qtp1dkm/include/QtXml -IC:/WindRiver/workspace/qtp1dkm/include -IC:/WindRiver/workspace/qtp1dkm/include/QtCore -IC:/WindRiver/workspace/qtp1dkm/include/QtGui -I$(WIND_BASE)/target/h -I$(PRJ_ROOT_DIR)/MonitorSystem/debug -I$(PRJ_ROOT_DIR)/MonitorSystem/Xml -IC:/WindRiver/workspace/MonitorSystem/MonitorSystem 

IDE_LIBRARIES = C:/WindRiver/workspace/qtp1dkm/lib/libQtNetwork.a C:/WindRiver/workspace/qtp1dkm/lib/libQtSql.a C:/WindRiver/workspace/qtp1dkm/lib/libQtXml.a C:/WindRiver/workspace/qtp1dkm/lib/libQtGui.a C:/WindRiver/workspace/qtp1dkm/lib/libQtCore.a 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2
DEBUGFLAGS_C++-Compiler = -O2
DEBUGFLAGS_Linker = -O2
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2
endif


#Project Targets
PROJECT_TARGETS = MonitorSystem/$(MODE_DIR)/MonitorSystem.out \
	 MonitorSystem_partialImage/$(MODE_DIR)/MonitorSystem_partialImage.o


#Rules

# MonitorSystem
ifeq ($(DEBUG_MODE),1)
MonitorSystem/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
MonitorSystem/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
MonitorSystem/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
MonitorSystem/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
MonitorSystem/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
MonitorSystem/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
MonitorSystem/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2
MonitorSystem/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2
MonitorSystem/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2
MonitorSystem/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
MonitorSystem/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
MonitorSystem/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2
endif
MonitorSystem/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/wrn/coreip -IC:/WindRiver/workspace/qtp1dkm/include/Qt -IC:/WindRiver/workspace/qtp1dkm/include/QtNetwork -IC:/WindRiver/workspace/qtp1dkm/include/QtSql -IC:/WindRiver/workspace/qtp1dkm/include/QtXml -IC:/WindRiver/workspace/qtp1dkm/include -IC:/WindRiver/workspace/qtp1dkm/include/QtCore -IC:/WindRiver/workspace/qtp1dkm/include/QtGui -I$(WIND_BASE)/target/h -I$(PRJ_ROOT_DIR)/MonitorSystem/debug -I$(PRJ_ROOT_DIR)/MonitorSystem/Xml -IC:/WindRiver/workspace/MonitorSystem/MonitorSystem 
MonitorSystem/$(MODE_DIR)/% : IDE_LIBRARIES = C:/WindRiver/workspace/qtp1dkm/lib/libQtNetwork.a C:/WindRiver/workspace/qtp1dkm/lib/libQtSql.a C:/WindRiver/workspace/qtp1dkm/lib/libQtXml.a C:/WindRiver/workspace/qtp1dkm/lib/libQtGui.a C:/WindRiver/workspace/qtp1dkm/lib/libQtCore.a 
MonitorSystem/$(MODE_DIR)/% : PROJECT_TYPE = DKM
MonitorSystem/$(MODE_DIR)/% : DEFINES = -DVXWORKS
MonitorSystem/$(MODE_DIR)/% : EXPAND_DBG = 0
MonitorSystem/$(MODE_DIR)/% : VX_CPU_FAMILY = pentium
MonitorSystem/$(MODE_DIR)/% : CPU = PENTIUM4
MonitorSystem/$(MODE_DIR)/% : TOOL_FAMILY = gnu
MonitorSystem/$(MODE_DIR)/% : TOOL = gnu
MonitorSystem/$(MODE_DIR)/% : TOOL_PATH = 
MonitorSystem/$(MODE_DIR)/% : CC_ARCH_SPEC = -mtune=pentium4 -march=pentium4 -nostdlib -fno-builtin -fno-defer-pop
MonitorSystem/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
MonitorSystem/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
MonitorSystem/$(MODE_DIR)/% : LIBPATH = 
MonitorSystem/$(MODE_DIR)/% : LIBS = 
MonitorSystem/$(MODE_DIR)/% : OBJ_DIR := MonitorSystem/$(MODE_DIR)

OBJECTS_MonitorSystem = MonitorSystem_partialImage/$(MODE_DIR)/MonitorSystem_partialImage.o

MonitorSystem/$(MODE_DIR)/MonitorSystem.out : $(OBJECTS_MonitorSystem)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmpentium $(OBJECTS_MonitorSystem) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium -tags $(VSB_DIR)/tags/pentium/PENTIUM4/common/dkm.tags > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccpentium -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_MonitorSystem) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

MonitorSystem/$(MODE_DIR)/MonitorSystem_compile_file : $(FILE) ;

_clean :: MonitorSystem/$(MODE_DIR)/MonitorSystem_clean

MonitorSystem/$(MODE_DIR)/MonitorSystem_clean : 
	$(TRACE_FLAG)if [ -d "MonitorSystem" ]; then cd "MonitorSystem"; rm -rf $(MODE_DIR); fi


# MonitorSystem_partialImage
ifeq ($(DEBUG_MODE),1)
MonitorSystem_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
MonitorSystem_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
MonitorSystem_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
MonitorSystem_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
MonitorSystem_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
MonitorSystem_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
MonitorSystem_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2
MonitorSystem_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2
MonitorSystem_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2
MonitorSystem_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
MonitorSystem_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
MonitorSystem_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2
endif
MonitorSystem_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/wrn/coreip -IC:/WindRiver/workspace/qtp1dkm/include/Qt -IC:/WindRiver/workspace/qtp1dkm/include/QtNetwork -IC:/WindRiver/workspace/qtp1dkm/include/QtSql -IC:/WindRiver/workspace/qtp1dkm/include/QtXml -IC:/WindRiver/workspace/qtp1dkm/include -IC:/WindRiver/workspace/qtp1dkm/include/QtCore -IC:/WindRiver/workspace/qtp1dkm/include/QtGui -I$(WIND_BASE)/target/h -I$(PRJ_ROOT_DIR)/MonitorSystem/debug -I$(PRJ_ROOT_DIR)/MonitorSystem/Xml -IC:/WindRiver/workspace/MonitorSystem/MonitorSystem 
MonitorSystem_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = C:/WindRiver/workspace/qtp1dkm/lib/libQtNetwork.a C:/WindRiver/workspace/qtp1dkm/lib/libQtSql.a C:/WindRiver/workspace/qtp1dkm/lib/libQtXml.a C:/WindRiver/workspace/qtp1dkm/lib/libQtGui.a C:/WindRiver/workspace/qtp1dkm/lib/libQtCore.a 
MonitorSystem_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
MonitorSystem_partialImage/$(MODE_DIR)/% : DEFINES = -DVXWORKS
MonitorSystem_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
MonitorSystem_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = pentium
MonitorSystem_partialImage/$(MODE_DIR)/% : CPU = PENTIUM4
MonitorSystem_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
MonitorSystem_partialImage/$(MODE_DIR)/% : TOOL = gnu
MonitorSystem_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
MonitorSystem_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mtune=pentium4 -march=pentium4 -nostdlib -fno-builtin -fno-defer-pop
MonitorSystem_partialImage/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
MonitorSystem_partialImage/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
MonitorSystem_partialImage/$(MODE_DIR)/% : LIBPATH = 
MonitorSystem_partialImage/$(MODE_DIR)/% : LIBS = 
MonitorSystem_partialImage/$(MODE_DIR)/% : OBJ_DIR := MonitorSystem_partialImage/$(MODE_DIR)

MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/CAN/CANHandler.o : $(PRJ_ROOT_DIR)/MonitorSystem/CAN/CANHandler.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/Database/querythread.o : $(PRJ_ROOT_DIR)/MonitorSystem/Database/querythread.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/Database/sqliteutil.o : $(PRJ_ROOT_DIR)/MonitorSystem/Database/sqliteutil.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/MainWindow.o : $(PRJ_ROOT_DIR)/MonitorSystem/MainWindow.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/SerialPort/SerialPortThread.o : $(PRJ_ROOT_DIR)/MonitorSystem/SerialPort/SerialPortThread.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/Xml/XmlHelper.o : $(PRJ_ROOT_DIR)/MonitorSystem/Xml/XmlHelper.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/Xml/XmlHelperPrivate.o : $(PRJ_ROOT_DIR)/MonitorSystem/Xml/XmlHelperPrivate.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/moc_MainWindow.o : $(PRJ_ROOT_DIR)/MonitorSystem/debug/moc_MainWindow.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/moc_SerialPortThread.o : $(PRJ_ROOT_DIR)/MonitorSystem/debug/moc_SerialPortThread.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/moc_qextserialenumerator.o : $(PRJ_ROOT_DIR)/MonitorSystem/debug/moc_qextserialenumerator.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/moc_qextserialport.o : $(PRJ_ROOT_DIR)/MonitorSystem/debug/moc_qextserialport.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/qrc_pngImages.o : $(PRJ_ROOT_DIR)/MonitorSystem/debug/qrc_pngImages.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/main.o : $(PRJ_ROOT_DIR)/MonitorSystem/main.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall   -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


OBJECTS_MonitorSystem_partialImage = MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/CAN/CANHandler.o \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/Database/querythread.o \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/Database/sqliteutil.o \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/MainWindow.o \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/SerialPort/SerialPortThread.o \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/Xml/XmlHelper.o \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/Xml/XmlHelperPrivate.o \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/moc_MainWindow.o \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/moc_SerialPortThread.o \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/moc_qextserialenumerator.o \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/moc_qextserialport.o \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/qrc_pngImages.o \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/main.o

MonitorSystem_partialImage/$(MODE_DIR)/MonitorSystem_partialImage.o : $(OBJECTS_MonitorSystem_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_MonitorSystem_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

MonitorSystem_partialImage/$(MODE_DIR)/MonitorSystem_partialImage_compile_file : $(FILE) ;

_clean :: MonitorSystem_partialImage/$(MODE_DIR)/MonitorSystem_partialImage_clean

MonitorSystem_partialImage/$(MODE_DIR)/MonitorSystem_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "MonitorSystem_partialImage" ]; then cd "MonitorSystem_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/CAN/CANHandler.d MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/Database/querythread.d MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/Database/sqliteutil.d \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/MainWindow.d MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/SerialPort/SerialPortThread.d MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/Xml/XmlHelper.d \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/Xml/XmlHelperPrivate.d MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/moc_MainWindow.d MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/moc_SerialPortThread.d \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/moc_qextserialenumerator.d MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/moc_qextserialport.d MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/debug/qrc_pngImages.d \
	 MonitorSystem_partialImage/$(MODE_DIR)/Objects/MonitorSystem/MonitorSystem/main.d
-include $(DEP_FILES)


WIND_SCOPETOOLS_BASE := $(subst \,/,$(WIND_SCOPETOOLS_BASE))

clean_scopetools :
	$(TRACE_FLAG)rm -rf $(PRJ_ROOT_DIR)/.coveragescope/db

CLEAN_STEP := clean_scopetools


-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

JOBS?=1
ifeq ($(JOBS),1)
main_all : external_build  $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS);\
	echo "make: built targets of `pwd`"
endif 

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
