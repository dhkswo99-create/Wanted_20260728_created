#include "File1.h"
#include <iostream>
#include "Static.h"

void FileOneFunction()
{
	++variable;
	std::cout
		<< "File1, variable"
		<< variable
		<< '\n';
}
