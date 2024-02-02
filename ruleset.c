#include "ruleset.h"
#include <stdlib.h>

void convert_number_to_rules(uint8_t rule, bool *array) {
    for (int i = 0; i < 8; i++) {
        array[i] = ((0x01 << i) & rule) != 0;
    }
}