#include "Picture.h"

using std::cout;

Picture::Picture(string n): name(n) {}

void Picture::draw() {
    cout << "Draw Picture: " << name << "\n";
    
    for (auto graphic : graphics)
        graphic -> draw();
}

void Picture::addGraphic(Graphic *g) {
    graphics.push_back(g);
}
