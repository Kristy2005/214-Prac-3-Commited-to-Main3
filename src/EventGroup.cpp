#include "EventGroup.h"

void EventGroup::add(EventComponent* child) {
	if(child == nullptr)return;

	auto it = this->children.begin();
	while(it != this->children.end()){
		if(*it == child){
			return;
		}else{
			++it;
		}
	}

	this->children.push_back(child);
}


EventComponent* EventGroup::remove(EventComponent* child) {
	if(child == nullptr)return nullptr;

	auto it = this->children.begin();
	while(it != this->children.end()){
		if(*it == child){
			EventComponent* removed = *it;
			this->children.erase(it);
			return removed;
		}else{
			++it;
		}
	}
	return nullptr;
}


void EventGroup::open() {
	this->isOpen = true;
	std::cout<< "[Evenet Group] ZONE:" << this->name << "is now OPEN" <<std::endl;
<<<<<<< HEAD
	for(size_t i = 0; i < this->children.size(); ++i){
=======
	for(size_t i = 0; i < this->childrensize(); ++i){
>>>>>>> 97d9d62 (Current concrete implementations of Observer)
		if(this->children[i] != nullptr){
			this->children[i]->open();
		}
	}
}

void EventGroup::close() {
	this->isOpen = false;
	std::cout<< "[Evenet Group] ZONE:" << this->name << "is now CLOSED" <<std::endl;
<<<<<<< HEAD
	for(size_t i = 0; i < this->children.size(); ++i){
=======
	for(size_t i = 0; i < this->childrensize(); ++i){
>>>>>>> 97d9d62 (Current concrete implementations of Observer)
		if(this->children[i] != nullptr){
			this->children[i]->close();
		}
	}
}

void EventGroup::reportStatus() const {
	std::cout << "\n=== Group Status: " << this->name 
              << " | State: " << (this->isOpen ? "OPEN" : "CLOSED") 
              << " | Total Capacity: " << this->getCapacity() << " ===" << std::endl;

    for (size_t i = 0; i < this->children.size(); ++i) {
        if (this->children[i] != nullptr) {
            this->children[i]->reportStatus();
        }
    }
}

int EventGroup::getCapacity() const {
	int capacity = 0;
	auto it = this->children.begin();
	while(it != this->children.end()){
<<<<<<< HEAD
		if(*it != nullptr) capacity += (*it)->getCapacity();
=======
		if(it != nullptr)capacity += *it->getCapacity();
>>>>>>> 97d9d62 (Current concrete implementations of Observer)
		++it;
	}
	return capacity;
}

void EventGroup::update(const Notice& notice) {
	std::cout << "[Composite Level: " << this->name 
              << "] Received notice from upper control. Cascading notification down..." << std::endl;
    
    this->notify(notice);
}

void EventGroup::notify(const Notice& notice) {
	for(size_t i = 0; i < this->observers.size(); ++i){
		if(this->observers[i] != nullptr){
			this->observers[i]->update(notice);
		}
	}
}

EventGroup::~EventGroup() {
	for(size_t i = 0; i < this->children.size(); ++i){
		if(this->children[i] != nullptr){
			delete this->children[i];
			this->children[i] = nullptr;
		}
	}
	this->children.clear();
	this->isOpen = false;
}

EventGroup::EventGroup(std::string name)
    : EventComponent(name), isOpen(false){}
