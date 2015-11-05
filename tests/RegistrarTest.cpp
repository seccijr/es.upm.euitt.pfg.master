#include "RegistrarTest.h"
#include "src/Registrar.h"


void Master::RegistrarTest::TestRegisterSubcriber() {
    bool called = false;
    String msg_str = String("MESSAGE");
    void TestFunc(const Message &msg) {
        called = true;
    }
    Message msg = Message(msg_str);
    String url = String("http://url.com/resource");
    void (*func)(const Message &);
    func = &TestFunc;

    reg_.RegisterSubscriber(url, func);
    reg_.emit(msg);
    assertEqual(called, true);
}

void Master::RegistrarTest::setup() {
    reg_ = Registrar();
}

void Master::RegistrarTest::once() {
    TestRegisterSubcriber();
}
