#include "cellauto.h"
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

void compute_next_state(bool *current, bool *next, uint8_t size) {
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
    state->size = size;
}