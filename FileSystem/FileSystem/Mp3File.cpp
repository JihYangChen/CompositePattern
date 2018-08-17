#include "Mp3File.h"

Mp3File::Mp3File(string name, int size): name(name), size(size) {}

string Mp3File::getName() {
    return name + ".mp3";
}

int Mp3File::getSize() {
    return size;
}

DirectoryElement* Mp3File::findDirectoryElement(string keyword) {
    DirectoryElement* foundElement = nullptr;
    if (keyword == getName())
        foundElement = this;
    
    return foundElement;
}
