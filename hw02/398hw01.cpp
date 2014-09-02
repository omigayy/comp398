// 398hw01.cpp : Defines the entry point for the console application.
// the driver program

#include "stdafx.h"
#include <iostream>
#include "linklist.h"
#include "node.h"

int main(){

	linklist test_ctor; //clear names
	cout << "pass CTOR\n";

	node a_node;
	a.AddNode(a_node); // avoid mixed case
	cout << "pass addNode\n";

	a.PopulateList("flat.csv");
	cout << "pass populateList\n";
	// can't pass this test, thus can't finish the latter ones.

	a.Search("David Cobb");
	cout << "pass search\n";

	a.Display();
	cout << "pass display\n";


	system("Pause");
}
