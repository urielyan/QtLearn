#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T18:31:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mvctest.cpp \
    setupdatetime.cpp \
    learnqpainter.cpp

HEADERS  += widget.h \
    mvctest.h \
    global.h \
    setupdatetime.h \
    learnqpainter.h

FORMS    += widget.ui \
    setupdatetime.ui
