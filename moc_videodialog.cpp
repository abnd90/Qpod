/****************************************************************************
** Meta object code from reading C++ file 'videodialog.h'
**
** Created: Thu Oct 22 13:18:48 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "videodialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videodialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VideoDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   32,   12,   12, 0x08,
      65,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VideoDialog[] = {
    "VideoDialog\0\0Conv_Done(QString)\0fpath\0"
    "open_video_dialog(QString)\0ConvertVideo()\0"
};

const QMetaObject VideoDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VideoDialog,
      qt_meta_data_VideoDialog, 0 }
};

const QMetaObject *VideoDialog::metaObject() const
{
    return &staticMetaObject;
}

void *VideoDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VideoDialog))
        return static_cast<void*>(const_cast< VideoDialog*>(this));
    if (!strcmp(_clname, "Ui::AddVideoDialog"))
        return static_cast< Ui::AddVideoDialog*>(const_cast< VideoDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int VideoDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Conv_Done((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: open_video_dialog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: ConvertVideo(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void VideoDialog::Conv_Done(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
