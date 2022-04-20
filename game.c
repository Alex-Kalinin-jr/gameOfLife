#include <stdio.h>
#include <stdlib.h>


#define WIDTH 60
#define HEIGHT 20


void initMatr(char **matr, char *arr);
void output(char **matr);
int input(char **matr, FILE *img);
void drawing(char ***initMatr, char ***finalMatr);
int rules(char **matr, int i, int j);

int main(void) {
    system("clear");
    printf("write path to file:\n");
    char path[50];
    scanf("%s", path);
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

    for (int i = 0; i < 100; i++) {
        drawing(&matr, &cloneMatr);
        output(matr);
        system("sleep 0.5");
    }


    fclose(img);
    free(matr);
    free(arr);
    return 0;
}

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
            if (rules(*initMatr, i, j) == 0) {
                (*finalMatr)[i][j] = '*';
            } else {
                (*finalMatr)[i][j] = ' ';
            }
        }
    }
    *initMatr =  *finalMatr;
}

int rules(char **matr, int i, int j) {
    int res, k, p;
    int alive = 0;
    for (int m = i - 1; m - i < 2; m++) {
        for (int n = j - 1; n - j < 2; n++) {
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
            if (!(m == i && n == j)) {
                if (matr[k][p] == '*')
                    alive++;
            }
        }
    }

    if (matr[i][j] == '*' && (alive == 2 || alive == 3)) {
        res = 0;
    } else if (matr[i][j] == ' ' && alive == 3) {
        res = 0;
    } else {
        res = 1;
    }

    return res;
}