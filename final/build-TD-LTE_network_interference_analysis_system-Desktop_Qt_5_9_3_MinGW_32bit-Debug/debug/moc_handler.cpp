/****************************************************************************
** Meta object code from reading C++ file 'handler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TD-LTE_network_interference_analysis_system/handler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Handler_t {
    QByteArrayData data[16];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Handler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Handler_t qt_meta_stringdata_Handler = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Handler"
QT_MOC_LITERAL(1, 8, 13), // "insertCSVData"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 21), // "inserttbCellExcelData"
QT_MOC_LITERAL(4, 45, 18), // "insertKPIExcelData"
QT_MOC_LITERAL(5, 64, 18), // "insertPRBExcelData"
QT_MOC_LITERAL(6, 83, 10), // "exportData"
QT_MOC_LITERAL(7, 94, 16), // "exportResultData"
QT_MOC_LITERAL(8, 111, 13), // "srearchSector"
QT_MOC_LITERAL(9, 125, 13), // "srearchENodeB"
QT_MOC_LITERAL(10, 139, 10), // "srearchKPI"
QT_MOC_LITERAL(11, 150, 14), // "exporttbPRNnew"
QT_MOC_LITERAL(12, 165, 14), // "searchtbPRBnew"
QT_MOC_LITERAL(13, 180, 12), // "searchTriple"
QT_MOC_LITERAL(14, 193, 10), // "analiseC2I"
QT_MOC_LITERAL(15, 204, 12) // "setGroupSize"

    },
    "Handler\0insertCSVData\0\0inserttbCellExcelData\0"
    "insertKPIExcelData\0insertPRBExcelData\0"
    "exportData\0exportResultData\0srearchSector\0"
    "srearchENodeB\0srearchKPI\0exporttbPRNnew\0"
    "searchtbPRBnew\0searchTriple\0analiseC2I\0"
    "setGroupSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Handler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Handler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Handler *_t = static_cast<Handler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->insertCSVData(); break;
        case 1: _t->inserttbCellExcelData(); break;
        case 2: _t->insertKPIExcelData(); break;
        case 3: _t->insertPRBExcelData(); break;
        case 4: _t->exportData(); break;
        case 5: _t->exportResultData(); break;
        case 6: _t->srearchSector(); break;
        case 7: _t->srearchENodeB(); break;
        case 8: _t->srearchKPI(); break;
        case 9: _t->exporttbPRNnew(); break;
        case 10: _t->searchtbPRBnew(); break;
        case 11: _t->searchTriple(); break;
        case 12: _t->analiseC2I(); break;
        case 13: _t->setGroupSize(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Handler::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Handler.data,
      qt_meta_data_Handler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Handler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Handler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Handler.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Handler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
