#ifndef TREE_MODEL_H
#define TREE_MODEL_H
#include"Info.h"
#include"ExceptionHandler.h"

template<typename T>
class TreeModel {
	public:
        virtual T SumValues() const = 0;
        virtual TreeModel<T>* Sum(const TreeModel<T>*) throw(ExceptionHandler) = 0;
        virtual TreeModel<T>* Intersection(const TreeModel<T>*) throw(ExceptionHandler) = 0;
    virtual void insertValues(QVector<T>) = 0;
        TreeModel();
		virtual ~TreeModel() = 0;
};

template<typename T>
TreeModel<T>::TreeModel() {}

template<typename T>
TreeModel<T>::~TreeModel() {}

#endif
