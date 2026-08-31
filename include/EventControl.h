/**
 * @file EventControl.h
 * @brief Central event coordinator acting as concrete Subject.
 */

#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include <string>
#include "Subject.h"

class Notice;

/**
 * @class EventControl
 * @brief Concrete Subject representing top-level event management.
 * 
 * @details 
 * GoF Role: ConcreteSubject (Observer Pattern).
 * 
 * EventControl serves as the top-level central control hub for the festival. 
 * It manages global observer subscriptions and broadcasts event notices 
 * across the entire festival infrastructure.
 * 
 * DESIGN DECISION: Interface Separation for Event Triggering
 * Separates issueNotice() (the administrative entry point) from notify() 
 * (the internal Subject dispatch mechanism). This encapsulates broadcast logging 
 * and notice validation prior to pushing updates to registered observers.
 */
class EventControl : public Subject {
private:
    std::string eventName; /**< Identifier name of the managed festival event. */

public:
    /**
     * @brief Constructs an EventControl instance.
     * @param eventName Descriptive name identifier for the festival event.
     */
    EventControl(std::string eventName);

    /**
     * @brief Virtual destructor for EventControl.
     */
    virtual ~EventControl() override;

    /**
     * @brief Administrative entry point to trigger and broadcast a Notice.
     * @param notice Reference to the Notice payload object to dispatch.
     */
    void issueNotice(const Notice& notice);

    /**
     * @brief Broadcasts a notice payload to all currently registered observers.
     * @param notice Reference to the Notice payload object.
     */
    void notify(const Notice& notice) override;
};

#endif // EVENTCONTROL_H