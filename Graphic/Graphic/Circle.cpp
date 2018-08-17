#include "Circle.h"

using std::cout;

Circle::Circle(string n): name(n) {}

void Circle::draw() {
    cout << "Draw Circle: " << name << "\n";
}
