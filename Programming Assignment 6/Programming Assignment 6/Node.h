#pragma once

#include "NodeData.h"

class Node
{
public: 
	Node(char newCharacter, std::string newCode);


	Data getData() const;
	Node* getLeftPtr() const;
	Node* getRightPtr() const;

	void setLeftPtr(Node* newLeftPtr);
	void setRightPtr(Node* newRightPtr);


private:
	Data mData;
	Node* mpLeft;
	Node* mpRight;

};