#include "EventComponent.h"

EventComponent::~EventComponent(){}//nothing to delete

std::string EventComponent::getName() const {
	return this->name;
}

EventComponent::EventComponent(std::string name)
    : name(name){}