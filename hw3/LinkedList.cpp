#include "LinkedList.h"
#include <iostream>
#include <stdlib.h> 
//Josh Manning u57872687
using namespace std;

//????
//initialize the linked list
LinkedList::LinkedList()
{
	head=NULL;
	listSize=0;
}

int LinkedList::size()
{
	int count=0;
	Node * position = head;//initialize at beginning
	//go through loop
	while(position->next!=NULL)
	{
		position->next;//go to next element
		count++;//increment count until last element reached
	}
	
	return count;
}

bool LinkedList::contains(int x)
{
	Node *current=head;
	//go through the list
	while(current->next!=NULL)
	{
		if(current->data==x)//if value has been found in list
		{
			return true;//stop and return true
		}
		current=current->next;//go to next element while desired element not found
	}
	
	return false;//if element not found, return false
}
//use contains to see if 
//segfault from add!!
bool LinkedList::add(int x)
{
	if (head==NULL)
	{
		Node *newNode = new Node;
		head=newNode;
		head->data=x;
		head->next=NULL;
		//listSize+;
		
	}
	else
	{
		Node *current=head;
		//see if it already exists
		if (contains(x)) return false;
		//get to end of list
		while(current->next!=NULL)
		{
			current=current->next;
		}
		cout << x << " has been added in loop" << endl;
		//add x to list
		Node *node=new Node;
		node->data=x;
		node->next=NULL;
		current->next=node;
		//listSize++;
		//return true;
		//place outside to see if it couts the other thing
	}
	cout << x << " has been added now " << endl;//never printed 

	
	return true;
	
}

bool LinkedList::remove(int x)
{
	Node *temp, *prev;
	temp=head;//initialize temp to beginning
	//loop through list
	while (temp->next!=NULL)
	{
		if(temp->data=x)//if num found
		{
			if(temp==head)//if x at the beginning
			{		
				head=temp->next;
				free(temp);
				return true;
			}

			else	//if x not at beginning
			{
				prev->next=temp->next;
				free(temp);
				return true;
			}
		}
		else//if not found, go to next element
		{
			prev=temp;
			temp=temp->next;
		}
	}
	return false;//if x not found	
}

void LinkedList::print()
{
	//head=new Node;
	Node *temp = head;
	if(temp==NULL)
	{
		cout << "NO ELEMENTS IN LIST" << endl;
	}
	else
	{
		//cout << "The list is: " << endl;
		while(temp->next!=NULL)
		{
			cout << temp->data << "->";
			temp=temp->next;
		}
	}
}

LinkedList::~LinkedList()
{
	Node *first = head;
	Node *second = head;
	while (second)
	{
		first = second;
		second = first->next;
		if (second) delete second;
	} 
}



