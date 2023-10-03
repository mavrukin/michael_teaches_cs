#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define PEEK 1
#define SWAP 2
#define CLEAR 3
#define DUPLICATE 4
#define ERROR -1

int getop(char []);
void push(double);
double pop(void);
double peek(void);

int main(int argc, char** argv) {
    int type, mod_op2;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        printf("type: %d\n", type);
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case PEEK:
            printf("\t%.8g\n", peek());
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
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknonwn command %s\n", s);
            break;
        }        
    }
    return 0;
}