#include "MedicalTeam.h"

void MedicalTeam::treatPatient(int severity) {
	// TODO - implement MedicalTeam::treatPatient
	throw "Not yet implemented";
}

void MedicalTeam::update(const Notice& notice) {
	// TODO - implement MedicalTeam::update
	throw "Not yet implemented";
}

MedicalTeam::MedicalTeam(std::string name)
    : EventUnit(name, 0),available(true){}
