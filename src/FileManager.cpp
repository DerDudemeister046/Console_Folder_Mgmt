#include "FileManager.hpp"

FileManager::FileManager()
{
    file = "./"; // Set a default string for initialization, will change in use
}

FileManager::~FileManager()
{

}

std::string FileManager::getFile()
{
    return file;
}

void FileManager::setFile(std::string file)
{
    this->file = file;
}

bool FileManager::checkIsFile(std::string pth)
{
    bool success = false;
    dirHandle = opendir(pth.c_str()); // Open Path that should be examined, converts std::string to const char*
    if(dirHandle == NULL)
    {   
        success = true;   
    }
    if(dirHandle != NULL)
    {
        success = false;
    }
    return success;
}

std::vector<std::string> FileManager::ruleOutFolders(std::vector<std::string> contentList)
{
    int x = contentList.size();
    std::vector<std::string> ruleOut;

    for (int i=0; i<x; i++)
    {
        if (checkIsFile(contentList.at(i)))
        {
            ruleOut.push_back(contentList.at(i));
        }
        if (!checkIsFile(contentList.at(i)))
        {
        }
    }
    return ruleOut; // Output Vector without Files    
}