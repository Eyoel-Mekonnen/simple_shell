#include "header.h"
void update_prompt()
{
    printf("($)");
    fflush(stdout);
}

int interactive(info_t *info) {
    if (isatty(STDIN_FILENO) && info->readfd <= 2) {
        update_prompt();
        return 1;
    }
    return 0;
}
