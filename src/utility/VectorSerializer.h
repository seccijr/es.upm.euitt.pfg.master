#ifndef _VECTORSERIALIZER_H
#define _VECTORSERIALIZER_H

#include "master_types.h"
#include "Address.h"

class VectorSerializer {
    public:
        static void deserialize(Vector *v, const byte *buffer);
        static void serialize(const AddressClass &source, const AddressClass &destination, const Packet &packet, Print &p);
        static void humanReadable(const Vector &v, Print &p);
};

#endif
