#ifndef _REGISTRAR_H
#define _REGISTRAR_H

#include <Arduino.h>
#include "utility/master_types.h"
#include "utility/master_definitions.h"
#include "utility/EventHandler.h"

typedef struct {
    Direction direction;
    EventHandler *handler;
} HandlerQueueItem;

class RegistrarClass {
    public:
        RegistrarClass(): hqsize_(0), eqsize_(0) {};
        void registerSubscriber(const Direction &drct, EventHandler *handler);
        void registerSubscriber(const Address &addr, EventHandler *handler);
        void publish(const Vector &v);
        void publish(const Address &addr, const Packet &pckt);
        void flushQueue();
        bool checkPublished(const Vector &v);
        bool checkSubscribed(const Direction &drct, EventHandler *handler);
        bool checkSubscribed(const Address &addr, EventHandler *handler);
    private:
        int getHandlers(const Direction &drct, EventHandler **hq);
        HandlerQueueItem hq_[MMT_MAX_HANDLER_NODES];
        Vector eq_[MMT_MAX_PACKETS];
        int hqsize_;
        int eqsize_;
};

extern RegistrarClass Registrar;

#endif
