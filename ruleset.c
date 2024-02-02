#include "ruleset.h"
#include <stdlib.h>

void convert_number_to_rules(uint8_t rule, bool *array) {
    for (int i = 0; i < 8; i++) {
        array[i] = ((0x01 << i) & rule) != 0;
    }
}

bool get_number_from_rule(uint8_t rule, uint8_t number) {
    return (0x1 << number) & rule;
}