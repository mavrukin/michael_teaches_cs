#include <stdio.h>
#include <stdlib.h>

/* This is bad style, they are duplicated here because header files were not yet
   coverd in the text.  The cleanup of this to use header files will be reserved 
   for a later exercise. */
#define MAXOP 100
#define NUMBER '0'
#define PEEK 1
#define SWAP 2
#define CLEAR 3
#define COPY 4
#define DEBUG 5
#define ERROR -1

/* prototypes of methods that are available at compile time, but are not yet
   defined in a dedicated header file since header files were not yet covered
   in the textbook. */
int getop(char []);
void push(double);
double pop(void);
double peek(void);
void swap();
void clear();
void copy();
void debug();

int main(int argc, char** argv) {
    int type, mod_op2;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {        
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case PEEK:
            printf("\t%.8g\n", peek());
            break;
        case SWAP:
            swap();
            break;
        case CLEAR:
            clear();
            break;
        case COPY:
            copy();
            break;
        case DEBUG:
            debug();
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            mod_op2 = (int)pop();
            if (mod_op2 != 0.0) 
                push((int)pop() % mod_op2);
            else
                printf("error: modulos of zero\n");
            break;
        case '\n':
            printf("\t%.8g\n", peek());
            break;
        default:
            printf("error: unknonwn command %s\n", s);
            break;
        }        
    }
    return 0;
}