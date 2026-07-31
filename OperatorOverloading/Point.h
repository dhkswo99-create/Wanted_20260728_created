#pragma once // 전처리기가 처리하는 명령어 include Gurad
#include <iostream>
//헤더 중복 선언 방지
//
class Point
{
public:
	Point();
	Point(int X, int Y);
	//덧셈 연산자 오버로드
	Point operator+(const Point& other) const; //변수 앞 const는 레퍼런스에서는 의미 ㅇ벗음
	friend Point operator-(const Point& left, const Point& right);
	//friend 선언하면 헤더을 받은 cpp에서 Point::없이구현 
	void ShowData();
	friend std::ostream& operator<<(std::ostream& os, const Point& point);

private:
	int x = 0;
	int y = 0;
};

