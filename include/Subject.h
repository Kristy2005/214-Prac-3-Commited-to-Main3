/**
 * @file Subject.h
 * @brief Header definition for the Subject abstract class in the Observer pattern.
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class Notice;

/**
 * @class Subject
 * @brief Abstract Subject base class managing observer registrations and notifications.
 * 
 * @details 
 * GoF Role: Subject.
 * Ownership policy: Stores non-owning pointers in `observers`. Does not delete observers 
 * upon detachment or destruction, allowing observers to exist independently within 
 * the Composite structure.
 */
class Subject {
protected:
    /**
     * @brief List of registered non-owning observer pointers.
     */
    std::vector<Observer*> observers;

public:
    /**
     * @brief Virtual destructor to ensure polymorphic cleanup.
     */
    virtual ~Subject();

    /**
     * @brief Registers an existing observer for updates.
     * @details Prevents nullptr registration and duplicate additions.
     * @param observer Non-owning pointer to the observer to attach.
     */
    virtual void attach(Observer* observer);

    /**
     * @brief Deregisters an observer.
     * @details Safely ignores requests to detach an unregistered observer.
     * @param observer Non-owning pointer to the observer to remove.
     */
    virtual void detach(Observer* observer);

    /**
     * @brief Broadcasts a notice to all currently registered observers.
     * @param notice Push-notification data payload passed to observers.
     */
    virtual void notify(const Notice& notice) = 0;
};

#endif