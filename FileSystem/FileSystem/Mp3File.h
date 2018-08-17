#ifndef Mp3File_h
#define Mp3File_h

#include "DirectoryElement.h"

class Mp3File : public DirectoryElement {
public:
    Mp3File(string name, int size);
    string getName();
    int getSize();
    DirectoryElement* findDirectoryElement(string);

private:
    string name;
    int size;
};

#endif /* Mp3File_h */
