// 398hw01.cpp : Defines the entry point for the console application.
// the driver program

#include "stdafx.h"
#include <iostream>
#include "linklist.h"
#include "node.h"

int main(){

	linklist testCTOR;
	cout << "pass CTOR\n";

	node aNode;
	a.addNode(aNode);
	cout << "pass addNode\n";

	a.populateList("flat.csv");
	cout << "pass populateList\n";
	// can't pass this test, thus can't finish the latter ones.

	a.search("David Cobb");
	cout << "pass search\n";

	a.display();
	cout << "pass display\n";


	system("Pause");
}
