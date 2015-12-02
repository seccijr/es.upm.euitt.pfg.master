#ifndef _FAKEHANDLER_H
#define _FAKEHANDLER_H

#include "utility/EventHandler.h"
#include "utility/master_types.h"

class FakeHandler: public EventHandler {
    public:
        void handle(const Vector &v) {
            called = true;
        };
        bool called = false;
};

#endif
