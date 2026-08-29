#include "FoodVendor.h"

bool FoodVendor::serveFood() {
	// TODO - implement FoodVendor::serveFood
	throw "Not yet implemented";
}

void FoodVendor::restock(int amount) {
	// TODO - implement FoodVendor::restock
	throw "Not yet implemented";
}

void FoodVendor::update(const Notice& notice) {
	// TODO - implement FoodVendor::update
	throw "Not yet implemented";
}

FoodVendor::FoodVendor(std::string name, int stockLevel)
    : EventUnit(name, 0),serving(true),stockLevel(stockLevel){}
