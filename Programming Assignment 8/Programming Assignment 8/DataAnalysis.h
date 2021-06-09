#pragma once
#include "BST.h"

class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();

/*
Function: Run analysis
Date Created: 4/11/21
Date Last Modified: 4/11/21
Description: The function runs the application
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void runAnalysis();


private:
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;

/*
Function: Import Data
Date Created: 4/11/21
Date Last Modified: 4/11/21
Description: The function imports the data from the data.csv
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void importData();
/*
Function: Open file
Date Created: 4/11/21
Date Last Modified: 4/11/21
Description: The function opens the data.csv file
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void openFile();
/*
Function: Read line
Date Created: 4/11/21
Date Last Modified: 4/11/21
Description: The function reads a line of code from the file and puts the values in the correct field
Input Parameters: References to variables units, type and transaction
Returns: None
Preconditions: None
Postconditions: None
*/
	void readLine(int& units, std::string& type, std::string& transaction);
/*
Function: Insert data
Date Created: 4/11/21
Date Last Modified: 4/11/21
Description: The function inserts the data to the corresponding BST based on transaction
Input Parameters: Data members units, type and transaction
Returns: None
Preconditions: None
Postconditions: None
*/
	void insertData(int units, std::string type, std::string transaction);
/*
Function: Print trends
Date Created: 4/11/21
Date Last Modified: 4/11/21
Description: The function prints the trends seen in the BST
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
	void printTrends();

};