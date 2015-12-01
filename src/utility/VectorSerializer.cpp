#include "VectorSerializer.h"
#include "PacketSerializer.h"
#include "master_types.h"

void VectorSerializer::deserialize(Vector *v, const byte *buffer) {
    memcpy(v->source, buffer, MMT_ENDPOINT_LEN);
    memcpy(v->destination, buffer + MMT_ENDPOINT_LEN, MMT_ENDPOINT_LEN);
    Packet pckt;
    PacketSerializer::deserialize(&pckt, buffer + (2 * MMT_ENDPOINT_LEN));
    v->packet = pckt;
}

void VectorSerializer::serialize(const AddressClass &source, const AddressClass &destination, const Packet &packet, Print &p) {
    for (int i = 0; i < 4; i++) {
        p.write(source.endpoint[i]);
    }
    for (int i = 0; i < 4; i++) {
        p.write(destination.endpoint[i]);
    }
    PacketSerializer::serialize(packet, p);
}

void VectorSerializer::humanReadable(const Vector &v, Print &p) {
    char ip_str[17] = {0};
    sprintf(ip_str, "%u.%u.%u.%u", v.source[0], v.source[1], v.source[2], v.source[3]);
    p.print("Source endpoint: ");
    p.println(ip_str);
    sprintf(ip_str, "%u.%u.%u.%u", v.destination[0], v.destination[1], v.destination[2], v.destination[3]);
    p.print("Destination endpoint: ");
    p.println(ip_str);
    p.print("Origin resource: ");
    p.println(v.packet.origin);
    p.print("Target resource: ");
    p.println(v.packet.target);
    p.print("Method: ");
    p.println(v.packet.method);
    char value_str[13] = {0};
    sprintf(value_str, "%02x %02x %02x %02x", v.packet.message.value.b[0], v.packet.message.value.b[1], v.packet.message.value.b[2], v.packet.message.value.b[3]);
    p.print("Value: ");
    p.println(value_str);
}
