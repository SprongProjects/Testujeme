#pragma once
#include "BWAPI.h"

namespace OpponentModelling {

	struct CObjectInfo {

		CObjectInfo();
		CObjectInfo(BWAPI::Unit unit);
		void updateUnit(BWAPI::Unit unit);

		const bool operator == (BWAPI::Unit unit) const;

		int  ID;
		int  Health;
		int  Shields;
		int	 Energy;
		bool Completed;
		bool IsMorphing;
		bool IsTraining;
		int	 Frame;

		BWAPI::Unit     Unit;
		BWAPI::UnitType UnitType;
		BWAPI::Position Position;
		BWAPI::TilePosition TilePosition;
		BWAPI::Player   Player;


	};
}
