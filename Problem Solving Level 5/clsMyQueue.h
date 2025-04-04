#pragma once
#include <iostream>
using namespace std;
#include "clsDbLinkedList.h"

template <class T>
class clsMyQueue
{
protected:

	clsDbLinkedList <T> _List;
public:

	void Push(T Value) {
		_List.InsertAtEnd(Value);
	}

	void Print() {
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
		_List.DeleteFirstNode();
	}

	bool IsEmpty() {
		return _List.IsEmpty();
	}

	// Just training on resubility :)

	T GetItem(int Index) {
		return _List.GetItem(Index);
	}

	void Reverse() {
		_List.Reverse();
	}

	void UpdateItem(int Index, T Value) {
		_List.UpdateItem(Index, Value);
	}

	bool InsertAfter(int Index, T Value) {
		return _List.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value) {
		_List.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value) {
		_List.InsertAtEnd(Value);
	}

	void Clear() {
		_List.Clear();
	}

};

