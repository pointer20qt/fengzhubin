#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T16:51:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sign
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    grjm.cpp \
    login.cpp \
    reg_a.cpp

HEADERS  += widget.h \
    grjm.h \
    login.h \
    reg_a.h

FORMS    += widget.ui \
    grjm.ui \
    login.ui \
    reg_a.ui
