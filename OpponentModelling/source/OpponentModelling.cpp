#include "OpponentModelling.h"

using namespace OpponentModelling;

COpponentModelling::COpponentModelling() {
	Opponent = new CPlayerModel();
	SelfGameModel = new CPlayerModel();
	OpponentsFileHandler = new COpponentsDir();
	enemy = nullptr; //BWAPI::Broodwar->enemy();
	self = nullptr; //BWAPI::Broodwar->self();
}

COpponentModelling::~COpponentModelling() {
	delete Opponent;
	delete SelfGameModel;
	delete OpponentsFileHandler;
}

CPlayerModel *COpponentModelling::getOpponentModel() const{
	return Opponent;
}

void COpponentModelling::updateUnit(BWAPI::Unit unit) {
	if (unit->getPlayer() == self)
		Opponent->unitUpdate(unit);		 // Unit I own
	else if (unit->getPlayer() == enemy)
		SelfGameModel->unitUpdate(unit); // Unit my opponent owns
}

void COpponentModelling::removeUnit(BWAPI::Unit unit) {
	if (unit->getPlayer() == self)
		Opponent->removeUnit(unit->getID());		 // Unit I own
	else if (unit->getPlayer() == enemy)
		SelfGameModel->removeUnit(unit->getID()); // Unit my opponent owns
}

/* --------------- BWAPI BOT FUNCTIONS --------------- */
void COpponentModelling::onStart() {
	init();
}

void COpponentModelling::onEnd(bool isWinner) {}
void COpponentModelling::onFrame() {}
void COpponentModelling::onSendText(std::string text) {}
void COpponentModelling::onReceiveText(BWAPI::Player player, std::string text) {}
void COpponentModelling::onPlayerLeft(BWAPI::Player player) {}
void COpponentModelling::onNukeDetect(BWAPI::Position target) {}
void COpponentModelling::onUnitDiscover(BWAPI::Unit unit) {
	updateUnit(unit);
}
void COpponentModelling::onUnitEvade(BWAPI::Unit unit) {}
void COpponentModelling::onUnitShow(BWAPI::Unit unit) {
	updateUnit(unit);
}
void COpponentModelling::onUnitHide(BWAPI::Unit unit) {
	updateUnit(unit);
}
void COpponentModelling::onUnitCreate(BWAPI::Unit unit) {
	updateUnit(unit);
}
void COpponentModelling::onUnitDestroy(BWAPI::Unit unit) {
	removeUnit(unit);
}
void COpponentModelling::onUnitMorph(BWAPI::Unit unit) {
	updateUnit(unit);
}
void COpponentModelling::onUnitRenegade(BWAPI::Unit unit) {
	
}
void COpponentModelling::onSaveGame(std::string gameName) {}
void COpponentModelling::onUnitComplete(BWAPI::Unit unit) {
	updateUnit(unit);
}

/* --------------- BWAPI BOT FUNCTIONS --------------- */

void COpponentModelling::init() {

}