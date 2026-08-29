#include "EventGroup.h"

void EventGroup::add(EventComponent* child) {
	// TODO - implement EventGroup::add
	throw "Not yet implemented";
}

EventComponent* EventGroup::remove(EventComponent* child) {
	// TODO - implement EventGroup::remove
	throw "Not yet implemented";
}

void EventGroup::open() {
	// TODO - implement EventGroup::open
	throw "Not yet implemented";
}

void EventGroup::close() {
	// TODO - implement EventGroup::close
	throw "Not yet implemented";
}

void EventGroup::reportStatus() const {
	// TODO - implement EventGroup::reportStatus
	throw "Not yet implemented";
}

int EventGroup::getCapacity() const {
	// TODO - implement EventGroup::getCapacity
	throw "Not yet implemented";
}

void EventGroup::update(const Notice& notice) {
	// TODO - implement EventGroup::update
	throw "Not yet implemented";
}

void EventGroup::notify(const Notice& notice) {
	// TODO - implement EventGroup::notify
	throw "Not yet implemented";
}

EventGroup::~EventGroup() {
	// TODO - implement EventGroup::~EventGroup
	throw "Not yet implemented";
}

EventGroup::EventGroup(std::string name)
    : EventComponent(name), isOpen(false){}
