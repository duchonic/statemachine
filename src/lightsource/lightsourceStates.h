// LightsourceStates.h
#pragma once

#include "lightsource.h"
#include <exception>
#include <stdexcept>

class Lightsource;

class AbstractState {
    public:
        virtual void start(Lightsource& lightsource) = 0;
        virtual void stop(Lightsource& lightsource) = 0;
        virtual ~AbstractState();
    protected:
        void setState(Lightsource& lightsource, AbstractState* st);
};

class Start : public AbstractState {
    public:
        virtual void start(Lightsource& lightsource);
        virtual void stop(Lightsource& lightsource);
        virtual ~Start();
};

class Stop : public AbstractState {
    public:
        virtual void start(Lightsource& lightsource);
        virtual void stop(Lightsource& lightsource);
        virtual ~Stop();
};

class Error {
    public: 
        virtual void reset(Lightsource& lightsource);
        virtual ~Error();
};

