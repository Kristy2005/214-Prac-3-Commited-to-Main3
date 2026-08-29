#include "Bar.h"

bool Bar::serveDrink() {
	// TODO - implement Bar::serveDrink
	throw "Not yet implemented";
}

void Bar::update(const Notice& notice) {
	// TODO - implement Bar::update
	throw "Not yet implemented";
}

Bar::Bar(std::string name, int drinkStock)
    : EventUnit(name, 0),serving(true),lastCall(false),drinkStock(drinkStock){}

void Bar::startLastCall() {
	// TODO - implement Bar::startLastCall
	throw "Not yet implemented";
}

void Bar::restockDrinks(int amount) {
	// TODO - implement Bar::restockDrinks
	throw "Not yet implemented";
}
