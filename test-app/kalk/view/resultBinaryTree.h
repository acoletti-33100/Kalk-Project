#ifndef RESULT_BINARY_TREE_H
#define RESULT_BINARY_TREE_H
#include"resultTree.h"

template<typename T>
class ResultBinaryTree : public ResultTree<T> {

public:
    ResultBinaryTree(const BinaryTreeModel<T>* Model = 0 , QWidget* parent = 0);
    ResultBinaryTree();
    virtual ~ResultBinaryTree();
    void buildResultTree();

private:
    static const QString leftLabel;
    static const QString rightLabel;
    const BinaryTreeModel<T>* model;
    void buildTree();
     void buildResult(QTreeWidgetItem* node = 0 , const BinaryNode<T>* model = 0);
};

template<typename T>
const QString ResultBinaryTree<T>::leftLabel = "left";
template<typename T>
const QString ResultBinaryTree<T>::rightLabel = "right";

template<typename T>
ResultBinaryTree<T>::ResultBinaryTree(const BinaryTreeModel<T>* Model , QWidget* parent) :
    ResultTree<T>(parent),
    model(Model) {}

template<typename T>
ResultBinaryTree<T>::ResultBinaryTree() :
    ResultTree<T>() , model(0) {}

template<typename T>
void ResultBinaryTree<T>::buildResultTree() { buildTree(); }

template<typename T>
void ResultBinaryTree<T>::buildTree() {
    QTreeWidgetItem* R = ResultTree<T>::getRoot();
    const BinaryNode<T>* modelRoot = model->getRoot();
    ResultTree<T>::createRootResultNode(R , QString::number(modelRoot->getInfo()));
    buildResult(R , modelRoot);
    }

template<typename T>
void ResultBinaryTree<T>::buildResult(QTreeWidgetItem* node , const BinaryNode<T>* model) {
    if(!model)
        return;
    const BinaryNode<T>* l = model->getLeft();
    const BinaryNode<T>* r = model->getRight();
    QTreeWidgetItem* nodeL = 0;
    QTreeWidgetItem* nodeR = 0;
    if(l) {
        nodeL = ResultTree<T>::createResultNode(leftLabel , node , QString::number(l->getInfo()));
    }
    if(r) {
        nodeR = ResultTree<T>::createResultNode(rightLabel , node , QString::number(r->getInfo()));
    }
    buildResult(nodeL , l);
    buildResult(nodeR , model->getRight());
}

template<typename T>
ResultBinaryTree<T>::~ResultBinaryTree() {}

#endif
