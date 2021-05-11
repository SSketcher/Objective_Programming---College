#pragma once
#include "Node.h"

class Lista
{
public:
	Lista();						//Constructor

	~Lista();						//The list destructor deletes all records

	int pop_back();					//Deletes the last record
									//Method returns 1 when the record is deleted and 0 when trying to remove a record from an empty list

	int pop(int i);					//Removes the selected record from the list
									//Method returns 1 if it removes a record from the list and 0 if the given value exceeds the size of the list

	int put(Point p, int i);		//Adds a record at the selected place in the list
									//Method returns 1 if it adds a record to the list and 0 if the value given exceeds the size of the list

	void insert(Point p);			//Adds a record to the end of the list

	Node* find(int i);				//Method searches record by cursor method returns a pointer to the searched record
									//Method returns "NULL" when the searched record does not exist

	int size();						//Method checks the length of the list and returns a value and updates the length parameter


private:
	Node* first = new Node();
	int length = 0;
	

	void show();					//Method displays a list on the screen
};

