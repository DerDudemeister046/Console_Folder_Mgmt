#include <iostream>
#include <dirent.h>

// Testing includes
#include <string>
#include "DirectoryManager.hpp"
#include <vector>

int main()
{
	std::string input = ""; 
	DirectoryManager* dirMgr = new DirectoryManager;
	std::cout << "" << std::endl;
	std::cout << "Eingabe: ";
	std::cin >> input;

	dirMgr->setDirPath(input);

	if (dirMgr->checkIsDirectory() == true)
	{
		std::cout << "VERZEICHNIS!" << std::endl;
	} else
	{
		std::cout << "KEIN VERZEICHNIS!" << std::endl;
	}

	std::vector<std::string> folders = dirMgr->getDirectoryList();
	int a = folders.size();

	std::cout << "ORDNER: " << a << std::endl;

	for (int i=0; i<a; i++)
	{
		std::cout << i+1 << ". ORDNER: " << folders.at(i) << std::endl;		
	}

		
	//std::string dir = "C:/Users/Andi/Desktop/Console_Folder_Mgmt/test.txt";
	/*
	std::string dir = "G:/";
	struct dirent *dr;	// Pointer for directory Entry
	DIR* directory = opendir(dir.c_str());

	if(directory != NULL)
	{
		std::cout << "Ist ein Verzeichnis!" << std::endl;
	}
	if (directory == NULL)
	{
		std::cout << "Ist kein Verzeichnis!" << std::endl;
		return 0;
	}

	while ((dr = readdir(directory)) != NULL)
	{
		std::cout << "FOLDER: " << dr->d_name << std::endl;		
	}

	std::cin.get();
	closedir(directory);
	return 0;*/
}

/*
// Includes
#include <iostream>
#include <string>
// Variables
int choice = 0;
std::string directory = "";
// Functions
void enterDirectory();
// Main-Function
int main ()
{
	std::cout << "\tHauptmenü" << std::endl;
	std::cout << "1.) - Verzeichnis eingeben" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Auswahl: ";
	std::cin >> choice;

	switch (choice)
	{
		case 1:
				enterDirectory();
				break;
		case 2:
				break;
		case 3:
				break;
		case 4:
				break;
		case 5:
				break;
		case 6:
				break;
		case 7:
				break;
		case 8:
				break;
		case 9:
				break;
		default:
				std::cout << "Ungültige Auswahl" << std::endl;
				break;
	
	}

	return 0;
}

void enterDirectory()
{

}
*/