#include "kalk.h"
#include "ui_kalk.h"
#include<QDebug>

Kalk::Kalk(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kalk),
    area(0),
    tree(0),
    validator(new QIntValidator(0,1000,this)),
    button(new QPushButton(0))
{
    ui->setupUi(this);
    result = 0;
    button->setText("premi");
    button->setObjectName("PushButton");
    QObject::connect(button , SIGNAL(clicked()) , this , SLOT(quit()));
    button->setMinimumHeight(30);
    button->setMinimumWidth(60);
    button->show();
   //validator = new QIntValidator(0,1000,this);
   //tree = 0;
   //area = new CreateBinaryTreeArea(validator , "prova" , 4 , this);
   //area = new CreateTernaryTreeArea(validator , "prova" , 6 , this);
   //area = new CreateRBTreeArea(validator , "prova" , 2 , this);

   /* 
   BinaryNode<int>* r = new BinaryNode<int>(Info<int>(11) , 0 , 0);
   tree = new BinaryTreeModel<int>(r);
   BinaryTreeModel<int>* aux = dynamic_cast<BinaryTreeModel<int>*>(tree);
   area->buildTree(aux);
*/

   BinaryRedBlackNode<int>* R = new BinaryRedBlackNode<int>(false , Info<int>(11) , 0 , 0);
   BinaryRedBlackNode<int>* l = new BinaryRedBlackNode<int>(false , Info<int>(16) , 0 , 0);
   BinaryRedBlackNode<int>* ll = new BinaryRedBlackNode<int>(false , Info<int>(76) , 0 , 0);
   BinaryRedBlackNode<int>* lll = new BinaryRedBlackNode<int>(false , Info<int>(81) , 0 , 0);
   BinaryRedBlackNode<int>* r = new BinaryRedBlackNode<int>(false , Info<int>(51) , 0 , 0);
   BinaryRedBlackNode<int>* rr = new BinaryRedBlackNode<int>(false , Info<int>(41) , 0 , 0);
   R->setChildren(l,r);
   r->setRight(rr);
   l->setLeft(ll);
   ll->setLeft(lll);
   tree = new RedBlackTreeModel<int>(R);
   RedBlackTreeModel<int>* aux = dynamic_cast<RedBlackTreeModel<int>*>(tree);
   area = new CreateRBTreeArea(validator , "asd" , 3 , ui->parent1);
   result = new ResultRBTree<int>(aux , ui->parent2);
   result->buildResultTree();


 /*
   TernaryNode<int>* R = new TernaryNode<int>(Info<int>(1) , 0 , 0 , 0);
   TernaryNode<int>* l = new TernaryNode<int>(Info<int>(41) , 0 , 0 , 0);
   TernaryNode<int>* r = new TernaryNode<int>(Info<int>(2) , 0 , 0 , 0);
   TernaryNode<int>* m = new TernaryNode<int>(Info<int>(3) , 0 , 0 , 0);
   TernaryNode<int>* ml = new TernaryNode<int>(Info<int>(51) , 0 , 0 , 0);
   TernaryNode<int>* rm = new TernaryNode<int>(Info<int>(71) , 0 , 0 , 0);
   TernaryNode<int>* ll = new TernaryNode<int>(Info<int>(28) , 0 , 0 , 0);
   TernaryNode<int>* mr = new TernaryNode<int>(Info<int>(99) , 0 , 0 , 0);
   TernaryNode<int>* lr = new TernaryNode<int>(Info<int>(68) , 0 , 0 , 0);
   R->setChildren(l,r,m);
   m->setLeft(ml);
   r->setMiddle(rm);
   l->setLeft(ll);
   m->setRight(mr);
   l->setRight(lr);
   tree = new TernaryTreeModel<int>(R);
   TernaryTreeModel<int>* aux = dynamic_cast<TernaryTreeModel<int>*>(tree);
   area->buildTree(aux);*/


   /*BinaryNode<int>* R = new BinaryNode<int>(Info<int>(1) , 0 , 0);
   BinaryNode<int>* l = new BinaryNode<int>(Info<int>(21) , 0 , 0);
   BinaryNode<int>* r = new BinaryNode<int>(Info<int>(13) , 0 , 0);
   BinaryNode<int>* ll = new BinaryNode<int>(Info<int>(41) , 0 , 0);
   BinaryNode<int>* rr = new BinaryNode<int>(Info<int>(55) , 0 , 0);
   BinaryNode<int>* rl = new BinaryNode<int>(Info<int>(38) , 0 , 0);
   R->setLeft(l);
   R->setRight(r);
   l->setLeft(ll);
   r->setLeft(rl);
   r->setRight(rr);
   tree = new BinaryTreeModel<int>(R);
   BinaryTreeModel<int>* aux = dynamic_cast<BinaryTreeModel<int>*>(tree);
   result = new ResultBinaryTree<int>(aux , this);
   result->buildResultTree();*/

}

void Kalk::quit() {
    qInfo()<<"quit()";
    const QVector<const QLineEdit*> lineTmp = area->getLineEditList();
    for(int i = 0 , dim = lineTmp.size(); i < dim ; i++){
        qInfo()<<lineTmp[i]->text();
    }
}

Kalk::~Kalk()
{
	delete validator;
    delete tree;
    delete area;
    delete button;
    delete ui;
}
