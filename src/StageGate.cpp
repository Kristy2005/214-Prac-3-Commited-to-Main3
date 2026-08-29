#include "StageGate.h"

bool StageGate::canAdmit() const {
	// TODO - implement StageGate::canAdmit
	throw "Not yet implemented";
}

bool StageGate::admitAttendee() {
	// TODO - implement StageGate::admitAttendee
	throw "Not yet implemented";
}

void StageGate::attendeeLeaves() {
	// TODO - implement StageGate::attendeeLeaves
	throw "Not yet implemented";
}

int StageGate::getOccupancy() const {
	// TODO - implement StageGate::getOccupancy
	throw "Not yet implemented";
}

void StageGate::update(const Notice& notice) {
	// TODO - implement StageGate::update
	throw "Not yet implemented";
}

StageGate::StageGate(std::string name, Stage* stage)
    : EventUnit(name, 0),currentOccupancy(0),admitting(true),controlledStage(stage){}