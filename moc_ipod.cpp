/****************************************************************************
** Meta object code from reading C++ file 'ipod.h'
**
** Created: Tue Oct 20 15:54:33 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ipod.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ipod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ipod[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      19,    5,    5,    5, 0x0a,
      42,    5,    5,    5, 0x0a,
      62,   60,    5,    5, 0x0a,
      92,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Ipod[] = {
    "Ipod\0\0AddedTrack()\0SetMountPoint(QString)\0"
    "AddTrack(QString)\0,\0AddTrack(Itdb_Track*,QString)\0"
    "AddFolder(QString)\0"
};

const QMetaObject Ipod::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ipod,
      qt_meta_data_Ipod, 0 }
};

const QMetaObject *Ipod::metaObject() const
{
    return &staticMetaObject;
}

void *Ipod::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ipod))
        return static_cast<void*>(const_cast< Ipod*>(this));
    return QObject::qt_metacast(_clname);
}

int Ipod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: AddedTrack(); break;
        case 1: SetMountPoint((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: AddTrack((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: AddTrack((*reinterpret_cast< Itdb_Track*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: AddFolder((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Ipod::AddedTrack()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
