#include <stdio.h>

#define BUFSIZE 100
#define MAXVAL 100

char buf[BUFSIZE];
double val[MAXVAL];
int bufp = 0;
int sp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZ) 
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop() {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

