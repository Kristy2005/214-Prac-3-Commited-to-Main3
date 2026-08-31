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
 * Deploys dynamically upon receiving safety alerts, capacity warnings, or evacuation commands[cite: 1].
 */
class SecurityTeam : public EventUnit {
private:
    bool deployed;
    int peopleRemoved;

public:
    virtual ~SecurityTeam();
    /**
     * @brief Constructs a SecurityTeam instance.
     * @param name Identifier or unit designation for the team.
     */
    explicit SecurityTeam(std::string name);


    /**
     * @brief Deploys security personnel to high-priority active areas.
     */
    void deploy();

    /**
     * @brief Escorts an individual off-site and updates gate occupancy metrics.
     * @param reason Description of the security violation or cause.
     * @param gate Optional non-owning raw pointer to StageGate to update occupancy. Can be nullptr[cite: 1].
     * @return True if removal action was logged successfully.
     */
    bool removePerson(std::string reason, StageGate* gate);

    /**
     * @brief Responds to safety notifications by deploying personnel and securing zones.
     * @param notice Reference to the Notice payload.
     */
    void update(const Notice& notice) override;
};

#endif