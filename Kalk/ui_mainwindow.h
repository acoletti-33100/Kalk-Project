/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QScrollArea *scrollCreateTreeArea;
    QWidget *scrollContentCreateTreeArea;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *expressionArea;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *errorArea;
    QWidget *layoutWidget2;
    QVBoxLayout *operationsBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *UndoTreeButton;
    QSpinBox *delTreeSpinBox;
    QPushButton *clearAllTreesButton;
    QPushButton *UndoOperationButton;
    QPushButton *ClearAllOperationButton;
    QPushButton *executeButton;
    QPushButton *SumMiddleButton;
    QPushButton *SumValuesButton;
    QPushButton *BlackHeightButton;
    QPushButton *SumRedNodesButton;
    QPushButton *SumBlackNodesButton;
    QPushButton *BinaryRotationButton;
    QPushButton *IntersectionButton;
    QPushButton *SumButton;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *createBinaryTree;
    QPushButton *createRBBinaryTree;
    QPushButton *createTernaryTree;
    QLabel *label_2;
    QSpinBox *TreeHeightBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *treeSelectorArea;
    QScrollArea *ResultArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *treeSelectOp;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *ResultExpression;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 749);
        MainWindow->setStyleSheet(QLatin1String("QPushButton{\n"
"	border: 2px solid black;\n"
"	color:black;\n"
"}\n"
"QPushButton:hover{\n"
"	background:yellow;\n"
"}\n"
"QPushButton:pressed{\n"
"	border: 2px solid red;\n"
"	background:blue;\n"
"	color:white;\n"
"}\n"
"QLabel {\n"
"	color:black;\n"
"}\n"
"QSpinBox{\n"
"	border: 2px solid black;\n"
" 	color: black; \n"
"}\n"
"QSpinBox:hover{\n"
"	border: 2px solid black;\n"
" 	background:yellow;\n"
"}\n"
"QSpinBox:focus{\n"
"	border: 2px solid red;\n"
"	background: yellow;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        scrollCreateTreeArea = new QScrollArea(centralWidget);
        scrollCreateTreeArea->setObjectName(QStringLiteral("scrollCreateTreeArea"));
        scrollCreateTreeArea->setGeometry(QRect(130, 70, 341, 251));
        scrollCreateTreeArea->setStyleSheet(QStringLiteral(""));
        scrollCreateTreeArea->setWidgetResizable(true);
        scrollCreateTreeArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollContentCreateTreeArea = new QWidget();
        scrollContentCreateTreeArea->setObjectName(QStringLiteral("scrollContentCreateTreeArea"));
        scrollContentCreateTreeArea->setGeometry(QRect(0, 0, 339, 249));
        scrollCreateTreeArea->setWidget(scrollContentCreateTreeArea);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 330, 111, 31));
        label_3->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 601, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(131, 29));

        horizontalLayout->addWidget(label_5);

        expressionArea = new QLabel(layoutWidget);
        expressionArea->setObjectName(QStringLiteral("expressionArea"));
        expressionArea->setStyleSheet(QLatin1String("border: 2px solid green;\n"
""));
        expressionArea->setTextFormat(Qt::AutoText);

        horizontalLayout->addWidget(expressionArea);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 461, 23));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(100, 29));

        horizontalLayout_4->addWidget(label_4);

        errorArea = new QLabel(layoutWidget1);
        errorArea->setObjectName(QStringLiteral("errorArea"));
        errorArea->setStyleSheet(QLatin1String("border: 2px solid orange;\n"
"color: red;"));
        errorArea->setTextFormat(Qt::AutoText);

        horizontalLayout_4->addWidget(errorArea);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(480, 30, 155, 341));
        operationsBox = new QVBoxLayout(layoutWidget2);
        operationsBox->setSpacing(6);
        operationsBox->setContentsMargins(11, 11, 11, 11);
        operationsBox->setObjectName(QStringLiteral("operationsBox"));
        operationsBox->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        UndoTreeButton = new QPushButton(layoutWidget2);
        UndoTreeButton->setObjectName(QStringLiteral("UndoTreeButton"));

        horizontalLayout_2->addWidget(UndoTreeButton);

        delTreeSpinBox = new QSpinBox(layoutWidget2);
        delTreeSpinBox->setObjectName(QStringLiteral("delTreeSpinBox"));
        delTreeSpinBox->setMinimum(0);

        horizontalLayout_2->addWidget(delTreeSpinBox);


        operationsBox->addLayout(horizontalLayout_2);

        clearAllTreesButton = new QPushButton(layoutWidget2);
        clearAllTreesButton->setObjectName(QStringLiteral("clearAllTreesButton"));

        operationsBox->addWidget(clearAllTreesButton);

        UndoOperationButton = new QPushButton(layoutWidget2);
        UndoOperationButton->setObjectName(QStringLiteral("UndoOperationButton"));
        UndoOperationButton->setMinimumSize(QSize(16, 16));

        operationsBox->addWidget(UndoOperationButton);

        ClearAllOperationButton = new QPushButton(layoutWidget2);
        ClearAllOperationButton->setObjectName(QStringLiteral("ClearAllOperationButton"));

        operationsBox->addWidget(ClearAllOperationButton);

        executeButton = new QPushButton(layoutWidget2);
        executeButton->setObjectName(QStringLiteral("executeButton"));
        executeButton->setMinimumSize(QSize(16, 16));

        operationsBox->addWidget(executeButton);

        SumMiddleButton = new QPushButton(layoutWidget2);
        SumMiddleButton->setObjectName(QStringLiteral("SumMiddleButton"));

        operationsBox->addWidget(SumMiddleButton);

        SumValuesButton = new QPushButton(layoutWidget2);
        SumValuesButton->setObjectName(QStringLiteral("SumValuesButton"));

        operationsBox->addWidget(SumValuesButton);

        BlackHeightButton = new QPushButton(layoutWidget2);
        BlackHeightButton->setObjectName(QStringLiteral("BlackHeightButton"));

        operationsBox->addWidget(BlackHeightButton);

        SumRedNodesButton = new QPushButton(layoutWidget2);
        SumRedNodesButton->setObjectName(QStringLiteral("SumRedNodesButton"));

        operationsBox->addWidget(SumRedNodesButton);

        SumBlackNodesButton = new QPushButton(layoutWidget2);
        SumBlackNodesButton->setObjectName(QStringLiteral("SumBlackNodesButton"));

        operationsBox->addWidget(SumBlackNodesButton);

        BinaryRotationButton = new QPushButton(layoutWidget2);
        BinaryRotationButton->setObjectName(QStringLiteral("BinaryRotationButton"));

        operationsBox->addWidget(BinaryRotationButton);

        IntersectionButton = new QPushButton(layoutWidget2);
        IntersectionButton->setObjectName(QStringLiteral("IntersectionButton"));

        operationsBox->addWidget(IntersectionButton);

        SumButton = new QPushButton(layoutWidget2);
        SumButton->setObjectName(QStringLiteral("SumButton"));

        operationsBox->addWidget(SumButton);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 70, 111, 167));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"	color:black;\n"
