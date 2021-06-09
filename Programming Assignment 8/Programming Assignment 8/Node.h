#pragma once
#include <iostream>
#include <string>
#include <fstream>


class Node
{
public:
	Node(std::string newData);
	virtual ~Node();

	// getters
	std::string getData() const;
	Node*& getLeftPtr();
	Node*& getRightPtr();

	// setters
	void setData(std::string newData);
	void setLeftPtr(Node* newLeftPtr);
	void setRightPtr(Node* newRightPtr);


	virtual void printData() = 0; // pure virtual


protected:
	std::string mData;
	Node* mpLeft;
	Node* mpRight;


};