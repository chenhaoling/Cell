#-------------------------------------------------
#
# Project created by QtCreator 2017-05-19T10:29:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tank
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bullet.cpp \
    boom.cpp \
    mapcell.cpp \
    gamemap.cpp \
    status.cpp \
    gamemainwindow.cpp \
    all.cpp \
    cell.cpp

HEADERS  += mainwindow.h \
    bullet.h \
    boom.h \
    mapcell.h \
    gamemap.h \
    main.h \
    status.h \
    gamemainwindow.h \
    all.h \
    cell.h

RESOURCES += \
    mytank.qrc
QT       += multimedia  multimediawidgets

RC_ICONS =myico.ico
