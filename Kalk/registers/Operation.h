#ifndef OPERATION_H
#define OPERATION_H

#include"model/TreeModel.h"

template<typename T>
class Operation {
	public:
		virtual TreeModel<T>* execute(TreeModel<T>* leftOperand = 0 , TreeModel<T>* rightOperand = 0) = 0;
		Operation();
		virtual ~Operation() = 0;
};

template<typename T>
Operation<T>::Operation() {}

template<typename T>
Operation<T>::~Operation() {}

#endif
