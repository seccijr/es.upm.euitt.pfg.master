#ifndef _FAKEREGIDSTRARHANDLER_H
#define _FAKEREGIDSTRARHANDLER_H

#include <EventHandler.h>

class FakeRegistrarHandlerClass: public EventHandlerClass {
    public:
        FakeRegistrarHandlerClass(): called_(false) {};
        void handle(const Packet *pckt) {
            called_ = true;
        };
        unsigned long getId() {
            return 1L;
        };
        bool called_;
};

#endif
