#ifndef __FOLDERMGMT_HPP__
#define __FOLDERMGMT_HPP__

#include <iostream>
#include <string>
#include "DirectoryManager.hpp"
#include "FileManager.hpp"

class FolderMGMT 
{
    private:
        DirectoryManager* dirMGMT;
        FileManager* fileMGMT;
    public:
        FolderMGMT();
        ~FolderMGMT();
        //Class-Functions
        void initialize();
        void outputFolderList();
        void outputFileList();
};

#endif