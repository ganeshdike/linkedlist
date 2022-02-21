#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
struct Stnode
{
	T data;
	struct Stnode * next;
};
template<class T>
class Stack
{
	private:
		struct Stnode<T>* head;
	public:
		Stack()
		{
			head=NULL;
		}
		void push(T);
		T pop();
		
};
template<class T>
void Stack<T>::push(T no)
{
	struct Stnode <T> * newn=(struct Stnode <T> *)malloc(sizeof(struct Stnode<T>));
	newn->data=no;
	newn->next=NULL;
	if(head==NULL)
	{
		head=newn;
	}
	else
	{
		newn->next=head;
		head=newn;
	}
	
}
template<class T>
T Stack<T>::pop()
{
	if(head==NULL)
	{
		cout<<"\nStack is Empty...";
		return NULL;
	}
	else
	{
		T no=head->data;
		struct Stnode <T> * temp=head;
		
		head=head->next;
		free(temp);
		return no;
		
	}
}
int main()
{
	
	Stack <int>st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout<<"\n"<<st.pop();
	cout<<"\n"<<st.pop();
	cout<<"\n"<<st.pop();
	cout<<"\n"<<st.pop()<<"\n";
	return 0;
}
