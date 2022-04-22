#include <termios.h>
#include <stdio.h>
#include "inp_settings.h"



void set_noncanonical(struct termios *init, struct termios *ne) {
    tcgetattr(fileno(stdin), init);
    *ne = *init;
    ne -> c_lflag &= ~ECHO;
    ne -> c_lflag &= ~ICANON;
    ne -> c_cc[VMIN] = 1;
    ne -> c_cc[VTIME] = 0;
    tcsetattr(fileno(stdin), TCSANOW, ne);
}

void set_canon(struct termios *init) {
    tcsetattr(fileno(stdin), TCSANOW, init);
}