"}"));

        verticalLayout->addWidget(label);

        createBinaryTree = new QPushButton(layoutWidget3);
        createBinaryTree->setObjectName(QStringLiteral("createBinaryTree"));

        verticalLayout->addWidget(createBinaryTree);

        createRBBinaryTree = new QPushButton(layoutWidget3);
        createRBBinaryTree->setObjectName(QStringLiteral("createRBBinaryTree"));

        verticalLayout->addWidget(createRBBinaryTree);

        createTernaryTree = new QPushButton(layoutWidget3);
        createTernaryTree->setObjectName(QStringLiteral("createTernaryTree"));
        createTernaryTree->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(createTernaryTree);

        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"	color:black;\n"
"}"));

        verticalLayout->addWidget(label_2);

        TreeHeightBox = new QSpinBox(layoutWidget3);
        TreeHeightBox->setObjectName(QStringLiteral("TreeHeightBox"));
        TreeHeightBox->setMinimum(1);
        TreeHeightBox->setMaximum(4);

        verticalLayout->addWidget(TreeHeightBox);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 350, 111, 271));
        treeSelectorArea = new QVBoxLayout(verticalLayoutWidget);
        treeSelectorArea->setSpacing(6);
        treeSelectorArea->setContentsMargins(11, 11, 11, 11);
        treeSelectorArea->setObjectName(QStringLiteral("treeSelectorArea"));
        treeSelectorArea->setContentsMargins(0, 0, 0, 0);
        ResultArea = new QScrollArea(centralWidget);
        ResultArea->setObjectName(QStringLiteral("ResultArea"));
        ResultArea->setGeometry(QRect(130, 370, 341, 251));
        ResultArea->setStyleSheet(QStringLiteral(""));
        ResultArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 339, 249));
        ResultArea->setWidget(scrollAreaWidgetContents);
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(500, 410, 111, 271));
        treeSelectOp = new QVBoxLayout(verticalLayoutWidget_2);
        treeSelectOp->setSpacing(6);
        treeSelectOp->setContentsMargins(11, 11, 11, 11);
        treeSelectOp->setObjectName(QStringLiteral("treeSelectOp"));
        treeSelectOp->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 316, 111, 21));
        label_6->setStyleSheet(QStringLiteral(""));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(500, 380, 111, 21));
        label_7->setStyleSheet(QStringLiteral(""));
        ResultExpression = new QLabel(centralWidget);
        ResultExpression->setObjectName(QStringLiteral("ResultExpression"));
        ResultExpression->setGeometry(QRect(70, 640, 411, 20));
        MainWindow->setCentralWidget(centralWidget);
        label_3->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        verticalLayoutWidget->raise();
        ResultArea->raise();
        verticalLayoutWidget_2->raise();
        label_6->raise();
        label_7->raise();
        ResultExpression->raise();
        scrollCreateTreeArea->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Kalk", 0));
        label_3->setText(QApplication::translate("MainWindow", "Result Display : ", 0));
        label_5->setText(QApplication::translate("MainWindow", "Track operation : ", 0));
        expressionArea->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Messages : ", 0));
        errorArea->setText(QString());
