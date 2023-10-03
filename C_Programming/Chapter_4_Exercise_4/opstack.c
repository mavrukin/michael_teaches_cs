#include <stdio.h>

#define BUFSIZE 100
#define MAXVAL 100

char buf[BUFSIZE];
double val[MAXVAL];
int bufp = 0;
int sp = 0;

const char* EMPTY_STACK_ERROR = "error: stack empty\n";
const char* FULL_STACK_ERROR = "error: stack full, can't push %g\n";

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
        printf(FULL_STACK_ERROR, f);
}

double pop() {
    if (sp > 0)
        return val[--sp];
    else {
        printf("%s", EMPTY_STACK_ERROR);
        return 0.0;
    }
}

double peek() {
    if (sp > 0) 
        return val[sp];
    else {
        printf("%s", EMPTY_STACK_ERROR);
        return 0.0;
    }
}

void copy() {
    if (sp < MAXVAL) 
        val[sp++] = peek();
    else 
        printf(FULL_STACK_ERROR, peek());
}

void clear() {
    sp = 0;
}

void swap() {
    double temp1, temp2;
    if (sp >= 2) 
        printf("error: stack only has %d elements, not enough to swap\n", sp);
    temp1 = pop();
    temp2 = pop();
    push(temp1);
    push(temp2);
}

