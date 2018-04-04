#pragma once
#include "BWTA.h"
#include "ObjectInfo.h"

namespace OpponentModelling {
	class CBaseManager {

	public:
		CBaseManager();
		void addBase(CObjectInfo * depot);
		void removeBase(CObjectInfo * depot);

	private:
		std::map<BWTA::BaseLocation *, CObjectInfo *>	AllPossibleBases;
		BWAPI::Player self;
		BWAPI::Player enemy;
		int OpponentsBases;
		int MyBases;

		bool closeEnough(BWAPI::TilePosition a, BWAPI::TilePosition b);
	};
}
