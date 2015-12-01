#ifndef _PACKETSERIALIZER_H
#define _PACKETSERIALIZER_H

#include <IPAddress.h>
#include "utility/master_types.h"

class PacketSerializer {
    public:
        static void deserialize(Packet *pckt, const byte *buffer);
        static bool checkPacket(const byte *buffer);
        static void serialize(const Packet &pckt, Print &p);
};

#endif
