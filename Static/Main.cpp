#include <iostream>
#include "File1.h"
#include "File2.h"
#include "Static.h"
#include "Person.h"

int count = 0;
void Increment()
{
	//static int count = 0;
	++count;
	std::cout << "Count : " << count << '\n';\
}

int main()
{
	Person p1;
	Person p2;
	//FileOneFunction();
	//FileTwoFunction();
	//Increment();
	//Increment();
	//Increment();

}
