#ifndef DirectoryElement_h
#define DirectoryElement_h

#include <iostream>
#include <list>
using std::string;
using std::list;

class DirectoryElement {
public:
    virtual string getName() = 0;
    virtual int getSize() = 0;
    virtual DirectoryElement* findDirectoryElement(string) = 0;
    virtual list<DirectoryElement *> getDirectoryElements();
    virtual void addDirectoryElement(DirectoryElement *);
    virtual void removeDirectoryElement(DirectoryElement *);
};

#endif /* DirectoryElement_h */
