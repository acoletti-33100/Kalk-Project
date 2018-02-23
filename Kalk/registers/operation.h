#ifndef OPERATION_H
#define OPERATION_H
#include<typeinfo>

template<typename T>
class Operation {
	public:
		virtual TreeModel<T>* execute(TreeModel<T>* leftOperand = 0 , TreeModel<T>* rightOperand = 0) = 0;
		Operation();
		virtual ~Operation() = 0;
};

template<typename T>
Operation::Operation() {}

template<typename T>
Operation::~Operation() {}

#endif
