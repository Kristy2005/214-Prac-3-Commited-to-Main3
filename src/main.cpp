// ============================================================
// COS 214 Practical 3 - Task 5: Summer Music Festival Engine
// ============================================================

// ==== COLOR MACROS ====
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

// 5.1 — Include directives
#include <iostream>
#include <string>
#include <vector>

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

using namespace std;

// 5.2 — Body of main() implementing steps 1–7
int main()
{
    cout << YELLOW << "\n====== COS 214 Practical 3 — Summer Music Festival Engine ======\n" << RESET;
    cout << CYAN << "Starting event management and notification control system...\n" << RESET;

    // ------------------------------------------------------------
    // Step 1: Central Control Center Instantiation
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 1: Instantiating Central Event Control Centre" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    EventControl* eventControl = new EventControl("Summer Music Festival Control Centre");
    cout << GREEN << "  [OK] EventControl instantiated" << RESET << endl;

    // ------------------------------------------------------------
    // Step 2: Constructing Teammate's Original Composite Hierarchy
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 2: Building Composite Structure (Original Layout)" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    // Root Composite representing the whole festival
    EventGroup* festivalGrounds = new EventGroup("Summer Music Festival");

    // -------------------------
    // River Stage area
    // -------------------------
    EventGroup* riverZone = new EventGroup("River Zone");
    EventGroup* riverStageArea = new EventGroup("River Stage Area");

    Stage* riverStage = new Stage(
        "River Stage",
        200,
        true,
        "Indie",
        true
    );

    StageGate* riverGate = new StageGate(
        "River Stage Gate",
        riverStage
    );

    Bar* riverBar = new Bar(
        "River Bar",
        100
    );

    SecurityTeam* riverSecurity = new SecurityTeam(
        "River Security Team"
    );

    MedicalTeam* riverMedical = new MedicalTeam(
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
    EntranceGate* mainEntrance = new EntranceGate(
        "Main Entrance",
        18
    );

    festivalGrounds->add(mainEntrance);

    // -------------------------
    // Food service area
    // -------------------------
    EventGroup* serviceArea = new EventGroup("Food and Service Area");

    FoodVendor* pizzaVendor = new FoodVendor(
        "Pizza Vendor",
        80
    );

    FoodVendor* burgerVendor = new FoodVendor(
        "Burger Vendor",
        100
    );

    serviceArea->add(pizzaVendor);
    serviceArea->add(burgerVendor);

    festivalGrounds->add(serviceArea);

    cout << GREEN << "  [OK] Festival Composite hierarchy built successfully" << RESET << endl;

    // ------------------------------------------------------------
    // Step 3: Registering Observers for Cascading Notifications
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 3: Establishing Observer Registration Chains" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    // Attach root composite to central control subject
    eventControl->attach(festivalGrounds);

    // Establish observer cascade through composites
    riverStageArea->attach(riverStage);
    riverStageArea->attach(riverGate);
    riverStageArea->attach(riverBar);
    riverStageArea->attach(riverSecurity);
    riverStageArea->attach(riverMedical);

    riverZone->attach(riverStageArea);

    serviceArea->attach(pizzaVendor);
    serviceArea->attach(burgerVendor);

    festivalGrounds->attach(riverZone);
    festivalGrounds->attach(mainEntrance);
    festivalGrounds->attach(serviceArea);

    cout << GREEN << "  [OK] Observers attached across all festival zones and leaf units" << RESET << endl;

    // ------------------------------------------------------------
    // Step 4: Executing Teammate's Original Composite Tests
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 4: Executing Original Composite Behavior Tests" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    std::cout << "\nOpening festival:\n";
    festivalGrounds->open();

    std::cout << "\nFestival status:\n";
    festivalGrounds->reportStatus();

    std::cout << "\nTotal festival capacity: "
              << festivalGrounds->getCapacity()
              << std::endl;

    // ------------------------------------------------------------
    // Step 5: Testing Push Notifications (Observer Engine)
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 5: Testing Observer Dispatches (Notice Pipeline)" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    cout << CYAN << "  [Dispatch 1] WEATHER_ALERT Notice" << RESET << endl;
    Notice weatherNotice(NoticeType::WEATHER_ALERT, "Heavy rain and river flood warning", "ALL", 5);
    eventControl->issueNotice(weatherNotice);

    cout << CYAN << "\n  [Dispatch 2] CAPACITY_ALERT Notice (Targeted)" << RESET << endl;
    Notice capacityNotice(NoticeType::CAPACITY_ALERT, "River Stage at maximum capacity", "River Stage Gate", 200);
    eventControl->issueNotice(capacityNotice);

    cout << CYAN << "\n  [Dispatch 3] LAST_CALL Notice" << RESET << endl;
    Notice lastCallNotice(NoticeType::LAST_CALL, "Last call for drinks at bars", "ALL", 15);
    eventControl->issueNotice(lastCallNotice);

    cout << CYAN << "\n  [Dispatch 4] EVACUATE Notice" << RESET << endl;
    Notice evacuateNotice(NoticeType::EVACUATE, "Emergency evacuation ordered", "ALL", 999);
    eventControl->issueNotice(evacuateNotice);

    cout << CYAN << "\n  [Dispatch 5] RESUME Notice" << RESET << endl;
    Notice resumeNotice(NoticeType::RESUME, "Clear to resume operations", "ALL", 0);
    eventControl->issueNotice(resumeNotice);

    // ------------------------------------------------------------
    // Step 6: Testing Dynamic Component Reorganization
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 6: Testing Dynamic Component Transfer Between Groups" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    cout << CYAN << "  Transferring 'River Security Team' from 'River Stage Area' to 'Food and Service Area'..." << RESET << endl;

    // 1. Detach from old observer subject
    riverStageArea->detach(riverSecurity);

    // 2. Remove from old composite container (without deleting memory)
    riverStageArea->remove(riverSecurity);

    // 3. Add to new composite container
    serviceArea->add(riverSecurity);

    // 4. Attach to new observer subject
    serviceArea->attach(riverSecurity);

    cout << GREEN << "  [OK] Transfer complete" << RESET << endl;
    cout << CYAN << "  Reporting status of updated Food and Service Area:" << RESET << endl;
    serviceArea->reportStatus();

    // ------------------------------------------------------------
    // Step 7: Clean Shutdown & Memory Deallocation
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 7: Executing Clean Shutdown & Memory Verification" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    // Delete central control subject (holds non-owning observer pointers)
    delete eventControl;
    eventControl = nullptr;
    cout << GREEN << "  [OK] EventControl deleted" << RESET << endl;

    // Delete root composite tree (recursively deletes all owned children)
    delete festivalGrounds;
    festivalGrounds = nullptr;
    cout << GREEN << "  [OK] festivalGrounds deleted (All nested nodes deallocated cleanly)" << RESET << endl;

    cout << YELLOW << "\n====== Engine shutdown complete ======\n\n" << RESET;
    return 0;
}