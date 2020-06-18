#include "lightsourceStates.h"
#include <iostream>

AbstractState::~AbstractState() {
}

void AbstractState::setState(Lightsource& lightsource, AbstractState* state) {
    AbstractState* aux = lightsource.mState;
    lightsource.mState = state; 
    delete aux;
}


Start::~Start() {
}

void Start::start(Lightsource& lightsource) {
}

void Start::stop(Lightsource& lightsource) {
    setState(lightsource, new Stop());
}


Stop::~Stop() {
}

void Stop::start(Lightsource& lightsource) {
    setState(lightsource, new Start());
}
void Stop::stop(Lightsource& lightsource) {
}

Error::~Error() {
    
}

