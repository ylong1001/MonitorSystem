#-------------------------------------------------
#
# Project created by QtCreator 2021-02-23T21:05:20
#
#-------------------------------------------------

QT       += core gui sql network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MonitorSystem
TEMPLATE = app

INCLUDEPATH += $$PWD/Xml
INCLUDEPATH += $$PWD/Database

SOURCES += main.cpp\
        MainWindow.cpp \
    Xml/XmlHelperPrivate.cpp \
    SerialPort/SerialPortThread.cpp \
    CAN/CANHandler.cpp \
    Database/querythread.cpp \
    Database/sqliteutil.cpp \
    Network/networkUDP.cpp \
    Network/networkTCP.cpp

HEADERS  += MainWindow.h \
    Xml/XmlHelperPrivate.h \
    SerialPort/SerialPortThread.h \
    CAN/canDeva.h \
    CAN/CANHandler.h \
    SysConfig.h \
    Database/querythread.h \
    Database/sqliteutil.h \
    Network/networkUDP.h \
    Network/networkTCP.h


#include(SerialPort/qextserialport/qextserialport.pri)
#INCLUDEPATH += $$PWD/SerialPort/qextserialport

FORMS += \
    Forms/MainWindow.ui

RESOURCES += \
    pngImages.qrc
