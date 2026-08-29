#ifndef STAGE_H
#define STAGE_H
#include <string>
#include "EventUnit.h"

class Notice;
class Stage : public EventUnit {

private:
	bool outdoor;
	bool performancePaused;
	std::string genre;
	bool nearWater;

public:
	void update(const Notice& notice);

	void pausePerformance();

	void resumePerformance();

	Stage(std::string name, int capacity, bool outdoor, std::string genre, bool nearWater);
};

#endif
