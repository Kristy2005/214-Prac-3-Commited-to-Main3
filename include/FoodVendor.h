/**
 * @file FoodVendor.h
 * @brief Concrete Leaf component representing food trucks and stalls.
 */

#ifndef FOODVENDOR_H
#define FOODVENDOR_H

#include <string>
#include "EventUnit.h"

class Notice;

/**
 * @class FoodVendor
 * @brief Concrete Leaf managing food inventory and catering operations.
 * 
 * @details 
 * GoF Role: ConcreteObserver (Observer Pattern) / Leaf (Composite Pattern).
 * 
 * Manages food portion sales and inventory replenishment. Listens for festival notifications 
 * to halt operations during evacuations or zone closures, and resume service upon notification.
 * 
 * DESIGN DECISION: Automated Operational State Control
 * Upon receiving EVACUATE, CLOSE, or WEATHER_ALERT notices, FoodVendor automatically updates 
 * its 'serving' state flag to false, rejecting subsequent serveFood() calls until an OPEN or 
 * RESUME notice is dispatched.
 */
class FoodVendor : public EventUnit {
private:
    bool serving;   /**< Flag indicating whether the vendor is actively open and serving customers. */
    int stockLevel; /**< Current quantity of available food portions in inventory. */
    bool busy;      /**< Operational status flag indicating high customer queue volume. */

public:
    /**
     * @brief Virtual destructor ensuring clean polymorphic cleanup.
     */
    virtual ~FoodVendor();

    /**
     * @brief Constructs a FoodVendor instance.
     * @param name Name or designation of the food stall or truck.
     * @param stockLevel Initial available food portions in stock.
     */
    FoodVendor(std::string name, int stockLevel);

    /**
     * @brief Serves a food order if the vendor is active and stock is available.
     * @return True if order was filled and stock decremented, false if out of stock or closed.
     */
    bool serveFood();

    /**
     * @brief Replenishes available food inventory stock.
     * @param amount Quantity of food portions added to stock.
     */
    void restock(int amount);

    /**
     * @brief Handles operational state changes triggered by festival notice dispatches.
     * @param notice Reference to the Notice payload.
     */
    void update(const Notice& notice) override;
};

#endif // FOODVENDOR_H