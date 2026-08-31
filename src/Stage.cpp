#include "Stage.h"
#include "Notice.h"
#include <iostream>

Stage::Stage(std::string name, int capacity, bool outdoor, std::string genre, bool nearWater)
    : EventUnit(name, capacity), outdoor(outdoor), performancePaused(false), genre(genre), nearWater(nearWater) {}

void Stage::pausePerformance() {
    this->performancePaused = true;
    std::cout << "[Stage: " << this->name << "] Performance has been PAUSED." << std::endl;
}

void Stage::resumePerformance() {
    this->performancePaused = false;
    std::cout << "[Stage: " << this->name << "] Performance has RESUMED." << std::endl;
}

void Stage::update(const Notice& notice) {
    std::cout << "[Stage: " << this->name << " (" << this->genre << ")] Received Notice: " 
              << notice.getMessage() << std::endl;

    NoticeType type = notice.getType();
    
    switch (type) {
        case NoticeType::OPEN:
            this->open();
            break;
        case NoticeType::CLOSE:
            this->close();
            break;
        case NoticeType::PAUSE:
            this->pausePerformance();
            break;
        case NoticeType::RESUME:
            this->resumePerformance();
            break;
        case NoticeType::EVACUATE:
            this->pausePerformance();
            this->close();
            std::cout << "[Stage: " << this->name << "] EVACUATING AREA IMMEDIATELY!" << std::endl;
            break;
        case NoticeType::WEATHER_ALERT:
            if (this->outdoor) {
                std::cout << "[Stage: " << this->name << "] Outdoor stage safety protocol triggered by severe weather!" << std::endl;
                this->pausePerformance();
            }
            break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "[Stage: " << this->name << "] Capacity warning acknowledged for " << this->genre << " crowd." << std::endl;
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "[Stage: " << this->name << "] Lineup schedule updated." << std::endl;
            break;
        default:
            break;
    }
}

Stage::~Stage(){}