#pragma once
#include "ObjectInfo.h"
#include "EconomyManager.h"
#include "BaseManager.h"

namespace OpponentModelling {

	typedef std::vector<CObjectInfo*>			ObjectInfoVector;
	typedef std::map<int, ObjectInfoVector>		MapUnitTypeVector;

	bool cmpO(const CObjectInfo * a, const CObjectInfo * b);
	bool cmpI(const CObjectInfo * a, const int & b);

	class CPlayerModel {

	public:

		CPlayerModel();
		~CPlayerModel();
		ObjectInfoVector getAllUnits()const;
		MapUnitTypeVector getMapOfAllUnits()const;
		void unitUpdate(BWAPI::Unit unitToBeUpdated);
		void updateKnownUnit(BWAPI::Unit unitToBeUpdated);
		void addUnit(CObjectInfo *unitToBeAdded);
		void addUnit(BWAPI::Unit unitToBeAdded);
		bool containsUnit(BWAPI::UnitTypes::Enum::Enum unitTypeID);
		CObjectInfo *getUnitByID(int unitID);
		void removeUnit(int unitID);

	private:

		ObjectInfoVector AllUnitsStored;
		CEconomyManager *EconomyHandler;
		CBaseManager	*BasesHandler;
		MapUnitTypeVector UnitsMap;
		std::vector<CObjectInfo*>::iterator bound;
	};
}