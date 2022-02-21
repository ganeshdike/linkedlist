#include<iostream>
#include<stdlib.h>
using namespace std;

template<typename T>
struct dsnode
{
	T data;
	struct dsnode* next;
	struct dsnode* prev;
};
template<class T>
class dublyc
{
	private:
		struct dsnode<T>* head;
		struct dsnode<T>* tail;
		int size;
	public:
	
		dublyc();
		void insertFirst(T);
		void insertLast(T);
		void insertAtpos(T,int);
		int count();
		void display();
		
		void deleteAtPos(int);
		void deleteFirst();
		void deleteLast();
				
		//~dublyc();
};
template<class T>
dublyc<T>::dublyc()
{
	this->head=NULL;
	tail=NULL;
	this->size=0;
}
template<class T>
void dublyc<T>::deleteFirst()
{
	if(head==NULL)
	{
		return;
	}
	else if(head->next==NULL)
	{
		free(head);
		head=NULL;
		tail=NULL;
	}
	else
	{
		head=head->next;
		free(head->prev);
		head->prev=tail;
		tail->next=head;
	}
	size--;
}
template<class T>
void dublyc<T>::deleteLast()
{
	if(head==NULL)
	{
		return;
	}
	else if(head->next==NULL)
	{
		free(head);
		head=NULL;
		tail=NULL;
	}
	else
	{
		struct dsnode<T>* temp=tail;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		tail=temp->prev;
		tail->next=head;
		head->prev=tail;
		free(temp);
	}
	size--;
}

template<class T>
void dublyc<T>::deleteAtPos(int pos)
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
		struct dsnode<T>* temp=head;
		for(int i=1;i<pos;i++)
		{
			temp=temp->next;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
		size--;
	}
	
}

template<class T>
void dublyc<T>::insertFirst(T no)
{
	struct dsnode <T> *newn=(struct dsnode<T> *)malloc(sizeof(struct dsnode<T>));
	newn->next=NULL;
	newn->data=no;
	newn->prev=NULL;
	
	if(this->head==NULL)
	{
		head=newn;
		tail=newn;
		tail->next=head;
		head->prev=tail;
	}
	else
	{
		newn->next=head;
		head->prev=newn;
		head=newn;
		tail->next=head;
		head->prev=tail;		
	}
	size++;
}
template<class T>
void dublyc<T>::insertLast(T no)
{
	struct dsnode <T> *newn=(struct dsnode<T> *)malloc(sizeof(struct dsnode<T>));
	newn->next=NULL;
	newn->data=no;
	newn->prev=NULL;
	if(this->head==NULL)
	{
		head=newn;
		tail=newn;
		tail->next=head;
		head->prev=tail;
	}
	else
	{
		newn->next=head;
		head->prev=newn;
		tail->next=newn;
		newn->prev=tail;
		tail=newn;		
	}
	size++;
}
template<class T>
void dublyc<T>::insertAtpos(T no,int pos)
{
	if((pos<0)||(pos>size+1))
	{
		return;
	}
	if(pos==1)
	{
		insertFirst(no);
	}
	else if(pos>size)
	{
		insertLast(no);	
	}
	else
	{
		struct dsnode <T> *newn=(struct dsnode<T> *)malloc(sizeof(struct dsnode<T>));
		newn->next=NULL;
		newn->data=no;
		newn->prev=NULL;
	
		struct dsnode<T>* temp=head;
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
template<class T>
void dublyc<T>::display()
{
	struct dsnode<T>* temp=head;
	if((head==NULL)&&(tail==NULL))
	{
		return;
	}
	do
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}while(temp!=tail->next);
}
/*dublyc::~dublyc()
{
	PNODE temp=head;
	if((head==NULL)&&(tail==NULL))
	{
		return;
	}
	do
	{
		temp=head;
		head=head->next;
		cout<<"\n"<<temp->data;
		delete temp;
		
	}while(head!=tail->next);
}*/
template<class T>
int dublyc<T>::count()
{
	return size;
}
int main()
{
	cout<<"\n----------------------------------------------------\n";
	cout<<"*************Doubly Circular*************";
	cout<<"\n----------------------------------------------------\n";
	dublyc <char>dsobj;
	dsobj.insertFirst('e');
	dsobj.insertFirst('d');
	dsobj.insertFirst('c');
	dsobj.insertFirst('b');
	dsobj.insertFirst('a');
	dsobj.insertFirst('p');
	dsobj.display();
	cout<<dsobj.count()<<"\n";
	dsobj.insertLast('z');
	dsobj.display();
	cout<<dsobj.count()<<"\n";
	dsobj.insertAtpos('g',3);
	dsobj.insertAtpos('k',7);
	dsobj.display();
	cout<<dsobj.count()<<"\n";
	cout<<"\n\n\n";
	
	dsobj.deleteFirst();
	dsobj.display();
	cout<<"\n";
	dsobj.deleteLast();
	dsobj.display();
	cout<<"\n";
	dsobj.deleteAtPos(3);
	dsobj.display();
	cout<<"\n";
	cout<<"\n----------------------------------------------------\n";	
	return 0;
}
