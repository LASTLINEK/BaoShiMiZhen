/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.13.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // C:/Users/22709/Desktop/new/login.png
  
  
    // C:/Users/22709/Desktop/new/input.png
  
  
    // C:/Users/22709/Desktop/new/background.png
  
  
  
static const unsigned char qt_resource_data[1581275] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // login.png
  0x0,0x9,
  0xe,0x1,0xb1,0xe7,
  0x0,0x6c,
  0x0,0x6f,0x0,0x67,0x0,0x69,0x0,0x6e,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
    // UI
  0x0,0x2,
  0x0,0x0,0x5,0x99,
  0x0,0x55,
  0x0,0x49,
    // input.png
  0x0,0x9,
  0x7,0xc7,0xb7,0xe7,
  0x0,0x69,
  0x0,0x6e,0x0,0x70,0x0,0x75,0x0,0x74,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
    // background.png
  0x0,0xe,
  0x7,0x4,0x9f,0x87,
  0x0,0x62,
  0x0,0x61,0x0,0x63,0x0,0x6b,0x0,0x67,0x0,0x72,0x0,0x6f,0x0,0x75,0x0,0x6e,0x0,0x64,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x3,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/UI
  0x0,0x0,0x0,0x18,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x4,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/input.png
  0x0,0x0,0x0,0x22,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x1,0xe8,0xcd,
0x0,0x0,0x1,0x72,0x70,0x39,0xa1,0xb5,
  // :/login.png
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x72,0x70,0x31,0x12,0x49,
  // :/UI/background.png
  0x0,0x0,0x0,0x3a,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x3,0xc1,0xdf,
0x0,0x0,0x1,0x72,0x2d,0x8c,0x77,0x2d,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_UI)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_UI)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_UI)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_UI)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_UI)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_UI)(); }
   } dummy;
}
