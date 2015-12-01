#include "utility/Address.h"
#include "utility/master_definitions.h"
#include <IPAddress.h>

AddressClass::AddressClass(const byte &res, const byte *endp) {
    resource = res;
    for (int i = 0; i < MMT_ENDPOINT_LEN; i++) {
        endpoint[i] = endp[i];
    }
}

AddressClass::AddressClass(const byte &first, const byte &second, const byte &third, const byte &fourth) {
    endpoint[0] = first;
    endpoint[1] = second;
    endpoint[2] = third;
    endpoint[3] = fourth;
}

AddressClass Localhost = AddressClass((const byte)2000, (const byte[4]){127, 0, 0, 1});
