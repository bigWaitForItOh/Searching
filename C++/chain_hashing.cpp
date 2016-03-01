/*
EXAMPLE CODE FOR CHAIN-HASHING

--------------HEADER FILES---------------
iostream:  I/O
cstdio:	   getchar()
cstdlib:   exit()
string:	   C++ string functions
-----------------------------------------
----------------------------EXPLANATION-------------------------------------
SCENARIO: person_id is an integer from 2-200, 
		  divisible by at least one of the first 4 prime numbers,
		  i.e.	S={2,3,5,7}
		  
		  HASH_FN(key) =  key/(smallest of S which is a prime factor of key)
		  KEY: person_id
		  
		  If more than one person_id maps to same slot index, 
		  entries are chained with linkedlist
----------------------------------------------------------------------------
----------------------TIME COMPLEXITY--------------------------
LOAD FACTOR: n/k = 200/100 = 2 entries on avg per slot

Key can be mapped in constant time.
First element of linkedlist can be accessed in constant time.
Element has to be searched linearly across avg 2 elements.
		  
SEARCH:	O(1);	constant time
---------------------------------------------------------------
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#define SIZE 100
using namespace std;

int hash_fn(int k)
{
	if(k%2==0)
		return (k/2);
	else if(k%3==0)
		return (k/3);
	else if(k%5==0)
		return (k/5);
	else if(k%7==0)
		return (k/7);
		
	else return -1;
}

class person
{
	public:
	int person_id;
	string person_name;
				
	void rec_wr(void);
	void rec_rd(void);
	person()
	{
		person_id=-1;						// -1 Indicates that node is empty
	}
};

void person::rec_rd(void)
{
	cout<<"Enter PersonID: ";
	cin>>person_id;
	cout<<"Enter Person Name: ";
	char c;
	while((c = getchar()) != '\n' && c != EOF);		//for flushing out residue inputs in buffer
	getline(cin,person_name);
}
void person::rec_wr(void)
{
	cout<<"Enter PersonID: "<<person_id<<endl;
	cout<<"Enter Person Name: "<<person_name<<endl;		
}

class node: public person
{
	public:
	node* next;
	node()
	{
		next=NULL;
	}
	int node_enter(void);
};

int node::node_enter(void)
{
	rec_rd();
	return hash_fn(person_id);
}

void node_insert(node *s,node *d)
{
	if(d->person_id==-1)
	{	d->person_id=s->person_id;
		d->person_name=s->person_name;
	}
	else
	{
		while(d->next!=NULL)
			d=d->next;
			
		d->next=s;
	}				
	cout<<"Inserted successfully!"<<endl;
}
void node_delete(node *s, int idno)
{
	if(s->person_id==-1)
		return;
	if(s->person_id==idno)
	{
		s=s->next;
		cout<<"Person deleted successfully!"<<endl;	
	}
	else
	{
		while(s!=NULL)
		{
			if(s->next->person_id==idno)
			{
				node *t=s->next;
				s->next=(s->next)->next;
				delete t;
				cout<<"Person deleted successfully!"<<endl;
				break;
			}
			s=s->next;
		}				
	}	
}
void node_show(node *s, int idno)
{	
	while(s!=NULL)
	{
		if(s->person_id==idno)
		{
			cout<<"Person Found!"<<endl;
			s->rec_wr();
			break;
		}
		s=s->next;
	}				
}

//------------------DRIVER PROGRAM-----------------
int main()
{
	node *n1=NULL;
	node hashtable[SIZE];
	int key,idno;
	char choice,ch,c;
	
	do
	{
		n1=new node;
		//system("cls");								//may not be supported on some compilers
		cout<<"\n----CHAIN-HASHING MENU----";
		cout<<"\n1. Insert";
		cout<<"\n2. Delete";
		cout<<"\n3. Search";
		cout<<"\n4. Exit";
		cout<<"\nEnter choice(1-4): ";
		cin>>choice;
		switch(choice)
		{
			case '1':key=n1->node_enter();
					 if(key==-1)
					 {
						cout<<"Invalid ID!"<<endl;
						break;
				     }
					 node_insert(n1,&hashtable[key]);
					break;
			case '2':cout<<"Enter ID: ";
					 cin>>idno;
					 key=hash_fn(idno);
				   	 if(key==-1)
					 {
						cout<<"Invalid ID!"<<endl;
						break;
				     }
					 node_delete(&hashtable[key], idno);
					break;
			case '3':cout<<"Enter ID: ";
					 cin>>idno;
					 key=hash_fn(idno);
					 if(key==-1)
					 {
						cout<<"Invalid ID!"<<endl;
						break;
				     }
					 node_show(&hashtable[key], idno);
					break;
			case '4':cout<<"Exiting...."<<endl;
					exit(0);
					break;
			
			default:cout<<"Invalid Choice!"<<endl;
		}
		cout<<"Continue?(y/n): ";
		cin>>ch;
		n1=NULL;	
	
	}while(ch!='N'||ch!='n');
	
	return 0;
}