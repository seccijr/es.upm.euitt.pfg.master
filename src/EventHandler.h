#ifndef _EVENTHANDLER_H
#define _EVENTHANDLER_H

#include <Arduino.h>
#include "utility/master_types.h"

class EventHandlerClass {
    public:
        virtual void handle(const Packet *pckt);
        virtual unsigned long getId();
};

#endif
