#include "Directory.h"

Directory::Directory(string name): name(name) {}

string Directory::getName() {
    return name;
}

int Directory::getSize() {
    int totalSize = 0;
    for (auto directoryElement : directoryElements)
        totalSize += directoryElement->getSize();
    
    return totalSize;
}

list<DirectoryElement *> Directory::getDirectoryElements() {
    return directoryElements;
}

void Directory::addDirectoryElement(DirectoryElement *element) {
    directoryElements.push_back(element);
}

void Directory::removeDirectoryElement(DirectoryElement *element) {
    directoryElements.remove(element);
}

DirectoryElement* Directory::findDirectoryElement(string keyword) {
    DirectoryElement* foundElement = nullptr;
    
    if (keyword == name)
        foundElement = this;
    else {
        for (auto directoryElement : directoryElements) {
            DirectoryElement* subDirectoryFoundElement = directoryElement -> findDirectoryElement(keyword);
            if (subDirectoryFoundElement != nullptr) {
                foundElement = subDirectoryFoundElement;
                break;
            }
        }
    }
    
    return foundElement;
}
