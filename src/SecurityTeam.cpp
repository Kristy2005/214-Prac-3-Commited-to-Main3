#include "SecurityTeam.h"

void SecurityTeam::deploy() {
	// TODO - implement SecurityTeam::deploy
	throw "Not yet implemented";
}

void SecurityTeam::update(const Notice& notice) {
	// TODO - implement SecurityTeam::update
	throw "Not yet implemented";
}

SecurityTeam::SecurityTeam(std::string name)
    : EventUnit(name, 0),deployed(false){}
