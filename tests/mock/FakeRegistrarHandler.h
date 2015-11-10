#ifndef _FAKEREGIDSTRARHANDLER_H
#define _FAKEREGIDSTRARHANDLER_H

#include "src/EventHandler.h"

namespace Master {
    class FakeRegistrarHandlerClass: public EventHandlerClass {
        public:
            FakeRegistrarHandlerClass(): called_(false) {};
            virtual void Handle(const Packet *pckt) {
                called_ = true;
            }
            bool called_;
    };
}

#endif
