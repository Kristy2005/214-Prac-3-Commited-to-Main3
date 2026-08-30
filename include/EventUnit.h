/**
 * @file EventUnit.h
 * @brief Header definition for the EventUnit abstract leaf class.
 */

#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include <string>
#include "EventComponent.h"
#include "Observer.h"

class Notice;

/**
 * @class EventUnit
 * @brief Abstract Leaf class in the Composite pattern and Observer in the Observer pattern.
 * 
 * @details 
 * GoF Role: Leaf (Composite Pattern) / ConcreteObserver (Observer Pattern).
 * Represents individual operational units (e.g., Stages, Gateways, Medical Tents) 
 * that receive notifications from higher-level Composites (EventGroup).
 */
class EventUnit : public Observer, public EventComponent {
protected:
    int capacity;
    bool isOpen;

public:
    /**
     * @brief Constructs an EventUnit with a name and maximum capacity.
     * @param name Descriptive name of the unit.
     * @param capacity Maximum attendee capacity.
     */
    explicit EventUnit(std::string name, int capacity);

    /**
     * @brief Virtual destructor for polymorphic leaf deallocation.
     */
    virtual ~EventUnit();

    // EventComponent Overrides
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

    // Observer Override (pure virtual - implemented by concrete leaf types)
    void update(const Notice& notice) override = 0;
};

#endif