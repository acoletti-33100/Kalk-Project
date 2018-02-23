#-------------------------------------------------
#
# Project created by QtCreator 2017-12-10T14:40:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kalk
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    model/ExceptionHandler.cpp \
    view/createBinaryTreeArea.cpp \
    view/createRBTreeArea.cpp \
    view/createTernaryTreeArea.cpp \
    view/createTreeArea.cpp

HEADERS  += mainwindow.h \
    model/ExceptionHandler.h \
    model/TreeModel.h \
    model/BinaryNode.h \
    model/RedBlackTreeModel.h \
    model/Info.h \
    model/BinaryTreeModel.h \
    model/BinaryRedBlackNode.h \
    model/TernaryTreeModel.h \
    model/TernaryNode.h \
    Controller.h \
    registers/Sum.h \
    registers/Intersection.h \
    registers/Operation.h \
    view/createBinaryTreeArea.h \
    view/createRBTreeArea.h \
    view/createTernaryTreeArea.h \
    view/createTreeArea.h \
    view/resultBinaryTree.h \
    view/resultRBTree.h \
    view/resultTernaryTree.h \
    view/resultTree.h

FORMS    += mainwindow.ui
