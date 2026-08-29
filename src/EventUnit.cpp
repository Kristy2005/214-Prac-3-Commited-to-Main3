#include "EventUnit.h"

void EventUnit::open() {
	// TODO - implement EventUnit::open
	throw "Not yet implemented";
}

void EventUnit::close() {
	// TODO - implement EventUnit::close
	throw "Not yet implemented";
}

void EventUnit::reportStatus() const {
	// TODO - implement EventUnit::reportStatus
	throw "Not yet implemented";
}

int EventUnit::getCapacity() const {
	return this->capacity;
}

EventUnit::~EventUnit() {
	// TODO - implement EventUnit::~EventUnit
	throw "Not yet implemented";
}

EventUnit::EventUnit(std::string name, int capacity)
    : EventComponent(name), capacity(capacity), isOpen(false){}
