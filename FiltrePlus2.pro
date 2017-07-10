#-------------------------------------------------
#
# Project created by QtCreator 2017-06-05T16:05:46
#
#-------------------------------------------------

QT       += core gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = FiltrePlus2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH     += "D:\Programme\openCV\opencv-3.2.0\include"
LIBS            +=  -L ""

SOURCES += main.cpp\
        mainwindow.cpp \
    niveaugris.cpp \
    imagemanager.cpp \
    negatif.cpp \
    filtre.cpp

HEADERS  += mainwindow.h \
    niveaugris.h \
    imagemanager.h \
    negatif.h \
    filtre.h

FORMS    += mainwindow.ui

QT_CONFIG -= no-pkg-config
CONFIG += link_pkgconfig
PKGCONFIG += opencv

DISTFILES += \
    ReadMe.txt
