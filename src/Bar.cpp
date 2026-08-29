#include "Bar.h"
#include <iostream>

bool Bar::serveDrink(){

    if (serving==false){
        std::cout << "Bar is not currently serving" << std::endl;
        return false;
    }

	//bartender busy serving someone else
    if (busy == true){
        std::cout << "Customer waits in line" << std::endl;
        return false;
    }

    if (drinkStock>0){
        busy = true;
        std::cout << "Customer gets a drink" << std::endl;
        --drinkStock;
        busy = false;
        return true;
    }

    std::cout << "Bar is out of stock" << std::endl;
    return false;
}

void Bar::update(const Notice& notice){

    if (notice.getType() == NoticeType::OPEN){
        isOpen = true;
        lastCall = false;
        std::cout << name << " bar is open" << std::endl;
    }

    if (notice.getType() == NoticeType::CLOSE){
        isOpen = false;
        serving = false;
        std::cout << name << " bar is closed" << std::endl;
    }

    if (notice.getType() == NoticeType::PAUSE){
        isOpen = false;
        serving = false;
        std::cout << name << " bar temporarily stops service" << std::endl;
    }

    if (notice.getType() == NoticeType::RESUME){
        isOpen = true;
        std::cout << name << " bar resumes service" << std::endl;
    }

    if (notice.getType() == NoticeType::EVACUATE){
        isOpen = false;
        serving = false;
        std::cout << name << " bar stops service for evacuation" << std::endl;
    }

    if (notice.getType() == NoticeType::LAST_CALL){
        startLastCall();
    }
}

//constructor
Bar::Bar(std::string name, int drinkStock)
    : EventUnit(name, 0),serving(true),busy(false),lastCall(false),drinkStock(drinkStock){}

void Bar::startLastCall(){

    if(lastCall==false){
        lastCall=true;
		//inherited name from event component
		//specific to cetain bars
        std::cout << name << " bar has started last call" << std::endl;
    }
    else{
        std::cout << name << " bar is already on last call" << std::endl;
    }
}

void Bar::restockDrinks(int amount){

    if(amount>0){
        drinkStock = drinkStock+amount;

        std::cout<< name <<" bar restocked by "<< amount << " drinks" << std::endl;
    }
    else{
        std::cout << "Invalid restock amount" << std::endl;
    }
}
