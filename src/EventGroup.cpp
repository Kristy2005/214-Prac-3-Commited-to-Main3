#include "EventGroup.h"
#include <iostream>

//constructor
EventGroup::EventGroup(std::string name)
    : EventComponent(name), isOpen(false){}


void EventGroup::add(EventComponent* child)
{
    //do not add a null pointer
    if (child == nullptr){
        return;
    }

    for(size_t i = 0; i < children.size(); i++){ //size_t is the proper type used for container sizes/indexes
        //do not add the same child twice
        if (children[i] == child){
            return;
        }
    }

    // Add the new child
    children.push_back(child);
}


EventComponent* EventGroup::remove(EventComponent* child){

    for (size_t i = 0; i < children.size(); i++){
        if (children[i] == child){

            EventComponent* removedChild = children[i];
			children.erase(children.begin() + i);

            return removedChild;
        }
    }

    return nullptr;
}


void EventGroup::open(){

    isOpen = true;

    std::cout<<getName() << " is open" << std::endl;

    for(size_t i = 0; i < children.size(); i++){
        children[i]->open();
    }
}


void EventGroup::close(){

    isOpen = false;

    std::cout << getName() << " is closed" << std::endl;

    for (size_t i = 0; i < children.size(); i++){
        children[i]->close();
    }
}


void EventGroup::reportStatus() const{

    if (isOpen == true){
        std::cout << getName() << " is open" << std::endl;
    }else{
        std::cout << getName() << " is closed" << std::endl;
    }

    for(size_t i = 0; i < children.size(); i++){
        children[i]->reportStatus();
    }
}


int EventGroup::getCapacity() const{

    int totalCapacity = 0;

    for(size_t i = 0; i < children.size(); i++){
        totalCapacity = totalCapacity + children[i]->getCapacity();
    }

    return totalCapacity;
}


EventGroup::~EventGroup(){
    for (size_t i = 0; i < children.size(); i++){

        if (children[i] != nullptr){
            delete children[i];
            children[i] = nullptr;
        }
    }
    children.clear();
}

void EventGroup::update(const Notice& notice){
    // EventGroup receives the notice from a subject above it and passes the notice to its own observers
    notify(notice);
}


void EventGroup::notify(const Notice& notice)
{

    for (size_t i = 0; i < observers.size(); i++){
        if (observers[i] != nullptr){
            //send the notice to this observer
            observers[i]->update(notice);
        }
    }
}