#include "ruleset.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    uint8_t rule = 0;
    uint32_t iterations = 0;

    while ((opt = getopt(argc, argv, "r:i:")) != -1) {
        switch (opt) {
        case 'r':
            rule = (uint8_t)atoi(optarg);
            break;
        case 'i':
            iterations = (uint32_t)atoi(optarg);
            break;
        case '?':
            if (optopt == 'r' || optopt == 'i') {
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            } else {
                fprintf(stderr, "Unknown option: -%c\n", optopt);
            }
            return 1;
        default:
            fprintf(stderr, "Usage: %s -r <uint8> -i <uint32>\n", argv[0]);
            return 1;
        }
    }

    printf("Value of -r: %u\n", rule);
    printf("Value of -i: %u\n", iterations);

    return 0;
}
