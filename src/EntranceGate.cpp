#include "EntranceGate.h"

bool EntranceGate::checkID(int age) const {
	// TODO - implement EntranceGate::checkID
	throw "Not yet implemented";
}

bool EntranceGate::admitAttendee(int age) {
	// TODO - implement EntranceGate::admitAttendee
	throw "Not yet implemented";
}

void EntranceGate::update(const Notice& notice) {
	// TODO - implement EntranceGate::update
	throw "Not yet implemented";
}

EntranceGate::EntranceGate(std::string name, int minimumAge)
    : EventUnit(name, 0),minimumAge(minimumAge),admitting(true){}
