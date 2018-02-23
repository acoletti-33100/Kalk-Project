#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"view/createTreeArea.h"
#include"view/createTernaryTreeArea.h"
#include"view/createBinaryTreeArea.h"
#include"view/createRBTreeArea.h"
#include"model/ExceptionHandler.h"
#include"Controller.h"
#include<QCloseEvent>
#include<QMessageBox>
#include <QMainWindow>
#include<QSignalMapper>
#include<QValidator>
#include<QIntValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void closeEvent (QCloseEvent *event);
    ~MainWindow();

private slots:
    void on_executeButton_clicked();
    void on_SumButton_clicked();
    void on_BlackHeightButton_clicked();
    void on_SumValuesButton_clicked();
    void on_UndoOperationButton_clicked();
    void on_ClearAllOperationButton_clicked();
    void on_createRBBinaryTree_clicked();
    void on_createBinaryTree_clicked();
    void keyPressed(int);
    void createOperand(int);
    void on_createTernaryTree_clicked();
    void on_SumMiddleButton_clicked();
    void on_UndoTreeButton_clicked();
    void on_clearAllTreesButton_clicked();
    void on_IntersectionButton_clicked();
    void on_SumRedNodesButton_clicked();
    void on_SumBlackNodesButton_clicked();

    void on_BinaryRotationButton_clicked();

private:
    Ui::MainWindow *ui;
    QValidator* validator;
    Controller<int>* controller;
    QVector<CreateTreeArea*> treeList;
    QLabel* labelResult;
    static const int MAX_TREES_NUMBER = 5;
    static int CURR_TREES_NUMBER;
    static int CURR_TREE_INDEX;
    QVector<bool> expressionRegister;
    QVector<QString> expressionTextRegister;
    QString textExpressionArea;
    QSignalMapper* signalMapper;
    QSignalMapper* signalMapperOperand;
    QVector<QPushButton*> treeSelector;
    QVector<QPushButton*> treeOperandSelector;
    bool isWellFormed() const;
    void evaluate() const throw(ExceptionHandler);
    void updateOnUndoExpressionArea();
    void clearAllRegisters();
    void updateOnTreeCreation();
    void createTreeSelectorButton();
    void clearAllTreeSelectorButtons();
    void clearTreeSelectorButton();
    void addOperand(const int&);
    void hideTree(const int&);
    QPushButton* createSignaledButton(QSignalMapper& signalMap , QVector<QPushButton*>& list);
    void updateExpressionRegisters(const bool& , const QString&);
};


#endif
