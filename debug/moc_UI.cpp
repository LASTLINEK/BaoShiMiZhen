/****************************************************************************
** Meta object code from reading C++ file 'UI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../UI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UI_t {
    QByteArrayData data[13];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UI_t qt_meta_stringdata_UI = {
    {
QT_MOC_LITERAL(0, 0, 2), // "UI"
QT_MOC_LITERAL(1, 3, 12), // "sendGameOver"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 11), // "iconClicked"
QT_MOC_LITERAL(4, 29, 12), // "iconReleased"
QT_MOC_LITERAL(5, 42, 8), // "iconSwap"
QT_MOC_LITERAL(6, 51, 3), // "dir"
QT_MOC_LITERAL(7, 55, 6), // "timeUp"
QT_MOC_LITERAL(8, 62, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 84, 18), // "on_restart_clicked"
QT_MOC_LITERAL(10, 103, 22), // "on_musicButton_clicked"
QT_MOC_LITERAL(11, 126, 21), // "on_action_H_triggered"
QT_MOC_LITERAL(12, 148, 21) // "on_HintButton_clicked"

    },
    "UI\0sendGameOver\0\0iconClicked\0iconReleased\0"
    "iconSwap\0dir\0timeUp\0on_pushButton_clicked\0"
    "on_restart_clicked\0on_musicButton_clicked\0"
    "on_action_H_triggered\0on_HintButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   67,    2, 0x0a /* Public */,
       4,    0,   68,    2, 0x0a /* Public */,
       5,    1,   69,    2, 0x0a /* Public */,
       7,    0,   72,    2, 0x0a /* Public */,
       8,    0,   73,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x0a /* Public */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendGameOver((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->iconClicked(); break;
        case 2: _t->iconReleased(); break;
        case 3: _t->iconSwap((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->timeUp(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_restart_clicked(); break;
        case 7: _t->on_musicButton_clicked(); break;
        case 8: _t->on_action_H_triggered(); break;
        case 9: _t->on_HintButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UI::sendGameOver)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UI::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_UI.data,
    qt_meta_data_UI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int UI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void UI::sendGameOver(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
