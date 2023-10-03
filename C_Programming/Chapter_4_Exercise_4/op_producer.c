#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'
#define PEEK 1
#define SWAP 2
#define CLEAR 3
#define DUPLICATE 4

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c, sign = 0;
    
    /* skip leading white space */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';    

    /* if this not a digit, or a decimal point, or - or + then 
       return what we parsed (likely * / %) */
    if (!isdigit(c) && c != '.' && c != '-' && c != '+') {
        /* attempt to parse a command */
        if (c == '*' || c == '/') 
            return c;
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