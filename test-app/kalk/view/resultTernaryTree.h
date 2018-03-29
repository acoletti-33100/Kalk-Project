#ifndef RESULT_TERNARY_TREE_H
#define RESULT_TERNARY_TREE_H
#include"resultTree.h"

template<typename T>
class ResultTernaryTree : public ResultTree<T> {

public:
    ResultTernaryTree(const TernaryTreeModel<T>* Model = 0 , QWidget* parent = 0);
    ResultTernaryTree();
    virtual ~ResultTernaryTree();
    void buildResultTree();

private:
    static const QString middleLabel;
    static const QString leftLabel;
    static const QString rightLabel;
    const TernaryTreeModel<T>* model;
    void buildTree();
     void buildResult(QTreeWidgetItem* node = 0 , const TernaryNode<T>* model = 0);
};

template<typename T>
const QString ResultTernaryTree<T>::leftLabel = "left";
template<typename T>
const QString ResultTernaryTree<T>::rightLabel = "right";
template<typename T>
const QString ResultTernaryTree<T>::middleLabel = "middle";

template<typename T>
ResultTernaryTree<T>::ResultTernaryTree(const TernaryTreeModel<T>* Model , QWidget* parent) :
    ResultTree<T>(parent),
    model(Model) {}

template<typename T>
ResultTernaryTree<T>::ResultTernaryTree() :
    ResultTree<T>(),
    model(0) {}

template<typename T>
void ResultTernaryTree<T>::buildResultTree() { buildTree(); }

template<typename T>
void ResultTernaryTree<T>::buildTree() {
    QTreeWidgetItem* R = ResultTree<T>::getRoot();
    const TernaryNode<T>* modelRoot = model->getRoot();
    ResultTree<T>::createRootResultNode(R , QString::number(modelRoot->getInfo()));
    buildResult(R , modelRoot);
    }

template<typename T>
void ResultTernaryTree<T>::buildResult(QTreeWidgetItem* node , const TernaryNode<T>* model) {
    if(!model)
        return;
    const TernaryNode<T>* l = model->getLeft();
    const TernaryNode<T>* r = model->getRight();
    const TernaryNode<T>* m = model->getMiddle();
    QTreeWidgetItem* nodeL = 0;
    QTreeWidgetItem* nodeR = 0;
    QTreeWidgetItem* nodeM = 0;
    if(l) {
        nodeL = ResultTree<T>::createResultNode(leftLabel , node , QString::number(l->getInfo()));
    }
    if(r) {
        nodeR = ResultTree<T>::createResultNode(rightLabel , node , QString::number(r->getInfo()));
    }
    if(m) {
        nodeM = ResultTree<T>::createResultNode(middleLabel , node , QString::number(m->getInfo()));
    }
    buildResult(nodeL , l);
    buildResult(nodeR , model->getRight());
    buildResult(nodeM , model->getMiddle());
}

template<typename T>
ResultTernaryTree<T>::~ResultTernaryTree() {}

#endif
