TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
QT += core gui
QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES += \
        basic_solver.cpp \
        hyperbolic_interface.cpp \
        hyperbolic_solver.cpp \
        main.cpp \
        matrix.cpp \
        parab_hyperb_solver.cpp \
        parabolic_interface.cpp \
        parabolic_solver.cpp \
        solution_saver.cpp \
        tridiagonal.cpp

HEADERS += \
    basic_solver.h \
    hyperbolic_interface.h \
    hyperbolic_solver.h \
    matrix.h \
    methods.h \
    parab_hyperb_solver.h \
    parabolic_interface.h \
    parabolic_solver.h \
    solution_saver.h \
    tridiagonal.h

FORMS += \
    hyperbolic_interface.ui \
    parabolic_interface.ui
