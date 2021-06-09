/*
	Programming Language C++

	Programming Assignment 6: Morse Code Lookup BST

	Programmer: Drayer Sivertsen
	Date Created: 3/21/21
	Last Modified: 3/25/21

	Description: In this assignment you will be using a BST to convert 
	English characters to Morse code strings. Morse code is a famous 
	coding scheme that assigns a series of dots and dashes to each 
	letter of the alphabet, each digit, and a few special characters. 
	In sound-oriented systems, the dot represents a short sound and the 
	dash represents a long sound. Other representations of dots and 
	dashes are used with light-oriented systems and signal-flag systems.

*/

#include "BST.h"


int
main(void)
{
	BST tree;

	//tree.print();

	/*std::string code = "";

	char letter = '.';

	code = tree.search(letter);

	std::cout << code;*/

	tree.convert();




	return 0;
}