#pragma once
#include <iostream>
#include <string>
#include <stack>

using std::cout;
using std::cin;
using std::endl;


template <typename T>
class Node
{
private:

	Node<T> *pNext;
	T data;	

public:
	
	//Constructors Copy Constructors and Destructors
	Node();
	Node(const T& newData);
	~Node();

	//getters
	T& getData();
	Node<T>* getNext() const;

	//setters
	void setData(const T& newData);
	void setNext(Node<T>* newNext);

	//members 
		//none needed
};

//BELOW ARE THE DECLARATIONS FOR THE FUNCTIONS ABOVE
template<typename T>
inline Node<T>::Node()
{
}

template<typename T>
inline Node<T>::Node(const T& newData)
{
}

template<typename T>
inline Node<T>::~Node()
{
}

template<typename T>
inline T& Node<T>::getData()
{
	// TODO: insert return statement here
}

template<typename T>
inline Node<T>* Node<T>::getNext() const
{
	return nullptr;
}

template<typename T>
inline void Node<T>::setData(const T& newData)
{
}

template<typename T>
inline void Node<T>::setNext(Node<T>* newNext)
{
}
