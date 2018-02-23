#ifndef TERNARY_NODE_H
#define TERNARY_NODE_H
#include"Info.h"

template<typename T>
class TernaryNode {
    private:
            Info<T> info;
    protected: 
            TernaryNode<T>* left;
            TernaryNode<T>* right;
            TernaryNode<T>* middle;
            TernaryNode<T>* parent;
	public:
        T getInfo() const;
        void setInfo(const T& val = 0);
        void addInfo(const T& val = 0);
        int getHeight() const;
        virtual TernaryNode<T>* getMiddle() const;
        virtual TernaryNode<T>* getRight() const;
        virtual TernaryNode<T>* getLeft() const;
        TernaryNode<T>* getParent() const;
        void setParent(TernaryNode<T>* node = 0);
        void setMiddle(TernaryNode<T>* node = 0);
        void setLeft(TernaryNode<T>* node = 0);
        void setRight(TernaryNode<T>* node = 0);
        void setChildren(TernaryNode<T>* l = 0 , TernaryNode<T>* r = 0 , TernaryNode<T>* m = 0);
        TernaryNode(const Info<T>& value = 0 , TernaryNode<T>* lx = 0 , TernaryNode<T>* rx = 0 , TernaryNode<T>* mx = 0);
		virtual ~TernaryNode();
};

template<typename T>
TernaryNode<T>::TernaryNode(const Info<T>& value , TernaryNode<T>* lx ,
                        TernaryNode<T>* rx , TernaryNode<T>* mx) :
info(value) , left(lx) , right(rx) , middle(mx) , parent(0) {
    if(left)
        left->setParent(this);
    if(right)
        right->setParent(this);
    if(middle)
        middle->setParent(this);
}

template<typename T>
int TernaryNode<T>::getHeight() const {
    if(getParent())
        return 1 + getParent()->getHeight();
    else
        return 1;
}

template<typename T>
TernaryNode<T>* TernaryNode<T>::getMiddle() const { return middle; }

template<typename T>
TernaryNode<T>* TernaryNode<T>::getRight() const { return right; }

template<typename T>
TernaryNode<T>* TernaryNode<T>::getParent() const { return parent; }

template<typename T>
void TernaryNode<T>::setParent(TernaryNode<T>* node) { parent = node; }

template<typename T>
void TernaryNode<T>::setMiddle(TernaryNode<T>* node) {
    middle = node;
    middle->setParent(this);
}

template<typename T>
void TernaryNode<T>::setLeft(TernaryNode<T>* node) {
    left = node;
    left->setParent(this);
}

template<typename T>
void TernaryNode<T>::setRight(TernaryNode<T>* node) {
    right = node;
    right->setParent(this);
}

template<typename T>
void TernaryNode<T>::setChildren(TernaryNode<T>* l , TernaryNode<T>* r , TernaryNode<T>* m) {
    left = l;
    right = r;
    middle = m;
    left->setParent(this);
    right->setParent(this);
    middle->setParent(this);
}

template<typename T>
T TernaryNode<T>::getInfo() const { return info.getValue(); }

template<typename T>
void TernaryNode<T>::addInfo(const T& val) { info += val; }

template<typename T>
void TernaryNode<T>::setInfo(const T& val) { info = val; }

template<typename T>
TernaryNode<T>* TernaryNode<T>::getLeft() const { return left; }

template<typename T>
TernaryNode<T>::~TernaryNode() {
if(left) {
    delete left;
    left = 0;
}
if(right) {
    delete right;
    right = 0;
}
if(middle) {
    delete middle;
    middle = 0;
}
}

#endif
