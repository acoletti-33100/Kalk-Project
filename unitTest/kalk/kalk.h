#ifndef KALK_H
#define KALK_H

#include <QMainWindow>
#include"view/createTreeArea.h"
#include"view/createBinaryTreeArea.h"
#include"view/createRBTreeArea.h"
#include"view/createTernaryTreeArea.h"
#include"view/resultTree.h"
#include"view/resultTernaryTree.h"
#include"view/resultBinaryTree.h"
#include"view/resultRBTree.h"
#include"model/BinaryNode.h"
#include"model/BinaryRedBlackNode.h"
#include"model/TernaryNode.h"
#include"model/TreeModel.h"
#include"model/BinaryTreeModel.h"
#include"model/RedBlackTreeModel.h"
#include<QValidator>
#include<QIntValidator>

#include<QPushButton>//debug

namespace Ui {
class Kalk;
}

class Kalk : public QMainWindow
{
    Q_OBJECT

public:
    explicit Kalk(QWidget *parent = 0);
    ~Kalk();

private slots:

    void quit();

private:
    Ui::Kalk *ui;
    CreateTreeArea* area;
    ResultTree<int>* result;
    TreeModel<int>* tree;
    QValidator* validator;
    QPushButton* button;

};

#endif // KALK_H
