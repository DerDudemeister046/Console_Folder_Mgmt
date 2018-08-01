#ifndef __FILEMANAGER_H__
#define __FILEMANAGER_H__

#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <errno.h>

class FileManager 
{
    private:
        std::string file;
        DIR* dirHandle;
        struct dirent* dirRent;
    public:
        FileManager();
        ~FileManager();
        // GET-Methods
        std::string getFile();
        // SET-Methods
        void setFile(std::string file);
        //Class-Methods        
        bool checkIsFile(std::string pth);
        std::vector<std::string> ruleOutFolders(std::vector<std::string> contentList);
};

#endif // __FILEMANAGER_H__