#include "Stage.h"

void Stage::update(const Notice& notice) {
	// TODO - implement Stage::update
	throw "Not yet implemented";
}

void Stage::pausePerformance() {
	// TODO - implement Stage::pausePerformance
	throw "Not yet implemented";
}

void Stage::resumePerformance() {
	// TODO - implement Stage::resumePerformance
	throw "Not yet implemented";
}

Stage::Stage(std::string name, int capacity, bool outdoor,std::string genre, bool nearWater)
    : EventUnit(name, capacity),outdoor(outdoor),performancePaused(false),genre(genre), nearWater(nearWater){}
