#include "cellauto.h"
#include "ruleset.h"
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

bool new_bool_from_rule(bool first, bool second, bool third, uint8_t rule) {
    uint8_t offset = 0;
    // Compute the offset
    offset |= (third ? 1 : 0) << 0;
    offset |= (second ? 1 : 0) << 1;
    offset |= (first ? 1 : 0) << 2;

    return get_number_from_rule(rule, offset);
}

void compute_next_state(State *current, State *next, uint8_t rule) {
    for (int i = 1; i < current->size - 1; i++) {
    }
}

void print_state(State *state) {
    setlocale(LC_CTYPE, "");
    for (int i = 0; i < state->size; i++) {
        wprintf(L"%lc", state->array[i] == true ? (wchar_t)0x2588 : ' '); // 0x2588 is a filled in character
    }
    putchar('\n');
}

void fill_state(State *state, bool fill) {
    for (int i = 0; i < state->size; i++) {
        state->array[i] = fill;
    }
}

void fill_starting_state(State *state) {
    fill_state(state, false);
    state->array[state->size / 2] = true;
}

void construct_state(State *state, size_t size) {
    state->array = (bool *)malloc(sizeof(bool) * size);
    if (state->array == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    state->size = size;
}

void destroy_state(State *state) {
    free(state->array);
    state->array = NULL;
    state->size = 0;
}