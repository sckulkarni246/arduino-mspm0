#include "Arduino.h"

extern void setup();
extern void loop();

int main() {
    // Bare-bones implementation as of now!
    setup();

    while(1) {
        loop();
    }
}