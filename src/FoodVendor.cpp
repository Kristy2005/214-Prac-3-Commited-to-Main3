#include "FoodVendor.h"
#include <iostream>

bool FoodVendor::serveFood(){

    if (serving == false){
        std::cout << "Food vendor is not currently serving" << std::endl;
        return false;
    }

	//bsuy cooking or serving another customer
    if (busy == true){
        std::cout << "Customer waits in line" << std::endl;
        return false;
    }

    if(stockLevel>0){
        busy = true;
        std::cout << "Customer receives food" << std::endl;
        --stockLevel;
        busy = false;
        return true;
    }

    std::cout << "Food vendor is out of stock" << std::endl;
    return false;
}

void FoodVendor::restock(int amount){

    if(amount > 0){

        stockLevel = stockLevel + amount;

        std::cout <<"Food vendor restocked by "<< amount << " items" << std::endl;
    }
    else{
        std::cout << "Invalid restock amount" << std::endl;
    }
}

void FoodVendor::update(const Notice& notice){

    if (notice.getType() == NoticeType::OPEN){

        serving = true;
        isOpen = true;

        std::cout << getName() << " is open and serving food" << std::endl;
    }

    if (notice.getType() == NoticeType::CLOSE){

        serving = false;
        isOpen = false;

        std::cout << getName() << " has closed"<< std::endl;
    }

    if (notice.getType() == NoticeType::PAUSE){

        serving = false;

        std::cout << getName() << " temporarily stops serving food"<< std::endl;
    }

    if (notice.getType() == NoticeType::RESUME)
    {
        serving = true;

        std::cout << getName() << " resumes serving food" << std::endl;
    }

    if (notice.getType() == NoticeType::EVACUATE)
    {
        serving = false;

        std::cout << getName()<< " stops serving due to evacuation"<< std::endl;
    }
}

//constructor
FoodVendor::FoodVendor(std::string name, int stockLevel)
    : EventUnit(name, 0),serving(true),busy(false),stockLevel(stockLevel){}