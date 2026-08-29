#ifndef FOODVENDOR_H
#define FOODVENDOR_H
#include <string>
#include "EventUnit.h"

class Notice;
class FoodVendor : public EventUnit {

private:
	bool serving;
	int stockLevel;

public:
	bool serveFood();

	void restock(int amount);

	void update(const Notice& notice);

	FoodVendor(std::string name, int stockLevel);
};

#endif
