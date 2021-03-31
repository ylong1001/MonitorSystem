/****************************************************************************
** Meta object code from reading C++ file 'networkUDP.h'
**
** Created: Wed Mar 31 17:08:07 2021
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Network/networkUDP.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkUDP.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NetworkUDP[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      59,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NetworkUDP[] = {
    "NetworkUDP\0\0data\0"
    "send_mainUi_luojujiao1_singal(QByteArray)\0"
    "slot_UdpReadyToRead()\0"
};

void NetworkUDP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NetworkUDP *_t = static_cast<NetworkUDP *>(_o);
        switch (_id) {
        case 0: _t->send_mainUi_luojujiao1_singal((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->slot_UdpReadyToRead(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NetworkUDP::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NetworkUDP::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_NetworkUDP,
      qt_meta_data_NetworkUDP, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NetworkUDP::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NetworkUDP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NetworkUDP::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkUDP))
        return static_cast<void*>(const_cast< NetworkUDP*>(this));
    return QThread::qt_metacast(_clname);
}

int NetworkUDP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void NetworkUDP::send_mainUi_luojujiao1_singal(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
