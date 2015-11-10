#ifndef _MESSAGE_H
#define _MESSAGE_H

#include "Arduino.h"

namespace Master {
    class MessageClass {
        public:
            MessageClass(const unsigned char value[]);
            MessageClass(const int &value);
            MessageClass(const String &value);
            MessageClass(const float &value);
            uint8_t type_;
            unsigned char value_[];
            int ToInt();
            String ToString();
            float ToFloat();
   };
}

#define MMT_INT (0x00 << 1)  // INTEGER
#define MMT_STR (0x00 << 2)  // STRING
#define MMT_FLO (0x00 << 3)  // FLOAT

#endif
