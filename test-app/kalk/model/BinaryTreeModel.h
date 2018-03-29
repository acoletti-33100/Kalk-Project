#ifndef BINARY_TREE_MODEL_H
#define BINARY_TREE_MODEL_H
#include"TreeModel.h"
#include"BinaryNode.h"

template<typename T>
class BinaryTreeModel : public TreeModel<T> {
private:
    BinaryNode<T>* root;
    void insertValues(QVector<T> list , const int& listSize , int& index = 1 , BinaryNode<T>* node = 0);
    static BinaryNode<T>* copy(BinaryNode<T>* node = 0);
    void insertBalanced(BinaryNode<T>* , BinaryNode<T>*);
    T Count(BinaryNode<T>* node = 0) const;
BinaryTreeModel<T>* InsertOnIntersectionList(const QVector<T>& list) throw(ExceptionHandler);
void InsertIfEquals(QVector<T>& list , BinaryNode<T>* fixed = 0 , BinaryNode<T>* iterable = 0);
	void Iterate(QVector<T>& list , BinaryNode<T>* iterable = 0 , BinaryNode<T>* fixed = 0);
    BinaryNode<T>* copyNodeOnly(BinaryNode<T>* node = 0);
    void RotationRec(BinaryNode<T>* , BinaryNode<T>*);

protected:
    int getLeaves(BinaryNode<T>* node = 0) const;
    virtual BinaryNode<T>* RotationHelp();

public:
    static int getHeight(BinaryNode<T>* node = 0);
	virtual void insertValues(QVector<T>);
        BinaryTreeModel(BinaryNode<T>* r = 0);
		virtual ~BinaryTreeModel();
        virtual BinaryTreeModel<T>* Rotation() throw(ExceptionHandler);
        virtual BinaryNode<T>* getRoot() const;
     T SumValues() const;
     BinaryTreeModel<T>& operator=(const BinaryTreeModel<T>&);
        virtual BinaryTreeModel<T>* Sum(const TreeModel<T>*) throw(ExceptionHandler);
        virtual BinaryTreeModel<T>* Intersection(const TreeModel<T>*) throw(ExceptionHandler);
};

template<typename T>
    BinaryTreeModel<T>::BinaryTreeModel(BinaryNode<T>* r) : root(r) {}

    template<typename T>
BinaryTreeModel<T>* BinaryTreeModel<T>::Rotation() throw(ExceptionHandler) {
    if(!root || !root->getRight())
        throw ExceptionHandler(1);
    BinaryNode<T>* resultRoot = RotationHelp();
    return (new BinaryTreeModel<T>(resultRoot));
}

template<typename T>
BinaryNode<T>* BinaryTreeModel<T>::copyNodeOnly(BinaryNode<T>* node) {
    if(!node)
        return 0;
    return new BinaryNode<T>(node->getInfo() , 0 , 0);
}

template<typename T>
BinaryNode<T>* BinaryTreeModel<T>::RotationHelp() {
    BinaryNode<T>* resultRoot = copyNodeOnly(root);
    RotationRec(resultRoot , root);
    return resultRoot;
}

