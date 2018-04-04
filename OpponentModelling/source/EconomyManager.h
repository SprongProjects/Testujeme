#pragma once
#include "ObjectInfo.h"

namespace OpponentModelling {
	class CEconomyManager {

	public:

		CEconomyManager();
		void unitRemoved(CObjectInfo *unit);

	private:
		int MineralsLost;
		int GasLost;

		int MineralsMined;
		int GasMined;

	};
}

// TODO
// add approximate amount of minerals/gas
// mined by opponend based on his workers, etc.
// add approximate income