#pragma once
#include "Point.h"
#include <iostream>

struct Node
{
	Point p;

	Node* next;

	Node() {
		next = NULL;
		
	}
};