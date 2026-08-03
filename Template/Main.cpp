#include <iostream>

//template<typename T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//template<typename T>
//void Print(T& a, T& b)
//{
//	std::cout
//		<< "(" << a << ", " << b << ")\n";
//}

template<typename T, int Size = 10 >
class Data
{
public:
	Data(const T& newData)
		: data(newData * Size)
	{
	}
	T GetData() const { return data; }
	void SetData(const T& newData) { data = newData; }


private:
	T data = {};

};

int main()
{
	//int a1 = 50, b1 = 3;
	//float a2 = 3.f, b2 = 6.31f;
	//Print(a1, b1); Swap(a1, b1);
	//Print(a1, b1); 
	//
	//Print(a2, b2); Swap(a2, b2);
	//Print(a2, b2); 
	Data<int> intData(30);
	std::cout << intData.GetData() << "\n";
	Data<float,  27> pi(3.1415f);
	std::cout << pi.GetData() << "\n";

	



}