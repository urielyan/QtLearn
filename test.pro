#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T18:31:36
#
#-------------------------------------------------

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
    learn/mvctest.cpp \
    setupdatetime.cpp \
    learn/learnqpainter.cpp \
    trendcontextbutton.cpp \
    learn/exception.cpp \
    learn/metaobject.cpp \
    learn/styleoptionstudy.cpp \
    learn/database.cpp \
    learn/syslogstudy.cpp \
    learn/testforlooptime.cpp \
    learn/customscrollbar.cpp

HEADERS  += \
    learn/mvctest.h \
    global.h \
    setupdatetime.h \
    learn/learnqpainter.h \
    trendcontextbutton.h \
    learn/exception.h \
    learn/metaobject.h \
    learn/styleoptionstudy.h \
    learn/database.h \
    learn/syslogstudy.h \
    learn/testforlooptime.h \
    learn/customscrollbar.h

FORMS    +=

unix:INCLUDEPATH += "/home/yange/QtCode/QtLearn/learn"
