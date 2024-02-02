#include <stdbool.h>
#include <stdint.h>

typedef struct State {
    bool *array;
    size_t size;
} State;

void compute_next_state(bool *current, bool *next, uint8_t size);

void print_state(bool *state, uint8_t size);

void fill_state(bool *state, uint8_t size, bool fill);

void fill_starting_state(bool *state, uint8_t size);