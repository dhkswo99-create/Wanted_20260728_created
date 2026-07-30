#include <iostream>

class Person
{
public:
	void Sleep()
	{
		std::cout << "Sleep\n";
	}
};

class Student : public Person
{
public:
	void Study()
	{
		std::cout << "Study\n";
	}
};

class PartTimeStudent : public Student
{
public:
	void Work()
	{
		std::cout << "Work\n";
	}
};

int main()
{
	Person personObject;
	Student studentObject;
	PartTimeStudent partTimeStudentObject;

	Person* person1 = &personObject;
	Person* person2 = &studentObject;
	PartTimeStudent* person3 = &partTimeStudentObject;
	//여러 객체를 한 타입으로 다루려고 할 때 이를 다형성이라 한다.
	person1->Sleep();
	person2->Sleep();
	person3->Work();
}