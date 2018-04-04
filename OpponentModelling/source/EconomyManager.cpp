#include "EconomyManager.h"

using namespace OpponentModelling;

CEconomyManager::CEconomyManager() {
	
}

void CEconomyManager::unitRemoved(CObjectInfo *unit) {
	MineralsLost += unit->UnitType.mineralPrice();
	GasLost += unit->UnitType.gasPrice();
}