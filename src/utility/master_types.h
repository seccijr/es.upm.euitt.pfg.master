#ifndef _MASTERTYPES_H
#define _MASTERTYPES_H

#include <Arduino.h>
#include <IPAddress.h>
#include "Address.h"
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
    byte origin;
    byte target;
    byte method;
    Message message;
    bool operator==(const PacketStruct &pckt) {
        bool same_origin = origin == pckt.origin;
        bool same_target = target == pckt.target;
        bool same_method = method == pckt.method;
        bool same_message = message == pckt.message;
        return same_origin && same_target && same_method && same_message;
    };
};
typedef struct PacketStruct Packet;

typedef struct {
    Packet packet;
    byte source[MMT_ENDPOINT_LEN];
    byte destination[MMT_ENDPOINT_LEN];
} Vector;

#endif
