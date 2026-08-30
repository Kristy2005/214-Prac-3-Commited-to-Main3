#include "Subject.h"

void Subject::attach(Observer* observer) {
	//DO NOT ACCEPT NULLPTR 
	if(observer == nullptr)return;

	//DUPLICATE CHECK 
	bool dup = false;
	auto it = this->observers.begin();
	while(it != this->observers.end()){
		if(*it == observer){
			dup = true;
			break;
		}else{
			++it;
		}
	}

	if(!dup){
		this->observers.push_back(observer);
	}
	
}

void Subject::detach(Observer* observer) {
	//NULL CHECK 
	if(observer == nullptr)return;

	auto it = this->observers.begin();
	while(it != this->observers.end()){
		if(*it == observer){
			this->observers.erase(it);
			break;
		}else{
			++it;
		}
	}
}

Subject::~Subject() {
	// TODO - implement Subject::~Subject

}
