#include<iostream>
#include<stdlib.h>
using namespace std;

template<typename T>
struct ssnode
{
	T data;
	struct ssnode* next;
};
template<class T>
class singlycir
{
	private:
		struct ssnode<T>* head;
		struct ssnode<T>* tail;
		int size;
	public:
	
		singlycir();
		void insertFirst(T);
		void insertLast(T);
		void insertAtpos(T,int);
		int count();
		void display();
		
		void deleteAtPos(int);
		void deleteFirst();
		void deleteLast();
				
		//~singlycir();
};
template<class T>
singlycir<T>::singlycir()
{
	this->head=NULL;
	tail=NULL;
	this->size=0;
}
template<class T>
void singlycir<T>::deleteFirst()
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
		free(tail->next);
		tail->next=head;
	}
	size--;
}
template<class T>
void singlycir<T>::deleteLast()
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
		struct ssnode<T>* temp=head;
		struct ssnode<T>* temp1=tail;
		
		while(temp->next->next!=head)
		{
			temp=temp->next;
		}
		tail=temp;
		tail->next=head;
		free(temp1);
	}
	size--;
}

template<class T>
void singlycir<T>::deleteAtPos(int pos)
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
		struct ssnode<T>* temp=head;
		struct ssnode<T>* temp1=NULL;
		
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=temp1->next;
		free(temp1);
		size--;
	}
	
}

template<class T>
void singlycir<T>::insertFirst(T no)
{
	struct ssnode <T> *newn=(struct ssnode<T> *)malloc(sizeof(struct ssnode<T>));
	newn->next=NULL;
	newn->data=no;
	
	if(this->head==NULL)
	{
		head=newn;
		tail=newn;
		tail->next=head;
	}
	else
	{
		newn->next=head;
		head=newn;
		tail->next=head;
			
	}
	size++;
}
template<class T>
void singlycir<T>::insertLast(T no)
{
	struct ssnode <T> *newn=(struct ssnode<T> *)malloc(sizeof(struct ssnode<T>));
	newn->next=NULL;
	newn->data=no;
	if(this->head==NULL)
	{
		head=newn;
		tail=newn;
		tail->next=head;
	}
	else
	{
		tail->next=newn;
		tail=newn;
		tail->next=head;
				
	}
	size++;
}
template<class T>
void singlycir<T>::insertAtpos(T no,int pos)
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
		struct ssnode <T> *newn=(struct ssnode<T> *)malloc(sizeof(struct ssnode<T>));
		newn->next=NULL;
		newn->data=no;
			
		struct ssnode<T>* temp=head;
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		size++;
	}
}
template<class T>
void singlycir<T>::display()
{
	struct ssnode<T>* temp=head;
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
/*singlycir::~singlycir()
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
int singlycir<T>::count()
{
	return size;
}
int main()
{
	cout<<"\n----------------------------------------------------\n";
	cout<<"*********singly circular linked list************";
	cout<<"\n----------------------------------------------------\n";
	singlycir <int>ssobj;
	ssobj.insertFirst(51);
	ssobj.insertFirst(31);
	ssobj.insertFirst(21);
	ssobj.insertFirst(15);
	ssobj.insertFirst(11);
	ssobj.insertFirst(8);
	ssobj.display();
	cout<<ssobj.count()<<"\n";
	ssobj.insertLast(61);
	ssobj.display();
	cout<<ssobj.count()<<"\n";
	ssobj.insertAtpos(13,3);
	ssobj.insertAtpos(611,7);
	ssobj.display();
	cout<<ssobj.count()<<"\n";
	cout<<"\n\n\n";
	
	ssobj.deleteFirst();
	ssobj.display();
	cout<<"\n";
	ssobj.deleteLast();
	ssobj.display();
	cout<<"\n";
	ssobj.deleteAtPos(3);
	ssobj.display();
	cout<<"\n";
	cout<<"\n----------------------------------------------------\n";
		
	return 0;
}
