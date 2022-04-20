#include <stdio.h>
#include <stdlib.h>


#define WIDTH 60
#define HEIGHT 20


void initMatr(char **matr, char *arr);
void output(char **matr);
int input(char **matr, FILE *img);

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
    output(matr);


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