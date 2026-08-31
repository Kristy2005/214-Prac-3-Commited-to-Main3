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
 * Controls beverage distribution and reacts to schedule changes or festival closure notices[cite: 1].
 */
class Bar : public EventUnit {
private:
    bool serving;
    bool lastCall;
    int drinkStock;
    bool busy;

public:
    virtual ~Bar();
    /**
     * @brief Constructs a Bar instance with initial inventory stock.
     * @param name Descriptive identifier for the bar unit.
     * @param drinkStock Total initial units of drink inventory.
     */
    Bar(std::string name, int drinkStock);


    /**
     * @brief Serves a beverage to a customer if stock is available and serving is enabled.
     * @return True if drink was served successfully, false otherwise.
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

#endif