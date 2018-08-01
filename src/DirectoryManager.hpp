#ifndef __DIRECTORYMANAGER_H__
#define __DIRECTORYMANAGER_H__

#include <string>
#include <vector>
#include <dirent.h>
#include <errno.h>

#include <iostream>

class DirectoryManager 
{
    private:
        std::string dirPath;
        DIR* dirHandle;
        struct dirent* dirRent;
    public:
        DirectoryManager();
        ~DirectoryManager();
        // GET-Methods
        std::string getDirPath();
        // SET-Methods
        void setDirPath(std::string dirPath);        
        // Class-Methods
        bool checkIsDirectory();
        std::vector<std::string> getDirectoryList();

};

#endif // __DIRECTORYMANAGER_H__