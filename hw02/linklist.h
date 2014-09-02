// header file for linklist

#include "stdafx.h"
#include <string>
#include <fstream>

#include "node.h" // Forward Declaration

using namespace std;

#ifndef 398HW01_LINKLIST_H  // naming rule
#define 398HW01_LINKLIST_H  // define Guard

class linklist{
	public: 
	
		// all function names start with a capital letter
		linklist(); //CTOR

		void AddNode(node a);//add a node to the list

		void PopulateList(string in_file);// populate the list from a flat file database // avoid mixed case

		node* Search(string item);// search for a value in the list	

		void Display(); // display in a plain text
		
	private:
		
		node *head, *tail;  // clear names
};

#endif //398HW01_LINKLIST_H
