#include "Lista.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdint>
#include <windows.h>


using namespace std;



Lista::Lista()		//Default constructor
{
	first = nullptr;
	length = 0;
}

Lista::Lista(vector<Point>& points) : first(nullptr)		//Initialization constructor
{
	for (int i = 0; i < points.size(); i++)
	{
		this->insert(points[i]);
	}
}

Lista::Lista(const Lista & lista)		//Copy constructor
{
	this->first = NULL;
	Node* temp = lista.first;
	while (temp)
	{
		this->insert(temp->p);
		temp = temp->next;
	}
}


Lista::~Lista()			//Destructor
{
	while (first) pop_back();
}

Lista Lista::add(const Lista& lista)		//Method adding two lists
{
	Node* temp = lista.first;
	while (temp)
	{
		this->insert(temp->p);
		temp = temp->next;
	}
	return *this;
}

Lista & Lista::operator--()				//Operator -- removes the last element
{
	this->pop_back();
	return *this;
}


Lista Lista::operator+(const Lista & lista)			//Operator + adds two lists
{
	Lista copy(*this);
	copy.add(lista);
	return copy;
}

Lista Lista::operator*(const Lista & lista)			//Operator * duplicates lists
{
	Lista copy(*this);
	Node* temp = lista.first;
	while (temp)
	{
		this->insert(temp->p);
		temp = temp->next;
	}
	return copy;
}

Node * Lista::operator[](const int i)			//Operator [] returns a record from the index
{
	size();
	if (i > length)return NULL;
	Node* temp = this->find(i);
	return temp;
}

Lista & Lista::operator+=(const Lista & lista)			//Operator + = copies the records of the list to the second list 
{
	this->add(lista);
	return *this;
}

Lista & Lista::operator++()				//Operator ++ deletes records from the list
{
	while (this->first)this->pop_back();
	return *this;
}

Lista Lista::operator=(const Lista & lista)				//Operator = compares two lists
{			
	while (this->first)this->pop_back();
	this->add(lista);
	return *this;
}

Lista Lista::scale(int i)			//Method duplicates the list given the number of times
{
	Lista copy(*this);
	for (int j = 0; j < i; j++)
	{
		Node* temp = this->first;
		while (temp)
		{
			copy.insert(temp->p);
			temp = temp->next;
		}
	}
	return copy;
}

int Lista::pop_back()			//Method removing the last item from the list
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

int Lista::pop(int i)			//Method removing the selected record from the list
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

int Lista::put(Point p, int i)			//Method adding a record in the selected place
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

void Lista::insert(Point p)				//Method adding a record to the end of the list
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

Node* Lista::find(int i)			//Method returns the selected list item
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

int Lista::size()			//Method checks the number of items in the list
{
	Node* temp = first;
	if (temp == NULL)return 0;
	int i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	length = i;
	return i;
}

std::ostream & operator<<(std::ostream & os, const Lista & lista)			//Stream operator
{
	Lista copy(lista);
	Node* temp = copy.first;
	int i = 1;
	while (temp)
	{
		os << i << ":" << temp->p.a << ',' << temp->p.b << ',' << temp->p.c << ',' << '\n';
		i++;
		temp = temp->next;
	};
	return os;
}