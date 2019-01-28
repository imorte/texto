#include <unistd.h>
#include <stdio.h>
#include <termios.h>

#define TEXTO_KEY_QUIT 'q'

void enableRawMode() {
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != TEXTO_KEY_QUIT);

    return 0;
}
