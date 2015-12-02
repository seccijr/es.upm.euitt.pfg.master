#ifndef _EVENTHANDLER_H
#define _EVENTHANDLER_H

#include "master_types.h"

class EventHandler {
    public:
        virtual void handle(const Vector &v) =0;
};

#endif
