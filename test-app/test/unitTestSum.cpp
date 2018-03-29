#include <QString>
#include <QtTest>

#include"model/BinaryNode.h"
#include"model/BinaryRedBlackNode.h"
#include"model/TernaryNode.h"
#include"model/TreeModel.h"
#include"model/BinaryTreeModel.h"
#include"model/RedBlackTreeModel.h"
#include"model/TernaryTreeModel.h"
#include"model/Info.h"
#include"model/ExceptionHandler.h"

class TreeTest : public QObject
{
    Q_OBJECT

public:
    TreeTest();
    void printTernary(TernaryNode<int>* node = 0) const {
            if(node) {
                    qInfo()<<"value : "<<node->getInfo();
                printTernary(node->getLeft());
                printTernary(node->getRight());
            printTernary(node->getMiddle());
            }
        }
    void addLeftNode(BinaryNode<int>* node = 0) {
        if(node) {
            BinaryNode<int>* l = new BinaryNode<int>(Info<int>(222) , 0 , 0);
            node->setLeft(l);
        }
    }
    void printRBBinary(BinaryRedBlackNode<int>* node = 0) const {
            if(node) {
                    qInfo()<<"value : "<<node->getInfo();
                    qInfo()<<"color : "<<node->getColor();
                printBinary(node->getLeft());
                printBinary(node->getRight());
            }
        }
    void printBinary(BinaryNode<int>* node = 0) const {
            if(node) {
                    qInfo()<<"value : "<<node->getInfo();
                printBinary(node->getLeft());
                printBinary(node->getRight());
            }
        }
    void create(int& val , const int& height , BinaryNode<int>* node = 0) {
        if(getHeight(node) == height)
            return;
            BinaryNode<int>* l = new BinaryNode<int>(Info<int>(val) , 0 , 0);
            BinaryNode<int>* r = new BinaryNode<int>(Info<int>(val+1) , 0 , 0);
            node->setChildren(l,r);
            qInfo()<<node->getLeft()->getInfo();
            qInfo()<<node->getRight()->getInfo();
            create(++val , height , l);
            create(++val , height , r);
    }
    int getHeight(BinaryNode<int>* node = 0) {
        if(node->getParent())
            return 1 + getHeight(node->getParent());
        else
            return 1;
    }

private Q_SLOTS:
    void testCase1();
};

TreeTest::TreeTest()
{
    /*BinaryNode<int>* l = new BinaryNode<int>(Info<int>(3) , 0 , 0);
	BinaryNode<int>* l1 = new BinaryNode<int>(Info<int>(53) , 0 , 0);
	BinaryNode<int>* r = new BinaryNode<int>(Info<int>(36) , 0 , 0);
    BinaryNode<int>* r1 = new BinaryNode<int>(Info<int>(7) , 0 , 0);
	BinaryNode<int>* R = new BinaryNode<int>(Info<int>(33) , 0 , 0);
	BinaryNode<int>* R1 = new BinaryNode<int>(Info<int>(13) , 0 , 0);
	BinaryTreeModel<int>* t1 = new BinaryTreeModel<int>(R);
    BinaryTreeModel<int>* t2 = new BinaryTreeModel<int>(R1);
    R->setLeft(l);
	R->setRight(r);
	R1->setLeft(l1);
    R1->setRight(r1);
    BinaryRedBlackNode<int>* R = new BinaryRedBlackNode<int>(false , Info<int>(33) , 0 , 0);
    BinaryRedBlackNode<int>* R1 = new BinaryRedBlackNode<int>(false , Info<int>(13) , 0 , 0);
    RedBlackTreeModel<int>* t1 = new RedBlackTreeModel<int>(R);
    RedBlackTreeModel<int>* t2 = new RedBlackTreeModel<int>(R1);*/

    TernaryNode<int>* R = new TernaryNode<int>(Info<int>(33) , 0 , 0);
    TernaryNode<int>* R1 = new TernaryNode<int>(Info<int>(13) , 0 , 0);
    TernaryTreeModel<int>* t1 = new TernaryTreeModel<int>(R);
    TernaryTreeModel<int>* t2 = new TernaryTreeModel<int>(R1);

    //BinaryTreeModel<int>* tmp = t1->Sum(t2);

    //RedBlackTreeModel<int>* tmp = t1->Sum(t2);

    TernaryTreeModel<int>* tmp = t1->Sum(t2);

    //printBinary(tmp->getRoot());
    //printRBBinary(tmp->getRoot());
    printTernary(tmp->getRoot());

	delete t1;
	delete t2;
    delete tmp;
}

void TreeTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TreeTest)

#include "tst_treetest.moc"
