#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T18:41:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Plagiarism-Detection
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    nfa.cpp \
#    digraph.cpp \
    directedgraph.cpp \
    directeddfs.cpp

HEADERS  += mainwindow.h \
    nfa.h \
#    digraph.h \
    directedgraph.h \
    directeddfs.h

FORMS    += mainwindow.ui
