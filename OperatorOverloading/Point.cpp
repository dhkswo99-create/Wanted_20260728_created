#include "Point.h"
#include <iostream>

Point::Point()
	: x(0), y(0)
{
}

Point::Point(int X, int Y)
	: x(X), y(Y)
{//생성자 내부에서의 초기화는 복잡성이 높거나 동적 할당을 진행할 때.
}

Point Point::operator+(const Point& other) const
{
	return Point(x + other.x, y + other.y);
}

Point operator-(const Point& left, const Point& right)
{
	return Point(left.x - right.x, left.y - right.y);
}

void Point::ShowData()
{
	std::cout
		<< "(x : "
		<< x
		<< ", y : "
		<< y
		<< ")\n";
}
