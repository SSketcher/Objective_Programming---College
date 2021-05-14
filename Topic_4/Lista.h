#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdint>
#include <windows.h>
#include "Node.h"
#include "Point.h"

using namespace std;

class Lista
{
public:
	Lista();													//List constructor

	Lista(const Lista& lista);									//Copy constructor that takes a list as an argument

	Lista(vector<Point>& points);								//Initialization constructor that takes a vector as an argument

	~Lista();													//List destructor deletes all records

	Lista add(const Lista& lista);								//Method adds two lists together

	Lista & operator -- ();										//Operator -- causes the last element to be removed from the list

	Lista  & operator += (const Lista& lista);					//Operator += adds records from the right list to the left list

	Lista operator + (const Lista& lista);						//Operator + sums the records of the list from the right to the list on the left, returns the list

	Lista operator * (const Lista& lista);						//Operator * returns a new duplicate list

	Node* operator [] (const int i);							//Operator [] returns a record with the given index

	Lista & operator ++ ();										//Operator ++ causes all records in the list to be deleted

	Lista operator = (const Lista& lista);						//Operator = assigns the value of the list on the right to the list on the left

	friend std::ostream & operator<<(std::ostream & os, const Lista& lista);		//Stream operator allows you to list to the screen with cout

	Lista scale(int i);				//Ccauses the list of tasks to be duplicated as many times as possible

	int pop_back();					//Method deletes the last record
									//Method returns 1 when the record is deleted and 0 when we try to remove a record from an empty list

	int pop(int i);					//Method removes the selected record from the list
									//Method returns 1 if it removes a record from the list and 0 if the given value exceeds the size of the list


	int put(Point p, int i);		//Method adds a record at the selected place in the list
									//Method returns 1 when it adds a record to the list and 0 when the given value exceeds the size of the list

	void insert(Point p);			//Method adds a record to the end of the list

	Node* find(int i);				//Method searches for a record by the cursor, returns a pointer to the searched record
									//Method returns "NULL" when the searched record does not exist

	int size();						//Method checks the length of the list and returns a value to the length parameter

private:
	Node* first = new Node;
	int length;
};