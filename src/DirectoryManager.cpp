#include "DirectoryManager.hpp"

DirectoryManager::DirectoryManager()
{

}

DirectoryManager::~DirectoryManager()
{

}

// GET-Methods
std::string DirectoryManager::getDirPath()
{
    return dirPath;
}

// SET-Methods
void DirectoryManager::setDirPath(std::string dirPath)
{
    this->dirPath = dirPath;
}

// Class-Methods
bool DirectoryManager::checkIsDirectory()
{
    bool success = false;
    dirHandle = opendir(getDirPath().c_str()); // Open Path that should be examined, converts std::string to const char*
    if(dirHandle != NULL)
    {
        closedir(dirHandle);    // Close DIR after reading
        success = true;
    }
    if (errno == ENOTDIR)
    {
        success = false;    // set success false if not a directory
    }
    return success; // return success as result of check
}

std::vector<std::string> DirectoryManager::getDirectoryList()
{
    std::vector<std::string> folderList;
    bool start = checkIsDirectory(); // security check if a valid path is given
    if (start)
    {
        dirHandle = opendir(getDirPath().c_str());
        while ((dirRent = readdir(dirHandle)) != NULL)
        {
            std::string rootPath = getDirPath() + dirRent->d_name;            
            folderList.push_back(rootPath);
        }
    }
    return folderList;
}