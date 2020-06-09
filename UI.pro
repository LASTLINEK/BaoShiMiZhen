UI_DIR=./UI

QT      += widgets
QT      += sql
QT      += multimedia

SOURCES += \
    Icon.cpp \
    UI.cpp \
    login.cpp \
    logon.cpp \
    main.cpp \
    menu.cpp \
    music.cpp \
    myhelper.cpp \
    orderview.cpp \
    playerinfo.cpp \
    setting.cpp

HEADERS += \
    Icon.h \
    UI.h \
    login.h \
    logon.h \
    menu.h \
    music.h \
    myhelper.h \
    orderview.h \
    playerinfo.h \
    setting.h

FORMS += \
    UI.ui \
    login.ui \
    logon.ui \
    menu.ui \
    orderview.ui \
    setting.ui

RESOURCES += \
    UI.qrc \
    images.qrc
