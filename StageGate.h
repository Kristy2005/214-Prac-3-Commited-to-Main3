/**
 * @file StageGate.h
 * @brief Concrete Leaf component controlling crowd access to specific stage zones.
 */

#ifndef STAGEGATE_H
#define STAGEGATE_H

#include <string>
#include "EventUnit.h"

class Stage;
class Notice;

/**
 * @class StageGate
 * @brief Concrete Leaf managing localized access control and occupancy tracking for stages.
 * 
 * @details 
 * GoF Role: ConcreteObserver (Observer Pattern) / Leaf (Composite Pattern).
 * Holds a non-owning pointer reference to its associated Stage object.
 * This Stage object must exist before any operation can take place.
 */
class StageGate : public EventUnit {
private:
    int currentOccupancy;   /**< Tracks current number of attendees inside the stage area. */
    bool admitting;         /**< Flag indicating if the gate is active and accepting entries. */
    Stage* controlledStage; /**< Non-owning pointer to the target Stage instance. */

public:
    /**
     * @brief Virtual destructor ensuring clean polymorphic cleanup.
     * @details Even though StageGate does not own raw dynamic memory directly, 
     * the destructor must be explicitly declared to avoid vtable linker errors 
     * as this class inherits from the abstract Observer class.
     */
    virtual ~StageGate();

    /**
     * @brief Constructs a StageGate associated with a specific Stage.
     * @param name Identifier for the access gate.
     * @param stage Non-owning raw pointer to the Stage being controlled. Must not be nullptr.
     */
    StageGate(std::string name, Stage* stage);

    /**
     * @brief Checks if the gate is accepting admissions based on current occupancy and state.
     * @return True if admission is allowed and capacity is available, false otherwise.
     */
    bool canAdmit() const;

    /**
     * @brief Admits an attendee into the stage area, incrementing occupancy metrics.
     * @return True if attendee was successfully admitted, false if admission failed.
     */
    bool admitAttendee();

    /**
     * @brief Records an attendee exiting the stage area, decrementing occupancy metrics.
     * @return True if an attendee left successfully, false if occupancy was already zero.
     */
    bool attendeeLeaves();

    /**
     * @brief Returns current active occupancy for the controlled stage area.
     * @return Total integer count of attendees currently admitted.
     */
    int getOccupancy() const;

    /**
     * @brief Handles event notices such as capacity alerts or evacuations by locking gate access.
     * @param notice Reference to the Notice payload.
     */
    void update(const Notice& notice) override;
};

#endif // STAGEGATE_H