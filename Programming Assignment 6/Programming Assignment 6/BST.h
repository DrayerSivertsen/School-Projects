#pragma once
#include "Node.h"

class BST
{
public:
	BST();

	~BST();
/*
Function: Destroy Tree
Date Created: 3/22/21
Date Last Modified: 3/26/21
Description: The function recursively helps destroy the tree
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void destroyTree();
/*
Function: Insert
Date Created: 3/22/21
Date Last Modified: 3/26/21
Description: The function inserts data into the tree
Input Parameters: Character and a string of morse code
Returns: None
Preconditions: None
Postconditions: None
*/
	void insert(const char& newCharacter, const std::string& newCode);
/*
Function: Print
Date Created: 3/22/21
Date Last Modified: 3/26/21
Description: The function prints the tree
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void print();
/*
Function: Search
Date Created: 3/22/21
Date Last Modified: 3/26/21
Description: The function searches for the input character
Input Parameters: Character to search for
Returns: None
Preconditions: None
Postconditions: None
*/
	std::string search(char character);
/*
Function: Convert
Date Created: 3/22/21
Date Last Modified: 3/26/21
Description: The function converts the file in english to morse code
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void convert();


private:
	Node* mpRoot;
/*
Function: Destroy Tree
Date Created: 3/22/21
Date Last Modified: 3/26/21
Description: The function recursively helps destroy the tree
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void destroyTree(Node* pTree);
/*
Function: Insert
Date Created: 3/22/21
Date Last Modified: 3/26/21
Description: The function inserts data into the tree
Input Parameters: Character and a string of morse code
Returns: None
Preconditions: None
Postconditions: None
*/
	void insert(Node* pTree, const char& newCharacter, const std::string& newCode);
/*
Function: Print
Date Created: 3/22/21
Date Last Modified: 3/26/21
Description: The function prints the tree
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void print(Node* pTree);
/*
Function: Search
Date Created: 3/22/21
Date Last Modified: 3/26/21
Description: The function searches for the input character
Input Parameters: Character to search for
Returns: None
Preconditions: None
Postconditions: None
*/
	void search(Node* pTree, char character, Node*& found);

};