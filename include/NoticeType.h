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
