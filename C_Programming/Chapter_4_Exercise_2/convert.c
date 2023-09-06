#include <ctype.h>

double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); ++i)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); ++i) 
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        ++i;
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val / power;
}

/*
 * This function extracts the integer part of the exponent.
 * In many ways this function merely extracts an integer from
 * a string and relies on the caller to validate that what
 * came before it indicated that the rest of the string should
 * be treated as an integer for the sake of exponentiation.  
 * The input parameter is the string along with the index into 
 * the string where to start processing the integer extraction 
 * part.  
*/
int parse_int_at_index(char s[], int i) {
    int sign = 1, value = 0;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') 
        ++i;        
    for (; isdigit(s[i]); ++i) {
        value = value * 10 + (s[i] - '0');                    
    }
    return value * sign;
}

/*
* This function converts a given string to a 
* double-precision floating point value.  It 
* adds support for exponential notation, i.e e/E.
* The value after e/E should be an integer value 
* with either a +/-.  This implementation will be
* improved upon in later chapters once the concepts
* around pointers are introduced.  
*
* The exponent part will always be assumed to be the
* 'last' part of the string, i.e. no decimal point
* will be accepted as valid input after an e/E is 
* detected.  
*/
double atof_with_e(char s[]) {
    double val, power = 1.0;
    int i, sign;
    int exponent_part = 0, exponent_sign = 1;
    int parse_int_at_index(char s[], int i);

    for (i = 0; isspace(s[i]); ++i)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); ++i) 
        val = 10.0 * val + (s[i] - '0');
    
    if (s[i] == 'e' || s[i] == 'E') {
        /* logic for exponent extraction */        
        exponent_part = parse_int_at_index(s, ++i);
    } else {    
        if (s[i] == '.')
            ++i;
        for (power = 1.0; isdigit(s[i]); ++i) {
            val = 10.0 * val + (s[i] - '0');
            power /= 10.0;
        }

        if (s[i] == 'e' || s[i] == 'E') {
            /* logic for exponent extraction, but after 
            the decimal point.  In practical terms this
            doesn't materially change the logic or
            behavior of the application, but needs to be
            considered as two separate cases. */          
            exponent_part = parse_int_at_index(s, ++i);              
        }
    }

    exponent_sign = exponent_part < 0 ? -1 : 1;
    /* flips negative to positive */
    exponent_part *= exponent_sign; 
    for (i = 0; i < exponent_part; ++i) {
        power = exponent_sign == 1 ? power * 10 : power / 10;
    }

    return sign * val * power;
}

int atoi(char s[]) {
    double atof(char s[]);

    return (int)atof(s);
}