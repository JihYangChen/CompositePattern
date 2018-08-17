#include "Rectangle.h"

using std::cout;

Rectangle::Rectangle(string n): name(n) {}

void Rectangle::draw() {
    cout << "Draw Rectangle: " << name << "\n";
}
