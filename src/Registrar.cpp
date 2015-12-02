#include "Registrar.h"
#include "utility/Address.h"

void RegistrarClass::registerSubscriber(const AddressClass &source, Handler handler) {
    bool subscribed = checkSubscribed(source, handler);
    if (!subscribed && hqsize_ < MMT_MAX_HANDLER_NODES) {
        HandlerQueueItem item = {source, handler};
        hq_[hqsize_++] = item;
    }
}

void RegistrarClass::publish(const AddressClass &destination, const Packet &pckt) {
    if (hqsize_ < MMT_MAX_HANDLER_NODES) {
        EventQueueItem item = {destination, pckt};
        eq_[eqsize_++] = item;
    }
}

void RegistrarClass::publish(const Vector &v) {
    AddressClass addr = AddressClass(v.destination);
    addr.resource = v.packet.target;
    publish((const AddressClass)addr, (const Packet)v.packet);
}

void RegistrarClass::flushQueue() {
    while (--eqsize_ >= 0) {
        AddressClass eqaddr = eq_[eqsize_].addr;
        Packet eqpckt = eq_[eqsize_].pckt;
        Handler hq[MMT_MAX_HANDLER_NODES] = {0};
        int nh = getHandlers(eqaddr, hq);
        for (int i = 0; i < nh; i++) {
            Handler handler = hq[i];
            handler(eqpckt);
        }
    }
}

bool RegistrarClass::checkSubscribed(const AddressClass &source, Handler handler) {
    for (int i = 0; i < hqsize_; i++) {
        AddressClass qaddr = hq_[i].addr;
        Handler qhandler  = hq_[i].handler;
        bool same_address = (AddressClass)source == qaddr;
        bool same_handler = handler == qhandler;
        if (same_address && same_handler) {
            return true;
        }
    }
    return false;
}

bool RegistrarClass::checkPublished(const AddressClass &destination, Packet pckt) {
    for (int i = 0; i < eqsize_; i++) {
        AddressClass qaddr = eq_[i].addr;
        Packet qpckt = eq_[i].pckt;
        bool same_address = (AddressClass)destination == qaddr;
        bool same_pckt = qpckt == pckt;
        if (same_address && same_pckt) {
            return true;
        }
    }
    return false;
}

int RegistrarClass::getHandlers(const AddressClass &source, Handler *hq) {
    int j = 0;
    for (int i = 0; i < hqsize_; i++) {
        AddressClass qaddr = hq_[i].addr;
        bool same_address = (AddressClass)source == qaddr;
        if (same_address && j < MMT_MAX_HANDLER_NODES) {
            Handler qhandler  = hq_[i].handler;
            hq[j++] = qhandler;
        }
    }
    return j;
}
