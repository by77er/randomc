#pragma once

typedef struct Board {
    char slots[10]; // 0 through 8 + \00
} Board;

void set_slot(Board* b, int i, char c);
char get_slot(Board* b, int i);
void print_board(Board* b);
char check_winner(Board* b);
void print_winner(char c);
int prompt(char c);
void _log(char* s, int level);