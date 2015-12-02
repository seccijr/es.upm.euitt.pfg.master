#ifndef _REGISTRAR_H
#define _REGISTRAR_H

#include <Arduino.h>
#include "utility/master_types.h"
#include "utility/master_definitions.h"
#include "utility/Address.h"


typedef struct {
    AddressClass addr;
    void (*handler)(const Packet &);
} HandlerQueueItem;

typedef struct {
    AddressClass addr;
    Packet pckt;
} EventQueueItem;

class RegistrarClass {
    public:
        RegistrarClass(): hqsize_(0), eqsize_(0) {};
        void releaseSubscriber(const AddressClass &source, void (*handler)(const Packet &));
        void registerSubscriber(const AddressClass &source, void (*handler)(const Packet &));
        void publish(const AddressClass &destination, const Packet &pckt);
        void publish(const Vector &v);
        void flushQueue();
        bool checkPublished(const AddressClass &destination, Packet pckt);
    private:
        bool checkSubscribed(const AddressClass &destination, void (*handler)(const Packet &));
        HandlerQueueItem hq_[MMT_MAX_HANDLER_NODES];
        EventQueueItem eq_[MMT_MAX_PACKETS];
        int hqsize_;
        int eqsize_;
};

#endif
