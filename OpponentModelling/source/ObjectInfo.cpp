#include "ObjectInfo.h"

using namespace OpponentModelling;

CObjectInfo::CObjectInfo()
{
	ID			= 0;
	Health		= 0;
	Shields		= 0;
	Energy		= 0;
	Completed	= true;
	IsTraining	= false;
	IsMorphing	= false;
	Frame		= 0;
	
	
	Unit	 = nullptr;
	UnitType = BWAPI::UnitTypes::None;
	Position = BWAPI::Positions::None;
	TilePosition = BWAPI::TilePositions::None;
	Player	 = nullptr;
}

CObjectInfo::CObjectInfo(BWAPI::Unit unit)
{
	ID			= unit->getID();
	Health		= unit->getHitPoints();
	Shields		= unit->getShields();
	Energy		= unit->getEnergy();
	Completed	= unit->isCompleted();
	IsTraining	= unit->isTraining();
	IsMorphing	= unit->isMorphing();
	Frame		= BWAPI::Broodwar->getFrameCount();
	
	Unit	 = unit;
	UnitType = unit->getType();
	Position = unit->getPosition();
	TilePosition = unit->getTilePosition();
	Player	 = unit->getPlayer();
}

void CObjectInfo::updateUnit(BWAPI::Unit unit) {
	Health = unit->getHitPoints();
	Shields = unit->getShields();
	Energy = unit->getEnergy();
	Completed = unit->isCompleted();
	IsTraining = unit->isTraining();
	IsMorphing = unit->isMorphing();
	Frame = BWAPI::Broodwar->getFrameCount();

	Unit = unit;
	UnitType = unit->getType();
	Position = unit->getPosition();
	TilePosition = unit->getTilePosition();
	Player = unit->getPlayer();
}

const bool CObjectInfo::operator == (BWAPI::Unit unit) const
{
	return ID == unit->getID();
}