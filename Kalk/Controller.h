#ifndef CONTROLLER_H
#define CONTROLLER_H

#include"registers/Operation.h"
#include"registers/Sum.h"
#include"registers/Intersection.h"
#include"model/TreeModel.h"
#include"model/TernaryTreeModel.h"
#include"model/BinaryTreeModel.h"
#include"model/RedBlackTreeModel.h"
#include"model/BinaryNode.h"
#include"model/BinaryRedBlackNode.h"
#include"model/TernaryNode.h"
#include"model/Info.h"
#include"view/createTreeArea.h"
#include"view/createBinaryTreeArea.h"
#include"view/createRBTreeArea.h"
#include"view/createTernaryTreeArea.h"
#include"view/resultTree.h"
#include"view/resultBinaryTree.h"
#include"view/resultTernaryTree.h"
#include"view/resultRBTree.h"
#include<QLineEdit>
#include<QComboBox>

template<typename T>
class Controller {
	private:
        static const int MAX_TREES_NUMBER = 5;
		QVector<TreeModel<T>*> modelReg;
        QVector<Operation<T>*> operationReg;
	QVector<int> indexReg;
    ResultTree<T>* viewResult;
    QWidget* resultTreeParent;
    TreeModel<T>* result;
 	void showResult(TreeModel<T>* result = 0);
	void fillIndexReg(const QVector<QString>); 
 	void buildBT(const int& , BinaryNode<T>* node = 0);
        void buildRBT(const QVector<const QComboBox*> , const int& ,
                      int& , const int& , BinaryRedBlackNode<T>* node = 0);
        void buildTT(const int& , TernaryNode<T>* node = 0);
        QVector<int> getUserIntInput(const QVector<const QLineEdit*>) const;
	QVector<bool> getUserColorInput(const QVector<const QComboBox*>) const;
    void closeViewResult();

	public:
		explicit Controller(QWidget* resultParent = 0);
    void closeResultView();
		~Controller();
		void Calculate(const QVector<QString>);
		void addBinaryTree(const int&);
        void addRedBlackTree(const QVector<const QComboBox*> , const int&);
		void addTernaryTree(const int&);
		void removeAllTrees();
		void removeTree(const int&);
		void addSumOperation();
		void addIntersectionOperation();
        T SumMiddle(const int&) throw(ExceptionHandler);
        T SumValues(const int&);
        int BlackHeight(const int&) throw(ExceptionHandler);
        T SumBlackNodes(const int&) throw(ExceptionHandler);
        T SumRedNodes(const int&) throw(ExceptionHandler);
        void BinaryRotation(const int& index) throw(ExceptionHandler);
		void undoOperand();
		void undoOperation();
		void removeAllOperands();
		void removeAllOperations();
	void updateValuesOnExecute(const int& index , QVector<CreateTreeArea*> list);
	void updateValuesOnExecute(QVector<QString> expressionTextRegister ,
                                   QVector<CreateTreeArea*> list);
    };

template<typename T>
Controller<T>::Controller(QWidget* resultParent) :
    viewResult(0),
    resultTreeParent(resultParent),
    result(0) {}

/*
 * Pre = ( registers must be well formed and in order , there are at least 3 elements inside expressionTextRegister )
 * create result model , then display it.
 * eg: 1 + 2 + 3 = (1 + 2) + 3
 * eg : 1 I 2 + 4 I 3 = ((1 I 2) + 4) I 3
 *
 * indexReg holds the indexes of the models to operate on. It's necessary because modelReg holds
 * the unique models so in case of operations such as " 1 + 1 + 2 I 2 "
 * there would be the following situation :
 * 	indexReg	modelReg	operationReg
 * 	   1		   1                +
 * 	   1		   2	            +
 * 	   2                                I
 * 	   2
 * indexReg[i] 0 <= i <= 3 , modelReg[j] 0 <= j <= 1 , operationReg[k] 0 <= k <= 2
 * calculation is performed : operationReg[k]->execute( modelReg[indexReg[i]] , modelReg[indexReg[i+1]] )
 *
 * */
