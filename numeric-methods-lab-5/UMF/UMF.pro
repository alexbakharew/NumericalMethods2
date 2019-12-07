TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES += \
        main.cpp \
        mainwindow.cpp \
        solver.cpp

HEADERS += \
    mainwindow.h \
    methods.h \
    solver.h

FORMS += \
    mainwindow.ui
