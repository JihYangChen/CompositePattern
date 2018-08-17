#ifndef utDirectory_h
#define utDirectory_h

#include "Directory.h"
#include "utTxtFile.h"
#include "utMp3File.h"

TEST(Directory, constructor) {
    Directory dir("Dir");
    ASSERT_EQ("Dir", dir.getName());
}

TEST(Directory, emptyDirectory) {
    Directory dir("Dir");
    ASSERT_EQ(0, dir.getSize());
    ASSERT_TRUE(dir.getDirectoryElements().empty());
}

TEST(Directory, oneFiles) {
    Directory dir("Dir");
    DirectoryElement *file = new TxtFile("txtFile", 25);
    dir.addDirectoryElement(file);
    
    ASSERT_EQ(25, dir.getSize());
    ASSERT_EQ(1, dir.getDirectoryElements().size());
    ASSERT_EQ(file, dir.getDirectoryElements().front());
}

TEST(Directory, twoFiles) {
    Directory dir("Dir");
    DirectoryElement *file1 = new TxtFile("txtFile", 25);
    DirectoryElement *file2 = new Mp3File("mp3File", 248);
    dir.addDirectoryElement(file1);
    dir.addDirectoryElement(file2);
    
    ASSERT_EQ(273, dir.getSize());
    ASSERT_EQ(2, dir.getDirectoryElements().size());
    
    list<DirectoryElement *> directoryElements = dir.getDirectoryElements();
    ASSERT_EQ(file1, directoryElements.front());
    directoryElements.pop_front();
    ASSERT_EQ(file2, directoryElements.front());
}

TEST(Directory, twoLevelStructure) {
    Directory level1Dir("Dir1");
    Directory level2Dir("Dir2");
    DirectoryElement *file1 = new TxtFile("txtFile1", 25);
    DirectoryElement *file2 = new Mp3File("mp3File1", 248);
    DirectoryElement *file3 = new TxtFile("txtFile2", 30);
    DirectoryElement *file4 = new Mp3File("mp3File2", 7493);
    level1Dir.addDirectoryElement(file1);
    level1Dir.addDirectoryElement(file2);
    level2Dir.addDirectoryElement(&level1Dir);
    level2Dir.addDirectoryElement(file3);
    level2Dir.addDirectoryElement(file4);
    
    ASSERT_EQ(273, level1Dir.getSize());
    ASSERT_EQ(7796, level2Dir.getSize());
    ASSERT_EQ(2, level1Dir.getDirectoryElements().size());
    ASSERT_EQ(3, level2Dir.getDirectoryElements().size());
    
    list<DirectoryElement *> level1Elements = level1Dir.getDirectoryElements();
    list<DirectoryElement *> level2Elements = level2Dir.getDirectoryElements();
    
    ASSERT_EQ(file1, level1Elements.front());
    level1Elements.pop_front();
    ASSERT_EQ(file2, level1Elements.front());
    
    ASSERT_EQ(&level1Dir, level2Elements.front());
    level2Elements.pop_front();
    ASSERT_EQ(file3, level2Elements.front());
    level2Elements.pop_front();
    ASSERT_EQ(file4, level2Elements.front());
}

TEST(Directory, findElement_emptyDirectory) {
    Directory dir("Dir");
    ASSERT_EQ(nullptr, dir.findDirectoryElement("test.txt"));
}

TEST(Directory, findElement_oneFiles) {
    Directory dir("Dir");
    DirectoryElement *file = new TxtFile("txtFile", 25);
    dir.addDirectoryElement(file);
    
    ASSERT_EQ(file, dir.findDirectoryElement("txtFile.txt"));
    ASSERT_EQ(nullptr, dir.findDirectoryElement("txtFile"));
}

TEST(Directory, findElement_twoFiles) {
    Directory dir("Dir");
    DirectoryElement *file1 = new TxtFile("txtFile", 25);
    DirectoryElement *file2 = new Mp3File("mp3File", 248);
    dir.addDirectoryElement(file1);
    dir.addDirectoryElement(file2);
    
    ASSERT_EQ(&dir, dir.findDirectoryElement("Dir"));
    ASSERT_EQ(file1, dir.findDirectoryElement("txtFile.txt"));
    ASSERT_EQ(file2, dir.findDirectoryElement("mp3File.mp3"));
    ASSERT_EQ(nullptr, dir.findDirectoryElement("txtFile"));
    ASSERT_EQ(nullptr, dir.findDirectoryElement("mp3File"));
}

TEST(Directory, findElement_twoLevelStructure) {
    Directory level1Dir("Dir1");
    Directory level2Dir("Dir2");
    DirectoryElement *file1 = new TxtFile("txtFile1", 25);
    DirectoryElement *file2 = new Mp3File("mp3File1", 248);
    DirectoryElement *file3 = new TxtFile("txtFile2", 30);
    DirectoryElement *file4 = new Mp3File("mp3File2", 7493);
    level1Dir.addDirectoryElement(file1);
    level1Dir.addDirectoryElement(file2);
    level2Dir.addDirectoryElement(&level1Dir);
    level2Dir.addDirectoryElement(file3);
    level2Dir.addDirectoryElement(file4);
    
    ASSERT_EQ(&level2Dir, level2Dir.findDirectoryElement("Dir2"));
    ASSERT_EQ(&level1Dir, level2Dir.findDirectoryElement("Dir1"));
    ASSERT_EQ(file1, level2Dir.findDirectoryElement("txtFile1.txt"));
    ASSERT_EQ(file2, level2Dir.findDirectoryElement("mp3File1.mp3"));
    ASSERT_EQ(file3, level2Dir.findDirectoryElement("txtFile2.txt"));
    ASSERT_EQ(file4, level2Dir.findDirectoryElement("mp3File2.mp3"));
}

#endif /* utDirectory_h */