template<typename T>
void BinaryTreeModel<T>::RotationRec(BinaryNode<T>* node , BinaryNode<T>* aux) {
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
void BinaryTreeModel<T>::insertValues(QVector<T> list) {
    root->setInfo(list[0]);
	int index = 1 , listSize = list.size();
	insertValues(list , listSize , index , root);
}

template<typename T>    
void BinaryTreeModel<T>::insertValues(QVector<T> list , const int& listSize , 
		int& index , BinaryNode<T>* node) {
	if(!node || index+1 >= listSize)
		return;
	BinaryNode<T>* l = node->getLeft();
	BinaryNode<T>* r = node->getRight();
	if(l && r) {
		l->setInfo(list[index]);
		r->setInfo(list[index+1]);
		index += 2;
	}
	insertValues(list , listSize , index , l);
	insertValues(list , listSize , index , node->getRight());
}

template<typename T>
int BinaryTreeModel<T>::getLeaves(BinaryNode<T>* node) const {
    if(!node)
        return 0;
    if(!(node->getLeft()) && !(node->getRight()))
            return 1 + getLeaves(node->getLeft()) + getLeaves(node->getRight());
    return getLeaves(node->getLeft()) + getLeaves(node->getRight());
}

  template<typename T>
    T BinaryTreeModel<T>::Count(BinaryNode<T>* node) const {
        if(!node) { return 0; }
        else { return node->getInfo() + Count(node->getLeft()) + Count(node->getRight()); }
    }

    template<typename T>
      int BinaryTreeModel<T>::getHeight(BinaryNode<T>* node) {
          if(!node) { return 0; }
          else { return 1 + getHeight(node->getLeft()) + getHeight(node->getRight()); }
      }

      template<typename T>
      BinaryTreeModel<T>& BinaryTreeModel<T>::operator=(const BinaryTreeModel<T>& t) {
          if(this != &t) {
              delete root;
              root = BinaryNode<T>::copy(t.getRoot());
          }
          return *this;
      }

      template<typename T>
      void BinaryTreeModel<T>::insertBalanced(BinaryNode<T>* tmp , BinaryNode<T>* node) {
          while(tmp) {
        BinaryNode<T>* l = tmp->getLeft() , *r = tmp->getRight();
        if(!l) {
            tmp->setLeft(node);
            return;
        }
        if(!r) {
            tmp->setRight(node);
            return;
        }
        if(getHeight(l) <= getHeight(r))
            tmp = l;
        else
            tmp = r;

          }
      }

      template<typename T>
    BinaryNode<T>* BinaryTreeModel<T>::getRoot() const { return root; }

        template<typename T>
            T BinaryTreeModel<T>::SumValues() const { return Count(getRoot()); }

            template<typename T>
            BinaryNode<T>* BinaryTreeModel<T>::copy(BinaryNode<T>* node) {
                if(!node)
                    return 0;
                return new BinaryNode<T>(node->getInfo() , copy(node->getLeft()) , copy(node->getRight()));
            }

    template<typename T>
        BinaryTreeModel<T>* BinaryTreeModel<T>::Sum(const TreeModel<T>* tree) throw(ExceptionHandler) {
            BinaryTreeModel<T>* tmp = dynamic_cast<BinaryTreeModel<T>*>(const_cast<TreeModel<T>*>(tree));
            if(!tmp)
                throw ExceptionHandler(4);
            BinaryNode<T>* resultRoot = copy(root);
            insertBalanced(resultRoot , copy(tmp->getRoot()));
            return (new BinaryTreeModel<T>(resultRoot));
        }

    template<typename T>
        BinaryTreeModel<T>* BinaryTreeModel<T>::Intersection(const TreeModel<T>* tree) throw(ExceptionHandler) {
            BinaryTreeModel<T>* tmp = dynamic_cast<BinaryTreeModel<T>*>(const_cast<TreeModel<T>*>(tree));
            if(!tmp)
                throw ExceptionHandler(5);
        QVector<T> list;
        Iterate(list , root , tmp->getRoot());
        return InsertOnIntersectionList(list);
        }

template<typename T>
void BinaryTreeModel<T>::Iterate(QVector<T>& list , BinaryNode<T>* iterable , BinaryNode<T>* fixed) {
	if(!iterable)
		return;
	InsertIfEquals(list , iterable , fixed);
	Iterate(list , iterable->getLeft() , fixed);
	Iterate(list , iterable->getRight() , fixed); 
}

template<typename T>
void BinaryTreeModel<T>::InsertIfEquals(QVector<T>& list , BinaryNode<T>* fixed , BinaryNode<T>* iterable) {
	if(!iterable)
		return;
	if(fixed->getInfo() == iterable->getInfo())
        list.append(fixed->getInfo());
	InsertIfEquals(list , fixed , iterable->getLeft());
	InsertIfEquals(list , fixed , iterable->getRight());
}

template<typename T>
BinaryTreeModel<T>* BinaryTreeModel<T>::InsertOnIntersectionList(const QVector<T>& list) throw(ExceptionHandler) {
    int dim = list.size();
    if(dim > 0) {
      BinaryNode<T>* Root = new BinaryNode<T>(Info<T>(list[0]) , 0 , 0);
    for(int i = 1; i < dim; i++) {
        BinaryNode<T>* aux = new BinaryNode<T>(Info<T>(list[i]) , 0 , 0);
        insertBalanced(Root , aux);
    }
    return (new BinaryTreeModel<T>(Root));
    }
    else
        throw ExceptionHandler(8);

}

template<typename T>
BinaryTreeModel<T>::~BinaryTreeModel() {
    if(root) delete root;
}

#endif
