#include "stdafx.h"

template<typename Type> class singleList;
template<typename Type> class listNode{
private:
	friend typename singleList<Type>;

	listNode() :m_pnext(NULL){}
	listNode(const Type item, listNode<Type> *next = NULL) :m_data(item), m_pnext(next){}

	~listNode(){
		m_pnext = NULL;
	}
public:
	Type getData();
	friend ostream& operator<< <Type>(ostream&, listNode<Type>&);
private:
	Type m_data;
	listNode *m_pnext;
};

template<typename Type>
Type listNode<Type>::getData(){
	return this->m_data;
}

template<typename Type>
ostream& operator<< (ostream& os, listNode<Type>& out){
	os << out.m_data;
	return os;
}
