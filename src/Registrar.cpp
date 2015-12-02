#include "Registrar.h"
#include "utility/Address.h"

void RegistrarClass::registerSubscriber(const AddressClass &source, void (*handler)(const Packet &)) {
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

bool RegistrarClass::checkSubscribed(const AddressClass &source, void (*handler)(const Packet &)) {
    for (int i; i < hqsize_; i++) {
        AddressClass qaddr = hq_[i].addr;
        void (*qhandler)(const Packet &)  = hq_[i].handler;
        bool same_address = (AddressClass)source == qaddr;
        bool same_handler = handler == qhandler;
        if (same_address && same_handler) {
            return true;
        }
    }
    return false;
}

bool RegistrarClass::checkPublished(const AddressClass &destination, Packet pckt) {
    for (int i; i < eqsize_; i++) {
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
