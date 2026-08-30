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
 */
class EventControl : public Subject {
private:
    std::string eventName;

public:
    explicit EventControl(std::string eventName);
    virtual ~EventControl() override;

    void issueNotice(const Notice& notice);
    void notify(const Notice& notice) override;
};

#endif