template<typename T>
void Controller<T>::Calculate(const QVector<QString> reg) {
    fillIndexReg(reg);
    TreeModel<T>* aux = result;
    int k = 0 , dimK = operationReg.size() , i = 0 , dimI = indexReg.size();
    result = operationReg[k]->execute(modelReg[indexReg[i]] , modelReg[indexReg[i+1]]);
    delete aux;
    k++;
    i += 2;
    for(; k < dimK && i < dimI; k++ , i++) {
        aux = result;
        result = operationReg[k]->execute(result , modelReg[indexReg[i]]);
        delete aux;
    }
   showResult(result);
   indexReg.clear();
}

/* fills indexReg with the operands indexes from MainWindow::expressionTextRegister*/
template<typename T>
void Controller<T>::fillIndexReg(const QVector<QString> reg) {
	for(int i = 0 , dim = reg.size() ; i < dim; i+= 2) 
        indexReg.append(reg[i].toInt() - 1);
}

template<typename T>
void Controller<T>::showResult(TreeModel<T>* result) {
     closeViewResult();
      RedBlackTreeModel<T>* rbModel = dynamic_cast<RedBlackTreeModel<T>*>(result);
        if(rbModel && rbModel->getRoot()) {
            viewResult = new ResultRBTree<T>(rbModel , resultTreeParent);
            viewResult->buildResultTree();
            viewResult->show();
            return;
        }
    BinaryTreeModel<T>* binaryModel = dynamic_cast<BinaryTreeModel<T>*>(result);
    if(binaryModel && binaryModel->getRoot()) {
        viewResult = new ResultBinaryTree<T>(binaryModel , resultTreeParent);
        viewResult->buildResultTree();
        viewResult->show();
		return;
	}
    TernaryTreeModel<T>* ternaryModel = dynamic_cast<TernaryTreeModel<T>*>(result);
    if(ternaryModel && ternaryModel->getRoot()) {
        viewResult = new ResultTernaryTree<T>(ternaryModel , resultTreeParent);
        viewResult->buildResultTree();
        viewResult->show();
		return;
    }
}

template<typename T>
void Controller<T>::closeResultView() {
    if(viewResult) 
	viewResult->close();
}

template<typename T>
void Controller<T>::removeTree(const int& index) {
    if(index >= 0 && index < modelReg.size()) {
        TreeModel<T>* aux = modelReg[index];
        modelReg.remove(index);
        delete aux;
    }
}

template<typename T>
void Controller<T>::buildBT(const int& height , BinaryNode<T>* node) {
    if(node->getHeight() == height)
        return;
        BinaryNode<T>* l = new BinaryNode<T>(Info<T>(0) , 0 , 0);
        BinaryNode<T>* r = new BinaryNode<T>(Info<T>(0) , 0 , 0);
        node->setChildren(l,r);
            buildBT(height , l);
            buildBT(height , r);

}

template<typename T>
void Controller<T>::closeViewResult() {
if(viewResult) {
    viewResult->hide();
    delete viewResult;
}
}

template<typename T>
QVector<int> Controller<T>::getUserIntInput(const QVector<const QLineEdit*> list) const {
    QVector<int> res;
	for(int i = 0 , dim = list.size(); i < dim ; i++) {
        res.append(list[i]->text().toInt());
	} 
	return res;
}

template<typename T>
QVector<bool> Controller<T>::getUserColorInput(const QVector<const QComboBox*> list) const {
    QVector<bool> res;
	for(int i = 0 , dim = list.size(); i < dim ; i++) {
        if(list[i]->currentText() == "Red")
			res.append(true);
		else
			res.append(false);
	} 
	return res;
}

template<typename T>
void Controller<T>::buildRBT(const QVector<const QComboBox*> colorBox , const int& listSize ,
                             int& index , const int& height , BinaryRedBlackNode<T>* node) {
    int nodeHeight = node->getHeight();
    if(nodeHeight == height)
        return;
    BinaryRedBlackNode<T>* l = 0;
    BinaryRedBlackNode<T>* r = 0;
    bool lRed = false , rRed = false;
    if(nodeHeight != (height-1) && index+1 < listSize) {
        if(colorBox[index]->currentText() == "Red") {
            l = new BinaryRedBlackNode<T>(true , Info<T>(0) , 0 , 0);
            lRed = true;
        }
        if(colorBox[index+1]->currentText() == "Red") {
            r = new BinaryRedBlackNode<T>(true , Info<T>(0) , 0 , 0);
            rRed = true;
        }
        index += 2;
    }
    if(!lRed)
        l = new BinaryRedBlackNode<T>(false , Info<T>(0) , 0 , 0);
    if(!rRed)
        r = new BinaryRedBlackNode<T>(false , Info<T>(0) , 0 , 0);
        node->setChildren(l,r);
            buildRBT(colorBox , listSize , index , height , l);
            buildRBT(colorBox , listSize , index , height , r);

}

