#ifndef TERNARY_TREE_MODEL_H
#define TERNARY_TREE_MODEL_H
#include"TreeModel.h"
#include"TernaryNode.h"

template<typename T>
class TernaryTreeModel : public TreeModel<T> {
private:
    TernaryNode<T>* root;
    void helpSumMiddle(QVector<T>& list , TernaryNode<T>* node = 0) const;
    void insertBalanced(TernaryNode<T>* , TernaryNode<T>*);
void insertValues(QVector<T> list , const int& listSize , 
		int& index = 1 , TernaryNode<T>* node = 0); 
static TernaryNode<T>* copy(TernaryNode<T>* node = 0);
TernaryTreeModel<T>* InsertOnIntersectionList(const QVector<T>& list) throw(ExceptionHandler);
void InsertIfEquals(QVector<T>& list , TernaryNode<T>* fixed = 0 , TernaryNode<T>* iterable = 0);
    void Iterate(QVector<T>& list , TernaryNode<T>* iterable = 0 , TernaryNode<T>* fixed = 0);

public:
    static int getHeight(TernaryNode<T>* node = 0);
	virtual void insertValues(QVector<T>);
    T Count(TernaryNode<T>* node = 0) const;
        TernaryTreeModel(TernaryNode<T>* r = 0);
		virtual ~TernaryTreeModel();
        virtual TernaryNode<T>* getRoot() const;
     T SumValues() const;
     T SumMiddle() const;
     TernaryTreeModel<T>& operator=(const TernaryTreeModel<T>&);
        virtual TernaryTreeModel<T>* Sum(const TreeModel<T>*) throw(ExceptionHandler);
        virtual TernaryTreeModel<T>* Intersection(const TreeModel<T>*) throw(ExceptionHandler);
};

template<typename T>
    TernaryTreeModel<T>::TernaryTreeModel(TernaryNode<T>* r) : root(r) {}

template<typename T>
void TernaryTreeModel<T>::insertValues(QVector<T> list) {
	root->setInfo(list[0]);
	int index = 1 , listSize = list.size();
	insertValues(list , listSize , index , root);
}

