#include <iostream>

class Calculator
{
private:
	double x;
	double y;
	int addCount;
	int substractCount;
	int divideCount;
	int multiplyCount;
public:
	Calculator() : x(0), y(0), addCount(0), substractCount(0), divideCount(0), multiplyCount(0) {}
	
	double Add(double x, double y)
	{
		addCount++;
		return x + y;
	}
	double Substract(double x, double y)
	{
		substractCount++;
		return x - y;
	}
	double Divide(double x, double y)
	{
		divideCount++;
		return x / y;
	}
	double Multiply(double x, double y)
	{
		multiplyCount++;
		return x * y;
	}
	void ShowOperationCount()
	{
		std::cout << "덧셈 : " << addCount << ", 뺄셈 : " << substractCount << ", 곱셈 : "
			<< multiplyCount << ", 나눗셈 : " << divideCount << "\n";
	}
};
class Printer
{
private:
	char *name;
public:
	Printer() : name(nullptr)  {}
	~Printer() 
	{ 
		if(name != nullptr)
			delete[] name; 
	}
	void SetString(const char* setName)
	{
		if (name != nullptr) delete[] name;
		int i = 0;
		name = new char[100];
		while (setName[i] != '\0' && i < 99)
		{
			name[i] = setName[i];
			i++;
		}
		name[i] = '\0';
	}
	void ShowString()
	{
		if (name == nullptr)
		{
			std::cout << "Can’t show the string value\n";
		}
		else
		{
			for (int i = 0; name[i] != '\0' && i < 100; i++)
				std::cout << name[i];
			std::cout << "\n";
		}
	}
};
class Rectangle
{
private:
	double width, hight;
public:
	Rectangle(double w, double h) : width(w), hight(h) {}
	~Rectangle() {}

	double GetArea()
	{
		return width * hight;
	}
	double GetGirth()
	{
		return 2 * (width + hight);
	}
};
class Circle
{
#define PI 3.14
private:
	double radius;
	
public:
	Circle(double r) : radius(r) {}
	~Circle() {}

	double GetArea()
	{
		return PI * radius * radius;
	}
	double GetGirth()
	{
		return 2 * radius * PI;
	}
};
class NameCard
{
private:
	char* name;
	char* phoneNumber;
	char* email;
	char* job;
public:
	NameCard(const char* n, const char* pN, const char* em, const char* j)
	{
		int i = 0;
		while (n[i] != '\0') i++;
		name = new char[i + 1]; 
		i = 0;
		while (n[i] != '\0')
		{
			name[i] = n[i];
			i++;
		} name[i] = '\0';

		i = 0;
		while (pN[i] != '\0') i++;
		phoneNumber = new char[i + 1];
		i = 0;
		while (pN[i] != '\0')
		{
			phoneNumber[i] = pN[i];
			i++;
		} phoneNumber[i] = '\0';

		i = 0;
		while (em[i] != '\0') i++;
		email = new char[i + 1];
		i = 0;
		while (em[i] != '\0')
		{
			email[i] = em[i];
			i++;
		} email[i] = '\0';

		i = 0;
		while (j[i] != '\0') i++;
		job = new char[i + 1];
		i = 0;
		while (j[i] != '\0')
		{
			job[i] = j[i];
			i++;
		} job[i] = '\0';
	}
	~NameCard()
	{
		delete[] name;
		delete[]	 phoneNumber;
		delete[] email;
		delete[] job;
	}
	void ShowData()
	{
		std::cout << "이    름 : " << name
			<< "\n전화번호 : " << phoneNumber
			<< "\n이 메 일 : " << email
			<< "\n직    업 : " << job;
	}
};

void exam4()
{
	Calculator calculator;

	std::cout << "3+5=" << calculator.Add(3, 5) << "\n";
	std::cout << "3/5=" << calculator.Divide(3, 5) << "\n";
	std::cout << "12-7=" << calculator.Substract(12, 7) << "\n";
	std::cout << "12x7=" << calculator.Multiply(12, 7) << "\n";

	calculator.ShowOperationCount();
}
void exam5()
{
	Printer printer;
	printer.ShowString();

	printer.SetString("Hello C++");
	printer.ShowString();

	printer.SetString("I Want to be a Good Developer");
	printer.ShowString();
}
void exam6()
{
	Rectangle rect = Rectangle(3, 4);    // Rectangle(가로길이, 세로길이)
	std::cout << "면적: " << rect.GetArea() << "\n";
	std::cout << "둘레: " << rect.GetGirth() << "\n";

	Circle circle = Circle(5);    // Circle(원의 반지름)
	std::cout << "면적: " << circle.GetArea() << "\n";
	std::cout << "둘레: " << circle.GetGirth() << "\n";
}
void exam7()
{
	// NameCard (이름, 전화번호, 이메일, 직업)
	NameCard jang("Jane Se Yun", "010-000-0000", "abd@def.com", "Lecturer");
	jang.ShowData();
}
