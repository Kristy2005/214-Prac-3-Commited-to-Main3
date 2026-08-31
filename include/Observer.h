/**
 * @file Observer.h
 * @brief Abstract Observer interface for the event notification system.
 */

#ifndef OBSERVER_H
#define OBSERVER_H

class Notice;

/**
 * @class Observer
 * @brief Abstract Observer interface in the Observer design pattern.
 * 
 * @details 
 * GoF Role: Observer (Observer Pattern).
 * Defines the update interface for objects that receive notifications from Subjects.
 * 
 * LIFETIME & OWNERSHIP:
 * Observers are referenced via non-owning raw pointers inside Subject instances. 
 * An Observer must detach itself from registered Subjects prior to destruction to avoid 
 * dangling pointer dispatches.
 * 
 * DESIGN DECISION: Push-Based Notification Protocol
 * Uses a push-model update mechanism where the Notice payload is passed directly by reference, 
 * eliminating the need for concrete Observers to query the Subject back for event context.
 */
class Observer {
public:
    /**
     * @brief Receives event updates pushed from a Subject.
     * @param notice Reference to the Notice object containing event details payload.
     */
    virtual void update(const Notice& notice) = 0;

    /**
     * @brief Virtual destructor to ensure proper polymorphic cleanup of derived observers.
     */
    virtual ~Observer();
};

#endif // OBSERVER_H