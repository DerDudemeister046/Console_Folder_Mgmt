#ifndef __DIRECTORYMANAGER_H__
#define __DIRECTORYMANAGER_H__

#include <string>
#include <dirent.h>

class DirectoryManager 
{
    private:
        std::string directory;
    public:
        DirectoryManager();
        ~DirectoryManager();
        
        // Class-Methods
        bool checkIsDirectory();
};

#endif // __DIRECTORYMANAGER_H__