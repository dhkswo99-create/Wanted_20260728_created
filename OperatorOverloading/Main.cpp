#include <iostream>
#include "Point.h"



//출력 연산자 오버로딩.
std::ostream& operator<<(std::ostream& os, const Point& point)
{
	std::cout
		<< "(" << point.x << "," << point.y << ")\n";
	return os;
}

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);
	Point p3 = p1 + p2;
	Point p4 = p1 - p2;
	//결과값 출력
	p3.ShowData();
	p4.ShowData();
	std::cout << p3 << p4;
}