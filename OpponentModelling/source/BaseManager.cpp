#include "BaseManager.h"

using namespace OpponentModelling;

CBaseManager::CBaseManager() {
	
	for (BWTA::BaseLocation * base : BWTA::getBaseLocations())
		AllPossibleBases[base];

	self = BWAPI::Broodwar->self();
	enemy = BWAPI::Broodwar->enemy();
	OpponentsBases = 0;
	MyBases = 0;
}

// UAlbertaBot function
// checks if two places tilepositions are so close that it can be considered as one spot
bool CBaseManager::closeEnough(BWAPI::TilePosition a, BWAPI::TilePosition b){ 
	return abs(a.x - b.x) <= 2 && abs(a.y - b.y) <= 2;
}

void CBaseManager::addBase(CObjectInfo * depot){
	
	for (BWTA::BaseLocation * base : BWTA::getBaseLocations())
	{
		if (closeEnough(base->getTilePosition(), depot->TilePosition))
		{
			if (depot->Player == self)
				++MyBases;
			else if (depot->Player == enemy)
				++OpponentsBases;
			AllPossibleBases[base] = depot;
			return;
		}
	}
}

void CBaseManager::removeBase(CObjectInfo * depot) {
	for (BWTA::BaseLocation * base : BWTA::getBaseLocations())
	{
		if (closeEnough(base->getTilePosition(), depot->TilePosition))
		{
			AllPossibleBases.erase(base);
			if (depot->Player == self)
				--MyBases;
			else if (depot->Player == enemy)
				--OpponentsBases;
			return;
		}
	}

}