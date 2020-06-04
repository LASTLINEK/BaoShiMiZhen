UI_DIR=./UI

QT      += widgets
QT      += sql
QT      += multimedia

SOURCES += \
    Icon.cpp \
    UI.cpp \
    login.cpp \
    main.cpp \
    music.cpp \
    myhelper.cpp \
    orderview.cpp \
    playerinfo.cpp

HEADERS += \
    Icon.h \
    UI.h \
    login.h \
    music.h \
    myhelper.h \
    orderview.h \
    playerinfo.h

FORMS += \
    UI.ui \
    login.ui \
    orderview.ui

RESOURCES += \
    UI.qrc \
    images.qrc