template<typename T>    
void TernaryTreeModel<T>::insertValues(QVector<T> list , const int& listSize , 
		int& index , TernaryNode<T>* node) {
	if(!node || index+2 >= listSize)
		return;
	TernaryNode<T>* l = node->getLeft();
	TernaryNode<T>* r = node->getRight();
	TernaryNode<T>* m = node->getMiddle();
	if(l && r && m) {
		l->setInfo(list[index]);
		r->setInfo(list[index+1]);
		m->setInfo(list[index+2]);
		index += 3;
	}
	insertValues(list , listSize , index , l);
	insertValues(list , listSize , index , node->getRight());
	insertValues(list , listSize , index , node->getMiddle());
}

    template<typename T>
     T TernaryTreeModel<T>::SumMiddle() const {
         QVector<T> list;
         TernaryNode<T>* r = getRoot();
         T sum = 0;
         helpSumMiddle(list , r);
         for(int i = 0 , dim = list.size() ; i < dim ; i++) {
             sum += list[i];
         }
         return sum;
     }

    template<typename T>
    void TernaryTreeModel<T>::helpSumMiddle(QVector<T>& list , TernaryNode<T>* node) const {
        if(!node)
            return;
        TernaryNode<T>* aux = node->getMiddle();
        if(aux)
            list.append(aux->getInfo());
        helpSumMiddle(list , node->getLeft());
        helpSumMiddle(list , node->getRight());
        helpSumMiddle(list , node->getMiddle());
    }

  template<typename T>
    T TernaryTreeModel<T>::Count(TernaryNode<T>* node) const {
        if(!node) { return 0; }
        else { return node->getInfo() + Count(node->getLeft()) + Count(node->getRight()) + Count(node->getMiddle()); }
    }

    template<typename T>
      int TernaryTreeModel<T>::getHeight(TernaryNode<T>* node) {
          if(!node) { return 0; }
          else { return 1 + getHeight(node->getLeft()) + getHeight(node->getRight()) + getHeight(node->getMiddle()); }
      }

      template<typename T>
      TernaryTreeModel<T>& TernaryTreeModel<T>::operator=(const TernaryTreeModel<T>& t) {
          if(this != &t) {
              delete root;
              root = TernaryNode<T>::copy(t.getRoot());
          }
          return *this;
      }

      template<typename T>
      void TernaryTreeModel<T>::insertBalanced(TernaryNode<T>* tmp , TernaryNode<T>* node) {
          while(tmp) {
        TernaryNode<T>* l = tmp->getLeft() , *r = tmp->getRight() , *m = tmp->getMiddle();
        if(!l) {
            tmp->setLeft(node);
            return;
        }
        if(!r) {
            tmp->setRight(node);
            return;
        }
        if(!m) {
            tmp->setMiddle(node);
            return;
        }
        int heightL = getHeight(l) , heightR = getHeight(r) ,heightM = getHeight(m) , tmpH = -1;
        if(heightL < heightR) {
            tmp = l;
            tmpH = heightL;
        }
        else {
            tmp = r;
            tmpH = heightR;
        }
        if(tmpH > heightM)
            tmp = m;
          }
      }

      template<typename T>
    TernaryNode<T>* TernaryTreeModel<T>::getRoot() const { return root; }

        template<typename T>
            T TernaryTreeModel<T>::SumValues() const { return Count(getRoot()); }

    template<typename T>
        TernaryTreeModel<T>* TernaryTreeModel<T>::Sum(const TreeModel<T>* tree) throw(ExceptionHandler) {
            TernaryTreeModel<T>* tmp = dynamic_cast<TernaryTreeModel<T>*>(const_cast<TreeModel<T>*>(tree));
            if(!tmp)
                throw ExceptionHandler(4);
            TernaryNode<T>* resultRoot = copy(root);
        insertBalanced(resultRoot , copy(tmp->getRoot()));
            return (new TernaryTreeModel<T>(resultRoot));
        }

        template<typename T>
        TernaryNode<T>* TernaryTreeModel<T>::copy(TernaryNode<T>* node) {
            if(!node)
                return 0;
            return new TernaryNode<T>(node->getInfo() , copy(node->getLeft()) , copy(node->getRight()) , copy(node->getMiddle()));
        }

    template<typename T>
        TernaryTreeModel<T>* TernaryTreeModel<T>::Intersection(const TreeModel<T>* tree) throw(ExceptionHandler) {
            TernaryTreeModel<T>* tmp = dynamic_cast<TernaryTreeModel<T>*>(const_cast<TreeModel<T>*>(tree));
            if(!tmp)
                throw ExceptionHandler(5);
        QVector<T> list;
        Iterate(list , root , tmp->getRoot());
        return InsertOnIntersectionList(list);
        }

template<typename T>
void TernaryTreeModel<T>::Iterate(QVector<T>& list , TernaryNode<T>* iterable , TernaryNode<T>* fixed) {
    if(!iterable)
        return;
    InsertIfEquals(list , iterable , fixed);
    Iterate(list , iterable->getLeft() , fixed);
    Iterate(list , iterable->getRight() , fixed);
    Iterate(list , iterable->getMiddle() , fixed);
}

template<typename T>
void TernaryTreeModel<T>::InsertIfEquals(QVector<T>& list , TernaryNode<T>* fixed , TernaryNode<T>* iterable) {
    if(!iterable)
        return;
    if(fixed->getInfo() == iterable->getInfo())
        list.append(fixed->getInfo());
    InsertIfEquals(list , fixed , iterable->getLeft());
    InsertIfEquals(list , fixed , iterable->getRight());
    InsertIfEquals(list , fixed , iterable->getMiddle());
}

template<typename T>
TernaryTreeModel<T>* TernaryTreeModel<T>::InsertOnIntersectionList(const QVector<T>& list) throw(ExceptionHandler) {
    int dim = list.size();
    if(dim > 0) {
      TernaryNode<T>* Root = new TernaryNode<T>(Info<T>(list[0]) , 0 , 0);
    for(int i = 1; i < dim; i++) {
        TernaryNode<T>* aux = new TernaryNode<T>(Info<T>(list[i]) , 0 , 0);
        insertBalanced(Root , aux);
    }
    return (new TernaryTreeModel<T>(Root));
    }
    else
        throw ExceptionHandler(8);
}

template<typename T>
TernaryTreeModel<T>::~TernaryTreeModel() {
    if(root) delete root;
}

#endif
