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

/**
 * Produces the current top value in the stack without altering the state
 * 
 * command: peek
 * return: (double) current top value in the stack
*/
double peek() {
    if (sp > 0) 
        return val[sp - 1];
    else {
        printf("%s", EMPTY_STACK_ERROR);
        return 0.0;
    }
}

/**
 * Duplicates the top value in the stack so that if the top value is x, then 
 * another x is added to the stack.  Implicitly requires that there is at least
 * one value value in the stack because it relies on peek.  
 * 
 * command: copy
*/
void copy() {
    if (sp < MAXVAL) 
        val[sp++] = peek();
    else 
        printf(FULL_STACK_ERROR, peek());
}

/**
 * Clears the stack by moving the stack pointer to 0
 * 
 * command: clear
*/
void clear() {
    sp = 0;
}

/**
 * Swaps the top two values in the stack, requires that there are at least two
 * values in the stack, otherwise doesn't alter the stack and produces an error
 * message
 * 
 * command: swap
*/
void swap() {
    double temp1, temp2;
    if (sp < 2) 
        printf("error: stack only has %d elements, not enough to swap\n", sp);
    else {
        temp1 = pop();
        temp2 = pop();
        push(temp1);
        push(temp2);
    }
}

/**
 * Produces debug output, the command is 'debug'.  This shows the current stack
 * pointer position as well as the contents of the stack.  
 * 
 * command: debug
*/
void debug() {
    int i;
    printf("DEBUG\n");
    printf("sp: %d\n", sp);
    for (i = 0; i < sp; ++i) {
        printf("i[%d] - sp[%g]\n", i, val[i]);
    }
}

