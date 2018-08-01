#include "FolderMGMT.hpp"

int main()
{
	FolderMGMT* fmgmt = new FolderMGMT;

	fmgmt->initialize();	
	std::cin.get();
	delete(fmgmt);
	return 0;
}