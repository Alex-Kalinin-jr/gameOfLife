#ifndef _GAMEOFLIFE_MATR_H_
#define _GAMEOFLIFE_MATR_H_

#define WIDTH 60
#define HEIGHT 20

void initMatr(char **matr, char *arr);
void output(char **matr);
void output_curses(char **matr);

#endif //_GAMEOFLIFE_MATR_H_