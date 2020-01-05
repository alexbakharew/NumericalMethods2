TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES += \
        basic_solver.cpp \
        main.cpp \
        mainwindow.cpp \
        matrix.cpp \
        parabolic_solver.cpp \
        tridiagonal.cpp

HEADERS += \
    basic_solver.h \
    mainwindow.h \
    matrix.h \
    methods.h \
    parabolic_solver.h \
    tridiagonal.h

FORMS += \
    mainwindow.ui
