#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
struct tnode
{
	T data;
	struct tnode * lchild;
	struct tnode * rchild;	
};

template<class T>
class tree
{
	private:
		struct tnode <T>* head;
		
	public:
		struct tnode <T>* temp1;
		
		tree();	
		void insert(T);
		void inorder(struct tnode <T>*);
		void preorder(struct tnode <T>*);
		void postorder(struct tnode <T>*);
		
};

template<class T>
tree<T>::tree()
{
	head=NULL;
	temp1=NULL;
}

template<class T>
void tree<T>::insert(T no)
{
	struct tnode <T>* newn=(struct tnode <T>*)malloc(sizeof(struct tnode<T>));
	newn->data=no;
	newn->lchild=NULL;
	newn->rchild=NULL;
	
	if(head==NULL)
	{
		head=newn;
		temp1=head;
	}
	else
	{
		struct tnode <T>* temp=head;
		while(1)
		{
			if(no>temp->data)
			{
				if(temp->rchild==NULL)
				{
					temp->rchild=newn;
					break;
				}
				temp=temp->rchild;
			}
			else if(no<temp->data)
			{
				if(temp->lchild==NULL)
				{
					temp->lchild=newn;
					break;
				}
				temp=temp->lchild;
			}
			else
			{
				free(newn);
				break;
			}
		}
	}
}

template<class T>
void tree<T>::inorder(struct tnode <T>* temp)
{
	if(temp!=NULL)
	{
		inorder(temp->lchild);
		cout<<" "<<temp->data;
		inorder(temp->rchild);
	}
	
}

template<class T>
void tree<T>::preorder(struct tnode <T>* temp)
{
	if(temp!=NULL)
	{
		cout<<" "<<temp->data;
		inorder(temp->lchild);
		inorder(temp->rchild);
	}
	
}

template<class T>
void tree<T>::postorder(struct tnode <T>* temp)
{
	if(temp!=NULL)
	{
		inorder(temp->lchild);
		inorder(temp->rchild);
		cout<<" "<<temp->data;
	}
	
}
int main()
{
	tree <int>tobj;
	
	tobj.insert(30);
	tobj.insert(10);
	tobj.insert(40);
	tobj.insert(60);
	tobj.insert(1);
	cout<<"Inorder:";
	tobj.inorder(tobj.temp1);
	cout<<"\npreorder:";
	tobj.preorder(tobj.temp1);
	cout<<"\nPostorder:";
	tobj.postorder(tobj.temp1);
	cout<<"\n";
	return 0;
}
