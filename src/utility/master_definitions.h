#ifndef _MASTERDEFINITIONS_H
#define _MASTERDEFINITIONS_H

#define MMT_LONG (0x01 << 1)  // LONG
#define MMT_STR (0x01 << 2)  // STRING
#define MMT_FLO (0x01 << 3)  // FLOAT

#define MMT_ENDPOINT_LEN 4  // MAX ENDPOINT ADDR

#define MMT_GET (0x01 << 1)  // GET METHOD
#define MMT_POST (0x01 << 2)  // POST METHOD
#define MMT_PUT (0x01 << 3)  // PUT METHOD

#define MMT_PACKET_LEN 8
#define MMT_VECTOR_LEN 16
#define MMT_DEF_RESOURCE 2000

const byte MMT_DEF_ENDPOINT[4] = {127, 0, 0, 1};

#endif
