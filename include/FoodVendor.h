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
 * Reacts to opening, closing, and emergency evacuation notices across festival zones[cite: 1].
 */
class FoodVendor : public EventUnit {
private:
    bool serving;
    int stockLevel;
    bool busy;

public:
    virtual ~FoodVendor();
    /**
     * @brief Constructs a FoodVendor instance.
     * @param name Name of the food stall or truck.
     * @param stockLevel Initial available food portions in stock.
     */
    FoodVendor(std::string name, int stockLevel);

   
    /**
     * @brief Serves a food order if vendor is active and stock is available.
     * @return True if order was filled, false if out of stock or closed.
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

#endif