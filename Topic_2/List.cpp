#include <iostream>
#include "List.h"


using namespace std;


Lista::Lista()		//Constructor
{
	first = NULL;
}


Lista::~Lista()		//Destructor
{
	while (first) pop_back();
}

int Lista::pop_back()		//Methode deleting the last record
{
	Node* temp = first;
	if (temp == NULL)return 0;
	if (temp != NULL)
	{
		if (temp->next != NULL)
		{
			while (temp->next->next)temp = temp->next;
			delete temp->next;
			temp->next = NULL;
		}
		else
		{
			delete temp;
			first = NULL;
		}
	}
	size();
	return 1;
}

int Lista::pop(int i)		//Methode poping i'th record from the list
{
	if (i > length)return 0;
	if (i == 1) 
	{
		Node* temp = first;
		first = temp->next;
		delete temp;
	}
	else if (i >= 2) 
	{
		int p = 1;
		Node* temp = first;
		while (temp != NULL) 
		{
			if ((p + 1) == i) break;
			else
			{
				temp = temp->next;
				p++;
			}
	
		}
		if (temp->next->next == NULL) 
		{
			delete temp->next;
			temp->next = NULL;
		}
		else 
		{
			Node* del = temp->next;
			temp->next = temp->next->next;
			delete  del;
		}
			
	}
	size();
	return 1;
}

int Lista::put(Point p, int i)		//Methode putting record to the list at i'th place
{
	if (i > length)return 0;
	Node* temp = first;
	Node* object = new Node;
	object->p = p;
	if (i == 1) 
	{
		object->next = temp;
		first = object;
	}
	else
	{
		int j = 1;
		while (temp != NULL)
		{
			if ((j + 1) == i) break;
			else
			{
				temp = temp->next;
				j++;
			}
		}
		object->next = temp->next;
		temp->next = object;
	}
	size();
	return 1;
}

void Lista::insert(Point p)		//Methode adding record to the end of the list
{
	Node* object = new Node;
	object->p = p;
	if (first == NULL)first = object;
	if (first != NULL) 
	{
		Node *temp = first;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = object;
		object->next = NULL;
	}
	size();
}

Node* Lista::find(int i)		//Methode finding the i'th record
{
	if (i > length)return NULL;
	Node* temp = first;
	int p = 1;
	while (temp != NULL)
	{
		if (p == i) break;
		else
		{
			temp = temp->next;
			p++;
		}
	}
	return temp;
}

void Lista::show()		//Methode displaying the list
{
	Node *temp = first;

	while (temp != NULL) 
	{
		cout << "x=" << temp->p.a << "y=" << temp->p.b << "z=" << temp->p.c << endl;
		temp = temp->next;
	}
}

int Lista::size()		//Methode checking size of the list 
{
	int i = 0;
	Node* temp = first;
	while (temp != NULL) 
	{
		i++;
		temp = temp->next;
	}
	length = i;
	return i;
}
