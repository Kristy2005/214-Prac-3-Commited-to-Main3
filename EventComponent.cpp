#include "EventComponent.h"

EventComponent::~EventComponent() {
	//NO MEMORY TO DEALLOCATE 
}

std::string EventComponent::getName() const {
	return this->name;
}

EventComponent::EventComponent(std::string name)
    : name(name){}