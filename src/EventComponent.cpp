#include "EventComponent.h"

EventComponent::~EventComponent() {
	// TODO - implement EventComponent::~EventComponent
	throw "Not yet implemented";
}

std::string EventComponent::getName() const {
	return this->name;
}

EventComponent::EventComponent(std::string name)
    : name(name){}