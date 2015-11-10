#ifndef _REGISTRAR_H
#define _REGISTRAR_H

#include "Arduino.h"
#include "src/Message.h"
#include "src/EventHandler.h"

#define MAX_REGNODE 32

namespace Master {
    typedef struct {
         Address *addr;
         EventHandlerClass *handler;
    } Queue;

    class RegistrarClass {
        public:
            RegistrarClass() {};
            void RegisterSubscriber(const Address *source, const EventHandlerClass &handler);
            void Publish(const Address *source, const Packet *pckt);
        private:

    };
}

#endif
