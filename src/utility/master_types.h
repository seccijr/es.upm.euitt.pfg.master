#ifndef _MASTERTYPES_H
#define _MASTERTYPES_H

#include <Arduino.h>
#include "master_definitions.h"

struct MessageStruct {
    byte type;
    union {
        int32_t l;
        float f;
        byte b[4];
    } value;
    bool operator==(const MessageStruct &msg) {
        bool same_type = type == msg.type;
        bool same_value = value.l == msg.value.l;
        return same_type && same_value;
    }
};
typedef struct MessageStruct Message;

struct PacketStruct {
    byte method;
    Message message;
    bool operator==(const PacketStruct &pckt) {
        bool same_method = method == pckt.method;
        bool same_message = message == pckt.message;
        return same_method && same_message;
    };
};
typedef struct PacketStruct Packet;

struct AddressStruct {
    byte resource;
    byte endpoint[MMT_ENDPOINT_LEN];
    bool match(const AddressStruct &addr) {
        bool match_resource = matchResource(addr.resource);
        bool match_endpoint = matchEndpoint(addr.endpoint);
        return match_resource && match_endpoint;
    };
    bool matchResource(const byte &res) {
        bool match_resource = false;
        match_resource |= resource == res;
        match_resource |= resource == MMT_ADD_WILDCARD;
        match_resource |= res == MMT_ADD_WILDCARD;
        return match_resource;
    };
    bool matchEndpoint(const byte *endp) {
        bool match_endpoint = true;
        for (int i = 0; i < MMT_ENDPOINT_LEN; i++) {
            bool match_octect = false;
            match_octect |= endpoint[i] == endp[i];
            match_octect |= endpoint[i] == MMT_ADD_WILDCARD;
            match_octect |= endp[i] == MMT_ADD_WILDCARD;
            match_endpoint &= match_octect;
        }
        return match_endpoint;
    };
    bool operator==(const AddressStruct &addr) {
        bool same_resource = resource == addr.resource;
        bool same_endpoint = true;
        for (int i = 0; i < MMT_ENDPOINT_LEN; i++) {
            same_endpoint &= endpoint[i] == addr.endpoint[i];
        }
        return same_resource && same_endpoint;
    };
};

typedef struct AddressStruct Address;

extern Address Localhost;
extern Address Broadcast;
extern Address Netcast;
extern Address Wildcard;

struct DirectionStruct {
    Address source;
    Address destination;
    bool  match(const DirectionStruct &drct) {
        bool match_source = source.match(drct.source);
        bool match_destination = destination.match(drct.destination);
        return match_source && match_destination;
    };
    bool operator==(const DirectionStruct &drct) {
        bool same_source = source == drct.source;
        bool same_destination = destination == drct.destination;
        return same_source && same_destination;
    };
};
typedef struct DirectionStruct Direction;

struct VectorStruct {
    Packet packet;
    Direction direction;
    bool operator==(const VectorStruct &v) {
        bool same_packet = packet == v.packet;
        bool same_direction = direction == v.direction;
        return same_packet && same_direction;
    };
};
typedef struct VectorStruct Vector;

#endif
