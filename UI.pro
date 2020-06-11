UI_DIR=./UI

QT      += widgets
QT      += sql
QT      += multimedia
CONFIG += resources_big

SOURCES += \
    Icon.cpp \
    UI.cpp \
    choosedif.cpp \
    help.cpp \
    login.cpp \
    logon.cpp \
    main.cpp \
    menu.cpp \
    music.cpp \
    myhelper.cpp \
    number.cpp \
    orderview.cpp \
    playerinfo.cpp \
    setting.cpp

HEADERS += \
    Icon.h \
    UI.h \
    choosedif.h \
    help.h \
    login.h \
    logon.h \
    menu.h \
    music.h \
    myhelper.h \
    number.h \
    orderview.h \
    playerinfo.h \
    setting.h

FORMS += \
    UI.ui \
    choosedif.ui \
    help.ui \
    login.ui \
    logon.ui \
    menu.ui \
    orderview.ui \
    setting.ui

RESOURCES += \
    UI.qrc \
    images.qrc
