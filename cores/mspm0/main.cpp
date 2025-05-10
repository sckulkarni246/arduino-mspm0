#include "Arduino.h"

extern "C" void setup();
extern "C" void loop();

extern "C" int main() {
    // Bare-bones implementation as of now!
    setup();

    while(1) {
        loop();
    }
}