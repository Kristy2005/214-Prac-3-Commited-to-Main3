/**
 * @file EventUnit.h
 * @brief Header definition for the EventUnit abstract leaf class.
 */

#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include <string>
#include <iostream>
#include "EventComponent.h"
#include "Observer.h"

class Notice;

/**
 * @class EventUnit
 * @brief Abstract Leaf base class in the Composite pattern and Observer interface.
 * 
 * @details 
 * GoF Role: Leaf (Composite Pattern) / ConcreteObserver Base (Observer Pattern).
 * 
 * Serves as the base class for all individual operational units (e.g., Stage, StageGate, 
 * MedicalTeam, FoodVendor) across the festival infrastructure.
 * 
 * DESIGN DECISION: Dual Inheritance Bridge
 * Inherits from both EventComponent (Composite Leaf interface) and Observer (Observer pattern). 
 * This guarantees that every concrete Leaf node in the festival hierarchy can function as an 
 * independent observer registered with Subject dispatchers while participating in composite operational trees.
 */
class EventUnit : public Observer, public EventComponent {
protected:
    int capacity; /**< Maximum attendee capacity threshold for this operational unit. */
    bool isOpen;  /**< Operational status flag indicating whether the unit is currently active. */

public:
    /**
     * @brief Constructs an EventUnit with a name and maximum capacity.
     * @param name Descriptive name or identifier of the unit.
     * @param capacity Maximum attendee capacity constraint.
     */
    EventUnit(std::string name, int capacity);

    /**
     * @brief Virtual destructor for polymorphic leaf cleanup.
     */
    virtual ~EventUnit();

    /**
     * @brief Marks the operational unit as open and ready for attendees.
     */
    void open() override;

    /**
     * @brief Marks the operational unit as closed and halts operations.
     */
    void close() override;

    /**
     * @brief Outputs current status, operational state, and metrics to standard output.
     */
    void reportStatus() const override;

    /**
     * @brief Retrieves the maximum capacity of the unit.
     * @return Integer capacity threshold.
     */
    int getCapacity() const override;

    /**
     * @brief Handles incoming notification alerts dispatched by Subjects.
     * @param notice Reference to the Notice payload.
     */
    void update(const Notice& notice) override = 0;
};

#endif // EVENTUNIT_H