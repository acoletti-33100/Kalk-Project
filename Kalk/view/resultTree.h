#ifndef RESULT_TREE_H
#define RESULT_TREE_H
#include"../model/TreeModel.h"
#include"../model/TernaryTreeModel.h"
#include"../model/BinaryTreeModel.h"
#include"../model/RedBlackTreeModel.h"
#include <QScrollArea>
#include<QTreeWidget>
#include<QTreeWidgetItem>

template<typename T>
class ResultTree : public QScrollArea {

public:
    explicit ResultTree(QWidget* parent = 0);
    ResultTree();
    virtual ~ResultTree() = 0;
    virtual void buildResultTree() = 0;

protected:
        virtual void createResultSingleNode(const QString& nodeLabel = "" ,
                                    QTreeWidgetItem* parent = 0);
     virtual QTreeWidgetItem* createResultNode(const QString& nodeLabel = "" ,
                                                   QTreeWidgetItem* parent = 0 ,
                                 const QString& nodeInfo = "");
     QTreeWidgetItem* getRoot() const;
     void createRootResultNode(QTreeWidgetItem* parent = 0 , const QString& nodeInfo = "");
private:
    static const QString rootLabel;
    static const QString resultValueLabel;
    QTreeWidget* treeWidget;
    QTreeWidgetItem* root;
};

template<typename T>
const QString ResultTree<T>::rootLabel = "root";
template<typename T>
const QString ResultTree<T>::resultValueLabel = "value : ";

template<typename T>
ResultTree<T>::ResultTree(QWidget* parent) :
    QScrollArea(parent) {
    setMinimumSize(parent->width() , parent->height());
    treeWidget = new QTreeWidget(this);
    treeWidget->setMinimumSize(width() , height());
    treeWidget->setSortingEnabled(false);
    root = new QTreeWidgetItem(treeWidget);
    root->setText(0 , rootLabel);
    root = treeWidget->topLevelItem(0);
    treeWidget->setHeaderLabel("Result");
}

template<typename T>
ResultTree<T>::ResultTree() :
    QScrollArea(0) , treeWidget(0) , root(0) {}

template<typename T>
QTreeWidgetItem* ResultTree<T>::getRoot() const { return root; }

template<typename T>
void ResultTree<T>::createResultSingleNode(const QString& nodeLabel ,
                                            QTreeWidgetItem* parent) {
    QTreeWidgetItem* node = new QTreeWidgetItem(parent);
    node->setText(0 , nodeLabel);
}

/*creates the real node such as : "left" , "right" , "middle".
It also creates the node's value(eg: "value : 10").*/
template<typename T>
QTreeWidgetItem* ResultTree<T>::createResultNode(const QString& nodeLabel ,
                                                  QTreeWidgetItem* parent ,
                    const QString& nodeInfo) {
    QTreeWidgetItem* node = new QTreeWidgetItem(parent);
    QTreeWidgetItem* nodeValue = new QTreeWidgetItem(node);
    nodeValue->setText(0 , resultValueLabel + nodeInfo);
    node->setText(0 , nodeLabel);
    node->insertChild(0 , nodeValue);
    return node;
}

template<typename T>
void ResultTree<T>::createRootResultNode(QTreeWidgetItem* parent , const QString& nodeInfo) {
    QTreeWidgetItem* node = new QTreeWidgetItem(parent);
    node->setText(0 , resultValueLabel + nodeInfo);
}

template<typename T>
ResultTree<T>::~ResultTree() {}

#endif
