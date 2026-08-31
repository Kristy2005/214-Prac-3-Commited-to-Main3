/**
 * @file EventGroup.h
 * @brief Header definition for the EventGroup Composite class.
 */

#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include <vector>
#include <string>
#include <iostream>
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
 * 
 * Acts as both a container for child EventComponents and an intermediate router that receives
 * notifications from above and cascades them to registered observers below.
 * 
 * DESIGN DECISION: Triple Inheritance Composite Router
 * EventGroup combines EventComponent, Subject, and Observer to form an intermediate node 
 * in the festival tree. This allows a zone (e.g., "Main Stage Area") to act simultaneously as 
 * a composite container for child units, an observer listening to central EventControl alerts, 
 * and a local Subject broadcasting notices to sub-components inside its zone.
 */
class EventGroup : public EventComponent, public Subject, public Observer {
private:
    std::vector<EventComponent*> children; /**< Collection of owned child composite nodes (leaves or sub-groups). */
    bool isOpen;                            /**< Operational state flag indicating if the zone is currently active. */

public:
    /**
     * @brief Constructs an EventGroup with a name.
     * @param name Name of the festival area or zone.
     */
    EventGroup(std::string name);

    /**
     * @brief Destructor that safely recursively deletes all owned child EventComponents.
     * @note Ownership: In accordance with Composite lifecycle management, EventGroup 
     *       destroys all dynamically allocated components stored in its children container.
     */
    virtual ~EventGroup();

    /**
     * @brief Adds a child EventComponent to this composite group.
     * @param child Raw pointer to an EventComponent (leaf or nested group). Must not be nullptr.
     * @note OWNERSHIP TRANSFER: EventGroup assumes full memory ownership of the passed pointer. 
     *       The caller must not manually delete 'child' after adding it to a group.
     */
    void add(EventComponent* child);

    /**
     * @brief Removes a child EventComponent from this group without deleting it.
     * 
     * @details DESIGN DECISION: Composite Transfer & Ownership Relinquishment
     * When a child component is detached via remove(), EventGroup erases the pointer 
     * from its internal vector WITHOUT calling delete. Ownership transfers back to 
     * the caller or destination composite group, enabling dynamic transfers (e.g. moving a 
     * SecurityTeam from River Stage to Food Area) without object re-instantiation or double-free errors.
     * 
     * @param child Pointer to the child EventComponent to remove.
     * @return Pointer to the detached child component, or nullptr if not found.
     */
    EventComponent* remove(EventComponent* child);

    /**
     * @brief Opens this zone and recursively cascades open commands to all child components.
     */
    void open() override;

    /**
     * @brief Closes this zone and recursively cascades close commands to all child components.
     */
    void close() override;

    /**
     * @brief Outputs current zone status and recursively invokes reportStatus() on all child components.
     */
    void reportStatus() const override;

    /**
     * @brief Calculates and returns the aggregate capacity of all nested child components.
     * @return Total integer capacity sum of all child nodes in this branch.
     */
    int getCapacity() const override;

    /**
     * @brief Receives event notifications from parent Subject dispatches.
     * @param notice Reference to the Notice payload object.
     */
    void update(const Notice& notice) override;

    /**
     * @brief Cascades notice broadcasts to all registered observers inside this composite zone.
     * @param notice Reference to the Notice payload object to dispatch.
     */
    void notify(const Notice& notice) override;
};

#endif // EVENTGROUP_H