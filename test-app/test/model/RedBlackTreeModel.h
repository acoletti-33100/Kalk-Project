#ifndef RED_BLACK_TREE_MODEL_H
#define RED_BLACK_TREE_MODEL_H
#include"BinaryTreeModel.h"
#include"BinaryRedBlackNode.h"
template<typename T>
class RedBlackTreeModel : public BinaryTreeModel<T> {
private:
    void insertBalanced(BinaryRedBlackNode<T>* tmp = 0 , BinaryRedBlackNode<T>* node = 0);
    static BinaryRedBlackNode<T>* copy(BinaryRedBlackNode<T>* node = 0);
    T SumIfColor(BinaryRedBlackNode<T>* , const bool&) const;
    BinaryRedBlackNode<T>* copyBinary(BinaryNode<T>* node = 0);
    void insertRBTBalanced(BinaryRedBlackNode<T>* tmp = 0 , BinaryRedBlackNode<T>* node = 0);
    void Iterate(QVector<bool>& colorList , QVector<T>& list , BinaryRedBlackNode<T>* iterable = 0 , BinaryRedBlackNode<T>* fixed = 0);
    void InsertIfEquals(QVector<bool>& colorList , QVector<T>& list , BinaryRedBlackNode<T>* fixed = 0 , BinaryRedBlackNode<T>* iterable = 0);
    RedBlackTreeModel<T>* InsertOnIntersectionList(QVector<bool>& colorList , const QVector<T>& list) throw(ExceptionHandler);
    void insertColorValues(QVector<bool> list , const int& listSize ,
            int& index = 1 , BinaryRedBlackNode<T>* node = 0);
    BinaryRedBlackNode<T>* copyNodeOnly(BinaryRedBlackNode<T>* node = 0);
    void RotationRec(BinaryRedBlackNode<T>* , BinaryRedBlackNode<T>*);

protected:
    BinaryRedBlackNode<T>* RotationHelp();

	public :
        RedBlackTreeModel(BinaryRedBlackNode<T>* r = 0);
        ~RedBlackTreeModel();
        void insertValuesAndColor(QVector<T> , QVector<bool>);
        BinaryRedBlackNode<T>* getRoot() const;
        RedBlackTreeModel<T>* Rotation() throw(ExceptionHandler);
    RedBlackTreeModel<T>* Sum(const TreeModel<T>*) throw(ExceptionHandler);
        RedBlackTreeModel<T>* Intersection(const TreeModel<T>*) throw(ExceptionHandler);
	T SumRedNodes() const;
	T SumBlackNodes() const;
        int getBlackHeight(BinaryRedBlackNode<T>* node) const;
	int getRedCount(BinaryRedBlackNode<T>* node) const;	
};

template<typename T>
BinaryRedBlackNode<T>* RedBlackTreeModel<T>::copy(BinaryRedBlackNode<T>* node) {
    if(!node)
        return 0;
    return new BinaryRedBlackNode<T>(node->getBooleanColor() , node->getInfo() , copy(node->getLeft()) , copy(node->getRight()));
}

template<typename T>
RedBlackTreeModel<T>* RedBlackTreeModel<T>::Rotation() throw(ExceptionHandler) {
    BinaryRedBlackNode<T>* auxRoot = getRoot();
if(!auxRoot || !auxRoot->getRight())
    throw ExceptionHandler(1);
BinaryRedBlackNode<T>* resultRoot = RotationHelp();
return (new RedBlackTreeModel<T>(resultRoot));
}

template<typename T>
BinaryRedBlackNode<T>* RedBlackTreeModel<T>::copyNodeOnly(BinaryRedBlackNode<T>* node) {
if(!node)
    return 0;
return new BinaryRedBlackNode<T>(node->getBooleanColor() , node->getInfo() , 0 , 0);
}

template<typename T>
BinaryRedBlackNode<T>* RedBlackTreeModel<T>::RotationHelp() {
BinaryRedBlackNode<T>* resultRoot = copyNodeOnly(getRoot());
RotationRec(resultRoot , getRoot());
return resultRoot;
}

