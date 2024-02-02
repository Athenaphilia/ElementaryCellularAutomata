#include "ruleset.h"
#include <stdio.h>

int main(int argc, char **argv) {
    bool arr[8];
    convert_number_to_rules(0b01101110, arr);
    for (int i = 0; i < 8; i++) {
        printf("%i\n", arr[i]);
    }
    return 0;
}