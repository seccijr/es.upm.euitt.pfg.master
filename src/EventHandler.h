#ifndef _EVENTHANDLER_H
#define _EVENTHANDLER_H

#include "Arduino.h"
#include "src/Message.h"

namespace Master {
    class EventHandlerClass {
        public:
            virtual void Handle(const MessageClass &msg);
   };
}

#endif
