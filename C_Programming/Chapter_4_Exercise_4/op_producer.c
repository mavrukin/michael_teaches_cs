#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUMBER '0'
#define PEEK 1
#define SWAP 2
#define CLEAR 3
#define COPY 4
#define DEBUG 5
#define ERROR -1

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c, sign = 0;
    int op_code = 0;
    
    /* skip leading white space */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';    

    /* if this not a digit, or a decimal point, or - or + then 
       return what we parsed (likely * / %) */
    printf("1\n");
    if (!isdigit(c) && c != '.' && c != '-' && c != '+') {
        /* attempt to parse a command */

        /* basic arithmetic operations */
        if (c == '*' || c == '/' || c == '%' || c == '\n') 
            return c;
        i = 0;
        if (isalnum(c)) 
            while (isalnum(s[++i] = tolower(c = getch())))
                ;
        s[i] = '\0';
        if (c != EOF) 
            ungetch(c); 
        printf("%s\n", s);        
        if (strcmp(s, "peek") == 0)
            op_code = PEEK;
        if (strcmp(s, "swap") == 0)
            op_code = SWAP;
        if (strcmp(s, "clear") == 0)
            op_code = CLEAR;
        if (strcmp(s, "copy") == 0)
            op_code = COPY;
        if (strcmp(s, "debug") == 0)
            op_code = DEBUG;
        if (op_code == 0) 
            op_code = ERROR;
        printf("op_code = %d\n", op_code);
        return op_code; 
    }    
        
    i = 0;        

    /* if we got - or + track it as a 'sign' */
    if (c == '-' || c == '+')
        sign = c;
    
    if (isdigit(c) || sign > 0)         
        while (isdigit(s[++i] = c = getch())) 
            ;    
    
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    /* if we only parsed 1 character AND it is a sign character 
       then fall back to return the 'sign' value */
    if (i == 1 && sign != 0) {
        ungetch(c);
        return sign;
    }

    s[i] = '\0';        
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}