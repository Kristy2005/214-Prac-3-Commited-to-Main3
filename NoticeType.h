/**
 * @file NoticeType.h
 * @brief Categorized event notification types required for event dispatches.
 */

#ifndef NOTICETYPE_H
#define NOTICETYPE_H

/**
 * @enum NoticeType
 * @brief Strongly typed enumeration representing broadcast alert categories across the festival.
 * 
 * @details 
 * GoF Pattern Role: Notification Payload Category (Observer Pattern).
 * Serves as the key differentiator when Subject dispatches event payloads to Observer 
 * instances, allowing concrete components to selectively trigger specific reaction logic.
 */
enum class NoticeType {
    OPEN,            /**< Signals that a zone, gate, or vendor is opening for operations. */
    CLOSE,           /**< Signals that a zone, gate, or vendor is closing operations. */
    SCHEDULE_CHANGE, /**< Indicates a timetable or performance schedule adjustment. */
    CAPACITY_ALERT,  /**< Warns that a stage or zone has reached maximum attendee threshold. */
    WEATHER_ALERT,   /**< Alerts components of severe weather or environmental conditions. */
    PAUSE,           /**< Temporarily halts performances or stage operations. */
    RESUME,          /**< Resumes normal operations following a pause or safety clearance. */
    EVACUATE,        /**< Triggers immediate, high-priority emergency evacuation protocols. */
    LAST_CALL        /**< Signals last call for beverage/food service at bars and vendors. */
};

#endif // NOTICETYPE_H