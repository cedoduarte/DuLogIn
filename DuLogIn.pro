#-------------------------------------------------
#
# Project created by QtCreator 2015-08-14T14:48:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuLogIn
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    registraradmindialog.cpp \
    botan.cpp \
    DuCrypt.cpp \
    administrador.cpp \
    usuario.cpp \
    mainwindow.cpp \
    controlusuariosform.cpp

HEADERS  += dialog.h \
    registraradmindialog.h \
    botan.h \
    DuCrypt.h \
    administrador.h \
    usuario.h \
    mainwindow.h \
    controlusuariosform.h

FORMS    += dialog.ui \
    registraradmindialog.ui \
    mainwindow.ui \
    controlusuariosform.ui

DISTFILES += \
    Botan.pri

include($$PWD/Botan.pri)

QMAKE_CXXFLAGS += -std=gnu++14
