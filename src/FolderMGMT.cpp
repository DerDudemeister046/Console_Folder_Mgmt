#include "FolderMGMT.hpp"

FolderMGMT::FolderMGMT()
{
    dirMGMT = new DirectoryManager;
    fileMGMT = new FileManager;
}

FolderMGMT::~FolderMGMT()
{
    delete(dirMGMT);
    delete(fileMGMT);
}

void FolderMGMT::initialize()
{
    int choice = 0;
    std::string path = "";
    bool running = true;

    while (running)
    {
        /*
        for (int i=0; i<300; i++)
        {
            std::cout << "\n" << std::endl;
        }
        */
        
        std::cout << "\n########################################\n" << std::endl
        << "\t\tFolderMGMT\n" << std::endl
        << "FileName:\t[" << fileMGMT->getFile() << "]" << std::endl
        << "Path:\t\t[" << dirMGMT->getDirPath() << "]" << std::endl
        << "\n########################################\n" << std::endl
        << "1 - change path" << std::endl
        << "2 - output folders in path" << std::endl
        << "3 - output files in path" << std::endl
        << "9 - exit" << std::endl; 

        std::cout << "Enter: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                std::cout << "\nPlease enter a path: ";
                std::cin >> path;
                dirMGMT->setDirPath(path);
                break;
            case 2:        
                std::cout << "\nOutput of [" << dirMGMT->getDirPath() << "]" << std::endl;
                outputFolderList();
                std::cin.get();
                break;
            case 3:        
                std::cout << "\nOutput of [" << dirMGMT->getDirPath() << "]" << std::endl;
                outputFileList();
                std::cin.get();
                break;
            case 9:
                std::cout << "Exiting FolderMGMT" << std::endl;
                running = false;
                break;
            default:
                std::cout << "wrong entry" << std::endl;
                break;
        } 
    }
}

void FolderMGMT::outputFolderList()
{
    for (int i=0; i<300; i++)
    {
        std::cout << "\n" << std::endl;
    }
    std::vector<std::string> list = dirMGMT->getDirectoryList();
    int x = list.size();
    for (int i=0; i<x; i++)
    {
        std::cout << list.at(i) << std::endl;
    }
}

void FolderMGMT::outputFileList()
{
    for (int i=0; i<300; i++)
    {
        std::cout << "\n" << std::endl;
    }
    std::vector<std::string> list = fileMGMT->ruleOutFolders(dirMGMT->getFullDirectoryList());    
    int x = list.size();
    for (int i=0; i<x; i++)
    {
        std::cout << list.at(i) << std::endl;
    }
}