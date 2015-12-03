#include <Arduino.h>
#include <ArduinoUnit.h>
#include <Master.h>
#include "RegistrarTest.h"
#include "VectorSerializerTest.h"

RegistrarTest reg_test = RegistrarTest("RegistrarClass");
VectorSerializerTest vec_test = VectorSerializerTest("VectorSerializer");

void setup() {
    Serial.begin(9600);
    while(!Serial) {
        ;
    }
}

void loop() {
    Test::run();
}
