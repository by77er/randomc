#include <stddef.h>
#include "game.h"

int main(void) {
    Board b = {"123456789"}; // empty
    unsigned int done = 0; // 0 => continue, 1 => stop
    unsigned int counter = 0;
    while (!done) {
        print_board(&b);
        if (counter % 2 == 0) { // x
            int choice = prompt('X');
            if (get_slot(&b, choice) != 'O') {
                set_slot(&b, choice, 'X');
            } else {
                counter -= 1; // redo turn
                _log("slot already taken", 2);
            }
        } else { // o
            int choice = prompt('O');
            if (get_slot(&b, choice) != 'X') {
                set_slot(&b, choice, 'O');
            } else {
                counter -= 1; // redo turn
                _log("slot already taken", 2);
            }
        }
        char winner = check_winner(&b);
        if (winner != '\00' && winner != ' ') { // somebody won
            print_board(&b);
            print_winner(winner);
            done = 1; // set flag
        }
        counter++;
        if (counter > 8) {
            print_board(&b);
            done = 1;
        }
    }
    // _log("reached exit", 1);
}