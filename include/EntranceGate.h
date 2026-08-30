/**
 * @file EntranceGate.h
 * @brief Concrete Leaf component representing perimeter entrance turnstiles.
 */

#ifndef ENTRANCEGATE_H
#define ENTRANCEGATE_H

#include <string>
#include "EventUnit.h"

class Notice;

/**
 * @class EntranceGate
 * @brief Concrete Leaf managing primary festival entry and age verification.
 * 
 * @details 
 * GoF Role: ConcreteObserver (Observer Pattern) / Leaf (Composite Pattern).
 * Controls access at venue boundaries and halts admissions during closure or evacuation notices[cite: 1].
 */
class EntranceGate : public EventUnit {
private:
    int minimumAge;
    bool admitting;

public:
    /**
     * @brief Constructs an EntranceGate instance.
     * @param name Name or label of the gate.
     * @param minimumAge Minimum age required for attendee entry (default: 18).
     */
    EntranceGate(std::string name, int minimumAge = 18);

    /**
     * @brief Virtual destructor for EntranceGate.
     */
    virtual ~EntranceGate() override;

    /**
     * @brief Verifies whether an attendee satisfies age requirements.
     * @param age Age of the attendee requesting entry.
     * @return True if attendee meets or exceeds minimum age, false otherwise.
     */
    bool checkID(int age)const;

    /**
     * @brief Processes an attendee entry attempt based on gate state and age criteria.
     * @param age Age of the attendee requesting entry.
     * @return True if access is granted, false if access is denied or gate is closed.
     */
    bool admitAttendee(int age);

    /**
     * @brief Handles incoming event notices to open, close, or halt gate admissions.
     * @param notice Reference to the Notice payload.
     */
    void update(const Notice& notice) override;
};

#endif