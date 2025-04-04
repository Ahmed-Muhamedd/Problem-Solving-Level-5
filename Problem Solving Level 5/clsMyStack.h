#pragma once
#include <iostream>
using namespace std;
#include "clsMyQueue.h"


template <class T>
class clsMyStack : public clsMyQueue <T>
{
public:

	void Push(T Value) {
		clsMyQueue <T>::_List.InsertAtEnd(Value);
	}
	
	T Top() {
		return clsMyQueue <T>::Front();
	}

	T Bottom() {
		return clsMyQueue <T>::Back();
	}
};

