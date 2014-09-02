// header file for linklist

#include "stdafx.h"
#include <string>
#include <fstream>
#include "node.h"

using namespace std;

#ifndef LINKLIST
#define LINKLIST

class linklist{
	public:

		linklist(); //CTOR

		void addNode(node a);//add a node to the list

		void populateList(string inFile);// populate the list from a flat file database

		node* search(string item);// search for a value in the list	

		void display(); // display in a plain text
		
	private:
		
		node *head, *tail;
};

#endif
