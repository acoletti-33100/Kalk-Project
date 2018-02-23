#ifndef INTERSECTION_H
#define INTERSECTION_H 

#include"Operation.h"

template<typename T>
class Intersection : public Operation<T> {
	public:
		TreeModel<T>* execute(TreeModel<T>* leftOperand = 0 , TreeModel<T>* rightOperand = 0);
		Intersection();
		~Intersection();
};

template<typename T>
Intersection<T>::Intersection() {}

template<typename T>
Intersection<T>::~Intersection() {}

template<typename T>
TreeModel<T>* Intersection<T>::execute(TreeModel<T>* leftOperand , TreeModel<T>* rightOperand) {
	return leftOperand->Intersection(rightOperand);
}

#endif
