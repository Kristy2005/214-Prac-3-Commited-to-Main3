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
 * DESIGN DECISION: The combination of the Composite design pattern as well as the Observer design pattern 
 * creates a conflict when it comes to memory ownership and deallocation at runtime 
 * The Subject participant has a non-owning std::vector<Observer*> because the Composite design pattern owns each 
 * and every leaf component that is created at runtime, therefore it manages the deallocation of that memory as each Concrete leaf
 * component is a multiple inheritance of both the Observer and EventComponent class, but not every single Concrete leaf component is an observer
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