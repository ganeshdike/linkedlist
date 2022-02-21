#include<iostream>
#include<stdio.h>
#include<stdlib.h>
template<typename T>
struct node
{
	T data;
	struct node * next;
};

template<class T>
class singly
{
	private:
		struct node<T>* head;
		int size;
		
	public:
		singly();
		void addfirst(T);
		void addlast(T);
		
		void deletefirst();
		void deletelast();
		
		void insertAtpos(T,int);
		void deleteAtpos(int);
		
		void Display();
};
template<class T>
singly<T>::singly()
{
	head=NULL;
	size=0;
}
template<class T>
void singly<T>::insertAtpos(T no,int pos)
{
	if((pos<1)&&(pos>size+1))
	{
		return;
	}
	if(pos==1)
	{
		addfirst(no);
	}
	else if(pos==size+1)
	{
		addlast(no);
	}
	else
	{
		struct node<T> *newnode=(struct node<T>*)malloc(sizeof(struct node<T>));
		newnode->next=NULL;
		newnode->data=no;
		struct node <T> *temp=head;
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
		size++;
	}
}

template<class T>
void singly<T>::deleteAtpos(int pos)
{
	if((pos<1)&&(pos>size))
	{
		return;
	}
	if(pos==1)
	{
		deletefirst();
	}
	else if(pos==size)
	{
		deletelast();
	}
	else
	{
		struct node <T> *temp=head;
		struct node <T> *temp1=NULL;
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=temp->next->next;
		size--;
	}
}


template<class T>
void singly<T>::addfirst(T no)
{
	struct node<T> *newnode=(struct node<T>*)malloc(sizeof(struct node<T>));
	newnode->next=NULL;
	newnode->data=no;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
	size++;
}		
template<class T>
void singly<T>::addlast(T no)
{
	struct node <T> *newnode=(struct node<T> *)malloc(sizeof(struct node<T>));
	newnode->next=NULL;
	newnode->data=no;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		struct node <T> *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}	
		temp->next=newnode;
	}
	size++;
}
template<class T>
void singly<T>::deletefirst()
{
	if(head==NULL)
	{
		return;
	}	
	else
	{
		struct node<T>* temp=head;
		head=head->next;
		free(temp);
		
	}
	size--;
}

template<class T>
void singly<T>::deletelast()
{
	if(head==NULL)
	{
		return;
	}	
	if(head->next==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{
		struct node<T>* temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
	size--;
}

template<class T>
void singly<T>::Display()
{
	struct node<T>* temp=head;
	while(temp!=NULL)
	{
		std::cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main()
{
	std::cout<<"\n----------------------------------------------------\n";
	std::cout<<"*************Singly Linked List**************";
	std::cout<<"\n----------------------------------------------------\n";
	singly <int>sobj;
	sobj.addfirst(10);
	sobj.addfirst(20);
	sobj.addfirst(30);
	sobj.addfirst(40);
	sobj.addlast(5);
	sobj.Display();
	std::cout<<"\n";
	
	sobj.insertAtpos(50,2);
	sobj.Display();
	std::cout<<"\n";
	
	sobj.deleteAtpos(2);
	sobj.Display();
	std::cout<<"\n";
	
	sobj.deletelast();
	sobj.Display();
	
	std::cout<<"\n";
	sobj.deletefirst();
	sobj.deletefirst();
	sobj.Display();
	singly <char>sobj1;
	sobj1.addfirst('c');
	sobj1.addfirst('d');
	sobj1.addfirst('e');
	sobj1.addfirst('f');
	sobj1.Display();
	std::cout<<"\n----------------------------------------------------\n";	
	return 0;
}
