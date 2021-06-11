#include "Data.h"

Data::Data(int newCustomerNumber, int newServiceTime, int newTotalTime)
{
	this->customerNumber = newCustomerNumber;
	this->serviceTime = newServiceTime;
	this->totalTime = newTotalTime;
}

Data::Data(const Data& copy)
{
	customerNumber = copy.customerNumber;
	serviceTime = copy.serviceTime;
	totalTime = copy.totalTime;
}

Data::~Data()
{
	// none
}

// getters

int Data::getCustomerNumber() const
{
	return customerNumber;
}

int Data::getServiceTime() const
{
	return serviceTime;
}

int Data::getTotalTime() const
{
	return totalTime;
}

// setters

void Data::setCustomerNumber(const int newCustomerNumber)
{
	customerNumber = newCustomerNumber;
}

void Data::setServiceTime(const int newServiceTime)
{
	serviceTime = newServiceTime;
}

void Data::setTotalTime(const int newTotalTime)
{
	totalTime = newTotalTime;
}

//Data* Data::operator=(const Data*& rhs)
//{
//	Data* temp = new Data;
//
//	if (this != rhs)
//	{
//		temp->setCustomerNumber(rhs->getCustomerNumber());
//		temp->setServiceTime(rhs->getServiceTime());
//		temp->setTotalTime(rhs->getTotalTime());
//	}
//
//	return temp;
//}