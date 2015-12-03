#ifndef _REGISTRAR_H
#define _REGISTRAR_H

#include <Arduino.h>
#include "utility/master_types.h"
#include "utility/master_definitions.h"
#include "utility/Address.h"
#include "utility/EventHandler.h"

typedef struct {
    AddressClass addr;
    EventHandler *handler;
} HandlerQueueItem;

class RegistrarClass {
    public:
        RegistrarClass(): hqsize_(0), eqsize_(0) {};
        void registerSubscriber(const AddressClass &source, EventHandler *handler);
        void publish(const Vector &v);
        void publish(const AddressClass &addr, const Packet &pckt);
        void flushQueue();
        bool checkPublished(const Vector &v);
        bool checkSubscribed(const AddressClass &source, EventHandler *handler);
    private:
        int getHandlers(const AddressClass &source, EventHandler **hq);
        HandlerQueueItem hq_[MMT_MAX_HANDLER_NODES];
        Vector eq_[MMT_MAX_PACKETS];
        int hqsize_;
        int eqsize_;
};

extern RegistrarClass Registrar;

#endif
