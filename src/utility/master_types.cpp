#include "master_types.h"

Address Localhost = {
    MMT_DEF_RESOURCE,
    {127, 0, 0, 1}
};

Address Broadcast = {
    MMT_BROADCAST_RESOURCE,
    {255, 255, 255, 255}
};

Address Wildcard = {
    MMT_ADD_WILDCARD,
    {MMT_ADD_WILDCARD, MMT_ADD_WILDCARD, MMT_ADD_WILDCARD, MMT_ADD_WILDCARD}
};
