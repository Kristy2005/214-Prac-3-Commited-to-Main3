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
 * Represents active music/performance stages across festival zones.
 * Responds to operational, capacity, and safety notifications (e.g., PAUSE, RESUME, WEATHER_ALERT, EVACUATE).
 */
class Stage : public EventUnit {
private:
    bool outdoor;
    bool performancePaused;
    std::string genre;
    bool nearWater;

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
     * @brief Virtual destructor for Stage.
     */
    virtual ~Stage() override;

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

#endif