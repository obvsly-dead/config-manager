/****************************************************************************
** Meta object code from reading C++ file 'ConfManagerApplication.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../app/ConfManagerApplication.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConfManagerApplication.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConfManagerApplication_t {
    QByteArrayData data[5];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfManagerApplication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfManagerApplication_t qt_meta_stringdata_ConfManagerApplication = {
    {
QT_MOC_LITERAL(0, 0, 22), // "ConfManagerApplication"
QT_MOC_LITERAL(1, 23, 22), // "onConfigurationChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 4), // "conf"
QT_MOC_LITERAL(4, 52, 11) // "checkServer"

    },
    "ConfManagerApplication\0onConfigurationChanged\0"
    "\0conf\0checkServer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfManagerApplication[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    0,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariantMap,    3,
    QMetaType::Void,

       0        // eod
};

void ConfManagerApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConfManagerApplication *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onConfigurationChanged((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 1: _t->checkServer(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConfManagerApplication::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ConfManagerApplication.data,
    qt_meta_data_ConfManagerApplication,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConfManagerApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfManagerApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConfManagerApplication.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ConfManagerApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
