#-------------------------------------------------
#
# Project created by QtCreator 2018-01-22T16:08:22
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_treetest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_treetest.cpp \
    model/ExceptionHandler.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    model/TreeModel.h \
    model/TernaryTreeModel.h \
    model/TernaryNode.h \
    model/RedBlackTreeModel.h \
    model/Info.h \
    model/ExceptionHandler.h \
    model/BinaryTreeModel.h \
    model/BinaryRedBlackNode.h \
    model/BinaryNode.h
