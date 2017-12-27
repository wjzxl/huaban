/****************************************************************************
** Meta object code from reading C++ file 'firsttest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../firsttest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'firsttest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FirstTest_t {
    QByteArrayData data[6];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FirstTest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FirstTest_t qt_meta_stringdata_FirstTest = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FirstTest"
QT_MOC_LITERAL(1, 10, 18), // "slideChangedBefore"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "slideChangedAfter"
QT_MOC_LITERAL(4, 48, 19), // "rectviceMouseChnage"
QT_MOC_LITERAL(5, 68, 6) // "cursor"

    },
    "FirstTest\0slideChangedBefore\0\0"
    "slideChangedAfter\0rectviceMouseChnage\0"
    "cursor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FirstTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QCursor,    5,

       0        // eod
};

void FirstTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FirstTest *_t = static_cast<FirstTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slideChangedBefore(); break;
        case 1: _t->slideChangedAfter(); break;
        case 2: _t->rectviceMouseChnage((*reinterpret_cast< QCursor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FirstTest::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FirstTest::slideChangedBefore)) {
                *result = 0;
            }
        }
        {
            typedef void (FirstTest::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FirstTest::slideChangedAfter)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject FirstTest::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_FirstTest.data,
      qt_meta_data_FirstTest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FirstTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FirstTest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FirstTest.stringdata0))
        return static_cast<void*>(const_cast< FirstTest*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int FirstTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FirstTest::slideChangedBefore()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void FirstTest::slideChangedAfter()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
