#include "cellauto.h"
#include "ruleset.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    uint8_t rule = 0x00;
    uint32_t iterations = 10;
    size_t size = 10;
    double seconds = 0;

    while ((opt = getopt(argc, argv, "r:i:s:w:")) != -1) {
        switch (opt) {
        case 'r':
            rule = (uint8_t)atoi(optarg);
            break;
        case 'i':
            iterations = (uint32_t)atoi(optarg);
            break;
        case 's':
            size = (uint8_t)atoi(optarg);
            if (size < 2) {
                printf("Size must be >= 2\n");
                exit(EXIT_FAILURE);
            }
            break;
        case 'w':
            seconds = atof(optarg);
            break;
        case '?':
            if (optopt == 'r' || optopt == 'i' || optopt == 's') {
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            } else {
                fprintf(stderr, "Unknown option: -%c\n", optopt);
            }
            return 1;
        default:
            fprintf(stderr, "Usage: %s -r <uint8> -i <uint32> -s <uint8>\n", argv[0]);
            return 1;
        }
    }
    /*
    printf("Value of -r: %u\n", rule);
    printf("Value of -i: %u\n", iterations);
    printf("Value of -s: %u\n", size);
    */
    // make arrays
    State state1;
    State state2;

    construct_state(&state1, size);
    construct_state(&state2, size);

    fill_starting_state(&state1);

    // run simulation
    bool one_is_current = true;
    for (int i = 0; i < iterations; i++) {
        if (one_is_current) {
            print_state(&state1);
            compute_next_state(&state1, &state2, rule);
        } else {
            print_state(&state2);
            compute_next_state(&state2, &state1, rule);
        }
        one_is_current = !one_is_current;
        if (seconds != 0) {
            usleep((unsigned int)(seconds * 1000000.0));
        }
    }

    // clean up
    destroy_state(&state1);
    destroy_state(&state2);
    return 0;
}
