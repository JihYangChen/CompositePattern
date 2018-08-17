#ifndef Directory_hpp
#define Directory_hpp

#include "DirectoryElement.h"

class Directory : public DirectoryElement {
public:
    Directory(string name);
    string getName();
    int getSize();
    list<DirectoryElement *> getDirectoryElements();
    void addDirectoryElement(DirectoryElement *);
    void removeDirectoryElement(DirectoryElement *);
    DirectoryElement* findDirectoryElement(string);
    
private:
    string name;
    int size;
    list<DirectoryElement *> directoryElements;
};

#endif /* Directory_h */
