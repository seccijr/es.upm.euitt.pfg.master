#ifndef _REGISTRAR_H
#define _REGISTRAR_H

#include <Arduino.h>
#include <Message.h>
#include <EventHandler.h>

#define MAX_REGNODE 32

namespace Master {
    typedef struct {
         const Address *addr;
         const EventHandlerClass *handler;
    } Queue;

    class RegistrarClass {
        public:
            RegistrarClass(): qsize_(0) {};
            void RegisterSubscriber(const Address *source, const EventHandlerClass *handler);
            void Publish(const Address *source, const Packet *pckt);
        private:
            Queue q_[MAX_REGNODE];
            int qsize_;
    };
}

#endif
