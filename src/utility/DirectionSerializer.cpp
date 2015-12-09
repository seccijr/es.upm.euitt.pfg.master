#include "DirectionSerializer.h"

void DirectionSerializer::deserialize(Direction *drct, const byte *buffer) {
    const byte *source_ptr = buffer;
    const byte origin = buffer[2 * MMT_ENDPOINT_LEN];
    const byte *destination_ptr = buffer + MMT_ENDPOINT_LEN;
    const byte target = destination_ptr[MMT_ENDPOINT_LEN + 1];
    drct->source.resource = origin;
    memcpy(drct->source.endpoint, source_ptr, MMT_ENDPOINT_LEN);
    drct->destination.resource = target;
    memcpy(drct->destination.endpoint, destination_ptr, MMT_ENDPOINT_LEN);
}

void DirectionSerializer::serialize(const Direction &drct, Print *p) {
    p->write(drct.source.endpoint, MMT_ENDPOINT_LEN);
    p->write(drct.destination.endpoint, MMT_ENDPOINT_LEN);
    p->write(drct.source.resource);
    p->write(drct.destination.resource);
}
