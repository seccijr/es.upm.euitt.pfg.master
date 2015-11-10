#ifndef _REGISTRARTEST_H
#define _REGISTRARTEST_H

#include "Arduino.h"
#include "ArduinoUnit.h"
#include "src/Registrar.h"

namespace Master {
    class RegistrarTest: public TestOnce {
        public:
            RegistrarTest(const char *name): TestOnce(name) {
                verbosity = TEST_VERBOSITY_ALL;
            }
            void setup();
            void once();
        private:
            void TestRegisterSubcriber();
            RegistrarClass reg_;
    };
}

#endif
