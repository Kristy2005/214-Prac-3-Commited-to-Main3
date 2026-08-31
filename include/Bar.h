/**
 * @file Bar.h
 * @brief Concrete Leaf component representing beverage service stations.
 */

#ifndef BAR_H
#define BAR_H

#include <string>
#include "EventUnit.h"

class Notice;

/**
 * @class Bar
 * @brief Concrete Leaf managing beverage inventory, sales, and last-call protocols.
 * 
 * @details 
 * GoF Role: ConcreteObserver (Observer Pattern) / Leaf (Composite Pattern).
 * 
 * Controls beverage distribution, monitors active stock levels, and reacts 
 * dynamically to schedule changes or emergency closure notices.
 * 
 * DESIGN DECISION: Multi-State Notice Reaction Protocol
 * Bar encapsulates fine-grained operational states (serving, lastCall, busy) beyond simple 
 * binary open/close states. Upon receiving Subject notifications (Notice payload), the Bar can 
 * transition to an intermediate last-call mode before total shutdown, guaranteeing orderly attendee 
 * dispersal without abrupt service termination.
 */
class Bar : public EventUnit {
private:
    bool serving;     /**< Flag indicating if the bar is actively serving beverages. */
    bool lastCall;    /**< Flag indicating if last-call restrictions are currently in effect. */
    int drinkStock;   /**< Current inventory count of available beverages. */
    bool busy;        /**< State flag indicating high-density customer activity. */

public:
    /**
     * @brief Constructs a Bar instance with a name and initial drink stock.
     * @param name Descriptive identifier for the bar unit (e.g., "Main Stage Bar").
     * @param drinkStock Total initial units of drink inventory.
     */
    Bar(std::string name, int drinkStock);

    /**
     * @brief Virtual destructor ensuring clean polymorphic cleanup.
     */
    virtual ~Bar();

    /**
     * @brief Serves a beverage to a customer if stock is available and serving is enabled.
     * @return True if a drink was served successfully, false if out of stock or closed.
     */
    bool serveDrink();

    /**
     * @brief Triggers last-call protocols in response to schedule or closing alerts.
     */
    void startLastCall();

    /**
     * @brief Adds stock units to the bar's active inventory.
     * @param amount Quantity of drinks to add to stock.
     */
    void restockDrinks(int amount);

    /**
     * @brief Receives event notices to initiate last-call, resume service, or close down.
     * @param notice Reference to the Notice payload.
     */
    void update(const Notice& notice) override;
};

#endif // BAR_H