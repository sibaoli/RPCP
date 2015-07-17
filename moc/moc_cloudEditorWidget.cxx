/****************************************************************************
** Meta object code from reading C++ file 'cloudEditorWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/cloudEditorWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cloudEditorWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CloudEditorWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      26,   18,   18,   18, 0x0a,
      33,   18,   18,   18, 0x0a,
      44,   18,   18,   18, 0x0a,
      62,   18,   18,   18, 0x0a,
      69,   18,   18,   18, 0x0a,
      80,   18,   18,   18, 0x0a,
      91,   18,   18,   18, 0x0a,
     102,   18,   18,   18, 0x0a,
     117,   18,   18,   18, 0x0a,
     132,   18,   18,   18, 0x0a,
     139,   18,   18,   18, 0x0a,
     147,   18,   18,   18, 0x0a,
     156,   18,   18,   18, 0x0a,
     162,   18,   18,   18, 0x0a,
     174,   18,   18,   18, 0x0a,
     184,   18,   18,   18, 0x0a,
     191,   18,   18,   18, 0x0a,
     211,   18,   18,   18, 0x0a,
     231,   18,   18,   18, 0x0a,
     259,   18,   18,   18, 0x0a,
     292,  287,   18,   18, 0x0a,
     310,  287,   18,   18, 0x0a,
     336,   18,   18,   18, 0x0a,
     349,   18,   18,   18, 0x0a,
     360,   18,   18,   18, 0x0a,
     371,   18,   18,   18, 0x0a,
     382,   18,   18,   18, 0x0a,
     396,   18,   18,   18, 0x0a,
     407,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CloudEditorWidget[] = {
    "CloudEditorWidget\0\0load()\0save()\0"
    "save_seg()\0toggleBlendMode()\0view()\0"
    "select1D()\0select2D()\0select3D()\0"
    "invertSelect()\0cancelSelect()\0copy()\0"
    "paste()\0remove()\0cut()\0transform()\0"
    "denoise()\0undo()\0increasePointSize()\0"
    "decreasePointSize()\0increaseSelectedPointSize()\0"
    "decreaseSelectedPointSize()\0size\0"
    "setPointSize(int)\0setSelectedPointSize(int)\0"
    "colorByRGB()\0colorByX()\0colorByY()\0"
    "colorByZ()\0colorByPure()\0showStat()\0"
    "segmentation()\0"
};

void CloudEditorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CloudEditorWidget *_t = static_cast<CloudEditorWidget *>(_o);
        switch (_id) {
        case 0: _t->load(); break;
        case 1: _t->save(); break;
        case 2: _t->save_seg(); break;
        case 3: _t->toggleBlendMode(); break;
        case 4: _t->view(); break;
        case 5: _t->select1D(); break;
        case 6: _t->select2D(); break;
        case 7: _t->select3D(); break;
        case 8: _t->invertSelect(); break;
        case 9: _t->cancelSelect(); break;
        case 10: _t->copy(); break;
        case 11: _t->paste(); break;
        case 12: _t->remove(); break;
        case 13: _t->cut(); break;
        case 14: _t->transform(); break;
        case 15: _t->denoise(); break;
        case 16: _t->undo(); break;
        case 17: _t->increasePointSize(); break;
        case 18: _t->decreasePointSize(); break;
        case 19: _t->increaseSelectedPointSize(); break;
        case 20: _t->decreaseSelectedPointSize(); break;
        case 21: _t->setPointSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->setSelectedPointSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->colorByRGB(); break;
        case 24: _t->colorByX(); break;
        case 25: _t->colorByY(); break;
        case 26: _t->colorByZ(); break;
        case 27: _t->colorByPure(); break;
        case 28: _t->showStat(); break;
        case 29: _t->segmentation(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CloudEditorWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CloudEditorWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_CloudEditorWidget,
      qt_meta_data_CloudEditorWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CloudEditorWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CloudEditorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CloudEditorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CloudEditorWidget))
        return static_cast<void*>(const_cast< CloudEditorWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int CloudEditorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
