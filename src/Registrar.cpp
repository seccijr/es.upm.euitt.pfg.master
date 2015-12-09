#include "Registrar.h"

void RegistrarClass::registerSubscriber(const Direction &drct, EventHandler *handler) {
    bool subscribed = checkSubscribed(drct, handler);
    if (!subscribed && hqsize_ < MMT_MAX_HANDLER_NODES) {
        HandlerQueueItem item = {drct, handler};
        hq_[hqsize_++] = item;
    }
}

void RegistrarClass::registerSubscriber(const Address &addr, EventHandler *handler) {
    const Direction drct = {
        Wildcard,
        addr
    };
    registerSubscriber(drct, handler);
}

void RegistrarClass::publish(const Vector &v) {
    if (eqsize_ < MMT_MAX_PACKETS) {
        eq_[eqsize_++] = v;
    }
}

void RegistrarClass::publish(const Address &addr, const Packet &pckt) {
    Direction drct = {
        Localhost,
        addr
    };
    Vector v = {
        pckt,
        drct
    };
    publish(v);
}

void RegistrarClass::flushQueue() {
    while (eqsize_ > 0) {
        eqsize_--;
        Vector qv = eq_[eqsize_];
        EventHandler *hq[MMT_MAX_HANDLER_NODES];
        int nh = getHandlers(qv.direction, hq);
        for (int i = 0; i < nh; i++) {
            EventHandler *handler = hq[i];
            handler->handle(qv);
        }
    }
}

bool RegistrarClass::checkPublished(const Vector &v) {
    for (int i = 0; i < eqsize_; i++) {
        Vector qv = eq_[i];
        if (qv == v) {
            return true;
        }
    }
    return false;
}

bool RegistrarClass::checkSubscribed(const Direction &drct, EventHandler *handler) {
    for (int i = 0; i < hqsize_; i++) {
        Direction qdrct = hq_[i].direction;
        EventHandler *qhandler  = hq_[i].handler;
        bool same_direction = ((Direction)drct) == qdrct;
        bool same_handler = handler == qhandler;
        if (same_direction && same_handler) {
            return true;
        }
    }
    return false;
}

bool RegistrarClass::checkSubscribed(const Address &addr, EventHandler *handler) {
    const Direction drct = {
        Broadcast,
        addr
    };
    return checkSubscribed(drct, handler);
}

int RegistrarClass::getHandlers(const Direction &drct, EventHandler **hq) {
    int j = 0;
    for (int i = 0; i < hqsize_; i++) {
        Direction qdrct = hq_[i].direction;
        bool match_direction = ((Direction)drct).match(qdrct);
        if (match_direction && j < MMT_MAX_HANDLER_NODES) {
            EventHandler *qhandler  = hq_[i].handler;
            hq[j++] = qhandler;
        }
    }
    return j;
}

RegistrarClass Registrar;
