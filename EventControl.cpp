#include "EventControl.h"
#include "Observer.h"

void EventControl::issueNotice(const Notice& notice) {
	this->notify(notice);
}

void EventControl::notify(const Notice& notice) {
	for(Observer* er: this->observers){
		if(er != nullptr){
			er->update(notice);
		}
	}
}

EventControl::EventControl(std::string eventName): eventName(eventName){}

EventControl::~EventControl(){}
