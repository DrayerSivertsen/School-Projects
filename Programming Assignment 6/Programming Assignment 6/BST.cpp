#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;

	std::ifstream infile;

	infile.open("MorseTable.txt", std::ios::in);

	char newCharacter = '\0';
	std::string newCode = "";

	std::string input = "";


	while (!infile.eof())
	{
		std::getline(infile, input);
		newCharacter = input[0];
		std::getline(infile, input);
		newCode = input;

		insert(newCharacter, newCode);
	}

}

BST::~BST()
{
	destroyTree();
}
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
void BST::destroyTree()
{
	destroyTree(this->mpRoot);
}
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
void BST::destroyTree(Node* pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		delete pTree;
	}
}
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
void BST::insert(const char& newCharacter, const std::string& newCode)
{
	insert(this->mpRoot, newCharacter, newCode);
}
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
void BST::insert(Node* pTree, const char& newCharacter, const std::string& newCode)
{
	if (pTree == nullptr)
	{
		this->mpRoot = new Node(newCharacter, newCode);
	}
	else
	{
		if (newCharacter < pTree->getData().getCharacter())
		{
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(new Node(newCharacter, newCode));
			}
			else
			{
				insert(pTree->getLeftPtr(), newCharacter, newCode);
			}
		}
		else if (pTree->getData().getCharacter() < newCharacter)
		{
			if (pTree->getRightPtr() == nullptr)
			{
				pTree->setRightPtr(new Node(newCharacter, newCode));
			}
			else
			{
				insert(pTree->getRightPtr(), newCharacter, newCode);
			}
		}
	}

}
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
void BST::print()
{
	std::cout << "***Morse Code BST***" << std::endl;
	print(this->mpRoot);
}
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
void BST::print(Node* pTree)
{
	if (pTree != nullptr)
	{
		print(pTree->getLeftPtr());
		print(pTree->getRightPtr());
		std::cout << pTree->getData().getCharacter() << std::endl;
		std::cout << pTree->getData().getCode() << std::endl;
	}
}
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
std::string BST::search(char character)
{
	Node* temp;

	std::string found = "";

	search(this->mpRoot, character, temp);

	if (temp != nullptr)
	{
		return temp->getData().getCode();
	}
}
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
void BST::search(Node* pTree, char character, Node*& found)
{
	
	if (pTree != nullptr)
	{
		if (pTree->getData().getCharacter() == character)
		{
			found = pTree;
		}
		search(pTree->getLeftPtr(), character, found);
		search(pTree->getRightPtr(), character, found);
		
	}

}
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
void BST::convert()
{
	std::ifstream infile;

	infile.open("Convert.txt", std::ios::in);

	std::string line = "";
	char letter = '\0';
	std::string code = "";

	while (!infile.eof())
	{
		std::getline(infile, line);

		line.append("\n");
		
		for (int index = 0; index < line.size(); ++index)
		{
			letter = line[index];

			letter = toupper(letter);

			if (letter == ' ')
			{
				std::cout << " ";
			}
			else if (letter == '\n')
			{
				std::cout << std::endl;
			}
			else
			{
				code = search(letter);

				std::cout << code << " ";
			}

		}
		
	}
}