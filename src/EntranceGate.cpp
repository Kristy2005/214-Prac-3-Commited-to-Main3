#include "EntranceGate.h"
#include "Notice.h"
#include <iostream>

//const because just doing comparisons no modifications
bool EntranceGate::checkID(int age) const{
    if(age>=minimumAge){
        return true;
    }else{
        return false;
    }
}

bool EntranceGate::admitAttendee(int age){

    if (admitting==false){
        std::cout << "Entrance gate is not admitting attendees" << std::endl;
        return false;
    }

    if(checkID(age) == true){
        std::cout << "ID accepted. Attendee may enter the Music festival" << std::endl;
        return true;
    }
    else{
        std::cout<<"ID rejected. Attendee must be at least "<< minimumAge << " years old to enter" << std::endl;
        return false;
    }
}

void EntranceGate::update(const Notice& notice){

    if (notice.getType() == NoticeType::OPEN){
        admitting = true;
        isOpen = true;
        std::cout << getName()<< " is open and admitting attendees"<< std::endl;
    }

    if (notice.getType() == NoticeType::CLOSE){
        admitting = false;
        isOpen = false;
        std::cout << getName() << " has stopped admitting attendees"<< std::endl;
    }

    if (notice.getType() == NoticeType::PAUSE){
        admitting = false;
        std::cout << getName()<< " temporarily stops admitting attendees" << std::endl;
    }

    if (notice.getType() == NoticeType::RESUME){
        admitting = true;
        std::cout << getName()<< " resumes admitting attendees"<< std::endl;
    }

    if (notice.getType() == NoticeType::EVACUATE){
        admitting = false;
        std::cout<< getName()<< " stops entry due to evacuation"<< std::endl;
    }
}

EntranceGate::EntranceGate(std::string name, int minimumAge)
    : EventUnit(name, 0),minimumAge(minimumAge),admitting(true){}

EntranceGate::~EntranceGate(){}
