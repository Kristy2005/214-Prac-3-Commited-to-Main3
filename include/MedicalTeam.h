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
 * Remains operational during emergency alerts and evacuations to provide first aid support[cite: 1].
 */
class MedicalTeam : public EventUnit {
private:
    bool available;
    int currentPatients;
    int maxPatients;
    int medicalSupplies;

public:
    /**
     * @brief Constructs a MedicalTeam instance with capacity and supply constraints.
     * @param name Name or unit code for the first aid post.
     * @param maxPatients Maximum concurrent patients the team can accommodate.
     * @param medicalSupplies Initial supply units available for triage.
     */
    MedicalTeam(std::string name, int maxPatients, int medicalSupplies);

    /**
     * @brief Virtual destructor for MedicalTeam.
     */
    virtual ~MedicalTeam() override;

    /**
     * @brief Admits and treats a patient, consuming medical supplies based on severity.
     * @param severity Numeric severity rating indicating supply consumption.
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

#endif