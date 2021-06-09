#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class Data
{
public:
	Data();

	Data(Data& copy);

	~Data();

	Data& operator=(const Data& rhs);

	char getCharacter() const;
	std::string getCode() const;

	void setCharacter(char newCharacter);
	void setCode(std::string newCode);

private:
	char mCharacter;
	std::string mCode;

};
