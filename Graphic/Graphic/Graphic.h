#ifndef Graphic_h
#define Graphic_h

class Graphic {
public:
    virtual void draw() = 0;
    virtual void addGraphic(Graphic *);
};

#endif /* Graphic_h */
