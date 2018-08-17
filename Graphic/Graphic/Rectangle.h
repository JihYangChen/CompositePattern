#ifndef Rectangle_h
#define Rectangle_h

#include <iostream>
#include "Graphic.h"

using std::string;

class Rectangle : public Graphic {
public:
    Rectangle(string);
    void draw();
    
private:
    string name;
};

#endif /* Rectangle_h */
