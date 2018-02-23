#ifndef SUM_VALUES_H
#define SUM_VALUES_H

#include"Operation.h"

template<typename T>
class Sum : public Operation<T> {
	public:
		TreeModel<T>* execute(TreeModel<T>* leftOperand = 0 , TreeModel<T>* rightOperand = 0);
		Sum();
		~Sum();
};

template<typename T>
Sum<T>::Sum() {}

template<typename T>
Sum<T>::~Sum() {}

template<typename T>
TreeModel<T>* Sum<T>::execute(TreeModel<T>* leftOperand , TreeModel<T>* rightOperand) {
	return leftOperand->Sum(rightOperand);
}

#endif
