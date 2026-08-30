/**
 * @file EventComponent.h
 * @brief Header definition for the abstract EventComponent class in the Composite pattern.
 */

#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>

/**
 * @class EventComponent
 * @brief Abstract base class representing any structural component in the festival.
 * 
 * @details 
 * GoF Role: Component (Composite Pattern).
 * Serves as the common base interface for both individual operational units (Leaves) 
 * and grouped festival areas (Composites).
 */
class EventComponent {
protected:
    std::string name;

public:
    /**
     * @brief Constructs an EventComponent with a given name.
     * @param name Descriptive name of the component.
     */
    explicit EventComponent(std::string name);

    /**
     * @brief Virtual destructor ensuring safe polymorphic deallocation.
     */
    virtual ~EventComponent();

    virtual void open() = 0;
    virtual void close() = 0;
    virtual void reportStatus() const = 0;
    virtual int getCapacity() const = 0;

    std::string getName() const;
};

#endif