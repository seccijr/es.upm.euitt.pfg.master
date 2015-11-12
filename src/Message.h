#ifndef _MESSAGE_H
#define _MESSAGE_H

#include <Arduino.h>

#define MMT_LONG (0x00 << 1)  // LONG
#define MMT_STR (0x00 << 2)  // STRING
#define MMT_FLO (0x00 << 3)  // FLOAT

#define MMT_RESID 4  // MAX RESOURCE ID
#define MMT_ENDPOINT 4  // MAX ENDPOINT ADDR

#define MMT_GET (0x00 << 1)  // GET METHOD
#define MMT_POST (0x00 << 2)  // POST METHOD
#define MMT_PUT (0x00 << 3)  // PUT METHOD

namespace Master {
    typedef byte Resource[MMT_RESID];
    typedef byte Endpoint[MMT_ENDPOINT];

    typedef struct {
        Resource res;
        Endpoint dest;
    } Address;

    typedef struct {
        unsigned char type;
        union {
            long l;
            float f;
            unsigned char b[4];
        } value;
    } Message;

    typedef struct {
        unsigned char method;
        Message *msg;
    } Packet;
}


#endif
