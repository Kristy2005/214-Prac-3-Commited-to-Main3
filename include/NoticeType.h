/**
 * @file NoticeType.h
 * @brief Categorized event notification types required by Task 3.3.
 */

#ifndef NOTICETYPE_H
#define NOTICETYPE_H

enum class NoticeType {
    OPEN,
    CLOSE,
    SCHEDULE_CHANGE,
    CAPACITY_ALERT,
    WEATHER_ALERT,
    PAUSE,
    RESUME,
    EVACUATE,
    LAST_CALL
};

#endif