#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include <string>
#include "EventComponent.h"
#include "Observer.h"

class Notice;

class EventUnit : public Observer,public EventComponent {

protected:
	int capacity;
	bool isOpen;

public:
	void open();

	void close();

	void reportStatus() const;

	int getCapacity() const;

	virtual void update(const Notice& notice) = 0;

	~EventUnit();

	EventUnit(std::string name, int capacity);
};

#endif
