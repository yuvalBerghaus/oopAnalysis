// C++ program to demonstrate factory method design pattern
#include <iostream>
using namespace std;
class Shape
{
public:
	Shape() {}
	virtual void draw() = 0;
};
class Circle :
	public Shape
{
	void draw() {
		cout << "im a circle!";
	}
};
class Square :
	public Shape
{
	void draw() {
		cout << "im a square!";
	}
};
class Triangle :
	public Shape
{
	void draw() {
		cout << "im a triangle!";
	}
};
class ShapeFactory
{

public:
	ShapeFactory() {}
public:
	Shape* getShape(string type) {
		if (type == "Circle") {
			return new Circle();
		}
		else if (type == "Circle") {
			return new Square();
		}
		else if (type == "Triangle") {
			return new Triangle();
		}
		else return nullptr;
	}
};
// Driver program
int main() {
	ShapeFactory* factory = new ShapeFactory();
	string answer;
	cin >> answer;
	Shape* cir = factory->getShape(answer);
	cir->draw();
    return 0;
}