#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct State {
    bool *array;
    size_t size;
} State;

bool get_number_from_rule(uint8_t rule, uint8_t number);

void compute_next_state(State *current, State *next, uint8_t rule);

void print_state(State *state);

void fill_state(State *state, bool fill);

void fill_starting_state(State *state);

void construct_state(State *state, size_t size);

void destroy_state(State *state);