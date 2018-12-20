#include <stdio.h>
#include <stddef.h>
#include "game.h"

void set_slot(Board* b, int i, char c) {
    if (i >= 9) {
        _log("invalid board set_slot", 2); // too great
    }
    b->slots[i] = c; // sets slot
};
char get_slot(Board* b, int i) {
    if (i >= 9) {
        _log("invalid board get_slot", 2); // too great
    }
    return b->slots[i];
};
void print_board(Board* b) {
    printf("\e[1;1H\e[2J" // leading newline
           " %c | %c | %c \n"
           "-------|---\n"
           " %c | %c | %c \n"
           "---|-------\n"
           " %c | %c | %c \n\n",
           b->slots[0], b->slots[1], b->slots[2],
           b->slots[3], b->slots[4], b->slots[5],
           b->slots[6], b->slots[7], b->slots[8]); // pointers
};

char check_winner(Board* b) {
    // 8 cases or \x00
    if ((b->slots[0] == b->slots[1]) && (b->slots[1] == b->slots[2])) {
        return b->slots[0];
    } else if ((b->slots[3] == b->slots[4]) && (b->slots[4] == b->slots[5])) {
        return b->slots[3];
    } else if ((b->slots[6] == b->slots[7]) && (b->slots[7] == b->slots[8])) {
        return b->slots[6];
    } else if ((b->slots[0] == b->slots[3]) && (b->slots[3] == b->slots[6])) {
        return b->slots[0];
    } else if ((b->slots[1] == b->slots[4]) && (b->slots[4] == b->slots[7])) {
        return b->slots[1];
    } else if ((b->slots[2] == b->slots[5]) && (b->slots[5] == b->slots[8])) {
        return b->slots[2];
    } else if ((b->slots[0] == b->slots[4]) && (b->slots[4] == b->slots[8])) {
        return b->slots[0];
    } else if ((b->slots[6] == b->slots[4]) && (b->slots[4] == b->slots[2])) {
        return b->slots[6];
    } else {
        return '\x00';
    }

};

void print_winner(char c) {
    printf("Winner: %c\n", c);
};

int prompt(char c) {
    for (;;) {
        printf("Player %c, enter 1-9 > ", c);
        char x = (char)getchar();
        switch(x) {
            case '1': return 0;
            case '2': return 1;
            case '3': return 2;
            case '4': return 3;
            case '5': return 4;
            case '6': return 5;
            case '7': return 6;
            case '8': return 7;
            case '9': return 8;
            default: printf("\r"); break; // keep looping
        }
    }
};

void _log(char* s, int level) {
    switch(level) {
        case 1: printf("[*] %s\n", s); break;
        case 2: printf("[x] %s\n", s); break;
        default: printf("[-] %s\n", s); break;
    }
};