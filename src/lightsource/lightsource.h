#pragma once

#include "lightsourceStates.h"
#include <string>
#include <ctime>

class AbstractState;
class Lightsource {
    friend class AbstractState;
    public:
        Lightsource(std::string name);
        void start();
        void stop();
        ~Lightsource();
        std::string getName(){
            return mName;
        };
        std::time_t getStartTime(){
            return startTime;
        };
        std::time_t getRunningTime(){
            return std::time(nullptr)-startTime;
        };
    private:
        AbstractState* mState;
        std::string mName;
        std::time_t startTime;
};

