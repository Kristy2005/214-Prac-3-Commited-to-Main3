#include "EventUnit.h"
#include <iostream>

void EventUnit::open(){
    
    isOpen = true;
    std::cout << getName() << " is open" << std::endl;
}

void EventUnit::close(){

    isOpen = false;
    std::cout << getName() << " is closed" << std::endl;
}

void EventUnit::reportStatus() const{
    
	if (isOpen == true){
        std::cout << getName() << " is open" << std::endl;
    }
    else{
        std::cout << getName() << " is closed" << std::endl;
    }
}

int EventUnit::getCapacity() const{
    return capacity;
}

EventUnit::~EventUnit()
{
    // no dynamic objects
}

EventUnit::EventUnit(std::string name, int capacity)
    : EventComponent(name),capacity(capacity),isOpen(false){}