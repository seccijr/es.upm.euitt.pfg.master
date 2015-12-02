#include "PacketSerializer.h"
#include <IPAddress.h>

bool PacketSerializer::checkPacket(const byte *buffer) {
    byte methods[3] = {MMT_GET, MMT_POST, MMT_PUT};
    byte method = buffer[2];
    for (int i = 0; i < 3; i++) {
        if (method == methods[i]) {
            return true;
        }
    }
    return false;
}

void PacketSerializer::deserialize(Packet *pckt, const byte *buffer) {
    pckt->origin = buffer[0];
    pckt->target = buffer[1];
    pckt->method = buffer[2];
    pckt->message.type = buffer[3];
    for (int i = 0; i < 4; i++) {
        pckt->message.value.b[i] = buffer[i + 4];
    }
}

void PacketSerializer::serialize(const Packet &pckt, Print *p) {
    p->write(pckt.origin);
    p->write(pckt.target);
    p->write(pckt.method);
    p->write(pckt.message.type);
    for (int i = 0; i < 4; i++) {
        p->write(pckt.message.value.b[i]);
    }
}
