#ifndef BAR_H
#define BAR_H
#include <string>
#include "EventUnit.h"

class Notice;
class Bar : public EventUnit {

private:
	bool serving;
	bool lastCall;
	int drinkStock;

public:
	bool serveDrink();

	void update(const Notice& notice);

	Bar(std::string name, int drinkStock);

	void startLastCall();

	void restockDrinks(int amount);
};

#endif
