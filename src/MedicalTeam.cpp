#include "MedicalTeam.h"
#include <iostream>
#include "Notice.h"

bool MedicalTeam::treatPatient(int severity){

    if(available == false){
        std::cout << "Medical team is unavailable" << std::endl;
        return false;
    }

    if(currentPatients >= maxPatients){
        std::cout << "Medical station is at full capacity" << std::endl;
        return false;
    }

    if(medicalSupplies <= 0){
        std::cout << "Medical team has no supplies available" << std::endl;
        return false;
    }

    if(severity <= 0){
        std::cout << "Invalid severity level" << std::endl;
        return false;
    }

    currentPatients=currentPatients + 1;

    if (severity == 1){

        medicalSupplies = medicalSupplies - 1;

        std::cout << "Patient admitted with a minor injury"<< std::endl;
    }else if (severity == 2){
        medicalSupplies = medicalSupplies - 2;

        std::cout << "Patient admitted with a moderate injury"<< std::endl;
    }else{
        medicalSupplies = medicalSupplies - 3;

        std::cout << "Critical patient stabilised for hospital transfer"<< std::endl;
    }

    return true;
}

void MedicalTeam::dischargePatient(){

    if (currentPatients>0){
        currentPatients = currentPatients - 1;

        std::cout << "Patient discharged" << std::endl;
    }
    else{
        std::cout << "There are no patients to discharge"<< std::endl;
    }
}

void MedicalTeam::update(const Notice& notice){
    
	if(notice.getType() == NoticeType::OPEN){
        available = true;

        std::cout << getName()<< " is available for medical assistance"<< std::endl;
    }

    if (notice.getType() == NoticeType::CLOSE){
        available = false;

        std::cout << getName()<< " medical station is closed"<< std::endl;
    }

    if (notice.getType() == NoticeType::PAUSE){
        available = true;

        std::cout << getName()<< " remains available during the pause"<< std::endl;
    }

    if (notice.getType() == NoticeType::WEATHER_ALERT){
        available = true;

        std::cout << getName()<< " remains available during the weather alert"<< std::endl;
    }

    if (notice.getType() == NoticeType::EVACUATE){
        available = true;

        std::cout << getName()<< " remains active during the evacuation"<< std::endl;
    }

    if (notice.getType() == NoticeType::RESUME){
        available = true;

        std::cout << getName()<< " continues normal medical operations"<< std::endl;
    }
}

//constructor
MedicalTeam::MedicalTeam(std::string name, int maxPatients, int medicalSupplies)
    : EventUnit(name, 0),available(true),currentPatients(0), maxPatients(maxPatients),medicalSupplies(medicalSupplies){}