#include "OpponentsDirectory.h"

using namespace OpponentModelling;

COpponentsDir::COpponentsDir() {
	AllKnownOpponents = findAllOpponents();
}

bool COpponentsDir::isThereFileForOpp(std::string nameOfOpponent) {
	for (auto it : AllKnownOpponents)
		if (nameOfOpponent == it)
			return true;
	return false;
}

void COpponentsDir::createFileForOpp(std::string opponentsNick) {
	
	std::string fileName = opponentsNick + ".txt";
	std::ofstream outfile(fileName);
	outfile << std::endl;
	outfile.close();
}

bool COpponentsDir::insertIntoFile(std::string toBeInserted) {

	return true;
}


std::vector<std::string> COpponentsDir::findAllOpponents() {

	std::vector<std::string> tmp;

	std::string pattern(OpponentsDirPath);
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind = FindFirstFile(OpponentsDirPath, &data);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Finding files with opponents failed with (%d) error code.\n", GetLastError());
		dirWithOpponentsFounded = false;
		return tmp;
	}
		do {
			tmp.push_back(data.cFileName);
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);

	dirWithOpponentsFounded = true;
	return tmp;
}