#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "matr.h"


int input(char **matr, FILE *img);
void drawing(char ***initMatr, char ***finalMatr);
int rules(char ***matr, int i, int j);


int main(void) {
    system("clear");
    initscr();

    char string[] = "write path to file:";
    char path[50];
    int row, col;
    getmaxyx(stdscr, row, col);
    mvprintw(row/2, col/2 - strlen(string)/2, "%s", string);
    move(row/2 + 1, 0);
    getstr(path);

    raw();
    noecho();

    FILE *img;
    if ((img = fopen(path, "r")) == NULL) {
        printf("cannot open the file\n");
        exit(1);
    }

    char **matr = (char **)malloc(HEIGHT * sizeof(char **));
    char *arr = (char *)malloc(HEIGHT * WIDTH * sizeof(char));
    char **cloneMatr = (char **)malloc(HEIGHT * sizeof(char **));
    char *cloneArr = (char *)malloc(HEIGHT * WIDTH * sizeof(char));
    initMatr(matr, arr);
    initMatr(cloneMatr, cloneArr);
    input(matr, img);
    fclose(img);

    int ch;
    do {
        output_curses(matr);
        drawing(&matr, &cloneMatr);
        timeout(100);
        ch = getch();
        clear();
        move(0,0);
    } while (ch != 'q');
    endwin();

    free(matr);
    free(arr);
    return 0;
}


int input(char **matr, FILE *img) {
    int k;
    int res = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fscanf(img, "%d", &k);
            if (k == 1) {
                matr[i][j] = '*';
            } else {
                matr[i][j] = ' ';
            }
        }
    }

    return res;
}


void drawing(char ***initMatr, char ***finalMatr) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rules(initMatr, i, j) == 0) {
                (*finalMatr)[i][j] = '*';
            } else {
                (*finalMatr)[i][j] = ' ';
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            (*initMatr)[i][j] = (*finalMatr)[i][j];
        }
    }
}


int rules(char ***matr, int i, int j) {
    int res;
    int k, p;
    int alive = 0;
    for (int m = i - 1; m < i + 2; m++) {
        for (int n = j - 1; n < j + 2; n++) {
            k = m;
            p = n;
            if (m == -1)
                k = HEIGHT - 1;
            if (m == HEIGHT)
                k = 0;
            if (n == -1)
                p = WIDTH - 1;
            if (n == WIDTH)
                p = 0;
            if (!(k == i && p == j)) {
                if ((*matr)[k][p] == '*') {
                    alive++;
                }
            }
        }
    }

    if ((*matr)[i][j] == '*' && (alive == 2 || alive == 3)) {
        res = 0;
    } else if ((*matr)[i][j] == ' ' && alive == 3) {
        res = 0;
    } else {
        res = 1;
    }
    return res;
}
