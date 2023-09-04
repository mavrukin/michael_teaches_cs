#include <stdio.h>

#define MAXLINE 100

int main(int argc, char** argv) {
    double sum, atof(char[]), atof_with_e(char[]);
    char line[MAXLINE];
    int getline_kr(char line[], int max);

    sum = 0;
    while (getline_kr(line, MAXLINE) > 0) {
        /* printf("\t%g\n", sum += atof(line)); */
        printf("\t%g\n", sum += atof_with_e(line));
    }

    return 0;
}