#ifndef _MASTERDEFINITIONS_H
#define _MASTERDEFINITIONS_H

#define MMT_LONG (0x01 << 1)  // LONG
#define MMT_STR (0x01 << 2)  // STRING
#define MMT_FLO (0x01 << 3)  // FLOAT

#define MMT_GET (0x01 << 1)  // GET METHOD
#define MMT_POST (0x01 << 2)  // POST METHOD
#define MMT_PUT (0x01 << 3)  // PUT METHOD

#define MMT_ENDPOINT_LEN 4
#define MMT_PACKET_LEN 8
#define MMT_VECTOR_LEN 16
#define MMT_DEF_RESOURCE 200
#define MMT_BROADCAST_RESOURCE 255
#define MMT_MAX_HANDLER_NODES 4
#define MMT_MAX_PACKETS 16
#define MMT_ADD_WILDCARD '*'

const byte MMT_DEF_ENDPOINT[4] = {127, 0, 0, 1};
const byte MMT_BROADCAST_ENDPOINT[4] = {255, 255, 255, 255};

#endif