template<typename T>
void Controller<T>::buildTT(const int& height , TernaryNode<T>* node) {
    if(node->getHeight() == height)
        return;
        TernaryNode<T>* l = new TernaryNode<T>(Info<T>(0) , 0 , 0 , 0);
        TernaryNode<T>* r = new TernaryNode<T>(Info<T>(0) , 0 , 0 , 0);
        TernaryNode<T>* m = new TernaryNode<T>(Info<T>(0) , 0 , 0 , 0);
        node->setChildren(l,r,m);
            buildTT(height , l);
            buildTT(height , r);
            buildTT(height , m);
}

template<typename T>
void Controller<T>::addBinaryTree(const int& height) {
    BinaryNode<T>* r = new BinaryNode<T>(Info<T>() , 0 , 0);
    BinaryTreeModel<T>* tree = new BinaryTreeModel<T>(r);
    buildBT(height , r);
    modelReg.append(tree);
}

template<typename T>
void Controller<T>::addRedBlackTree(const QVector<const QComboBox*> colorBox , const int& height) {
    BinaryRedBlackNode<T>* r = new BinaryRedBlackNode<T>(false , Info<T>() , 0 , 0);
    RedBlackTreeModel<T>* tree = new RedBlackTreeModel<T>(r);
    int index = 1;
    buildRBT(colorBox , colorBox.size() , index , height , r);
    modelReg.append(tree);
}

template<typename T>
void Controller<T>::addTernaryTree(const int& height) {
    TernaryNode<T>* r = new TernaryNode<T>(Info<T>() , 0 , 0);
    TernaryTreeModel<T>* tree = new TernaryTreeModel<T>(r);
    buildTT(height , r);
    modelReg.append(tree);
}

template<typename T>
T Controller<T>::SumMiddle(const int& index) throw(ExceptionHandler) {
    TernaryTreeModel<T>* aux = dynamic_cast<TernaryTreeModel<T>*>(modelReg[index]);
    if(aux)
        return aux->SumMiddle();
    else
        throw ExceptionHandler(6);
}

template<typename T>
T Controller<T>::SumValues(const int& index) {
        return modelReg[index]->SumValues();
}

template<typename T>
int Controller<T>::BlackHeight(const int& index) throw(ExceptionHandler) {
    RedBlackTreeModel<T>* aux = dynamic_cast<RedBlackTreeModel<T>*>(modelReg[index]);
    if(aux)
        return aux->getBlackHeight(aux->getRoot());
    else
        throw ExceptionHandler(7);
}

template<typename T>
void Controller<T>::BinaryRotation(const int& index) throw(ExceptionHandler) {
    RedBlackTreeModel<T>* rbTree = dynamic_cast<RedBlackTreeModel<T>*>(modelReg[index]);
    if(rbTree) {
    RedBlackTreeModel<T>* rbModel = rbTree->Rotation();
    closeViewResult();
    viewResult = new ResultRBTree<T>(rbModel , resultTreeParent);
    viewResult->buildResultTree();
    viewResult->show();
    delete rbModel;
    }
    else {
        BinaryTreeModel<T>* bTree = dynamic_cast<BinaryTreeModel<T>*>(modelReg[index]);
        if(bTree) {
                BinaryTreeModel<T>* binaryModel = bTree->Rotation();
                closeViewResult();
                viewResult = new ResultBinaryTree<T>(binaryModel , resultTreeParent);
                viewResult->buildResultTree();
                viewResult->show();
                delete binaryModel;
        }
        else
            throw ExceptionHandler(1);
    }
}

template<typename T>
T Controller<T>::SumBlackNodes(const int& index) throw(ExceptionHandler) {
    RedBlackTreeModel<T>* aux = dynamic_cast<RedBlackTreeModel<T>*>(modelReg[index]);
    if(aux)
        return aux->SumBlackNodes();
    else
        throw ExceptionHandler(3);
}

