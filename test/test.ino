#include <Arduino.h>
#include <ArduinoUnit.h>
#include <Master.h>
#include "RegistrarTest.h"

RegistrarTest test = RegistrarTest("Master::RegistrarClass");

void setup() {
    Serial.begin(9600);
    while(!Serial) {
        ;
    }
}

void loop() {
    Test::run();
}
