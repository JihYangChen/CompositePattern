#include "Graphic.h"
#include <string>

using std::string;

void Graphic::addGraphic(Graphic *g) {
    throw string("Cannot add graphic with non Graphic instance");
}
