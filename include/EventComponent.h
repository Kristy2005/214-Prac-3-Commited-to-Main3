#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>
class EventComponent {

protected:
	std::string name;

public:
	virtual void open() = 0;

	virtual void close() = 0;

	virtual void reportStatus() const = 0;

	virtual int getCapacity() const = 0;

	virtual ~EventComponent();

	std::string getName() const;

	EventComponent(std::string name);
};

#endif
