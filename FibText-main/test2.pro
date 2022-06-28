#-------------------------------------------------
#
# Project created by QtCreator 2022-04-21T10:56:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test2
TEMPLATE = app


SOURCES += main.cpp\
        mytestwidget.cpp \
        viewdialog.cpp

HEADERS  += mytestwidget.h \
        viewdialog.h

FORMS    += mytestwidget.ui \
        viewdialog.ui

RESOURCES += \
        icon.qrc \
        image.qrc
