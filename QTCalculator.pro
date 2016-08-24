#-------------------------------------------------
#
# Project created by QtCreator 2016-08-20T21:37:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTCalculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculate.cpp \
    arithmetictree.cpp

HEADERS  += mainwindow.h \
    calculate.h \
    arithmetictree.h

FORMS    += mainwindow.ui
