#ifndef EVENTGROUP_H
#define EVENTGROUP_H
#include <vector>
#include <string>
#include "EventComponent.h"
#include "Observer.h"
#include "Subject.h"

class Notice;

class EventGroup : public EventComponent, Subject, Observer {

private:
	std::vector<EventComponent*> children;
	bool isOpen;

public:
	void add(EventComponent* child);

	EventComponent* remove(EventComponent* child);

	void open();

	void close();

	void reportStatus() const;

	int getCapacity() const;

	void update(const Notice& notice);

	void notify(const Notice& notice);

	~EventGroup();

	EventGroup(std::string name);
};

#endif
