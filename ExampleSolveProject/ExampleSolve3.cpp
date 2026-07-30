#include <iostream>

class Person
{
public:
	Person() : age(0), name(nullptr) {}
	Person(int pAge, const char* pName)
	{
		this->age = pAge;
		size_t length = strlen(pName) + 1;
		this->name = new char[length];
		strcpy_s(name, length, pName);
	}
	Person(const Person& other)
	{
		this->age = other.age;
		size_t length = strlen(other.name) + 1;
		this->name = new char[length];
		strcpy_s(name, length, other.name);
	}
	virtual ~Person()
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
	}
	virtual void ShowData()
	{
		std::cout
			<< "이름 : "
			<< name
			<< "\n나이 : "
			<< age
			<< "\n";
	}

private:
	int age;
	char* name;
};

class Student : public Person
{
public:
	Student()
		: Person(), major(nullptr)
	{}
	Student(int sAge, const char* sName, const char* sMajor)
		: Person(sAge, sName)
	{
		size_t length = strlen(sMajor) + 1;
		this->major = new char[length];
		strcpy_s(major, length, sMajor);
	}
	Student(const Student& other)
		: Person(other)
	{
		size_t length = strlen(other.major) + 1;
		this->major = new char[length];
		strcpy_s(major, length, other.major);
	}
	~Student()
	{
		if (major)
		{
			delete[] major;
			major = nullptr;
		}
	}


	virtual void ShowData() override
	{
		Person::ShowData();
		std::cout
			<< "전공 : "
			<< major
			<< "\n"; 
	}
	
private:
	char* major;
};

void exam10()
{
	Student Jang1 = Student(20, "Jang Se Yun", "Computer Science");
	Jang1.ShowData();

	Student Jang2 = Jang1;
	Jang2.ShowData();
}