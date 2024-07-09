#include "mbed.h"
#include <cstdio>


InterruptIn bluebtn(PC_13);
volatile int int_trig = 0;
volatile int button_press_count = 0;

void bttnFall() {
    int_trig = 1;
    button_press_count++;
}

int main() {
    bluebtn.fall(&bttnFall);

    while (true) {
        if (int_trig == 1) {
            int_trig = 0;
            printf("Total button presses: %d\r\n", button_press_count);
        }
    }
}
