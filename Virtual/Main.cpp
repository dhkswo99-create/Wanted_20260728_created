#include <cstring>
#include <iostream>

class Person
{
public:
	Person(const char* name)
	{
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, name);
		std::cout << "Person(const char* name) called\n";
	}

	virtual ~Person()
	{
		std::cout << "~Person() call!\n";
		delete[] name;
	}

	virtual void Print()
	{
		std::cout << "이름: " << name << "\n";
	}

protected:
	char* name = nullptr;
};

class Student : public Person
{
public:
	Student(const char* name, const char* major)
		: Person(name)
	{
		size_t length = strlen(major) + 1;
		this->major = new char[length];
		strcpy_s(this->major, length, major);
		std::cout << "Student(const char* name, const char* major) called\n";
	}

	~Student()
	{
		std::cout << "~Student() call!\n";
		delete[] major;
	}

	void Print() override
	{
		Person::Print();
		std::cout << "전공: " << major << "\n";
	}

private:
	char* major = nullptr;
};

int main()
{
	Person* person1 =
		new Student("Ronnie", "Information Communication Engineering");
	Student* person2 =
		new Student("Emily", "Computer Science");

	person1->Print();
	person2->Print();

	std::cout << "객체 소멸 전\n";

	delete person1;
	delete person2;
}