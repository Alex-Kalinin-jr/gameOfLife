#include <stdio.h>
#include <stdlib.h>
#include "matr.h"

void initMatr(char **matr, char *arr) {
    int i = 0;
    for (char **pr = matr; pr - matr < HEIGHT; pr++) {
        *pr = arr + i * WIDTH;
        i++;
    }
}

void output(char **matr) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", matr[i][j]);
        }
        fprintf(stdout, "\n");
    }
}