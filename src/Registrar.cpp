#include <Registrar.h>

using namespace Master;


void RegistrarClass::RegisterSubscriber(const Address *source, const EventHandlerClass *handler) {
    if (qsize_ < MAX_REGNODE) {
        Queue item = {source, handler};
        q_[qsize_++] = item;
    }
}

void RegistrarClass::Publish(const Address *source, const Packet *pckt) {
    for (int i; i < qsize_; i++) {
        const Address *addr = q_[i].addr;
        if (source->dest == addr->dest && source->res == addr->res) {
            EventHandlerClass  *handler = (EventHandlerClass  *)q_[i].handler;
            handler->Handle(pckt);
        }
    }
}
