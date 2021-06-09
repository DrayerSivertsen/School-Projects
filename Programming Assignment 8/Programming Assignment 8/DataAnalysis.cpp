#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{
	
}

DataAnalysis::~DataAnalysis()
{

}

void DataAnalysis::importData()
{
	int units = 0;
	std::string type = "";
	std::string transaction = "";

	std::getline(mCsvStream, type);

	while (!mCsvStream.eof())
	{
		readLine(units, type, transaction);
		
		insertData(units, type, transaction);
	}

	std::cout << "***Sold Tree***" << std::endl;
	mTreeSold.inOrderTraversal();
	std::cout << "***Purchased Tree***" << std::endl;
	mTreePurchased.inOrderTraversal();

}

void DataAnalysis::openFile()
{
	mCsvStream.open("data.csv", std::ios::in);
	
}

void DataAnalysis::readLine(int& units, std::string& type, std::string& transaction)
{
	std::string line = "";

	std::getline(mCsvStream, line, ',');
	units = stoi(line);
	std::getline(mCsvStream, type, ',');
	std::getline(mCsvStream, transaction);

}

void DataAnalysis::insertData(int units, std::string type, std::string transaction)
{
	if (transaction == "Sold")
	{
		mTreeSold.insert(units, type);
	}
	else if (transaction == "Purchased")
	{
		mTreePurchased.insert(units, type);
	}
}

void DataAnalysis::printTrends()
{
	TransactionNode temp;

	temp = mTreePurchased.findSmallest();
	std::cout << "Least Purchased: ";
	temp.printData();

	temp = mTreeSold.findSmallest();
	std::cout << "Least Sold: ";
	temp.printData();

	temp = mTreePurchased.findLargest();
	std::cout << "Most Purchased: ";
	temp.printData();

	temp = mTreeSold.findLargest();
	std::cout << "Most Sold: ";
	temp.printData();

}

void DataAnalysis::runAnalysis()
{
	DataAnalysis run;

	run.openFile();
	run.importData();
	run.printTrends();

}