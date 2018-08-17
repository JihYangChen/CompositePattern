#include "Line.h"

using std::cout;

Line::Line(string n): name(n) {}

void Line::draw() {
    cout << "Draw Line: " << name << "\n";
}
