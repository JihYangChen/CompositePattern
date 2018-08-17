#ifndef Circle_h
#define Circle_h

#include <iostream>
#include "Graphic.h"

using std::string;

class Circle : public Graphic {
public:
    Circle(string);
    void draw();
    
private:
    string name;
};

#endif /* Circle_h */
