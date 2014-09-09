// converter.cpp: This program converts a markdown file to a html file.
// Programmer: Yingying Wu
// time last modified: 09/09/2014
// program situation: untested, unfinished

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

	//========================read file==========================================
	string inFile;			// filename to open and search
	ifstream fin;			// stream to connect to input file


	// ----------------------------------
	
	cout << "Enter file address and name: ";
	cin >> inFile;
	cout << endl;
	// let the user pass path of file using command line

	fin.clear();
	fin.open(inFile.c_str());		// try to open the file	

	if (fin.fail())				// but did the attempt fail?
	{
		cout << "ERROR: file called " << inFile << " did NOT open." << endl;
		system("Pause");
		exit(-1);
	} // if
	//===========================================================================




	//======================OPEN OUTPUT FILE=====================================

	string outFile;
	cout << "Enter output file name end with .html: ";
	cin >> outFile;
	cout << endl;

	ofstream fout;                  // stream to connect to output file

	fout.open(outFile.c_str());

	if (fout.fail())				// but did the attempt to open fail?
	{
		cout << "ERROR: file called " << outFile << " did NOT open." << endl;
		exit(-1);
	} // if

	//===========================================================================




	//========================== CONVERT ========================================
	fout << "<!DOCTYPE html><html>\n" << "<body>\n";

	string line,nextLine;

	// read lines of the story until End Of File (EOF)
	getline(fin, nextLine);
	line = nextLine;
	getline(fin, nextLine);
	bool pHead = 1, bHead = 1, lHead = 1;
	while (fin){
		// headers
		if (line[0] == '#' && line[1] == '#'&&line[2] == '#'){
			fout << "<h3>";
			for (int i = 4; i < line.length(); i++)
				fout << line[i];
			fout << "<\h3>" << endl;
		}
		else if (nextLine.find('=') == 0 && nextLine.rfind('=') == nextLine.length() - 1){
			fout << "<h1>" << line << "<\h1>" << endl;
		}
		else if (nextLine.find('-') == 0 && nextLine.rfind('-') == nextLine.length() - 1){
			fout << "<h2>" << line << "<\h2>" << endl;
		}

		// paragraph
		else if (line[0] == '\t' && line[1] == '\t'){
			if (pHead = 1){
				fout << "<p>" << line;
				pHead = 0;
			}
			else
				fout << line;

			if (nextLine.empty){
				fout << "</p>" << endl;
				pHead = 1;
			}
		}

		// blockquote
		else if (line[0] == '>'){
			if (bHead = 1){
				fout << "<blockquote>";
				bHead = 0;
			}
			
			fout << "<p>";
			for (int i = 2; i < line.length(); i++)
				fout << line[i];
			fout << "<\p>" << endl;

			if (nextLine.empty){
				fout << "</blockquote>" << endl;
				pHead = 1;
			}
		}
		
		//list
		else if (line[0] == '+' || line[0] == '-' || line[0] == '*'){
			if (lHead = 1){
				fout << "<ul>" << endl;
				lHead = 0;
			}

			fout << "<li>";
			for (int i = 2; i < line.length(); i++)
				fout << line[i];
			fout << "</li>" << endl;

			if (nextLine[0] != '+' || nextLine[0] != '-' || nextLine[0] != '*'){
				fout << "</ul>" << endl;
				lHead = 1;
			}
		}

		//emphasis 
		if (line.find('**')){
			fout << "<strong>";
			for (int i = line.find('**')+2; i < line.length(); i++){
				while (line[i] != '*')
					fout << line[i];
			}
			fout << "</strong>";
		}
		else if (line.find('__')){
			fout << "<strong>";
			for (int i = line.find('__') + 2; i < line.length(); i++){
				while (line[i] != '_')
					fout << line[i];
			}
			fout << "</strong>";
		}
		// only one * not solve
		if (line.find('*')!=0){
			fout << "<em>";
			for (int i = line.find('*') + 1; i < line.length(); i++){
				while (line[i] != '*')
					fout << line[i];
			}
			fout << "</em>";
		}
		else if (line.find('_')){
			fout << "<em>";
			for (int i = line.find('_') + 1; i < line.length(); i++){
				while (line[i] != '_')
					fout << line[i];
			}
			fout << "</em>";
		}


		line = nextLine;
		getline(fin, nextLine);
	}

	fout << "<\body>\n<\html>";
	//===========================================================================

	system("Pause");
}
