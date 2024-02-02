#include "cellauto.h"
#include "ruleset.h"
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

bool get_number_from_rule(uint8_t rule, uint8_t number) {
    return (bool)((0x1 << number) & rule);
}

bool new_bool_from_rule(bool first, bool second, bool third, uint8_t rule) {
    uint8_t offset = 0;
    // Compute the offset
    offset |= (third ? 1 : 0) << 0;
    offset |= (second ? 1 : 0) << 1;
    offset |= (first ? 1 : 0) << 2;

    return get_number_from_rule(rule, offset);
}

void compute_next_state(State *current, State *next, uint8_t rule) {
    bool *cur_arr = current->array;
    bool *nex_arr = next->array;
    size_t size = current->size;
    // handle left and right edges
    nex_arr[0] = new_bool_from_rule(cur_arr[size - 1], cur_arr[0], cur_arr[1], rule);
    nex_arr[next->size - 1] = new_bool_from_rule(cur_arr[size - 2], cur_arr[size - 1], cur_arr[0], rule);
    for (int i = 1; i < size - 1; i++) {
        nex_arr[i] = new_bool_from_rule(cur_arr[i - 1], cur_arr[i], cur_arr[i + 1], rule);
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