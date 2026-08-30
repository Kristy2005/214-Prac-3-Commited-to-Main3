#include "EventUnit.h"
#include <iostream>

void EventUnit::open() {
	this->isOpen = true;
	std::cout<<"[Event Unit] " << this->name << "is now OPEN" <<std::endl;
}

void EventUnit::close() {
	this->isOpen = false;
	std::cout<<"[Event Unit] " << this->name << "is now CLOSED" <<std::endl;
}

void EventUnit::reportStatus() const {
	std::cout << "Unit: " << this->name 
              << " | Capacity: " << this->capacity 
              << " | Status: " << (this->isOpen ? "OPEN" : "CLOSED") 
              << std::endl;
}

int EventUnit::getCapacity() const{
    return capacity;
}

EventUnit::~EventUnit() {
	//NO MEMORY TO DEALLOCATE 
}

EventUnit::EventUnit(std::string name, int capacity)
    : EventComponent(name),capacity(capacity),isOpen(false){}