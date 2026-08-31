/**
 * @file Notice.h
 * @brief Encapsulates push-notification data transferred from Subject to Observers.
 */

#ifndef NOTICE_H
#define NOTICE_H

#include "NoticeType.h"
#include <string>

/**
 * @class Notice
 * @brief Encapsulates notification data pushed from Subject to Observers.
 * 
 * @details 
 * GoF Role: Event Payload / Concrete Notification (Observer Pattern).
 * 
 * The Notice class encapsulates event details (category type, descriptive message, 
 * target identifier, and numeric value) created by Subjects and dispatched to Observers.
 * 
 * DESIGN DECISION: Immutable Pass-by-Const-Reference Value Object
 * Notice objects are designed with value semantics and passed down observer notification 
 * chains via 'const Notice&'. This prevents observers from modifying notification payload 
 * state during cascading updates while avoiding expensive dynamic allocations.
 */
class Notice {
private:
    NoticeType type;     /**< Category classification of the notification event. */
    std::string message; /**< Human-readable explanation or alert details. */
    std::string target;  /**< Target component identifier ("ALL" for global broadcasts). */
    int value;           /**< Optional numeric parameter (e.g. capacity limits or severity). */

public:
    /**
     * @brief Constructs a Notice payload object.
     * @param type Category of event notification.
     * @param message Descriptive textual message.
     * @param target Specific target unit or zone name (default: "ALL").
     * @param value Optional numeric metric (e.g., threshold capacity or severity level).
     */
    Notice(NoticeType type, std::string message, std::string target = "ALL", int value = 0);

    /**
     * @brief Destructor for Notice payload instances.
     */
    ~Notice();

    /**
     * @brief Retrieves the notification event category type.
     * @return The NoticeType enumeration value.
     */
    NoticeType getType() const;

    /**
     * @brief Retrieves the descriptive message string of the notice.
     * @return std::string containing event details.
     */
    std::string getMessage() const;

    /**
     * @brief Retrieves the target component or zone identifier for this notice.
     * @return std::string specifying target name ("ALL" if broadcast to all).
     */
    std::string getTarget() const;

    /**
     * @brief Retrieves the optional numeric payload metric.
     * @return Integer value associated with the event (e.g., capacity count).
     */
    int getValue() const;
};

#endif // NOTICE_H