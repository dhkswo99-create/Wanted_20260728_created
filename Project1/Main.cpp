#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base() called\n";
	}
	~Base()
	{
		std::cout << "~Base() called\n";
	}
	void Play()
	{

	}
};

class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "Derived() called\n";
	}
	~Derived()
	{
		std::cout << "~Derived() called\n";
	}
	void Attack()
	{
		Base* b = new Derived();
		b->Play(); //가능
		//b->Attack(); //불가능
		//Derived d = new Base(); //불가능
	}
};

int main()
{
	Derived* d;
}