#include<iostream>
#include<stdlib.h>
using namespace std;
template<typename T>
struct dnode
{
	T data;
	struct dnode * next;
	struct dnode * prev;
	
};
template<class T>
class dublyll
{
	private:
		struct dnode<T>* Head;
		int size;
	public:
		dublyll();
		//~dublyll();
		void insertFirst(T);
		void insertLast(T);
		void insertAtPos(T,int);
		void deleteAtPos(int);
		void deleteFirst();
		void deleteLast();
		int Count();
		void DisplayF();
		void DisplayB();
};
template<class T>
void dublyll<T>::deleteAtPos(int pos)
{
	if((pos<1)||(pos>size))
	{
		return;
	}
	if(pos==1)
	{
		this->deleteFirst();
	}
	else if(pos==size)
	{
		deleteLast();
	}
	else
	{
		struct dnode<T>* temp=Head;
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		free(temp->next->prev);
		temp->next->prev=temp;
		size--;
	}
	
}
template<class T>
void dublyll<T>::insertAtPos(T no,int pos)
{
	if((pos<1)||(pos>size+1))
	{
		return;
	}
	if(pos==1)
	{
		this->insertFirst(no);	
	}
	else if(pos==size+1)
	{
		this->insertLast(no);
	}
	else
	{
		struct dnode <T> *newn=(struct dnode<T> *)malloc(sizeof(struct dnode<T>));
		newn->next=NULL;
		newn->data=no;
		newn->prev=NULL;
		
		struct dnode<T>* temp=Head;
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
		size++;
	}
}
/*template<class T>
dublyll::~dublyll()
{
	PNODE temp;
	while(Head!=NULL)
	{
		temp=Head;
		Head=Head->next;
		delete temp;
	}
}*/
template<class T>
dublyll<T>::dublyll()
{
	this->Head=NULL;
	this->size=0;
}
template<class T>
void dublyll<T>::insertFirst(T no)
{
	struct dnode <T> *newn=(struct dnode<T> *)malloc(sizeof(struct dnode<T>));
	newn->next=NULL;
	newn->data=no;
	newn->prev=NULL;
	if(this->Head==NULL)
	{
		Head=newn;
	}
	else
	{
		newn->next=Head;
		Head->prev=newn;
		Head=newn;
	}
	size++;
}
template<class T>
void dublyll<T>::insertLast(T no)
{
	struct dnode <T> *newn=(struct dnode<T> *)malloc(sizeof(struct dnode<T>));
	newn->next=NULL;
	newn->data=no;
	newn->prev=NULL;
	if(this->Head==NULL)
	{
		Head=newn;
	}
	else
	{
		struct dnode<T>* temp=Head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->prev=temp;
	}
	size++;
}
template<class T>
void dublyll<T>::deleteFirst()
{
	if(Head==NULL)
	{
		return;
	}
	else if(Head->next==NULL)
	{
		free(Head);
		Head=NULL;
	}
	else
	{
		Head=Head->next;
		free(Head->prev);
		Head->prev=NULL;
	}
	size--;
}
template<class T>
void dublyll<T>::deleteLast()
{
	if(Head==NULL)
	{
		return;
	}
	else if(Head->next==NULL)
	{
		free(Head);
		Head=NULL;
	}
	else
	{
		struct dnode<T>* temp=Head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp);
	}
	size--;
}
template<class T>
void dublyll<T>::DisplayF()
{
	struct dnode<T>* temp=Head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
}
template<class T>
void dublyll<T>::DisplayB()
{
	struct dnode<T>* temp=Head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->prev;
	}
}
template<class T>
int dublyll<T>::Count()
{
	return size;
}
int main()
{

	cout<<"\n----------------------------------------------------\n";
	cout<<"************Doubly Linked List*************";
	cout<<"\n----------------------------------------------------\n";	
	dublyll <char>dobj1;
	dobj1.insertFirst('d');
	dobj1.insertFirst('b');
	dobj1.insertFirst('a');
	dobj1.DisplayF();
	cout<<"\n";
	dobj1.insertAtPos('c',3);
	dobj1.DisplayF();
	cout<<"\n";
	dobj1.deleteAtPos(3);
	dobj1.DisplayF();
	cout<<"\n"<<dobj1.Count();
	cout<<"\n";
	dobj1.DisplayB();
	cout<<"\n";
	dobj1.insertLast('e');
	dobj1.DisplayF();
	cout<<"\n";
	dobj1.deleteFirst();
	dobj1.DisplayF();
	cout<<"\n";
	dobj1.deleteLast();
	dobj1.DisplayF();
	cout<<"\n"<<dobj1.Count();
	
	cout<<"\n";
	cout<<"\n----------------------------------------------------\n";
	return 0;
	
}
