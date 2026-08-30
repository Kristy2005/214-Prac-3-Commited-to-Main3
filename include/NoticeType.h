#ifndef NOTICETYPE_H
#define NOTICETYPE_H

/**
 * @enum NoticeType
 * @brief Categorized event notification types required by Task 3.3.
 */
enum class NoticeType {
    // Operational changes
    OPEN,
    CLOSE,
    SCHEDULE_CHANGE,

    // Capacity-related changes
    CAPACITY_ALERT,

    // Safety-related changes
    WEATHER_ALERT,
    PAUSE,
    RESUME,
    EVACUATE
};

#endif
