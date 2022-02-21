#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
struct Qnode
{
	T data;
	struct Qnode * next;	
};
template<class T>
class Queue
{
	private:
		struct Qnode <T>* head;
		struct Qnode <T>* tail;
	public:
		Queue();
		//~Queue();
		void Enqueue(T no);
		T Dequeue();
		void Display();
		 
};
template<class T>
Queue<T>::Queue()
{
	head=NULL;
	tail=NULL;
}
template<class T>
void Queue<T>::Enqueue(T no)
{
	struct Qnode <T>* newn=(struct Qnode <T>*)malloc(sizeof(struct Qnode<T>));
	newn->data=no;
	newn->next=NULL;
	
	if((head==NULL)&&(tail==NULL))
	{
		head=tail=newn;
	}
	else
	{
		tail->next=newn;
		tail=newn;
	}
}

template<class T>
T Queue<T>::Dequeue()
{
	if((head==NULL)&&(tail==NULL))
	{
		cout<<"Queue is Empty...";
		return -1;
	}
	if(head==tail)
	{
		T iRet=head->data;
		free(head);
		head=NULL;
		tail=NULL;
		return iRet;
	}
	else
	{
		T iRet=head->data;
		struct Qnode <T>* temp=head;
		head=head->next;
		free(temp);
		return iRet; 
	}
}
template<class T>
void Queue<T>::Display()
{
	struct Qnode <T>* temp=head;
	cout<<"\nQueue Element ";
	while(temp!=NULL)
	{
		cout<<" "<<temp->data;
		temp=temp->next;
	}
	cout<<"\n";
		
}
		
		
int main()
{
	Queue <char>qobj;
	qobj.Enqueue('x');
	qobj.Enqueue('y');
	qobj.Enqueue('z');
	qobj.Enqueue('a');
	
	qobj.Display();
	cout<<" "<<qobj.Dequeue();
	cout<<" "<<qobj.Dequeue();
	cout<<" "<<qobj.Dequeue();
	cout<<" "<<qobj.Dequeue();
	return 0;	
}
