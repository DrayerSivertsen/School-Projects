#include "Node.h"

Node::Node(std::string newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{

}

// getters
std::string Node::getData() const
{
	return mData;
}
Node*& Node::getLeftPtr()
{
	return mpLeft;
}
Node*& Node::getRightPtr()
{
	return mpRight;
}

// setters
void Node::setData(std::string newData)
{
	mData = newData;
}
void Node::setLeftPtr(Node* newLeftPtr)
{
	mpLeft = newLeftPtr;
}
void Node::setRightPtr(Node* newRightPtr)
{
	mpRight = newRightPtr;
}

