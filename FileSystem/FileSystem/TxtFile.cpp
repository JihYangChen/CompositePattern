#include "TxtFile.h"

TxtFile::TxtFile(string name, int size): name(name), size(size) {}

string TxtFile::getName() {
    return name + ".txt";
}

int TxtFile::getSize() {
    return size;
}

DirectoryElement* TxtFile::findDirectoryElement(string keyword) {
    DirectoryElement* foundElement = nullptr;
    if (keyword == getName())
        foundElement = this;
    
    return foundElement;
}
