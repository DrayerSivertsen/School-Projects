#include "NodeData.h"

Data::Data()
{
	this->mCharacter = '\0';
	this->mCode = "";
}

Data::Data(Data& copy)
{
	this->mCharacter = copy.getCharacter();
	this->mCode = copy.getCode();
}

Data::~Data()
{

}

Data& Data::operator=(const Data& rhs)
{
	if (this != &rhs)
	{
		this->mCharacter = rhs.getCharacter();
		this->mCode = rhs.getCode();
	}

	return *this;
}

char Data::getCharacter() const
{
	return mCharacter;
}

std::string Data::getCode() const
{
	return mCode;
}

void Data::setCharacter(char newCharacter)
{
	this->mCharacter = newCharacter;
}

void Data::setCode(std::string newCode)
{
	this->mCode = newCode;
}

