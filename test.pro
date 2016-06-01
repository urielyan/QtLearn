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
    learn/mvctest.cpp \
    setupdatetime.cpp \
    learn/learnqpainter.cpp

HEADERS  += widget.h \
    learn/mvctest.h \
    global.h \
    setupdatetime.h \
    learn/learnqpainter.h

FORMS    += widget.ui

unix:INCLUDEPATH += "/home/yange/QtCode/QtLearn/learn"
