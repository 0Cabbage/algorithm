#include "StackNode.h"

template<typename Type> class LinkStack{
public:
	LinkStack():m_ptop(NULL){}
	~LinkStack(){
		MakeEmpty();
	}

public:
	void MakeEmpty();           //make the stack empty
	void Push(const Type item); //push the data
	Type Pop();                 //pop the data
	Type GetTop() const;        //get the data
    void Print();               //print the stack
        
	bool IsEmpty() const{
		return m_ptop==NULL;
	}
	
private:
	StackNode<Type> *m_ptop;
};

template<typename Type> void LinkStack<Type>::MakeEmpty(){
	StackNode<Type> *pmove;
	while(m_ptop!=NULL){
		pmove=m_ptop;
		m_ptop=m_ptop->m_pnext;
		delete pmove;
	}
}

template<typename Type> void LinkStack<Type>::Push(const Type item){
	m_ptop=new StackNode<Type>(item,m_ptop);
}

template<typename Type> Type LinkStack<Type>::GetTop() const{
	if(IsEmpty()){
		cout<<"There is no elements!"<<endl;
		exit(1);
	}
	return m_ptop->m_data;
}

template<typename Type> Type LinkStack<Type>::Pop(){
	if(IsEmpty()){
		cout<<"There is no elements!"<<endl;
		exit(1);
	}
	StackNode<Type> *pdel=m_ptop;
	m_ptop=m_ptop->m_pnext;
	Type temp=pdel->m_data;
	delete pdel;
	return temp;
}

template<typename Type> void LinkStack<Type>::Print(){
	StackNode<Type> *pmove=m_ptop;
	cout<<"buttom";
	while(pmove!=NULL){
		cout<<"--->"<<pmove->m_data;
		pmove=pmove->m_pnext;
	}
	cout<<"--->top"<<endl<<endl<<endl;
}

Test.cpp

#include <iostream>
using namespace std;

#include "LinkStack.h"

int main(){
	LinkStack<int> stack;
	int init[10]={1,3,5,7,4,2,8,0,6,9};
	for(int i=0;i<10;i++){
		stack.Push(init[i]);
	}
	stack.Print();

	cout<<stack.Pop()<<endl;
	stack.Print();
	
	cout<<stack.GetTop()<<endl;
	stack.Print();

	cout<<stack.Pop()<<endl;
	stack.Print();

	stack.MakeEmpty();
	stack.Print();
	
	stack.Pop();


	return 0;
}
