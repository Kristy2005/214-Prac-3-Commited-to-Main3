/**
 * @file MedicalTeam.h
 * @brief Concrete Leaf component representing first aid stations and triage teams.
 */

#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include <string>
#include "EventUnit.h"

class Notice;

/**
 * @class MedicalTeam
 * @brief Concrete Leaf managing medical triage, supply tracking, and patient admissions.
 * 
 * @details 
 * GoF Role: ConcreteObserver (Observer Pattern) / Leaf (Composite Pattern).
 * 
 * Remains operational during emergency alerts and evacuations to provide first aid support.
 * 
 * DESIGN DECISION: Emergency Operational Persistence
 * Unlike commercial units (such as Bar or FoodVendor) that immediately halt service 
 * upon receiving an EVACUATE or WEATHER_ALERT notice, MedicalTeam intentionally remains 
 * active and available to manage triage and emergency response during evacuation protocols.
 */
class MedicalTeam : public EventUnit {
private:
    bool available;        /**< Indicates whether the team can accept new triage patients. */
    int currentPatients;  /**< Number of active patients currently admitted at this station. */
    int maxPatients;      /**< Maximum concurrent patient capacity threshold. */
    int medicalSupplies;  /**< Current count of medical supply units available. */

public:
    /**
     * @brief Virtual destructor ensuring clean polymorphic cleanup.
     */
    virtual ~MedicalTeam();

    /**
     * @brief Constructs a MedicalTeam instance with capacity and supply constraints.
     * @param name Name or unit code for the first aid post.
     * @param maxPatients Maximum concurrent patients the team can accommodate.
     * @param medicalSupplies Initial supply units available for triage.
     */
    MedicalTeam(std::string name, int maxPatients, int medicalSupplies);

    /**
     * @brief Admits and treats a patient, consuming medical supplies based on severity.
     * @param severity Numeric severity rating indicating supply consumption required.
     * @return True if patient was admitted and treated successfully, false if at capacity or out of supplies.
     */
    bool treatPatient(int severity);

    /**
     * @brief Discharges a treated patient, freeing up medical station capacity.
     */
    void dischargePatient();

    /**
     * @brief Receives event notices to prepare triage areas during emergencies.
     * @param notice Reference to the Notice payload.
     */
    void update(const Notice& notice) override;
};

#endif // MEDICALTEAM_H