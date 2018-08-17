#ifndef Line_h
#define Line_h

#include <iostream>
#include "Graphic.h"

using std::string;

class Line : public Graphic {
public:
    Line(string);
    void draw();
    
private:
    string name;
};

#endif /* Line_h */
