#include "PacketSerializer.h"

bool PacketSerializer::checkPacket(const byte *buffer) {
    byte methods[3] = {MMT_GET, MMT_POST, MMT_PUT};
    byte method = buffer[0];
    for (int i = 0; i < 3; i++) {
        if (method == methods[i]) {
            return true;
        }
    }
    return false;
}

void PacketSerializer::deserialize(Packet *pckt, Stream *s) {
    int i = 0;
    byte buffer[MMT_PACKET_LEN] = {0};
    while (s->available() > 0) {
        buffer[i++] = s->read();
    }
    PacketSerializer::deserialize(pckt, (const byte *)buffer);
}

void PacketSerializer::deserialize(Packet *pckt, const byte *buffer) {
    pckt->method = buffer[0];
    pckt->message.type = buffer[1];
    memcpy(pckt->message.value.b, buffer + 2, 4);
}

void PacketSerializer::serialize(const Packet &pckt, Print *p) {
    p->write(pckt.method);
    p->write(pckt.message.type);
    for (int i = 0; i < 4; i++) {
        p->write(pckt.message.value.b[i]);
    }
}
