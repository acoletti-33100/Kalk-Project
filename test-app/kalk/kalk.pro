#-------------------------------------------------
#
# Project created by QtCreator 2018-01-26T21:35:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kalk
TEMPLATE = app


SOURCES += main.cpp\
        kalk.cpp \
    view/createBinaryTreeArea.cpp \
    view/createRBTreeArea.cpp \
    view/createTernaryTreeArea.cpp \
    view/createTreeArea.cpp \
    model/ExceptionHandler.cpp

HEADERS  += kalk.h \
    view/createBinaryTreeArea.h \
    view/createRBTreeArea.h \
    view/createTernaryTreeArea.h \
    view/createTreeArea.h \
    model/BinaryNode.h \
    model/BinaryRedBlackNode.h \
    model/BinaryTreeModel.h \
    model/ExceptionHandler.h \
    model/Info.h \
    model/RedBlackTreeModel.h \
    model/TernaryNode.h \
    model/TernaryTreeModel.h \
    model/TreeModel.h \
    view/resultTree.h \
    view/resultTernaryTree.h \
    view/resultRBTree.h \
    view/resultBinaryTree.h

FORMS    += kalk.ui
