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
                printRBBinary(node->getLeft());
                printRBBinary(node->getRight());
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
	BinaryNode<int>* l = new BinaryNode<int>(Info<int>(3) , 0 , 0);
	BinaryNode<int>* l1 = new BinaryNode<int>(Info<int>(53) , 0 , 0);
	BinaryNode<int>* r = new BinaryNode<int>(Info<int>(36) , 0 , 0);
	BinaryNode<int>* r1 = new BinaryNode<int>(Info<int>(7) , 0 , 0);
	BinaryNode<int>* R = new BinaryNode<int>(Info<int>(33) , 0 , 0);
	BinaryNode<int>* R1 = new BinaryNode<int>(Info<int>(13) , 0 , 0);
	BinaryTreeModel<int>* t1 = new BinaryTreeModel<int>(R);
	BinaryTreeModel<int>* t2 = new BinaryTreeModel<int>(R2);
	R->setLeft(l);
	R->setRight(r);
	R1->setLeft(l1);
	R1->setRight(r1);

	delete t1;
	delete t2;
}

void TreeTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TreeTest)

#include "tst_treetest.moc"
