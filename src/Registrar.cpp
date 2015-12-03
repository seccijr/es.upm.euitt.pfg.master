#include "Registrar.h"
#include "utility/Address.h"

void RegistrarClass::registerSubscriber(const AddressClass &source, EventHandler *handler) {
    bool subscribed = checkSubscribed(source, handler);
    if (!subscribed && hqsize_ < MMT_MAX_HANDLER_NODES) {
        HandlerQueueItem item = {source, handler};
        hq_[hqsize_++] = item;
    }
}

void RegistrarClass::publish(const Vector &v) {
    if (eqsize_ < MMT_MAX_PACKETS) {
        eq_[eqsize_++] = v;
    }
}

void RegistrarClass::flushQueue() {
    while (--eqsize_ >= 0) {
        Vector qv = eq_[eqsize_];
        AddressClass eqaddr = AddressClass(qv.packet.target, qv.destination);
        EventHandler *hq[MMT_MAX_HANDLER_NODES];
        int nh = getHandlers(eqaddr, hq);
        for (int i = 0; i < nh; i++) {
            EventHandler *handler = hq[i];
            handler->handle(qv);
        }
    }
}

bool RegistrarClass::checkPublished(const Vector &v) {
    AddressClass destination = AddressClass(v.packet.target, v.destination);
    for (int i = 0; i < eqsize_; i++) {
        Vector qv = eq_[i];
        AddressClass qaddr = AddressClass(qv.packet.target, qv.destination);
        Packet qpckt = qv.packet;
        bool same_address = destination == qaddr;
        bool same_pckt = qpckt == v.packet;
        if (same_address && same_pckt) {
            return true;
        }
    }
    return false;
}

bool RegistrarClass::checkSubscribed(const AddressClass &source, EventHandler *handler) {
    for (int i = 0; i < hqsize_; i++) {
        AddressClass qaddr = hq_[i].addr;
        EventHandler *qhandler  = hq_[i].handler;
        bool same_address = (AddressClass)source == qaddr;
        bool same_handler = handler == qhandler;
        if (same_address && same_handler) {
            return true;
        }
    }
    return false;
}

int RegistrarClass::getHandlers(const AddressClass &source, EventHandler **hq) {
    int j = 0;
    for (int i = 0; i < hqsize_; i++) {
        AddressClass qaddr = hq_[i].addr;
        bool match_address = ((AddressClass)source).match(qaddr);
        if (match_address && j < MMT_MAX_HANDLER_NODES) {
            EventHandler *qhandler  = hq_[i].handler;
            hq[j++] = qhandler;
        }
    }
    return j;
}

RegistrarClass Registrar;
