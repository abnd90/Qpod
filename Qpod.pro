# -------------------------------------------------
# Project created by QtCreator 2009-09-26T22:56:33
# -------------------------------------------------
TARGET = Qpod
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    ipod.cpp \
    videodialog.cpp \
    common.cpp
HEADERS += mainwindow.h \
    ipod.h \
    ipod.h \
    videodialog.h \
    common.h
FORMS += mainwindow.ui \
    addvideodialog.ui
CONFIG += link_pkgconfig
PKGCONFIG += libgpod-1.0 \
    glib-2.0 \
    taglib
RESOURCES += images.qrc
QMAKE_CXXFLAGS -= -m64
QMAKE_CFLAGS -= -m64
QMAKE_LFLAGS -= -m64
