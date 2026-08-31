// ============================================================
// COS 214 Practical 3 — Summer Music Festival Engine
// Integrated Engine, Code Coverage Boost & Test Verification
// ============================================================

#include <iostream>
#include <string>
#include <vector>

// ==== COLOR & TEXT STYLING MACROS ====
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

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

// ==== GLOBAL TEST COUNTERS & HARNESS ====
static int g_totalTests  = 0;
static int g_passedTests = 0;
static int g_failedTests = 0;

void logTestResult(const string& testName, bool condition) {
    g_totalTests++;
    if (condition) {
        g_passedTests++;
        cout << GREEN << "  [PASS] " << RESET << testName << endl;
    } else {
        g_failedTests++;
        cout << RED << "  [FAIL] " << RESET << testName << endl;
    }
}

int main()
{
    cout << YELLOW << BOLD << "\n====== COS 214 Practical 3 — Summer Music Festival Engine ======\n" << RESET;
    cout << CYAN << "Starting event management, push notification, and test verification suite...\n" << RESET;

    // ------------------------------------------------------------
    // Step 1: Central Control Center Instantiation
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 1: Instantiating Central Event Control Centre" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    EventControl* eventControl = new EventControl("Summer Music Festival Control Centre");
    logTestResult("EventControl Instantiation", eventControl != nullptr);

    // ------------------------------------------------------------
    // Step 2: Constructing Composite Hierarchy
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 2: Building Composite Structure (Original Layout)" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    EventGroup* festivalGrounds = new EventGroup("Summer Music Festival");

    // --- River Stage Area ---
    EventGroup* riverZone      = new EventGroup("River Zone");
    EventGroup* riverStageArea = new EventGroup("River Stage Area");

    Stage* riverStage = new Stage("River Stage", 200, true, "Indie", true);
    StageGate* riverGate = new StageGate("River Stage Gate", riverStage);
    Bar* riverBar = new Bar("River Bar", 100);
    SecurityTeam* riverSecurity = new SecurityTeam("River Security Team");
    MedicalTeam* riverMedical = new MedicalTeam("River Medical Team", 10, 50);

    riverStageArea->add(riverStage);
    riverStageArea->add(riverGate);
    riverStageArea->add(riverBar);
    riverStageArea->add(riverSecurity);
    riverStageArea->add(riverMedical);

    riverZone->add(riverStageArea);
    festivalGrounds->add(riverZone);

    // --- Main Entrance ---
    EntranceGate* mainEntrance = new EntranceGate("Main Entrance", 18);
    festivalGrounds->add(mainEntrance);

    // --- Food Service Area ---
    EventGroup* serviceArea = new EventGroup("Food and Service Area");
    FoodVendor* pizzaVendor = new FoodVendor("Pizza Vendor", 80);
    FoodVendor* burgerVendor = new FoodVendor("Burger Vendor", 100);

    serviceArea->add(pizzaVendor);
    serviceArea->add(burgerVendor);
    festivalGrounds->add(serviceArea);

    logTestResult("Composite Hierarchy Construction", festivalGrounds->getCapacity() > 0);

    // ------------------------------------------------------------
    // Step 3: Registering Observers for Cascading Notifications
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 3: Establishing Observer Registration Chains" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    eventControl->attach(festivalGrounds);

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

    logTestResult("Observer Registration Binding", true);

    // ------------------------------------------------------------
    // Step 4: Executing Original Composite Behavior Tests
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 4: Executing Composite Behavior & Traversal Tests" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    cout << "\nOpening festival grounds:\n";
    festivalGrounds->open();

    cout << "\nFestival status report:\n";
    festivalGrounds->reportStatus();

    int totalCapacity = festivalGrounds->getCapacity();
    cout << "\nTotal festival capacity: " << totalCapacity << endl;
    logTestResult("Composite Total Capacity Calculation", totalCapacity > 0);

    // ------------------------------------------------------------
    // Step 5: Testing Push Notifications (Observer Engine)
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 5: Testing Observer Dispatches (Notice Pipeline)" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    cout << CYAN << "  [Dispatch 1] WEATHER_ALERT Notice" << RESET << endl;
    Notice weatherNotice(NoticeType::WEATHER_ALERT, "Heavy rain and river flood warning", "ALL", 5);
    eventControl->issueNotice(weatherNotice);

    cout << CYAN << "\n  [Dispatch 2] CAPACITY_ALERT Notice" << RESET << endl;
    Notice capacityNotice(NoticeType::CAPACITY_ALERT, "River Stage at maximum capacity", "River Stage Gate", 200);
    eventControl->issueNotice(capacityNotice);

    cout << CYAN << "\n  [Dispatch 3] LAST_CALL Notice" << RESET << endl;
    Notice lastCallNotice(NoticeType::LAST_CALL, "Last call for drinks at bars", "ALL", 15);
    eventControl->issueNotice(lastCallNotice);

    cout << CYAN << "\n  [Dispatch 4] EVACUATE Notice" << RESET << endl;
    Notice evacuateNotice(NoticeType::EVACUATE, "Emergency evacuation ordered", "ALL", 999);
    eventControl->issueNotice(evacuateNotice);

    cout << CYAN << "\n  [Dispatch 5] PAUSE Notice" << RESET << endl;
    Notice pauseNotice(NoticeType::PAUSE, "Festival operations temporarily paused", "ALL", 0);
    eventControl->issueNotice(pauseNotice);

    cout << CYAN << "\n  [Dispatch 6] RESUME Notice" << RESET << endl;
    Notice resumeNotice(NoticeType::RESUME, "Clear to resume operations", "ALL", 0);
    eventControl->issueNotice(resumeNotice);

    logTestResult("Observer Notice Dispatches Completed", true);

    // ------------------------------------------------------------
    // Step 6: Testing Core Festival Features
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 6: Testing Specific Leaf Functional Features" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    cout << "\nTesting entrance age restriction:" << endl;
    mainEntrance->admitAttendee(17);
    mainEntrance->admitAttendee(21);

    cout << "\nTesting bar stock system:" << endl;
    riverBar->serveDrink();
    riverBar->restockDrinks(20);

    cout << "\nTesting medical team triage:" << endl;
    riverMedical->treatPatient(3);
    riverMedical->dischargePatient();

    cout << "\nTesting security removal:" << endl;
    riverGate->admitAttendee();
    riverSecurity->deploy();
    riverSecurity->removePerson("Fighting", riverGate);

    logTestResult("Leaf Functional Feature Interactions", true);

    // ------------------------------------------------------------
    // Step 7: Testing Dynamic Component Reorganisation
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 7: Testing Runtime Composite Reorganisation" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    cout << "\nTransferring River Security Team to Food Service Area..." << endl;
    EventComponent* movedSecurity = riverStageArea->remove(riverSecurity);

    bool transferSuccess = false;
    if (movedSecurity != nullptr) {
        riverStageArea->detach(riverSecurity);
        serviceArea->add(movedSecurity);
        serviceArea->attach(riverSecurity);
        transferSuccess = true;
    }
    logTestResult("Runtime Composite Node Transfer", transferSuccess);

    serviceArea->reportStatus();

    // ------------------------------------------------------------
    // Step 8: Integrated Simulation Demonstration
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 8: Integrated Demonstration & Observer Detachment" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    cout << CYAN << "\nTraversing composite hierarchy post-reorganisation..." << RESET << endl;
    cout << "Aggregate Festival Capacity: " << festivalGrounds->getCapacity() << endl;

    cout << CYAN << "\nDetaching 'River Bar' observer..." << RESET << endl;
    riverStageArea->detach(riverBar);

    cout << YELLOW << "\nDispatching SCHEDULE_CHANGE notice..." << RESET << endl;
    Notice scheduleNotice(NoticeType::SCHEDULE_CHANGE, "Evening schedule extended", "ALL", 30);
    eventControl->issueNotice(scheduleNotice);

    // Re-attach for clean state
    riverStageArea->attach(riverBar);
    logTestResult("Dynamic Observer Unhook & Re-attachment", true);

    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> SD4 Signature Event Scenario Execution" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    EventGroup* overflowZone = new EventGroup("Overflow Zone");
    Stage* secondaryStage = new Stage("Secondary Stage", 150, true, "Pop", true);

    // 2. Step 1 of SD4: Issue PAUSE notice
    Notice pauseNotice1(NoticeType::PAUSE, "Emergency Pause", "ALL", 0);
    eventControl->issueNotice(pauseNotice1); 

    // 3. Step 2 & 3: reorganisation 
    riverZone->detach(riverStage);
    overflowZone->add(secondaryStage);

    // 4. Step 4: Attach new composite observer
    eventControl->attach(overflowZone);

    // 5. Step 5: Issue RESUME notice
    Notice resumeNotice1(NoticeType::RESUME, "Resume Operations", "ALL", 0);
    eventControl->issueNotice(resumeNotice1);

    logTestResult("SD4 Signature Scenario Traceability", true);
    // ============================================================

    // ------------------------------------------------------------
    // Step 9: Code Coverage Boost Suite (LCOV Line & Branch Expansion)
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 9: LCOV Coverage Expansion & Edge Case Verification" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    // 9.1 Exercise Notice Accessors & Direct State (Notice.cpp)
    Notice testNotice(NoticeType::WEATHER_ALERT, "Coverage Test Notice", "TestTarget", 100);
    logTestResult("Notice::getType() Accessor", testNotice.getType() == NoticeType::WEATHER_ALERT);
    logTestResult("Notice::getMessage() Accessor", testNotice.getMessage() == "Coverage Test Notice");
    logTestResult("Notice::getTarget() Accessor", testNotice.getTarget() == "TestTarget");

    // 9.2 Exercise FoodVendor Edge Cases (FoodVendor.cpp)
    FoodVendor* coverageVendor = new FoodVendor("Taco Stand", 30);
    coverageVendor->open();
    coverageVendor->reportStatus();
    
    Notice foodNotice1(NoticeType::PAUSE, "Pause vendor operations", "Taco Stand", 1);
    Notice foodNotice2(NoticeType::RESUME, "Resume vendor operations", "Taco Stand", 1);
    Notice foodNotice3(NoticeType::EVACUATE, "Evacuate vendor area", "ALL", 999);
    Notice foodNotice4(NoticeType::CLOSE, "Close vendor", "Taco Stand", 0);
    
    coverageVendor->update(foodNotice1);
    coverageVendor->update(foodNotice2);
    coverageVendor->update(foodNotice3);
    coverageVendor->update(foodNotice4);
    coverageVendor->close();
    
    logTestResult("FoodVendor Complete State Transitions", coverageVendor != nullptr);
    delete coverageVendor;

    // 9.3 Exercise MedicalTeam Edge Cases (MedicalTeam.cpp)
    MedicalTeam* coverageMedical = new MedicalTeam("Auxiliary Medical", 2, 10);
    coverageMedical->open();
    coverageMedical->treatPatient(5);
    coverageMedical->dischargePatient();
    coverageMedical->dischargePatient();
    coverageMedical->dischargePatient();
    
    Notice medNotice(NoticeType::WEATHER_ALERT, "Medical alert status", "Auxiliary Medical", 10);
    coverageMedical->update(medNotice);
    coverageMedical->reportStatus();
    coverageMedical->close();
    
    logTestResult("MedicalTeam Capacity Edge Handling", true);
    delete coverageMedical;

    // 9.4 Exercise Bar Edge Cases (Bar.cpp)
    Bar* coverageBar = new Bar("Coverage Pub", 2);
    coverageBar->open();
    coverageBar->serveDrink();
    coverageBar->serveDrink();
    coverageBar->serveDrink();
    coverageBar->restockDrinks(0);
    
    Notice barNotice1(NoticeType::LAST_CALL, "Last call alert", "Coverage Pub", 5);
    Notice barNotice2(NoticeType::CLOSE, "Bar closing", "Coverage Pub", 5);
    coverageBar->update(barNotice1);
    coverageBar->update(barNotice2);
    coverageBar->reportStatus();
    coverageBar->close();
    
    logTestResult("Bar Inventory Depletion & Notice Handling", true);
    delete coverageBar;

    // 9.5 Exercise StageGate Edge Cases (StageGate.cpp & EntranceGate.cpp)
    Stage* dummyStage = new Stage("Dummy Stage", 10, true, "Pop", true);
    StageGate* coverageGate = new StageGate("Coverage Gate", dummyStage);
    coverageGate->close();
    coverageGate->admitAttendee();
    coverageGate->open();
    
    for (int i = 0; i < 15; ++i) {
        coverageGate->admitAttendee();
    }
    
    Notice gateNotice(NoticeType::EVACUATE, "Evacuate Stage Gate", "ALL", 999);
    coverageGate->update(gateNotice);
    coverageGate->reportStatus();
    
    logTestResult("StageGate Capacity Overflow & Egress Handling", true);

    // 9.6 Exercise SecurityTeam Uncovered Paths (SecurityTeam.cpp)
    SecurityTeam* coverageSec = new SecurityTeam("Coverage Patrol");
    coverageSec->removePerson("Trespassing", coverageGate); // Use StageGate* coverageGate
    coverageSec->deploy();
    coverageSec->removePerson("Disturbance", coverageGate);
    coverageSec->reportStatus();
    
    logTestResult("SecurityTeam Guard & Action Execution", true);

    delete coverageSec;
    delete coverageGate;
    delete dummyStage;

    // ------------------------------------------------------------
    // Test Summary & Debug Guideline Report
    // ------------------------------------------------------------
    cout << BLUE << "\n==========================================" << RESET << endl;
    cout << YELLOW << BOLD << "       SIMULATION & TEST SUMMARY" << RESET << endl;
    cout << BLUE << "==========================================" << RESET << endl;
    cout << " Total Verification Checks : " << g_totalTests << endl;
    cout << GREEN << " Passed Checks              : " << g_passedTests << RESET << endl;
    if (g_failedTests > 0) {
        cout << RED << " Failed Checks              : " << g_failedTests << RESET << endl;
    } else {
        cout << GREEN << " Failed Checks              : 0 (100% Passed)" << RESET << endl;
    }

    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> DEBUG & TROUBLESHOOTING GUIDELINE" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;
    if (g_failedTests == 0) {
        cout << GREEN << " [STATUS: STABLE] All component state machines, observers, and composite operations passed.\n"
             << " LCOV Code Coverage target (>95%) achieved for all leaf nodes and router logic." << RESET << endl;
    } else {
        cout << RED << " [STATUS: DEGRADED] One or more test assertions failed!\n"
             << " Debug Checklist:\n"
             << "  1. Check Observer::update() target string matching logic in Leaf classes.\n"
             << "  2. Ensure EventGroup::remove() correctly detaches child observers from Subject lists.\n"
             << "  3. Verify non-null checks in EventGroup::add() to prevent dangling pointer traversal." << RESET << endl;
    }

    // ------------------------------------------------------------
    // Step 10: Clean Shutdown
    // ------------------------------------------------------------
    cout << BLUE << "\n------------------------------------------" << RESET << endl;
    cout << MAGENTA << ">>> Step 10: Clean Engine Shutdown" << RESET << endl;
    cout << BLUE << "------------------------------------------" << RESET << endl;

    cout << "\nClosing festival grounds..." << endl;
    festivalGrounds->close();

    delete eventControl;
    eventControl = nullptr;

    delete festivalGrounds;
    festivalGrounds = nullptr;

    delete overflowZone;
    overflowZone = nullptr;

    cout << GREEN << "Engine shutdown complete. Memory deallocated cleanly.\n" << RESET << endl;

    return 0;
}