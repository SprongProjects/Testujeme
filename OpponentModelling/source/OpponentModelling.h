#pragma once
#include "PlayerModel.h"
#include "OpponentsDirectory.h"
#include "BWAPI.h"

namespace OpponentModelling {

	class COpponentModelling {

	public:

		COpponentModelling();
		~COpponentModelling();
		CPlayerModel *COpponentModelling::getOpponentModel() const;

		/* BWAPI Bot funcitons */
		void onStart();
		void onEnd(bool isWinner);
		void onFrame();
		void onSendText(std::string text);
		void onReceiveText(BWAPI::Player player, std::string text);
		void onPlayerLeft(BWAPI::Player player);
		void onNukeDetect(BWAPI::Position target);
		void onUnitDiscover(BWAPI::Unit unit);
		void onUnitEvade(BWAPI::Unit unit);
		void onUnitShow(BWAPI::Unit unit);
		void onUnitHide(BWAPI::Unit unit);
		void onUnitCreate(BWAPI::Unit unit);
		void onUnitDestroy(BWAPI::Unit unit);
		void onUnitMorph(BWAPI::Unit unit);
		void onUnitRenegade(BWAPI::Unit unit);
		void onSaveGame(std::string gameName);
		void onUnitComplete(BWAPI::Unit unit);
		/* BWAPI Bot funcitons */

	private:

		CPlayerModel *Opponent;
		CPlayerModel *SelfGameModel;
		COpponentsDir *OpponentsFileHandler;

		BWAPI::Player self;
		BWAPI::Player enemy;
		void init();
		void updateUnit(BWAPI::Unit unit);
		void removeUnit(BWAPI::Unit unitID);


	};
}
// TODO
/*
	UNDO comment players in the constructor
	Renegade method - unit player changes
*/





