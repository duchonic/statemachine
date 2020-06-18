#include <iostream>
#include <stdexcept>
#include "lightsource/lightsource.h"
#include "lightsource/lightsourceStates.h"
#include <ctime>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;


void lamp1()
{
    Lightsource m1("maggina 1");
    
    m1.start();    
    std::time_t result = m1.getStartTime();
    std::cout << "started at: " << std::asctime(std::localtime(&result));
    
    for (int i = 0; i < 5; ++i) {    
        std::this_thread::sleep_for(1s);
        std::cout << "runing since " << m1.getRunningTime() << " sec" << std::endl;
    }
}
 
void lamp2()
{
    Lightsource m2("maggina 2");

    for (int i = 0; i < 5; ++i) {
        m2.start();
        m2.stop();
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}



int main() {
    std::thread l1(lamp1); // pass by value
    std::thread l2(lamp2); // pass by value
    
    l1.join();
    l2.join();
    
    return 0;
}
