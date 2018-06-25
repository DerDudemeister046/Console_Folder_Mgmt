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
