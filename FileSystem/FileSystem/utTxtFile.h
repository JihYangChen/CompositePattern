#ifndef utTxtFile_h
#define utTxtFile_h

#include "TxtFile.h"

TEST(TxtFile, constructor) {
    TxtFile txtFile("txtFile", 25);
    ASSERT_EQ("txtFile.txt", txtFile.getName());
    ASSERT_EQ(25, txtFile.getSize());
}

TEST(TxtFile, getDirectoryElements) {
    try {
        TxtFile txtFile("txtFile", 25);
        txtFile.getDirectoryElements();
    } catch (const char* exception) {
        ASSERT_EQ(exception, "Cannot get directory elements with non Directory instance");
    }
}

TEST(TxtFile, addDirectoryElement) {
    try {
        TxtFile txtFile("txtFile", 25);
        txtFile.addDirectoryElement(&txtFile);
    } catch (const char* exception) {
        ASSERT_EQ(exception, "Cannot add directory element with non Directory instance");
    }
}

TEST(TxtFile, removeDirectoryElement) {
    try {
        TxtFile txtFile("txtFile", 25);
        txtFile.removeDirectoryElement(&txtFile);
    } catch (const char* exception) {
        ASSERT_EQ(exception, "Cannot remove directory element with non Directory instance");
    }
}

TEST(TxtFile, findDirectoryElement) {
    TxtFile txtFile("txtFile", 25);
    ASSERT_EQ(&txtFile, txtFile.findDirectoryElement("txtFile.txt"));
}
    
TEST(TxtFile, notFindDirectoryElement) {
  TxtFile txtFile("txtFile", 25);
  ASSERT_EQ(nullptr, txtFile.findDirectoryElement("mp3File.txt"));
}

#endif /* utTxtFile_h */
