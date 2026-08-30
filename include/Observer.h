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
 * GoF Role: Observer.
 * Defines the update interface for objects that receive notifications from Subjects.
 * Observers are non-owning references stored by Subjects and must detach prior to destruction.
 */
class Observer {
public:
    /**
     * @brief Receives event updates pushed from a Subject.
     * @param notice Reference to the Notice object containing event details.
     */
    virtual void update(const Notice& notice) = 0;

    /**
     * @brief Virtual destructor to ensure polymorphic cleanup of derived observers.
     */
    virtual ~Observer();
};

#endif