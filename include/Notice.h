#ifndef NOTICE_H
#define NOTICE_H

#include <string>
#include "NoticeType.h"

class Notice {

private:
	NoticeType type;
	std::string message;
	std::string target;
	int value;

public:
	NoticeType getType() const;

	std::string getMessage() const;

	std::string getTarget() const;

	int getValue() const;

	Notice(NoticeType type, std::string message, std::string target, int value);
};

#endif
