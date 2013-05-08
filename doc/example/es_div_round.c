#include "hah/hal.h"

int main(
    void) {

    uint32_t i = 28;
    uint32_t y = 5;

    printf(
        "Deljenje %d / %d = %d",
        i,
        y,
        i/y);

    printf(
        "Zaokruzeno: %d",
        ES_DIV_ROUND(
            i,
            y));
}
