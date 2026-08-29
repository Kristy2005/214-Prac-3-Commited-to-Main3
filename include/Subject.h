#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class Notice;

class Subject {

protected:
	std::vector<Observer*> observers;

public:
	void attach(Observer* observer);

	void detach(Observer* observer);

	virtual void notify(const Notice& notice) = 0;

	virtual ~Subject();
};

#endif
