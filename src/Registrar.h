#ifndef _REGISTRAR_H
#define _REGISTRAR_H

#include <Arduino.h>
#include "utility/master_types.h"
#include "utility/Address.h"
#include <EventHandler.h>

#define MAX_REGNODE 32

typedef struct {
    const AddressClass *addr;
    const EventHandlerClass *handler;
} QueueItem;

class RegistrarClass {
    public:
        RegistrarClass(): qsize_(0) {};
        void releaseSubscriber(const AddressClass *source, const EventHandlerClass *handler);
        void registerSubscriber(const AddressClass *source, const EventHandlerClass *handler);
        void publish(const AddressClass *source, const Packet *pckt);
    private:
        bool checkSubscribed(const AddressClass *source, EventHandlerClass *handler);
        QueueItem q_[MAX_REGNODE];
        int qsize_;
};

#endif
