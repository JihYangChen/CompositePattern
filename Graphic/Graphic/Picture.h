#ifndef Picture_h
#define Picture_h

#include <iostream>
#include <vector>
#include "Graphic.h"

using std::string;
using std::vector;

class Picture : public Graphic {
public:
    Picture(string);
    void draw();
    void addGraphic(Graphic *);
    
private:
    string name;
    vector<Graphic *> graphics;
};

#endif /* Picture_h */
