#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* Special values to signal what 'type' of command was parsed out.  These
   will be moved to a dedicated header file once that is covered in a later
   section of the course. */
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
    int i = 0, c, sign = 0;
    int op_code = 0;
    
    /* skip leading white space */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';        

    /* if the value is not a digit and doesn't look like it is
       numeric in nature, then attempt to parse out a command */
    if (!isdigit(c) && c != '.' && c != '-' && c != '+') {
        /* if 'c' is a basic arithmetic operation, except for +,- then
           return that value */
        if (c == '*' || c == '/' || c == '%' || c == '\n') 
            return c;

        /* keep fetching alpha-numeric values, converting them to lowercase
           and storing in the string */    
        if (isalnum(c)) 
            while (isalnum(s[++i] = tolower(c = getch())))
                ;
        
        /* perform the string termination part and return the \n back 
           to the input stream */
        s[i] = '\0';
        if (c != EOF) 
            ungetch(c); 

        /* attempt to match the string against known command, if none worked
           then this is an error command */
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
        return op_code; 
    }                

    /* The non-command case is to parse out a numerical value */

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