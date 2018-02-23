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

    BinaryNode<int>* l5 = new BinaryNode<int>(Info<int>(3) , 0 , 0);
    BinaryNode<int>* ll5 = new BinaryNode<int>(Info<int>(6) , 0 , 0);
    BinaryNode<int>* llr5 = new BinaryNode<int>(Info<int>(7) , 0 , 0);
    BinaryNode<int>* l6 = new BinaryNode<int>(Info<int>(3) , 0 , 0);
    BinaryNode<int>* r5 = new BinaryNode<int>(Info<int>(36) , 0 , 0);
    BinaryNode<int>* r6 = new BinaryNode<int>(Info<int>(7) , 0 , 0);
    BinaryNode<int>* R5 = new BinaryNode<int>(Info<int>(13) , 0 , 0);
    BinaryNode<int>* R6 = new BinaryNode<int>(Info<int>(13) , 0 , 0);
    BinaryTreeModel<int>* t5 = new BinaryTreeModel<int>(R5);
    BinaryTreeModel<int>* t6 = new BinaryTreeModel<int>(R6);

    R5->setLeft(l5);
    R5->setRight(r5);
    R6->setLeft(l6);
    R6->setRight(r6);
    l5->setLeft(ll5);
    ll5->setRight(llr5);

    TernaryNode<int>* m4 = new TernaryNode<int>(Info<int>(4) , 0 , 0 , 0);
    TernaryNode<int>* l4 = new TernaryNode<int>(Info<int>(36) , 0 , 0 , 0);
    TernaryNode<int>* ll4 = new TernaryNode<int>(Info<int>(6) , 0 , 0 , 0);
    TernaryNode<int>* llr4 = new TernaryNode<int>(Info<int>(7) , 0 , 0 , 0);
    TernaryNode<int>* r4 = new TernaryNode<int>(Info<int>(36) , 0 , 0 , 0);
    TernaryNode<int>* R4 = new TernaryNode<int>(Info<int>(33) , 0 , 0 , 0);
    TernaryNode<int>* R3 = new TernaryNode<int>(Info<int>(33) , 0 , 0 , 0);
    TernaryNode<int>* l3 = new TernaryNode<int>(Info<int>(4) , 0 , 0 , 0);
    TernaryNode<int>* r3 = new TernaryNode<int>(Info<int>(36) , 0 , 0 , 0);
    TernaryTreeModel<int>* t3 = new TernaryTreeModel<int>(R3);
    TernaryTreeModel<int>* t4 = new TernaryTreeModel<int>(R4);

    R4->setChildren(l4,r4,m4);
    R3->setLeft(l3);
    R3->setRight(r3);
    l4->setLeft(ll4);
    ll4->setRight(llr4);
    
    BinaryRedBlackNode<int>* l = new BinaryRedBlackNode<int>(true , Info<int>(6) , 0 , 0);
    BinaryRedBlackNode<int>* ll = new BinaryRedBlackNode<int>(false , Info<int>(6) , 0 , 0);
    BinaryRedBlackNode<int>* llr = new BinaryRedBlackNode<int>(false , Info<int>(7) , 0 , 0);
    BinaryRedBlackNode<int>* l1 = new BinaryRedBlackNode<int>(false , Info<int>(4) , 0 , 0);
    BinaryRedBlackNode<int>* r = new BinaryRedBlackNode<int>(false , Info<int>(36) , 0 , 0);
    BinaryRedBlackNode<int>* r1 = new BinaryRedBlackNode<int>(true , Info<int>(6) , 0 , 0);
    BinaryRedBlackNode<int>* R = new BinaryRedBlackNode<int>(false , Info<int>(123) , 0 , 0);
    BinaryRedBlackNode<int>* R1 = new BinaryRedBlackNode<int>(false , Info<int>(13) , 0 , 0);
    RedBlackTreeModel<int>* t1 = new RedBlackTreeModel<int>(R);
    RedBlackTreeModel<int>* t2 = new RedBlackTreeModel<int>(R1);

    R->setChildren(l,r);
	R1->setLeft(l1);
    R1->setRight(r1);
    l->setLeft(ll);
    ll->setRight(llr);

    try{
    //TernaryTreeModel<int>* res = t1->Intersection(t2);
    RedBlackTreeModel<int>* res = t1->Intersection(t3);
    //BinaryTreeModel<int>* res = t1->Intersection(t2);
    printRBBinary(res->getRoot());
    //printBinary(res->getRoot());
   // printTernary(res->getRoot());
    delete res;
    } catch(ExceptionHandler ecc) {qInfo()<<ecc.what();}


    delete t1;
    delete t2;

    delete t5;
    delete t6;

   delete t3;
    delete t4;


    /*
    BinaryRedBlackNode<int>* R = new BinaryRedBlackNode<int>(false , Info<int>(33) , 0 , 0);
    BinaryRedBlackNode<int>* R1 = new BinaryRedBlackNode<int>(false , Info<int>(13) , 0 , 0);
    RedBlackTreeModel<int>* t1 = new RedBlackTreeModel<int>(R);
    RedBlackTreeModel<int>* t2 = new RedBlackTreeModel<int>(R1);*/
/*
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
    delete tmp;*/
   /* BinaryRedBlackNode<int>* R = new BinaryRedBlackNode<int>(false , Info<int>(33) , 0 , 0);
    BinaryRedBlackNode<int>* l = new BinaryRedBlackNode<int>(false , Info<int>(1) , 0 , 0);
    BinaryRedBlackNode<int>* r = new BinaryRedBlackNode<int>(false , Info<int>(2) , 0 , 0);
    R->setChildren(l,r);
    TreeModel<int>* t = new RedBlackTreeModel<int>(R);

    qInfo()<<"vsdvSUm values: "<<t->SumValues();
    delete t;*/
}

void TreeTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TreeTest)

#include "tst_treetest.moc"
