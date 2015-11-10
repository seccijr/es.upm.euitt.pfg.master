#ifndef _REGISTRAR_H
#define _REGISTRAR_H

#include "Arduino.h"
#include "src/Message.h"
#include "src/EventHandler.h"

namespace Master {
    class RegistrarClass {
        public:
            RegistrarClass();
            void RegisterSubscriber(const String &url, const EventHandlerClass &handler);
            void Publish(const String &url, const MessageClass &msg);
        private:
    };
}

#endif
