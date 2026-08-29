#include "SecurityTeam.h"
#include "StageGate.h"
#include <iostream>

//constructor
SecurityTeam::SecurityTeam(std::string name)
    : EventUnit(name, 0),deployed(false),peopleRemoved(0){}

void SecurityTeam::deploy(){

    if (deployed==false){
        deployed = true;

        std::cout << getName()<< " has been deployed"<< std::endl;
    }else{
        std::cout << getName()<< " is already deployed"<< std::endl;
    }
}

bool SecurityTeam::removePerson(std::string reason, StageGate* gate){

    if(deployed == false){
        std::cout << getName()<< " cannot remove the person because the team is not deployed" << std::endl;

        return false;
    }

    if (gate== nullptr){
        std::cout << "No valid stage gate was provided"<< std::endl;
        return false;
    }

	//security team makes a member leave
    if (gate->attendeeLeaves() == true){
        peopleRemoved = peopleRemoved + 1;

        std::cout << "Person removed from the event for: "<< reason<< std::endl;

        return true;
    }
    else{
        std::cout << "There are no attendees to remove from this area"<< std::endl;
        return false;
    }
}

void SecurityTeam::update(const Notice& notice){

    if (notice.getType() == NoticeType::CAPACITY_ALERT){
        deploy();

        std::cout << getName()<< " prepares for crowd control" << std::endl;
    }

    if (notice.getType() == NoticeType::EVACUATE){
        deploy();

        std::cout << getName()<< " assists with the evacuation"<< std::endl;
    }

    if (notice.getType() == NoticeType::WEATHER_ALERT) {
        deploy();

        std::cout << getName()<< " assists attendees during the weather alert"<< std::endl;
    }

    if (notice.getType() == NoticeType::PAUSE){
        deploy();

        std::cout << getName()<< " monitors the crowd while the event is paused"<< std::endl;
    }

    if (notice.getType() == NoticeType::RESUME){
        deployed = false;

        std::cout << getName()<< " returns to normal security duties"<< std::endl;
    }

    if (notice.getType() == NoticeType::CLOSE){
        deploy();

        std::cout << getName()<< " assists with clearing the event area"<< std::endl;
    }
}