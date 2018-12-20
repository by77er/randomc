#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>

struct termios t_old; // global so handlers can access
int ctr = 0;

void sig_handler(int _) {
    tcsetattr(0, TCSANOW, &t_old); // reset
    printf("\033[%dB\nGoodbye.\n", ctr);
    _exit(0);
}

int main(void) {
    signal(SIGINT, sig_handler);
    struct termios t;
    tcgetattr(0, &t);
    t_old = t; // save
    t.c_lflag &= ~ECHO; // disable echo
    t.c_lflag &= ~ICANON; // disable canonical mode
    tcsetattr(0, TCSANOW, &t); // set
    printf("\033[2J\033[H"); // clear terminal

    for(;;) {
        char c = getchar();
        if (c == 127 || c == 8) { // backspace
            printf("\033[D \033[D");
        } else if (c == 11) { // tab
            printf("    ");
        } else if (c == 10) { // newline
            if(ctr > 0) {
                ctr--;
            }
            printf("\033[B");
        } else if (c == 27) { // arrow
            getchar(); // 91
            int dir = getchar();
            switch(dir) {
                case 65: // up
                    ctr++;
                    printf("\033[A");
                    break;
                case 66: // down
                    if(ctr > 0) {
                        ctr--;
                    }
                    printf("\033[B");
                    break;
                case 67: // left
                    printf("\033[C");
                    break;
                case 68: // right
                    printf("\033[D");
                    break;
            }
        } else if (c == 24) {
            sig_handler(0);
        } else {
            printf("%c", c);
        } 
    }
}