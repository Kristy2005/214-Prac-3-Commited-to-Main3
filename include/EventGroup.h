/**
 * @file EventGroup.h
 * @brief Header definition for the EventGroup Composite class.
 */

#ifndef EVENTGROUP_H
#define EVENTGROUP_H


#include <vector>
#include <string>
#include "EventComponent.h"
#include "Observer.h"
#include "Subject.h"

class Notice;

/**
 * @class EventGroup
 * @brief Composite class representing a festival zone/group containing multiple components.
 * 
 * @details 
 * GoF Roles: Composite (Composite Pattern) / Subject & ConcreteObserver (Observer Pattern).
 * Acts as both a container for child EventComponents and an intermediate router that receives
 * notifications from above and cascades them to registered observers below (Task 3.4).
 */
class EventGroup : public EventComponent, public Subject, public Observer {
private:
    std::vector<EventComponent*> children;
    bool isOpen;

public:
    /**
     * @brief Constructs an EventGroup with a name.
     * @param name Name of the festival area/zone.
     */
    explicit EventGroup(std::string name);

    /**
     * @brief Destructor that safely deletes all owned child EventComponents.
     */
    virtual ~EventGroup();

    /**
     * @brief Adds a child EventComponent to this group.
     * @param child Non-null pointer to an EventComponent leaf or group.
     */
    void add(EventComponent* child);

    /**
     * @brief Removes a child EventComponent from this group without deleting it.
     * @param child Pointer to the child to remove.
     * @return Pointer to the removed child, or nullptr if not found.
     */
    EventComponent* remove(EventComponent* child);

    // EventComponent Overrides
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

    // Observer Override (Receives notifications from above)
    void update(const Notice& notice) override;

    // Subject Override (Cascades notifications below)
    void notify(const Notice& notice) override;
};

#endif