template<typename T>
void RedBlackTreeModel<T>::RotationRec(BinaryRedBlackNode<T>* node , BinaryRedBlackNode<T>* aux) {
if(!aux || !node)
    return;
if(aux->getRight()) {
    node->setLeft(copyNodeOnly(aux->getRight()));
    RotationRec(node->getLeft() , aux->getRight());
}
if(aux->getLeft()) {
    node->setRight(copyNodeOnly(aux->getLeft()));
    RotationRec(node->getRight() , aux->getLeft());
}
}

template<typename T>
void RedBlackTreeModel<T>::insertValuesAndColor(QVector<T> values , QVector<bool> colors) {
    BinaryTreeModel<T>::insertValues(values);
    BinaryRedBlackNode<T>* R = getRoot();
    R->setColor(false);
    int index = 0 , listSize = colors.size();
    insertColorValues(colors , listSize , index , R);
}

template<typename T>
void RedBlackTreeModel<T>::insertColorValues(QVector<bool> list , const int& listSize ,
        int& index , BinaryRedBlackNode<T>* node) {
    if(!node || index >= listSize)
        return;
    BinaryRedBlackNode<T>* l = node->getLeft();
    if(node->getParent() && l && node->getRight()) {
        node->setColor(list[index]);
        index++;
    }
    insertColorValues(list , listSize , index , l);
    insertColorValues(list , listSize , index , node->getRight());
}

template<typename T>
T RedBlackTreeModel<T>::SumRedNodes() const {
    bool color = true;
    return SumIfColor(getRoot() , color);
}

template<typename T>
T RedBlackTreeModel<T>::SumIfColor(BinaryRedBlackNode<T>* node , const bool& color) const {
	if(!node)
		return 0;
	if(node->getBooleanColor() == color)
        return (node->getInfo() + SumIfColor(node->getLeft() , color) + SumIfColor(node->getRight() , color));
	else
        return (SumIfColor(node->getLeft() , color) + SumIfColor(node->getRight() , color));
}

template<typename T>
T RedBlackTreeModel<T>::SumBlackNodes() const {
    bool color = false;
    return SumIfColor(getRoot() , color);
}

template<typename T>
BinaryRedBlackNode<T>* RedBlackTreeModel<T>::copyBinary(BinaryNode<T>* node) {
    if(!node)
        return 0;
    return new BinaryRedBlackNode<T>(false , node->getInfo() , copyBinary(node->getLeft()) , copyBinary(node->getRight()));
}

template<typename T>
        RedBlackTreeModel<T>::RedBlackTreeModel(BinaryRedBlackNode<T>* r) : BinaryTreeModel<T>(r) {}

    template<typename T>
    int RedBlackTreeModel<T>::getRedCount(BinaryRedBlackNode<T>* node) const {
        if(!node)
            return 0;
        if(node->hasBlack())
            return getRedCount(node->getLeft()) + getRedCount(node->getRight());
        else
            return 1 + getRedCount(node->getLeft()) + getRedCount(node->getRight());
    }

template<typename T>
RedBlackTreeModel<T>* RedBlackTreeModel<T>::Sum(const TreeModel<T>* tree) throw(ExceptionHandler){
    RedBlackTreeModel<T>* tmp = dynamic_cast<RedBlackTreeModel<T>*>(const_cast<TreeModel<T>*>(tree));
    BinaryTreeModel<T>* binary = 0;
    BinaryRedBlackNode<T>* operand = 0;
    if(!tmp) {
        binary = dynamic_cast<BinaryTreeModel<T>*>(const_cast<TreeModel<T>*>(tree));
        if(!binary)
            throw ExceptionHandler(4);
        else {
            operand = copyBinary(binary->getRoot());
        }
    }
    else {
        operand = copy(tmp->getRoot());
    }
    BinaryRedBlackNode<T>* resultRoot = copy(getRoot());
    RedBlackTreeModel<T>* resultTree = new RedBlackTreeModel<T>(resultRoot);
    insertRBTBalanced(resultRoot , operand);
    return resultTree;
}

template<typename T>
void RedBlackTreeModel<T>::insertRBTBalanced(BinaryRedBlackNode<T>* tmp , BinaryRedBlackNode<T>* node) {
    while(tmp) {
  BinaryRedBlackNode<T>* l = tmp->getLeft() , *r = tmp->getRight();
  if(!l) {
      tmp->setLeft(node);
      return;
  }
  if(!r) {
      tmp->setRight(node);
      return;
  }
  if(BinaryTreeModel<T>::getHeight(l) <= BinaryTreeModel<T>::getHeight(r))
      tmp = l;
  else
      tmp = r;

    }
}


