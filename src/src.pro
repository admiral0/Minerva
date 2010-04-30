include(../lib/lib.pri)
DESTDIR = ..
INCLUDEPATH = ../qcodeedit \
    ../qcodeedit/document
QT += xml
TARGET = Minerva
TEMPLATE = app
SOURCES += main.cpp \
    minervawindow.cpp \
    minervadocument.cpp

HEADERS += minervawindow.h \
    minervadocument.h
FORMS += minervawindow.ui
LIBS += -L \
    .. \
    -lqcodeedit
