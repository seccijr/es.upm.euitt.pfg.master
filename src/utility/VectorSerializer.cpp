#include "VectorSerializer.h"
#include "DirectionSerializer.h"
#include "PacketSerializer.h"
#include "master_types.h"

void VectorSerializer::deserialize(Vector *v, const byte *buffer) {
    const byte *direction_prt = buffer;
    const byte *packet_prt = buffer + (2 * MMT_ENDPOINT_LEN) + 2;
    Direction drct;
    DirectionSerializer::deserialize(&drct, direction_prt);
    Packet pckt;
    PacketSerializer::deserialize(&pckt, packet_prt);
    v->packet = pckt;
    v->direction = drct;
}

void VectorSerializer::deserialize(Vector *v, Stream *s) {
    int i = 0;
    byte buffer[MMT_VECTOR_LEN] = {0};
    while (s->available() > 0) {
        buffer[i++] = s->read();
    }
    VectorSerializer::deserialize(v, (const byte *)buffer);
}

void VectorSerializer::serialize(const Vector &v, Print *p) {
    DirectionSerializer::serialize(v.direction, p);
    PacketSerializer::serialize(v.packet, p);
}

void VectorSerializer::humanReadable(const Vector &v, Print *p) {
    char ip_str[17] = {0};
    sprintf(ip_str, "%u.%u.%u.%u", v.direction.source.endpoint[0], v.direction.source.endpoint[1], v.direction.source.endpoint[2], v.direction.source.endpoint[3]);
    p->print("Source endpoint: ");
    p->println(ip_str);
    sprintf(ip_str, "%u.%u.%u.%u", v.direction.destination.endpoint[0], v.direction.destination.endpoint[1], v.direction.destination.endpoint[2], v.direction.destination.endpoint[3]);
    p->print("Destination endpoint: ");
    p->println(ip_str);
    p->print("Origin resource: ");
    p->println(v.direction.source.resource);
    p->print("Target resource: ");
    p->println(v.direction.destination.resource);
    p->print("Method: ");
    p->println(v.packet.method);
    char value_str[13] = {0};
    sprintf(value_str, "%02x %02x %02x %02x", v.packet.message.value.b[0], v.packet.message.value.b[1], v.packet.message.value.b[2], v.packet.message.value.b[3]);
    p->print("Value: ");
    p->println(value_str);
}