template<typename T>
BinaryRedBlackNode<T>* RedBlackTreeModel<T>::getRoot() const {
    return dynamic_cast<BinaryRedBlackNode<T>*>(BinaryTreeModel<T>::getRoot());
}

    template<typename T>
RedBlackTreeModel<T>* RedBlackTreeModel<T>::Intersection(const TreeModel<T>* tree) throw(ExceptionHandler){
    RedBlackTreeModel<T>* tmp = dynamic_cast<RedBlackTreeModel<T>*>(const_cast<TreeModel<T>*>(tree));
    BinaryTreeModel<T>* binaryTmp = 0;
    if(!tmp) {
        binaryTmp = dynamic_cast<BinaryTreeModel<T>*>(const_cast<TreeModel<T>*>(tree));
        if(!binaryTmp)
            throw ExceptionHandler(5);
        else {
            BinaryTreeModel<T>* binary = BinaryTreeModel<T>::Intersection(tree);
            RedBlackTreeModel<T>* rbt(new RedBlackTreeModel<T>(copyBinary(binary->getRoot())));
            delete binary;
            return rbt;
        }
    }
    else {
        QVector<T> list;
        QVector<bool> colorList;
        Iterate(colorList , list , getRoot() , tmp->getRoot());
        return InsertOnIntersectionList(colorList , list);
    }
}

template<typename T>
void RedBlackTreeModel<T>::Iterate(QVector<bool>& colorList , QVector<T>& list , BinaryRedBlackNode<T>* iterable , BinaryRedBlackNode<T>* fixed) {
    if(!iterable)
        return;
    InsertIfEquals(colorList , list , iterable , fixed);
    Iterate(colorList , list , iterable->getLeft() , fixed);
    Iterate(colorList , list , iterable->getRight() , fixed);
}

template<typename T>
void RedBlackTreeModel<T>::InsertIfEquals(QVector<bool>& colorList , QVector<T>& list , BinaryRedBlackNode<T>* fixed , BinaryRedBlackNode<T>* iterable) {
    if(!iterable)
        return;
    if(fixed->getInfo() == iterable->getInfo() && fixed->getBooleanColor() == iterable->getBooleanColor())
         { list.append(fixed->getInfo());colorList.append(fixed->getBooleanColor()); }
    InsertIfEquals(colorList , list , fixed , iterable->getLeft());
    InsertIfEquals(colorList , list , fixed , iterable->getRight());
}

template<typename T>
RedBlackTreeModel<T>* RedBlackTreeModel<T>::InsertOnIntersectionList(QVector<bool>& colorList , const QVector<T>& list) throw(ExceptionHandler) {
    int dim = list.size();
    int dimC = colorList.size();
    if(dim > 0 && dimC > 0) {
      BinaryRedBlackNode<T>* Root = new BinaryRedBlackNode<T>(colorList[0] , Info<T>(list[0]) , 0 , 0);
    for(int i = 1; i < dim && i < dimC; i++) {
        BinaryRedBlackNode<T>* aux = new BinaryRedBlackNode<T>(colorList[i] , Info<T>(list[i]) , 0 , 0);
        insertRBTBalanced(Root , aux);
    }
    return (new RedBlackTreeModel<T>(Root));
    }
    else
        throw ExceptionHandler(8);
}

template<typename T>
        int RedBlackTreeModel<T>::getBlackHeight(BinaryRedBlackNode<T>* node) const {
        if(!node)
            return 0;
        else {
            int countL = getBlackHeight(node->getLeft()) , countR = getBlackHeight(node->getRight());
            if(countL == -1 || countR == -1 || (countL != countR && countL != 0 && countR != 0))
                return -1;
            else {
                int count = 0;
                (countL <= countR) ? count = countR : count = countL;
                if(node->hasBlack())
                    return (count + 1);
                else
                    return count;
            }
        }
        }

template<typename T>
RedBlackTreeModel<T>::~RedBlackTreeModel() {}

#endif

