/**
 * @file Notice.h
 * @brief Header definition for Notice types and data payload object in the Observer pattern.
 */

#ifndef NOTICE_H
#define NOTICE_H

#include "NoticeType.h"
#include <string>
/**
 * @class Notice
 * @brief Encapsulates push-notification data transferred from Subject to Observers.
 */
class Notice {
private:
    NoticeType type;
    std::string target;
    std::string message;
	int value;

public:
    /**
     * @brief Constructs a Notice payload object.
     * @param type The NoticeType category.
     * @param message Textual payload detailing the event.
     * @param sender Identifier of the component generating the notice.
     */
    Notice(NoticeType type, std::string message, std::string target, int value);

    ~Notice();

    NoticeType getType() const;
    std::string getMessage() const;
    std::string getTarget() const;
	int getValue()const;
};

#endif