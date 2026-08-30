#include "StageGate.h"
#include "Stage.h"
#include "Notice.h"
#include <iostream>


bool StageGate::canAdmit() const{

    if (admitting == false){
        return false;
    }

    if (controlledStage == nullptr){
        return false;
    }

	//check if capacity limit is not reached before admitting
    if (currentOccupancy < controlledStage->getCapacity()){
        return true;
    }
    else{
        return false;
    }
}


bool StageGate::admitAttendee(){

    if (canAdmit() == true){

        currentOccupancy = currentOccupancy + 1;

        std::cout << "Attendee admitted to "<< controlledStage->getName()<< std::endl;

        return true;
    }
    else{
        std::cout << "Attendee cannot enter "<< getName()<< std::endl;

        return false;
    }
}


bool StageGate::attendeeLeaves(){

    if(currentOccupancy > 0){

        currentOccupancy = currentOccupancy - 1;

        std::cout << "Attendee leaves "<< controlledStage->getName()<< std::endl;

        return true;
    }
    else
    {
        std::cout << "There are no attendees to remove" << std::endl;
        return false;
    }
}


int StageGate::getOccupancy() const{
    return currentOccupancy;
}


void StageGate::update(const Notice& notice){

    if (notice.getType() == NoticeType::OPEN)
    {
        admitting = true;
        isOpen = true;

        std::cout << getName()<< " is open for entry"<< std::endl;
    }

    if (notice.getType() == NoticeType::CLOSE){
        admitting = false;
        isOpen = false;

        std::cout << getName()<< " is closed for entry"<< std::endl;
    }

    if (notice.getType() == NoticeType::CAPACITY_ALERT)
    {
        admitting = false;

        std::cout << getName()<< " stops admitting attendees due to capacity"<< std::endl;
    }

    if (notice.getType() == NoticeType::PAUSE)
    {
        admitting = false;

        std::cout << getName()<< " temporarily stops admitting attendees"<< std::endl;
    }

    if (notice.getType() == NoticeType::RESUME)
    {
        admitting = true;

        std::cout << getName()<< " resumes admitting attendees"<< std::endl;
    }

    if (notice.getType() == NoticeType::EVACUATE)
    {
        admitting = false;

        std::cout << getName()<< " stops entry during evacuation"<< std::endl;
    }
}

//constructor
StageGate::StageGate(std::string name, Stage* stage)
    : EventUnit(name, 0),currentOccupancy(0), admitting(true),controlledStage(stage){}

StageGate::~StageGate(){}
