#include "DirectoryElement.h"

list<DirectoryElement *> DirectoryElement::getDirectoryElements() {
    throw "Cannot get directory elements with non Directory instance";
}

void DirectoryElement::addDirectoryElement(DirectoryElement *) {
    throw "Cannot add directory element with non Directory instance";
}

void DirectoryElement::removeDirectoryElement(DirectoryElement *) {
    throw "Cannot remove directory element with non Directory instance";
}
