#include "ListNode.h"

template<typename Type>
class singleList{
public:
	singleList() :head(new listNode<Type>()){}
	~singleList(){
		makeEmpty();
		delete head;
	}
public:
	void makeEmpty();
	int Length();
	listNode<Type>*Find(Type value, int n);
	listNode<Type>*Find(int n);
	bool Insert(Type item, int n = 0);
	Type Remove(int n = 0);
	bool RemoveAll(Type item);
	Type Get(int n);
	void Print();
private:
	listNode<Type> *head;
};

template<typename Type>
void singleList<Type>::makeEmpty(){
	listNode<Type> *pdel;
	while (head->m_pnext != NULL){
		pdel = head->m_pnext;
		head->m_pnext = pdel->m_pnext;
		delete pdel;
	}
}

template<typename Type>
int singleList<Type>::Length(){
	listNode<Type> *pmove = head->m_pnext;
	int count = 0;
	while (pmove != NULL){
		pmove = pmove->m_pnext;
		count++;
	}
	return count;
}

template<typename Type>
listNode<Type>* singleList<Type>::Find(int n){
	if (n < 0){
		cout << "The n is out of boundary" << endl;
		return NULL;
	}

	listNode<Type> *pmove = head->m_pnext;
	for (int i = 0; i < n && pmove; i++){
		pmove = pmove->m_pnext;
	}

	if (NULL == pmove){
		cout << "The n is out of boundary" << endl;
		return NULL;
	}
	return pmove;
}

template<typename Type>
listNode<Type>* singleList<Type>::Find(Type value, int n){
	if (n < 1 || n > this->Length() - 1){
		cout << "The n is illegal" << endl;
		return NULL;
	}

	listNode<Type> *pmove = head;
	/*for (int count = 0; count != n && pmove;){
		pmove = pmove->m_pnext;
		if (pmove->m_data == value){
			count++;
		}
	}*/

	int count = 0;
	while (count != n && pmove){
		pmove = pmove->m_pnext;
		if (pmove->m_data == value){
			count++;
		}
	}

	if (pmove == NULL){
		cout << "can't find the element" << endl;
		return NULL;
	}

	return pmove;
}


template<typename Type>
bool singleList<Type>::Insert(Type item, int n){
	if (n < 0){
		cout << "The n is illegal" << endl;
		return false;
	}

	listNode<Type> *pmove = head;
	listNode<Type> *pnode = new listNode<Type>(item);
	if (pnode == NULL){
		cout << "Application error" << endl;
		return false;
	}

	for (int i = 0; i < n && pmove; i++){
		pmove = pmove->m_pnext;
	}

	if (pmove == NULL){
		cout << "the n is illegal" << endl;
		return false;
	}

	pnode->m_pnext = pmove->m_pnext;
	pmove->m_pnext = pnode;
	return true;
}

template<typename Type>
bool singleList<Type>::RemoveAll(Type item){
	listNode<Type> *pmove = head;
	listNode<Type> *pdel = head->m_pnext;
	while (pdel != NULL){
		if (pdel->m_data == item){
			pmove->m_pnext = pdel->m_pnext;
			delete pdel;
			pdel = pmove->m_pnext;
			continue;
		}

		pmove = pmove->m_pnext;
		pdel = pdel->m_pnext;
	}

	return true;
}

template<typename Type>
Type singleList<Type>::Remove(int n){
	if (n < 0){
		cout << "can't find the element" << endl;
		exit(1);
	}

	listNode<Type> *pmove = head, *pdel;
	for (int i = 0; i < n && pmove->m_pnext; i++){
		pmove = pmove->m_pnext;
	}

	if (pmove->m_pnext == NULL){
		cout << "can't find the element" << endl;
		exit(1);
	}

	pdel = pmove->m_pnext;
	pmove->m_pnext = pdel->m_pnext;
	Type temp = pdel->m_data;
	delete pdel;

	return temp;
}

template<typename Type> Type singleList<Type>::Get(int n){
	if (n<0){
		cout << "The n is out of boundary" << endl;
		exit(1);
	}
	listNode<Type> *pmove = head->m_pnext;
	for (int i = 0; i < n; i++){
		pmove = pmove->m_pnext;
		if (NULL == pmove){
			cout << "The n is out of boundary" << endl;
			exit(1);
		}
	}
	return pmove->m_data;
}

template<typename Type> void singleList<Type>::Print(){
	listNode<Type> *pmove = head->m_pnext;
	cout << "head";
	while (pmove){
		cout << "--->" << pmove->m_data;
		pmove = pmove->m_pnext;
	}
	cout << "--->over" << endl << endl << endl;
}
