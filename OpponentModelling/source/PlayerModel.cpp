#include "PlayerModel.h"

using namespace OpponentModelling;

bool OpponentModelling::cmpO(const CObjectInfo * a, const CObjectInfo * b) {
	return a->ID < b->ID;
}

bool OpponentModelling::cmpI(const CObjectInfo *a, const int & b) {
	return a->ID < b;
}


CPlayerModel::CPlayerModel()  {
	EconomyHandler	= new CEconomyManager();
	BasesHandler = new CBaseManager();
}

CPlayerModel::~CPlayerModel() {
	delete EconomyHandler;
	delete BasesHandler;
}

ObjectInfoVector CPlayerModel::getAllUnits() const {
	return AllUnitsStored;
}

MapUnitTypeVector CPlayerModel::getMapOfAllUnits() const {
	return UnitsMap;
}

void CPlayerModel::updateKnownUnit(BWAPI::Unit unitToBeUpdated) {
	getUnitByID(unitToBeUpdated->getID())->updateUnit(unitToBeUpdated);
}

void CPlayerModel::unitUpdate(BWAPI::Unit unitToBeUpdated) {

	/* check whether we have already saved this unit and just needs to be updated */
	if (getUnitByID(unitToBeUpdated->getID()) == nullptr)
		addUnit(unitToBeUpdated);
	else
		updateKnownUnit(unitToBeUpdated);
}

void CPlayerModel::addUnit(CObjectInfo *unitToBeAdded) { 
	
	/* Find the place using upperbound, sorted units are by ID */
	bound = std::upper_bound(AllUnitsStored.begin(), AllUnitsStored.end(), unitToBeAdded, cmpO);
	AllUnitsStored.insert(bound, unitToBeAdded);
	
	/* If this type of unit wasnt added yet, add the key - creates initial vector */
	if (UnitsMap.find(unitToBeAdded->UnitType.getID()) == UnitsMap.end())
		UnitsMap[unitToBeAdded->UnitType.getID()];

	bound = std::upper_bound(UnitsMap.at(unitToBeAdded->UnitType.getID()).begin(), UnitsMap.at(unitToBeAdded->UnitType.getID()).end(), unitToBeAdded, cmpO);
	UnitsMap.at(unitToBeAdded->UnitType.getID()).insert(bound, unitToBeAdded);
	
	if (unitToBeAdded->UnitType.isResourceDepot())
		BasesHandler->addBase(unitToBeAdded);

}

void CPlayerModel::addUnit(BWAPI::Unit unitToBeAdded) {
	CObjectInfo *tmp = new CObjectInfo(unitToBeAdded);
	addUnit(tmp);
}

void CPlayerModel::removeUnit(int UnitID) {

	CObjectInfo * unit = getUnitByID(UnitID);

	/* Just in case we didnt store the unit */
	if (unit == nullptr)
		return;

	EconomyHandler->unitRemoved(unit);

	/* Find the unit in vector and map using logn lower bound */
	bound = std::lower_bound(AllUnitsStored.begin(), AllUnitsStored.end(), UnitID, cmpI);
	CObjectInfo * tmp = AllUnitsStored.at(bound - AllUnitsStored.begin());
	AllUnitsStored.erase(bound);

	bound = std::lower_bound(UnitsMap.at(tmp->UnitType.getID()).begin(), UnitsMap.at(tmp->UnitType.getID()).end(), UnitID, cmpI);
	UnitsMap.at(tmp->UnitType.getID()).erase(bound);

	/* delete the mess, vector and map store only pointer type, so we delete the object only once */
	delete tmp;
}

bool CPlayerModel::containsUnit(BWAPI::UnitTypes::Enum::Enum unitTypeID) {
	return UnitsMap[unitTypeID].size() != 0;
}

CObjectInfo *CPlayerModel::getUnitByID(int UnitID) {
	bound = std::lower_bound(AllUnitsStored.begin(), AllUnitsStored.end(), UnitID, cmpI);
	if (bound != AllUnitsStored.end() && AllUnitsStored.at(bound - AllUnitsStored.begin())->ID == UnitID )
		return AllUnitsStored.at(bound - AllUnitsStored.begin());
	return nullptr;
}