#ifndef QT_NO_TOOLTIP
        UndoTreeButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>undo tree with chosen index</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        UndoTreeButton->setText(QApplication::translate("MainWindow", "Undo Tree", 0));
#ifndef QT_NO_TOOLTIP
        delTreeSpinBox->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>choose tree's index to delete</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        clearAllTreesButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Clear all trees</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        clearAllTreesButton->setText(QApplication::translate("MainWindow", "Clear All Trees", 0));
#ifndef QT_NO_TOOLTIP
        UndoOperationButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Undo last operation</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        UndoOperationButton->setText(QApplication::translate("MainWindow", "Undo Operation", 0));
#ifndef QT_NO_TOOLTIP
        ClearAllOperationButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Clear all shown operations</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        ClearAllOperationButton->setText(QApplication::translate("MainWindow", "Clear All Operations", 0));
#ifndef QT_NO_TOOLTIP
        executeButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Calculate Result</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        executeButton->setText(QApplication::translate("MainWindow", "=", 0));
#ifndef QT_NO_TOOLTIP
        SumMiddleButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>TernaryTrees-Only</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        SumMiddleButton->setText(QApplication::translate("MainWindow", "SumMiddle", 0));
#ifndef QT_NO_TOOLTIP
        SumValuesButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Sum nodes values</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        SumValuesButton->setText(QApplication::translate("MainWindow", "SumValues", 0));
#ifndef QT_NO_TOOLTIP
        BlackHeightButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>RedBlackTrees-Only</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        BlackHeightButton->setText(QApplication::translate("MainWindow", "BlackHeight", 0));
        SumRedNodesButton->setText(QApplication::translate("MainWindow", "SumRedNodes", 0));
        SumBlackNodesButton->setText(QApplication::translate("MainWindow", "SumBlackNodes", 0));
        BinaryRotationButton->setText(QApplication::translate("MainWindow", "BinaryRotation", 0));
#ifndef QT_NO_TOOLTIP
        IntersectionButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Intersect Trees</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        IntersectionButton->setText(QApplication::translate("MainWindow", "Intersection", 0));
#ifndef QT_NO_TOOLTIP
        SumButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Sum Trees</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        SumButton->setText(QApplication::translate("MainWindow", "Sum", 0));
        label->setText(QApplication::translate("MainWindow", "Create Tree :", 0));
#ifndef QT_NO_TOOLTIP
        createBinaryTree->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>create Binary Tree</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        createBinaryTree->setText(QApplication::translate("MainWindow", "Binary", 0));
#ifndef QT_NO_TOOLTIP
        createRBBinaryTree->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>create Binary-RB Tree</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        createRBBinaryTree->setText(QApplication::translate("MainWindow", "BInary-RB", 0));
#ifndef QT_NO_TOOLTIP
        createTernaryTree->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>create Ternary Tree</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        createTernaryTree->setText(QApplication::translate("MainWindow", "Ternary", 0));
        label_2->setText(QApplication::translate("MainWindow", "Set Height : ", 0));
#ifndef QT_NO_TOOLTIP
        TreeHeightBox->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Set Tree Height</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("MainWindow", "Shown Tree :", 0));
        label_7->setText(QApplication::translate("MainWindow", "Select Operand : ", 0));
        ResultExpression->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
