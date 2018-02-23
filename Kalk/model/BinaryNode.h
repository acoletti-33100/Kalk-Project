#ifndef BINARY_NODE_H
#define BINARY_NODE_H
#include"Info.h"

template<typename T>
class BinaryNode {
    private:
            Info<T> info;
            BinaryNode<T>* left;
            BinaryNode<T>* right;
            BinaryNode<T>* parent;
	public:
        T getInfo() const;
        void addInfo(const T& val = 0);
	void setInfo(const T& val = 0);
        int getHeight() const;
        virtual BinaryNode<T>* getRight() const;
        virtual BinaryNode<T>* getLeft() const;
	void setParent(BinaryNode<T>* node = 0);
	BinaryNode<T>* getParent() const;
        void setLeft(BinaryNode<T>* node = 0);
        void setRight(BinaryNode<T>* node = 0);
        void setChildren(BinaryNode<T>* l = 0 , BinaryNode<T>* r = 0);
        BinaryNode(const Info<T>& value = 0 , BinaryNode<T>* lx = 0 ,
			BinaryNode<T>* rx = 0);
		virtual ~BinaryNode();
};

template<typename T>
BinaryNode<T>::BinaryNode(const Info<T>& value , BinaryNode<T>* lx , BinaryNode<T>* rx) :
info(value) ,
left(lx) ,
right(rx), parent(0) { 
	if(left)
		left->setParent(this);
	if(right)
		right->setParent(this);
}

template<typename T>
int BinaryNode<T>::getHeight() const {
    if(getParent())
        return 1 + getParent()->getHeight();
    else
        return 1;
}

template<typename T>
BinaryNode<T>* BinaryNode<T>::getParent() const { return parent; }

    template<typename T>
    void BinaryNode<T>::setParent(BinaryNode<T>* node) { parent = node; }

    template<typename T>
    BinaryNode<T>* BinaryNode<T>::getRight() const { return right; }

    template<typename T>
    BinaryNode<T>* BinaryNode<T>::getLeft() const { return left; }

template<typename T>
void BinaryNode<T>::setLeft(BinaryNode<T>* node) { 
    left = node;
	left->setParent(this);
}

template<typename T>
void BinaryNode<T>::setRight(BinaryNode<T>* node) { 
    right = node;
	right->setParent(this);
}

template<typename T>
void BinaryNode<T>::setChildren(BinaryNode<T>* l , BinaryNode<T>* r) {
    left = l;
    right = r;
	left->setParent(this);
	right->setParent(this);
}

template<typename T>
T BinaryNode<T>::getInfo() const { return info.getValue(); }

template<typename T>
void BinaryNode<T>::addInfo(const T& val) { info += val; }

template<typename T>
void BinaryNode<T>::setInfo(const T& val) { info = val; }

template<typename T>
BinaryNode<T>::~BinaryNode() {
if(left) {
    delete left;
    left = 0;
}
if(right) {
    delete right;
    right = 0;
}
}

#endif
