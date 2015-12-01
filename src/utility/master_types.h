#ifndef _MASTERTYPES_H
#define _MASTERTYPES_H

#include <Arduino.h>
#include <IPAddress.h>
#include "master_definitions.h"

typedef struct {
    byte type;
    union {
        int32_t l;
        float f;
        byte b[4];
    } value;
} Message;

typedef struct {
    byte origin;
    byte target;
    byte method;
    Message message;
} Packet;

typedef struct {
    Packet packet;
    byte source[MMT_ENDPOINT_LEN];
    byte destination[MMT_ENDPOINT_LEN];
} Vector;

#endif
