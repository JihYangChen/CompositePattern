#include <iostream>
#include "Graphic.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Picture.h"

int main(int argc, const char * argv[]) {
    /* Create Leaf instances */
    Graphic *line1 = new Line("Line1");
    Graphic *line2 = new Line("Line2");
    
    Graphic *rectangle1 = new Rectangle("Rectangle1");
    
    Graphic *circle1 = new Circle("Circle1");
    Graphic *circle2 = new Circle("Circle2");
    
    /* Create Composite instances */
    Graphic *picture = new Picture("Picture");
    
    /* Add Components for Composite instance */
    picture -> addGraphic(line1);
    picture -> addGraphic(line2);
    picture -> addGraphic(rectangle1);
    picture -> addGraphic(circle1);
    picture -> addGraphic(circle2);
    picture -> draw();
    
    /* Add Graph for Line/Circle/Rectangle objects */
    try {
        line1 -> addGraphic(line1);
        circle1 -> addGraphic(line1);
        rectangle1 -> addGraphic(line1);
    } catch (const char* error) {
        std::cout << error;
    }
    
    return 0;
}
