#include "Notice.h"

NoticeType Notice::getType() const {
	return this->type;
}

std::string Notice::getMessage() const {
	return this->message;
}

std::string Notice::getTarget() const {
	return this->target;
}

int Notice::getValue() const {
	return this->value;
}

Notice::Notice(NoticeType type, std::string message, std::string target, int value)
    : type(type), message(message), target(target), value(value){}
