/**
 * @file Stage.h
 * @brief Header definition for the Stage concrete leaf component.
 */

#ifndef STAGE_H
#define STAGE_H

#include <string>
#include "EventUnit.h"

class Notice;

/**
 * @class Stage
 * @brief Concrete Leaf component representing a performance stage.
 * 
 * @details 
 * GoF Role: ConcreteObserver (Observer Pattern) / Leaf (Composite Pattern).
 * 
 * Represents active music/performance stages across festival zones.
 * Responds to operational, capacity, and safety notifications (e.g., PAUSE, RESUME, 
 * WEATHER_ALERT, EVACUATE).
 * 
 * DESIGN DECISION: Selective Notification Filtering
 * Stage uses its internal attributes (`outdoor` and `nearWater`) during update() 
 * dispatches to conditionally ignore environmental notices that do not affect 
 * indoor or landlocked performance stages, keeping response logic localized.
 */
class Stage : public EventUnit {
private:
    bool outdoor;            /**< Flag indicating if the stage is exposed to weather elements. */
    bool performancePaused;  /**< Tracks active playback/performance state. */
    std::string genre;       /**< Music or performance style assigned to this stage. */
    bool nearWater;          /**< Flag for proximity to aquatic festival hazards. */

public:
    /**
     * @brief Constructs a Stage leaf object.
     * @param name Descriptive name of the stage.
     * @param capacity Maximum attendee capacity.
     * @param outdoor True if the stage is an outdoor setup.
     * @param genre Music/performance genre associated with this stage.
     * @param nearWater True if the stage is near water features.
     */
    Stage(std::string name, int capacity, bool outdoor, std::string genre, bool nearWater);

    /**
     * @brief Virtual destructor ensuring clean polymorphic destruction.
     */
    virtual ~Stage();

    /**
     * @brief Receives event updates pushed from a Subject and executes stage behavior.
     * @param notice Data payload containing notice type and message details.
     */
    void update(const Notice& notice) override;

    /**
     * @brief Pauses active stage performance.
     */
    void pausePerformance();

    /**
     * @brief Resumes active stage performance.
     */
    void resumePerformance();
};

#endif // STAGE_H