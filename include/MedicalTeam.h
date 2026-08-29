#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H
#include <string>
#include "EventUnit.h"

class Notice;
class MedicalTeam : public EventUnit {

public:
	bool available;

	void treatPatient(int severity);

	void update(const Notice& notice);

	MedicalTeam(std::string name);
};

#endif
