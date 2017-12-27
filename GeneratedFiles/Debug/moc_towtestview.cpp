/****************************************************************************
** Meta object code from reading C++ file 'towtestview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../towtestview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'towtestview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TowTestView_t {
    QByteArrayData data[3];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TowTestView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TowTestView_t qt_meta_stringdata_TowTestView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TowTestView"
QT_MOC_LITERAL(1, 12, 20), // "changeThemouseStatue"
QT_MOC_LITERAL(2, 33, 0) // ""

    },
    "TowTestView\0changeThemouseStatue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TowTestView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QCursor,    2,

       0        // eod
};

void TowTestView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TowTestView *_t = static_cast<TowTestView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeThemouseStatue((*reinterpret_cast< QCursor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TowTestView::*_t)(QCursor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TowTestView::changeThemouseStatue)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject TowTestView::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_TowTestView.data,
      qt_meta_data_TowTestView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TowTestView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TowTestView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TowTestView.stringdata0))
        return static_cast<void*>(const_cast< TowTestView*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int TowTestView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void TowTestView::changeThemouseStatue(QCursor _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
