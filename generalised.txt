 #include<iostream>
#include<stdlib.h>

using namespace std;

template<typename T>
struct node
{
	T data;
	struct node * next;
};

template<typename T>
struct ssnode
{
	T data;
	struct ssnode* next;
};

template<typename T>
struct dnode
{
	T data;
	struct dnode * next;
	struct dnode * prev;
	
};

template<typename T>
struct dsnode
{
	T data;
	struct dsnode* next;
	struct dsnode* prev;
};

template<class T>
struct Stnode
{
	T data;
	struct Stnode * next;
};

template<class T>
struct Qnode
{
	T data;
	struct Qnode * next;	
};

template<class T>
struct tnode
{
	T data;
	struct tnode * lchild;
	struct tnode * rchild;	
};

////////////////////////////////////////////////////////////////////////
//
// class Name  ::  singly
// Discription ::  this class represent singly linear LinkedList
//
////////////////////////////////////////////////////////////////////////
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
		void search(T);
		void Display();
};
////////////////////////////////////////////////////////////////////////
//
// Function Name   :: singly
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: NONE
// Description     :: This is Constructor of class singly
// Returns         :: NONE
//
////////////////////////////////////////////////////////////////////////
template<class T>
singly<T>::singly()
{
	head=NULL;
	size=0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: insertAtpos
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function Add Node from specified position in singly Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////
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


//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: search
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function search element in singly Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void singly<T>::search(T no)
{
	struct node<T>* temp=head;
	while(temp!=NULL)
	{
		if(no==temp->data)
		{
			break;
		}
		
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"\nNOT FOUND\n";
	}
	else
	{
		cout<<"\nFOUND\n";
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: deleteAtpos
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function Delete Node from specified position in singly Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: addfirst
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function Add Node first position in singly Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: addlast
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function Add Node last position in singly Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: deletefirst
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function delete Node first position in singly Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: deletelast
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function delete Node last position in singly Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: Display
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function Display all node in singly Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////
//
// class Name  ::  singly
// Discription ::  this class represent singly circular linear LinkedList
//
////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: singlycir
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: NONE
// Description     :: This is Constructor of class singly circular linkedlist
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
singlycir<T>::singlycir()
{
	this->head=NULL;
	tail=NULL;
	this->size=0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: deleteFirst
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function delete Node First position in singly circular Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: deleteLast
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function delete Node last position in singly circular Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: deleteAtPos
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function delete Node specified position in singly circular Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: insertFirst
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function Insert First Node position in singly circular Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: InsertLast
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function Insert Node last position  in singly circular Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: insertAtpos
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function Insert Node specified position  in singly circular Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name   :: display
// Function Date   :: 14/11/2019
// Function Author :: Ganesh Dike
// Parameters      :: 
// Description     :: This Function Display All element in singly circular Linear LinkedList
// Returns         :: NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////

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
		void Display();
		
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
		return 0;
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

template<class T>
void Stack<T>::Display()
{
	struct Stnode <T>* temp=head;
	cout<<"\nStack Element ";
	while(temp!=NULL)
	{
		cout<<" "<<temp->data;
		temp=temp->next;
	}
	cout<<"\n";
		
}


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
	sobj.search(30);
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
	
	cout<<"\n----------------------------------------------------\n";	
	cout<<"************* Stack *************";
	cout<<"\n----------------------------------------------------\n";
	Stack <int>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.Display();
	cout<<"pop element is:";
	cout<<" "<<st.pop();
	cout<<" "<<st.pop();
	cout<<" "<<st.pop();
	cout<<"\n"<<st.pop()<<"\n";
	
	Stack <char>st1;
	st1.push('A');
	st1.push('B');
	st1.push('C');
	st1.Display();
	cout<<"pop element is:";
	cout<<" "<<st1.pop();
	cout<<" "<<st1.pop();
	cout<<" "<<st1.pop();
	cout<<" "<<st1.pop()<<"\n";
	cout<<"\n----------------------------------------------------\n";	
	
	cout<<"\n----------------------------------------------------\n";	
	cout<<"************* Queue *************";
	cout<<"\n----------------------------------------------------\n";	
	Queue <char>qobj;
	qobj.Enqueue('x');
	qobj.Enqueue('y');
	qobj.Enqueue('z');
	qobj.Enqueue('a');
	
	qobj.Display();
	cout<<"Dequeue element is:";
	cout<<" "<<qobj.Dequeue();
	cout<<" "<<qobj.Dequeue();
	cout<<" "<<qobj.Dequeue();
	cout<<" "<<qobj.Dequeue();
	cout<<"\n----------------------------------------------------\n";	
	
	cout<<"\n----------------------------------------------------\n";	
	cout<<"************* Tree *************";
	cout<<"\n----------------------------------------------------\n";	
	
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
	cout<<"\n----------------------------------------------------\n";	
	
			
	return 0;
}

/*
dell@ubuntu:~/linkedlist$ g++ generalised.cpp -o myexe 
dell@ubuntu:~/linkedlist$ ./myexe 

----------------------------------------------------
*************Singly Linked List**************
----------------------------------------------------
40 30 20 10 5 

FOUND
40 50 30 20 10 5 
40 30 20 10 5 
40 30 20 10 
20 10 f e d c 
----------------------------------------------------

----------------------------------------------------
*********singly circular linked list************
----------------------------------------------------
8	11	15	21	31	51	6
8	11	15	21	31	51	61	7
8	11	13	15	21	31	611	51	61	9



11	13	15	21	31	611	51	61	
11	13	15	21	31	611	51	
11	13	21	31	611	51	

----------------------------------------------------

----------------------------------------------------
************Doubly Linked List*************
----------------------------------------------------
a	b	d	
a	b	c	d	
a	b	d	
3
d	b	a	
a	b	d	e	
b	d	e	
b	d	
2

----------------------------------------------------

----------------------------------------------------
*************Doubly Circular*************
----------------------------------------------------
p	a	b	c	d	e	6
p	a	b	c	d	e	z	7
p	a	g	b	c	d	k	e	z	9



a	g	b	c	d	k	e	z	
a	g	b	c	d	k	e	
a	g	c	d	k	e	

----------------------------------------------------

----------------------------------------------------
************* Stack *************
----------------------------------------------------

Stack Element  3 2 1
pop element is: 3 2 1
Stack is Empty...
0

Stack Element  C B A
pop element is: C B A
Stack is Empty... 

----------------------------------------------------

----------------------------------------------------
************* Queue *************
----------------------------------------------------

Queue Element  x y z a
Dequeue element is: x y z a
----------------------------------------------------

----------------------------------------------------
************* Tree *************
----------------------------------------------------
Inorder: 1 10 30 40 60
preorder: 30 1 10 40 60
Postorder: 1 10 40 60 30

----------------------------------------------------
dell@ubuntu:~/linkedlist$
*/ 

