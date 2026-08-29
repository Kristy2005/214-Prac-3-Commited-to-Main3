#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include <string>
#include "EventUnit.h"
#include "Notice.h"

class Notice;

class MedicalTeam : public EventUnit
{
private:
    bool available;
    int currentPatients;
    int maxPatients;
    int medicalSupplies;

public:
    MedicalTeam(std::string name, int maxPatients, int medicalSupplies);

    bool treatPatient(int severity);

    void dischargePatient();

    void update(const Notice& notice);
};

#endif