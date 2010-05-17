#include(../qcodeedit/lib.pri)
DESTDIR = ..
INCLUDEPATH = ../qcodeedit \
    ../qcodeedit/document
QT += xml
TARGET = Minerva
TEMPLATE = app
SOURCES += main.cpp \
    minervawindow.cpp \
    minervadocument.cpp \
    minervatabwidget.cpp \
    minervasettings.cpp \
    minervaapplication.cpp
HEADERS += minervawindow.h \
    minervadocument.h \
    minervatabwidget.h \
    minervasettings.h \
    minervaapplication.h
FORMS += minervawindow.ui
LIBS += -L \
    .. \
    -lqcodeedit
