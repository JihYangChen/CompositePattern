#ifndef utMp3File_h
#define utMp3File_h

#include "Mp3File.h"

TEST(Mp3File, constructor) {
    Mp3File mp3File("mp3File", 248);
    ASSERT_EQ("mp3File.mp3", mp3File.getName());
    ASSERT_EQ(248, mp3File.getSize());
}

TEST(Mp3File, getDirectoryElements) {
    try {
        Mp3File mp3File("mp3File", 248);
        mp3File.getDirectoryElements();
    } catch (string exception) {
        ASSERT_EQ(exception, "Cannot get directory elements with non Directory instance");
    }
}

TEST(Mp3File, addDirectoryElement) {
    try {
        Mp3File mp3File("mp3File", 248);
        mp3File.addDirectoryElement(&mp3File);
    } catch (string exception) {
        ASSERT_EQ(exception, "Cannot add directory element with non Directory instance");
    }
}

TEST(Mp3File, removeDirectoryElement) {
    try {
        Mp3File mp3File("mp3File", 248);
        mp3File.removeDirectoryElement(&mp3File);
    } catch (string exception) {
        ASSERT_EQ(exception, "Cannot remove directory element with non Directory instance");
    }
}

TEST(Mp3File, findDirectoryElement) {
    Mp3File mp3File("mp3File", 248);
    ASSERT_EQ(&mp3File, mp3File.findDirectoryElement("mp3File.mp3"));
}

TEST(Mp3File, notFindDirectoryElement) {
    Mp3File mp3File("mp3File", 248);
    ASSERT_EQ(nullptr, mp3File.findDirectoryElement("txtFile.mp3"));
}

#endif /* utMp3File_h */
