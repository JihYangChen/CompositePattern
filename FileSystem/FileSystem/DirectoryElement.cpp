#include "DirectoryElement.h"

list<DirectoryElement *> DirectoryElement::getDirectoryElements() {
    throw string("Cannot get directory elements with non Directory instance");
}

void DirectoryElement::addDirectoryElement(DirectoryElement *) {
    throw string("Cannot add directory element with non Directory instance");
}

void DirectoryElement::removeDirectoryElement(DirectoryElement *) {
    throw string("Cannot remove directory element with non Directory instance");
}
