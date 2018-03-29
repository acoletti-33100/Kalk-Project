#ifndef BINARY_RED_BLACK_NODE_H
#define BINARY_RED_BLACK_NODE_H
#include"BinaryNode.h"

template<typename T>
class BinaryRedBlackNode : public BinaryNode<T> {
	private:
		bool color;
	public:
		bool hasBlack() const;
        void setColor(const bool& col = false);
    QString getColor() const;
    bool getBooleanColor() const;
        BinaryRedBlackNode<T>* getRight() const;
        BinaryRedBlackNode<T>* getLeft() const;
        BinaryRedBlackNode(const bool& col = false , const Info<T>& value = 0 , 
            BinaryNode<T>* lx  = 0 , BinaryNode<T>* rx = 0);
		~BinaryRedBlackNode();
};

template<typename T>
BinaryRedBlackNode<T>::BinaryRedBlackNode(const bool& col , const Info<T>& value ,
                                          BinaryNode<T>* lx , BinaryNode<T>* rx) :
    BinaryNode<T>(value,lx,rx) ,
    color(col) {
}

template<typename T>
void BinaryRedBlackNode<T>::setColor(const bool& col) { color = col; }

template<typename T>
BinaryRedBlackNode<T>* BinaryRedBlackNode<T>::getRight() const {
    return dynamic_cast<BinaryRedBlackNode<T>*>(BinaryNode<T>::getRight());
}

    template<typename T>
    QString BinaryRedBlackNode<T>::getColor() const {
        if(color)
            return "Red";
        return "Black";
    }

    template<typename T>
    bool BinaryRedBlackNode<T>::getBooleanColor() const {
        return color;
    }

template<typename T>
BinaryRedBlackNode<T>* BinaryRedBlackNode<T>::getLeft() const {
    return dynamic_cast<BinaryRedBlackNode<T>*>(BinaryNode<T>::getLeft());
}

template<typename T>
bool BinaryRedBlackNode<T>::hasBlack() const { return color ^ 1; }

template<typename T>
BinaryRedBlackNode<T>::~BinaryRedBlackNode() {}

#endif
