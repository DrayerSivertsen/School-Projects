#include "Node.h"


Node::Node(char newCharacter, std::string newCode)
{
	this->mData.setCharacter(newCharacter);
	this->mData.setCode(newCode);

	this->mpLeft = nullptr;
	this->mpRight = nullptr;

}


Data Node::getData() const
{
	Data temp;

	temp.setCharacter(this->mData.getCharacter());
	temp.setCode(this->mData.getCode());
	
	
	return temp;

}

Node* Node::getLeftPtr() const
{
	return mpLeft;
}

Node* Node::getRightPtr() const
{
	return mpRight;
}

void Node::setLeftPtr(Node* newLeftPtr)
{
	this->mpLeft = newLeftPtr;
}

void Node::setRightPtr(Node* newRightPtr)
{
	this->mpRight = newRightPtr;
}