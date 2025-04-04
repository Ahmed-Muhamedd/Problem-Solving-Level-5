#pragma once
#include <iostream>
#include "clsMyDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
	clsMyDynamicArray <T> _List;

public:

	void Push(T Value) {
		_List.InsertAtEnd(Value);
	}

	void PrintList() {
		_List.PrintList();
	}

	int Size() {
		return _List.Size();
	}

	T Front() {
		return _List.GetItem(0);
	}

	T Back() {
		return _List.GetItem(Size() - 1);
	}

	void Pop() {
		_List.DeleteFirstItem();
	}

	void Clear() {
		_List.Clear();
	}

	// Just training on resubility :)
	void Reverse() {
		_List.Reverse();
	}
	
	void UpdateItem(int Index , T Value) {
		_List.SetItem(Index, Value);
	}

	bool IsEmpty() {
		return _List.IsEmpty();
	}

	T GetItem(int Index) {
		return _List.GetItem(Index); 
	}


};


