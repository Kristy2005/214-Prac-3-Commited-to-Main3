#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H
#include <string>
#include "EventUnit.h"

class Notice;
class SecurityTeam : public EventUnit {

public:
	bool deployed;

	void deploy();

	void update(const Notice& notice);

	SecurityTeam(std::string name);
};

#endif
