#ifndef _MESSAGE_H
#define _MESSAGE_H

namespace Comm {
    class Message {
        public:
            Message(const unsigned char[] &&value) value_(value);
            Message(const int &value);
            Message(const String &value);
            Message(const float &value);
            uint8_t type_;
            unsigned char[] value_;
            int ToInt();
            String ToString();
            float ToFloat();
   }
}

#define MMT_INT (0x00 << 1)  // INTEGER
#define MMT_STR (0x00 << 2)  // STRING
#define MMT_FLO (0x00 << 3)  // FLOAT

#endif
