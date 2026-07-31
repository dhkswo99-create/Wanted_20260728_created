#include "Person.h"
#include <iostream>

Person::Person()
{
	++personCount;
	std::cout
		<< "객체 생성\n"
		<< "Perosn 객체 수 : "
		<< personCount
		<< "\n";
}

Person::~Person()
{
	--personCount;
	std::cout
		<< "객체 소멸\n"
		<< "Perosn 객체 수 : "
		<< personCount
		<< "\n";
}
int Person::personCount = 0;
