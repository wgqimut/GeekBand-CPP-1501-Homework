#include <iostream>

using namespace std;

class Shape
{
	int no;

public:
    Shape(int number): no(number) {}
};


class Point
{
	int x;
	int y;

public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	int get_x() const { return x; }
	int get_y() const { return y; }
};


class Rectangle: public Shape
{
	int width;
	int height;

	Point *leftUp;

public:
	Rectangle(int width, int height, int x, int y);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	int get_width() const { return width; }
	int get_height() const { return height; }
	int get_leftup_x() const { return leftUp->get_x(); }
	int get_leftup_y() const { return leftUp->get_y(); }

	~Rectangle();
};


inline Rectangle::Rectangle(int width, int height, int x, int y)
	: Shape(4), width(width), height(height), leftUp(new Point(x, y))
{}

inline Rectangle::Rectangle(const Rectangle& other): Shape(other)
{
	this->width = other.width;
	this->height = other.height;

	if (other.leftUp != nullptr) {
		this->leftUp = new Point(*other.leftUp);
	}
	else {
		this->leftUp = nullptr;
	}
}

inline Rectangle& Rectangle::operator= (const Rectangle& other)
{
	if (this == &other)
	{
		return *this;
	}

	this->width = other.width;
	this->height = other.height;

	this->leftUp = new Point(*other.leftUp);
	return *this;

}

inline ostream& operator<< (ostream& os, const Rectangle& other)
{
	return os << "the width is: " << other.get_width() << endl 
			  << "the height is: " << other.get_height() << endl
			  << "the leftUp is: " << "( " << other.get_leftup_x() << ", " << other.get_leftup_y() << " )" << endl
			  << "the no is: 4" << endl;
}

inline Rectangle::~Rectangle()
{
	delete leftUp;
}