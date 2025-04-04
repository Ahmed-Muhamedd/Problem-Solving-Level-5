#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDbLinkedList
{
protected:
	int _Size = 0;
public:
	class Node {
	public:
		T Value;
		Node* Next;
		Node* Perv;
	};

	Node* Head = NULL;

	void InsertAtBeginning(T Value){
		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->Next = Head;
		NewNode->Perv = NULL;

		if (Head != NULL)
			Head->Perv = NewNode;

		Head = NewNode;
		_Size++;
	}

	void PrintList() {
		Node* Current = Head;

		while (Current != NULL) {
			cout << Current->Value << " ";
			Current = Current->Next;
		}

		cout << endl;
	}

	Node* Find(T Value) {
		Node* Current = Head;
		while (Current != NULL) {

			if (Current->Value == Value)
				return Current;

			Current = Current->Next;
		}
		return NULL;
	}

	void InsertAfter(Node* N1, T Value) {
		if (N1 == NULL)
			return;

		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->Next = N1->Next;
		NewNode->Perv = N1;

		if (N1->Next != NULL)
			N1->Next->Perv = NewNode;

		N1->Next = NewNode;
		_Size++;

	}

	void InsertAtEnd(T Value) {
		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->Next = NULL;

		if (Head == NULL) {
			NewNode->Perv = NULL;
			Head = NewNode;
		}
		else {
		Node* LastNode = Head;

		while (LastNode != NULL && LastNode->Next != NULL) {
			LastNode = LastNode->Next;
		}

		LastNode->Next = NewNode;
		NewNode->Perv = LastNode;
		}
		
		_Size++;
	}

	void DeleteNode(Node* N1) {
		if (Head == NULL||N1 == NULL)
			return;

		if (Head == N1)
			Head = N1->Next;

		if (N1->Next != NULL)
			N1->Next->Perv = N1->Perv;

		if (N1->Perv != NULL)
			N1->Perv->Next = N1->Next;

		delete N1;
		_Size--;

	}

	void DeleteFirstNode() {
		if (Head == NULL)
			return;

		Node* Temp = Head;
		Head = Head->Next;

		if(Head != NULL)
		Head->Perv = NULL;

		delete Temp;
		_Size--;

	}

	void DeleteLastNode() {
		if (Head == NULL)
			return;

		if (Head->Next == NULL) {
			delete Head;
			Head = NULL;
			return;
		}

		Node* Current = Head;
		while ( Current->Next->Next != NULL) {
		Current = Current->Next;
		}

		Node* LastNode = Current->Next;
		Current->Next = NULL;
		delete LastNode;
		_Size--;

	}

	int Size() {
		return _Size;
	}

	bool IsEmpty() {
		return _Size == 0 ? true : false;
	}

	void Clear() {
		while (_Size > 0) {
			DeleteFirstNode();
		}
	}

	void Reverse() {
		Node* Current = Head;
		Node* Temp = nullptr;

		while(Current != nullptr) {
			Temp = Current->Perv;
			Current->Perv = Current->Next;
			Current->Next = Temp;
			Current = Current->Perv;
		}

		if(Temp != nullptr)
		Head = Temp->Perv;
	}

	Node* GetNode(int Index) {

		if (Index > _Size - 1 || Index < 0)
			return NULL;

		int Counter = 0;
		Node* Temp = Head;
		
		while (Temp != NULL && Temp->Next != NULL) {
			if (Index == Counter)
				break;

			Temp = Temp->Next;
			Counter++;
		}
		return Temp;
	}

	T GetItem(int Index) {
		Node* Node = GetNode(Index);

		if (Node == NULL)
			return NULL;
		else
			return Node->Value;
			
	}

	bool UpdateItem(int Index, T Value) {
		Node* Node = GetNode(Index);
		if (Node == NULL)
			return false;
		else
			Node->Value = Value;

		return true;
	}

	bool InsertAfter(int Index,T Value) {
		Node* Node = GetNode(Index);

		if (Node != NULL) {
			InsertAfter(Node, Value);
			return true;
		}
		else
			return false;
	}
};

