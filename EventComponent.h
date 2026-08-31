/**
 * @file EventComponent.h
 * @brief Header definition for the abstract EventComponent class in the Composite pattern.
 */

#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>

/**
 * @class EventComponent
 * @brief Abstract base class representing any structural component in the festival hierarchy.
 * 
 * @details 
 * GoF Role: Component (Composite Pattern).
 * 
 * EventComponent defines the common interface for all elements in the festival composite tree, 
 * including both leaf operational units (EventUnit subclasses) and composite zone containers (EventGroup).
 * 
 * DESIGN DECISION: Transparent Uniform Component Interface
 * Declares operational controls (open, close, reportStatus, getCapacity) as pure virtual functions 
 * at the base Component level. This allows client code and central controllers to treat single operational 
 * units and entire composite sub-trees uniformly without performing runtime type checking (RTTI) or casting.
 */
class EventComponent {
protected:
    std::string name; /**< Descriptive name identifier for the component. */

public:
    /**
     * @brief Constructs an EventComponent with a given name.
     * @param name Descriptive name identifier.
     */
    explicit EventComponent(std::string name);

    /**
     * @brief Virtual destructor to guarantee proper polymorphic deletion down derived hierarchies.
     */
    virtual ~EventComponent();

    /**
     * @brief Opens the component or cascades open operations down child components.
     */
    virtual void open() = 0;

    /**
     * @brief Closes the component or cascades close operations down child components.
     */
    virtual void close() = 0;

    /**
     * @brief Reports status metrics to standard output for this component or sub-tree.
     */
    virtual void reportStatus() const = 0;

    /**
     * @brief Calculates maximum attendee capacity for this component or aggregate sub-tree.
     * @return Integer capacity count.
     */
    virtual int getCapacity() const = 0;

    /**
     * @brief Retrieves the descriptive name of the component.
     * @return std::string containing component name.
     */
    std::string getName() const;
};

#endif // EVENTCOMPONENT_H