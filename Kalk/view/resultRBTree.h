#ifndef RESULT_RB_TREE_H
#define RESULT_RB_TREE_H

#include"resultBinaryTree.h"

template<typename T>
class ResultRBTree : public ResultTree<T> {

public:
    ResultRBTree(const RedBlackTreeModel<T>* Model = 0 , QWidget* parent = 0);
    ResultRBTree();
    virtual ~ResultRBTree();
    void buildResultTree();

private:
    static const QString colorBlack;
    static const QString color;
    static const QString leftLabel;
    static const QString rightLabel;
    const RedBlackTreeModel<T>* model;
    void buildTree();
     void buildResult(QTreeWidgetItem* node = 0 , const BinaryRedBlackNode<T>* model = 0);
};

template<typename T>
const QString ResultRBTree<T>::colorBlack = "color : Black";
template<typename T>
const QString ResultRBTree<T>::color = "color : ";
template<typename T>
const QString ResultRBTree<T>::leftLabel = "left";
template<typename T>
const QString ResultRBTree<T>::rightLabel = "right";

template<typename T>
ResultRBTree<T>::ResultRBTree(const RedBlackTreeModel<T>* Model , QWidget* parent) :
    ResultTree<T>(parent),
    model(Model) {}

template<typename T>
ResultRBTree<T>::ResultRBTree() :
    ResultTree<T>(),
    model(0) {}

template<typename T>
void ResultRBTree<T>::buildResultTree() { buildTree(); }

template<typename T>
void ResultRBTree<T>::buildTree() {
    QTreeWidgetItem* R = ResultTree<T>::getRoot();
    const BinaryRedBlackNode<T>* modelRoot = model->getRoot();
    ResultTree<T>::createRootResultNode(R , QString::number(modelRoot->getInfo()));
    ResultTree<T>::createResultSingleNode(colorBlack , R);
    buildResult(R , modelRoot);
    }

template<typename T>
void ResultRBTree<T>::buildResult(QTreeWidgetItem* node , const BinaryRedBlackNode<T>* model) {
    if(!model)
        return;
    const BinaryRedBlackNode<T>* l = model->getLeft();
    const BinaryRedBlackNode<T>* r = model->getRight();
    QTreeWidgetItem* nodeL = 0;
    QTreeWidgetItem* nodeR = 0;
    if(l) {
        nodeL = ResultTree<T>::createResultNode(leftLabel , node , QString::number(l->getInfo()));
        ResultTree<T>::createResultSingleNode(color + l->getColor() , nodeL);
    }
    if(r) {
        nodeR = ResultTree<T>::createResultNode(rightLabel , node , QString::number(r->getInfo()));
        ResultTree<T>::createResultSingleNode(color + r->getColor() , nodeR);
    }
    buildResult(nodeL , l);
    buildResult(nodeR , model->getRight());
}

template<typename T>
ResultRBTree<T>::~ResultRBTree() {}

#endif
