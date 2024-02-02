#include "cellauto.h"
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

void compute_next_state(bool *current, bool *next, uint8_t size) {
}

void print_state(bool *state, uint8_t size) {
    setlocale(LC_CTYPE, "");
    for (int i = 0; i < size; i++) {
        wprintf(L"%lc", state[i] == true ? (wchar_t)0x2588 : ' '); // 0x2588 is a filled in character
    }
    putchar('\n');
}

void fill_state(bool *state, uint8_t size, bool fill) {
    for (int i = 0; i < size; i++) {
        state[i] = fill;
    }
}

void fill_starting_state(bool *state, uint8_t size) {
    fill_state(state, size, false);
    state[size / 2] = true;
}