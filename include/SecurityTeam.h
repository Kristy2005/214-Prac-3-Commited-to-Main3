/**
 * @file SecurityTeam.h
 * @brief Concrete Leaf component representing on-site security personnel units.
 */

#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include <string>
#include "EventUnit.h"

class StageGate;
class Notice;

/**
 * @class SecurityTeam
 * @brief Concrete Leaf handling crowd control, personnel deployment, and incident response.
 * 
 * @details 
 * GoF Role: ConcreteObserver (Observer Pattern) / Leaf (Composite Pattern).
 * Deploys dynamically upon receiving safety alerts, capacity warnings, or evacuation commands.
 * 
 * DESIGN DECISION: Dynamic Cross-Leaf Operations
 * SecurityTeam operates alongside StageGate components without maintaining persistent ownership,
 * allowing security personnel to interact with any gate dynamically across different festival zones.
 */
class SecurityTeam : public EventUnit {
private:
    bool deployed;     /**< Boolean representing whether this security team is currently occupied or ready to assist. */
    int peopleRemoved; /**< Counter tracking total attendees removed for census accounting and security audit reports. */

public:
    /**
     * @brief Virtual destructor ensuring clean polymorphic cleanup.
     */
    virtual ~SecurityTeam();

    /**
     * @brief Constructs a SecurityTeam instance.
     * @param name Identifier or unit designation for the team.
     */
    SecurityTeam(std::string name);

    /**
     * @brief Deploys security personnel to high-priority active areas.
     */
    void deploy();

    /**
     * @brief Escorts an individual off-site and updates gate occupancy metrics.
     * @param reason Description of the security violation or cause.
     * @param gate Non-owning raw pointer to the StageGate object where occupancy must be decremented. Must not be nullptr.
     * @return True if removal action was logged and executed successfully.
     */
    bool removePerson(std::string reason, StageGate* gate);

    /**
     * @brief Responds to safety notifications by deploying personnel and securing zones.
     * @param notice Reference to the Notice payload.
     */
    void update(const Notice& notice) override;
};

#endif // SECURITYTEAM_H