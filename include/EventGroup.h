#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include <vector>
#include <string>
#include "EventComponent.h"
#include "Observer.h"
#include "Subject.h"

class Notice;

class EventGroup : public EventComponent, public Subject, public Observer
{
private:
    std::vector<EventComponent*> children;
    bool isOpen;

public:
    EventGroup(std::string name);
    void add(EventComponent* child);
    EventComponent* remove(EventComponent* child);
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(const Notice& notice) override;
    void notify(const Notice& notice) override;
    ~EventGroup() override;
};

#endif