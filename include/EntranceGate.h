#ifndef ENTRANCEGATE_H
#define ENTRANCEGATE_H
#include <string>
#include "EventUnit.h"

class Notice;

class EntranceGate : public EventUnit {

private:
	int minimumAge;
	bool admitting;

public:
	bool checkID(int age) const;

	bool admitAttendee(int age);

	void update(const Notice& notice);

	EntranceGate(std::string name, int minimumAge);
};

#endif
