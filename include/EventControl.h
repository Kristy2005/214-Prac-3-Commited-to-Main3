#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H
#include <string>
#include "Subject.h"

class Notice;
class EventControl : public Subject {

public:
	std::string eventName;

	void issueNotice(const Notice& notice);

	void notify(const Notice& notice);

	EventControl(std::string eventName);
};

#endif
