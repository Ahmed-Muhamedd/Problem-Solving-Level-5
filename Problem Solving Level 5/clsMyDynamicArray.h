#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsMyDynamicArray
{
private:
	T* _TempArray;
	int _Size = 0 ;
public:
	T* OriginalArray;


	clsMyDynamicArray(int Size = 0) {
		if (Size < 0)
			Size = 0;

		_Size = Size;

		OriginalArray = new T[_Size];
	}

	~clsMyDynamicArray() {
		delete[] OriginalArray;
	}

	bool SetItem(int Index, T Value) {
		if (Index > _Size || Index < 0)
			return false;

		OriginalArray[Index] = Value;
		return true;
	}

	bool IsEmpty() {
		return _Size == 0 ? true : false;
	}

	int Size() {
		return _Size;
	}

	void PrintList() {
		for (short i = 0; i < _Size; i++) {
			cout << OriginalArray[i] << " ";
		}
		cout << endl;
	}

	void Resize(int NewSize) {

		if (NewSize < 0)
			NewSize = 0;

		_TempArray = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;

		for (int i = 0; i < _Size; i++) {
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	T GetItem(int Index) {
		return OriginalArray[Index];
	}

	void Reverse() {
		_TempArray = new T[_Size];
		int Counter = 0;

		for (short i = _Size; i > 0; i--) {
			_TempArray[Counter] = OriginalArray[i];
			Counter++;
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear() {
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(int Index) {
		if (Index < 0 || Index > _Size)
			return false;

		_Size--;
		_TempArray = new T[_Size];

		for (short i = 0; i < Index; i++) {
			_TempArray[i] = OriginalArray[i];
		}

		for (short i = Index + 1; i < _Size + 1; i++) {
			_TempArray[i - 1 ] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	bool DeleteFirstItem() {
		return DeleteItemAt(0);
	}

	bool DeleteLastItem() {
		return DeleteItemAt(_Size - 1);
	}

	short Find(T Value) {

		for (short i = 0; i < _Size; i++) {
			if (OriginalArray[i] == Value)
				return i;
		}
		return -1;
	}

	bool DeleteItem(T Value) {
		short IndexOfElement = Find(Value);

		if (IndexOfElement == -1)
			return false;

			DeleteItemAt(IndexOfElement);
			return true;
	}

	void InsertAt(int Index , T Value){
		if (Index > _Size || Index < 0)
			return;

		_Size++;

		_TempArray = new T[_Size];


		for (int i = 0; i < Index; i++) {
			_TempArray[i] = OriginalArray[i];
		}
		_TempArray[Index] = Value;

		for (int i = Index; i < _Size - 1; i++) {
			_TempArray[i + 1] = OriginalArray[i];
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;

	}

	void InsertAtBeginning(T Value) {
		InsertAt(0, Value);
	}

	bool InsertBefore(int Index, T Value) {
		if (Index < 1)
			return InsertAt(0, Value);
		else
			InsertAt(Index - 1 , Value);

	}

	bool InsertAfter(int Index, T Value) {
		if (Index > _Size)
			return InsertAt(_Size - 1, Value);
		else
			return InsertAt(Index + 1, Value);
	}

	void InsertAtEnd(T Value) {
		InsertAt(_Size , Value);
	}
};


