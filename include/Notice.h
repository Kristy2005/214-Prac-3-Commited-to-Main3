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
 */
class Notice {
private:
    NoticeType type;
    std::string message;
    std::string target;
    int value;

public:
    /**
     * @brief Constructs a Notice payload object.
     * @param type Category of event notification.
     * @param message Descriptive textual message.
     * @param target Specific target unit or zone name (default: "ALL").
     * @param value Optional numeric metric (e.g., threshold capacity or severity).
     */
    Notice(NoticeType type, std::string message, std::string target = "ALL", int value = 0);
    ~Notice();

    NoticeType getType() const;
    std::string getMessage() const;
    std::string getTarget() const;
    int getValue() const;
};

#endif