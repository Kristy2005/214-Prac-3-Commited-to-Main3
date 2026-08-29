#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include <string>
#include "EventUnit.h"
#include "Notice.h"

class Notice;
class StageGate;

class SecurityTeam : public EventUnit
{
private:
    bool deployed;
    int peopleRemoved;

public:
    SecurityTeam(std::string name);

    void deploy();

    bool removePerson(std::string reason, StageGate* gate);

    void update(const Notice& notice);
};

#endif