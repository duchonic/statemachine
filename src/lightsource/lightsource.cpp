// lightsource.cpp
#include "lightsource.h"
#include <string>
#include <iostream>

Lightsource::Lightsource(std::string name) : mName(name) {
  mState = new Stop();
}

Lightsource::~Lightsource() {
    delete mState;
}

void Lightsource::start() {
  mState->start(*this);
  startTime = std::time(nullptr);
  std::cout << this->getName() << " start" << std::endl;
}

void Lightsource::stop() {
  mState->stop(*this);
  std::cout << this->getName() << " stop" << std::endl;
}
