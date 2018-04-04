#pragma once
#include <cstdlib>
#include <cstdio>
#include <tchar.h>
#include <string>
#include <windows.h>
#include <vector>
#include <iostream>
#include <fstream> 

namespace OpponentModelling {
	class COpponentsDir {

	public:
		COpponentsDir();

	private:

		bool dirWithOpponentsFounded = false;
		const char *OpponentsDirPath = "D:\\UAlberta\\ualbertabot-master\\OpponentModelling\\opponentsDir";
		std::vector<std::string> AllKnownOpponents;

		bool isThereFileForOpp(std::string nameOfFile);
		void createFileForOpp(std::string opponentsNick);
		bool insertIntoFile(std::string toBeInserted);
		std::vector<std::string> findAllOpponents();


	};
}

// TODO
// add what should we save into files
// opponents builds? (Like SC2 score screen) Only units? Or whole graph like the one in the score screen?

