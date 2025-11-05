#pragma once
#include <iostream>
#include <string>
#include <stack>
#include "Node.h"
#include "Data.h"

using std::string;
using std::stack;
using std::cout;
using std::cin;
using std::endl;


template <typename T>
class List
{
private:

	Node<T>* pHead;

public:

	//Constructors Copy Constructors and Destructors
	List();
	~List();


	//getters
	Node<T>* getHead() const;

	//setters
	void setHead(Node<T>* newHead);
	//members
	void insertAtFront(const T& newData);
	bool isEmpty();
	bool destroyList();
	void markAbsences(const string& date);


};

template<typename T>
inline List<T>::List()
{
	pHead = nullptr;
}

template<typename T>
inline List<T>::~List()
{
	destroyList();
	//cout << "Destructor Activated" << endl; //Remember to delete this
}

template<typename T>
inline Node<T>* List<T>::getHead() const
{
	return this->pHead;
}

template<typename T>
inline void List<T>::setHead(Node<T>* newHead)
{
	pHead = newHead;
}

template<typename T>
inline void List<T>::insertAtFront(const T& newData)
{
	Node<T>* pNew = new Node<T>(newData);

	pNew->setNext(pHead);
	pHead = pNew;
}

template<typename T>
inline bool List<T>::isEmpty()
{
	return pHead == nullptr;
}

template<typename T>
inline bool List<T>::destroyList()
{
	while (pHead)
	{
		Node<T>* pTemp = pHead;
		pHead = pHead->getNext();
		delete pTemp;
	}
	return true;
}

template<typename T>
inline void List<T>::markAbsences(const string& date)
{
	if (isEmpty())
	{
		cout << "List Empty" << endl;
		return;
	}

	Node<T>* pCur = pHead;

	while (pCur)
	{
		T& Student = pCur->getData();
		char dec;

		cout << "Is " << Student.getName() << " absent?"; cout << "(Y) Yes or (N) No: ";
		cin >> dec;

		if (dec == 'Y' || dec == 'y')
		{
			Student.pushAbsences_Date(date);
			Student.setAbsences_Num(Student.getAbsences_Num() + 1);

		}
		else if (dec == 'N' || dec == 'n')
		{
			cout << "Canceling. . ." << endl;
		}
		pCur = pCur->getNext();
	}
}