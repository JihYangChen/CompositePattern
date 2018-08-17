#ifndef TxtFile_h
#define TxtFile_h

#include "DirectoryElement.h"

class TxtFile : public DirectoryElement {
public:
    TxtFile(string name, int size);
    string getName();
    int getSize();
    DirectoryElement* findDirectoryElement(string);

private:
    string name;
    int size;
};


#endif /* TxtFile_h */
