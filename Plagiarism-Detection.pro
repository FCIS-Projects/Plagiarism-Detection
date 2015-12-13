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
    directeddfs.cpp \
    nfa_to_dfa.cpp \
    directedgraph_dfa.cpp

HEADERS  += mainwindow.h \
    nfa.h \
#    digraph.h \
    directedgraph.h \
    directeddfs.h \
<<<<<<< 1f5c4dfab761a89c253e205ab71808495f5d0aba
    nfa_to_dfa.h
=======
    nfa_to_dfa.h \
    directedgraph_dfa.h
>>>>>>> 66d2046762647e5d4b73d304a3d9157aeab60703

FORMS    += mainwindow.ui