template<typename T>
T Controller<T>::SumRedNodes(const int& index) throw(ExceptionHandler) {
    RedBlackTreeModel<T>* aux = dynamic_cast<RedBlackTreeModel<T>*>(modelReg[index]);
    if(aux)
        return aux->SumRedNodes();
    else
        throw ExceptionHandler(2);
}

template<typename T>
void Controller<T>::undoOperand() {
    int index = indexReg.size() - 1;
    if(index >= 0) {
        indexReg.remove(index);
    }
}

template<typename T>
void Controller<T>::undoOperation() {
    int index = operationReg.size() - 1;
    if(index >= 0) {
        Operation<T>* aux = operationReg[index];
        operationReg.remove(index);
        delete aux;
    }
}

template<typename T>
void Controller<T>::addIntersectionOperation() {
    Intersection<T>* operation = new Intersection<T>();
    operationReg.append(operation);
}

template<typename T>
void Controller<T>::addSumOperation(){
    Sum<T>* operation = new Sum<T>();
    operationReg.append(operation);
}

template<typename T>
void Controller<T>::removeAllTrees() {
    for(int i = 0 , dim = modelReg.size() ; i < dim; i++)
        delete modelReg[i];
    modelReg.clear();
}

template<typename T>
void Controller<T>::removeAllOperands() {
    indexReg.clear();
}

template<typename T>
void Controller<T>::removeAllOperations() {
    for(int i = 0 , dim = operationReg.size() ; i < dim; i++)
            delete operationReg[i];
    operationReg.clear();
}

/*
 * expressionTextRegister holds the indexes of the models
 * expressionTextRegister is well formed(eg : 1 + 2 I 3) => operands are
 * found at position j = 0 , then at j+=2
 * use only the models inside expressionTextRegister.
 * index = expressionTextRegisterister[j] - 1 ( because expressionTextRegisterister[j]
 * starts from 1)
 * "QVector<int> inserted" holds the indexes of the previously updated models :
 * it's used to avoid reinserting the values on the same model.
 * */
template<typename T>
void Controller<T>::updateValuesOnExecute(QVector<QString> expressionTextRegister ,
                                          QVector<CreateTreeArea*> list) {
    QVector<int> inserted;
    RedBlackTreeModel<T>* rbModel = 0;
    CreateRBTreeArea* rbView = 0;
    for(int j = 0 , dimT = expressionTextRegister.size();j < dimT ; j+=2) {
        int index = expressionTextRegister[j].toInt() - 1;
        if(inserted.indexOf(index) == -1) {
                inserted.append(index);
                rbModel = dynamic_cast<RedBlackTreeModel<T>*>(modelReg[index]);
                rbView = dynamic_cast<CreateRBTreeArea*>(list[index]);
                if(rbModel && rbView)
                    rbModel->insertValuesAndColor(getUserIntInput(rbView->getLineEditList()) ,
                                                         getUserColorInput(rbView->getComboBoxList()));
                else
                modelReg[index]->insertValues(getUserIntInput(list[index]->getLineEditList()));
	    }
	}
}

/*
 * for unary operations that don't use the expressionTextRegister
 * */
template<typename T>
void Controller<T>::updateValuesOnExecute(const int& index , QVector<CreateTreeArea*> list) {
    RedBlackTreeModel<T>* rbModel = dynamic_cast<RedBlackTreeModel<T>*>(modelReg[index]);
    CreateRBTreeArea* rbView = dynamic_cast<CreateRBTreeArea*>(list[index]);
    if(rbModel && rbView){
        rbModel->insertValuesAndColor(getUserIntInput(rbView->getLineEditList()) ,
                                             getUserColorInput(rbView->getComboBoxList()));
    }
    else
        modelReg[index]->insertValues(getUserIntInput(list[index]->getLineEditList()));
}

template<typename T>
Controller<T>::~Controller() {
    for(int i = 0 , dim = operationReg.size() ; i < dim; i++)
        delete operationReg[i];
    for(int i = 0 , dim = modelReg.size() ; i < dim; i++)
        delete modelReg[i];
    delete viewResult;
    delete result;
}

#endif
