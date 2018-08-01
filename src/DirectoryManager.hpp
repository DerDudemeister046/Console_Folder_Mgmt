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
        bool checkIsDirectory(std::string directory);
        std::vector<std::string> getDirectoryList();
        std::vector<std::string> sortOutFiles(std::vector<std::string> folderList);
};

#endif // __DIRECTORYMANAGER_H__