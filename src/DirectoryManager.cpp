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
bool DirectoryManager::checkIsDirectory(std::string directory)
{
    bool success = false;
    dirHandle = opendir(directory.c_str()); // Open Path that should be examined, converts std::string to const char*
    if(dirHandle != NULL)
    {
        //closedir(dirHandle);    // Close DIR after reading
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
    bool start = checkIsDirectory(getDirPath()); // security check if a valid path is given
    if (start)
    {
        dirHandle = opendir(getDirPath().c_str());
        while ((dirRent = readdir(dirHandle)) != NULL)
        {
            std::cout << dirRent->d_name << std::endl;
            std::string rootPath = getDirPath() + dirRent->d_name; 
            folderList.push_back(rootPath);
            std::cout << rootPath << std::endl;        
        }
    }    
    return sortOutFiles(folderList);
}

std::vector<std::string> DirectoryManager::sortOutFiles(std::vector<std::string> folderList)
{
    int x = folderList.size();
    std::vector<std::string> ruleOut;

    for (int i=0; i<x; i++)
    {
        //std::cout << i+1 << ": " << folderList.at(i) << std::endl;
        if (checkIsDirectory(folderList.at(i)))
        {
            std::cout << i+1 << ": - " << "TRUE" << std::endl;
            ruleOut.push_back(folderList.at(i));
        }
        if (!checkIsDirectory(folderList.at(i)))
        {
            std::cout << i+1 << ": - " << "FALSE" << std::endl;
        }
    }

    return ruleOut; // Output Vector without Files
}