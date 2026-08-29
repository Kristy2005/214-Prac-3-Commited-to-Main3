#ifndef STAGEGATE_H
#define STAGEGATE_H
#include <string>
#include "EventUnit.h"

class Stage;
class Notice;
class StageGate : public EventUnit {

private:
	int currentOccupancy;
	bool admitting;
	Stage* controlledStage;

public:
	bool canAdmit() const;

	bool admitAttendee();

	void attendeeLeaves();

	int getOccupancy() const;

	void update(const Notice& notice);

	StageGate(std::string name, Stage* stage);
};

#endif
