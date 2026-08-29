#include <iostream>
#include <string>

#include "EventGroup.h"
#include "EventControl.h"
#include "Notice.h"
#include "NoticeType.h"

#include "Stage.h"
#include "EntranceGate.h"
#include "StageGate.h"
#include "Bar.h"
#include "FoodVendor.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"

int main()
{
    // Root Composite representing the whole festival
    EventGroup* festivalGrounds =
        new EventGroup("Summer Music Festival");


    // -------------------------
    // River Stage area
    // -------------------------

    EventGroup* riverZone =
        new EventGroup("River Zone");

    EventGroup* riverStageArea =
        new EventGroup("River Stage Area");

    Stage* riverStage =
        new Stage(
            "River Stage",
            200,
            true,
            "Indie",
            true
        );

    StageGate* riverGate =
        new StageGate(
            "River Stage Gate",
            riverStage
        );

    Bar* riverBar =
        new Bar(
            "River Bar",
            100
        );

    SecurityTeam* riverSecurity =
        new SecurityTeam(
            "River Security Team"
        );

    MedicalTeam* riverMedical =
        new MedicalTeam(
            "River Medical Team",
            10,
            50
        );


    // Add the River Stage leaves to the River Stage Area
    riverStageArea->add(riverStage);
    riverStageArea->add(riverGate);
    riverStageArea->add(riverBar);
    riverStageArea->add(riverSecurity);
    riverStageArea->add(riverMedical);


    // Add the River Stage Area to the River Zone
    riverZone->add(riverStageArea);


    // Add the River Zone to the Festival Grounds
    festivalGrounds->add(riverZone);


    // -------------------------
    // Main entrance
    // -------------------------

    EntranceGate* mainEntrance =
        new EntranceGate(
            "Main Entrance",
            18
        );

    festivalGrounds->add(mainEntrance);


    // -------------------------
    // Food service area
    // -------------------------

    EventGroup* serviceArea =
        new EventGroup("Food and Service Area");

    FoodVendor* pizzaVendor =
        new FoodVendor(
            "Pizza Vendor",
            80
        );

    FoodVendor* burgerVendor =
        new FoodVendor(
            "Burger Vendor",
            100
        );

    serviceArea->add(pizzaVendor);
    serviceArea->add(burgerVendor);

    festivalGrounds->add(serviceArea);


    // -------------------------
    // Test Composite behaviour
    // -------------------------

    std::cout << "\nOpening festival:\n";
    festivalGrounds->open();

    std::cout << "\nFestival status:\n";
    festivalGrounds->reportStatus();

    std::cout << "\nTotal festival capacity: "
              << festivalGrounds->getCapacity()
              << std::endl;


    // -------------------------
    // Clean shutdown
    // -------------------------

    delete festivalGrounds;

    festivalGrounds = nullptr;

    return 0;
}