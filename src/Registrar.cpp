#include "Registrar.h"
#include "utility/Address.h"

void RegistrarClass::registerSubscriber(const AddressClass *source, const EventHandlerClass *handler) {
    bool subscribed = checkSubscribed(source, (EventHandlerClass *)handler);
    if (!subscribed && qsize_ < MAX_REGNODE) {
        QueueItem item = {source, handler};
        q_[qsize_++] = item;
    }
}

void RegistrarClass::publish(const AddressClass *source, const Packet *pckt) {
    for (int i; i < qsize_; i++) {
        const AddressClass *addr = q_[i].addr;
        if (source->endpoint == addr->endpoint && source->resource == addr->resource) {
            EventHandlerClass  *handler = (EventHandlerClass  *)q_[i].handler;
            handler->handle(pckt);
        }
    }
}

bool RegistrarClass::checkSubscribed(const AddressClass *source, EventHandlerClass *handler) {
    for (int i; i < qsize_; i++) {
        const AddressClass *qaddr = q_[i].addr;
        EventHandlerClass  *qhandler = (EventHandlerClass  *)q_[i].handler;
        bool same_address = source->endpoint == qaddr->endpoint && source->resource == qaddr->resource;
        bool same_handler = handler->getId() == qhandler->getId();
        if (same_address && same_handler) {
            return true;
        }
    }
    return false;
}
