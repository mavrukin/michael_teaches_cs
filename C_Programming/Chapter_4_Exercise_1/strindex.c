



/*
 * Return the first index of pattern 't' in string 's' or -1
 * if it is not found.
 * 
 * Implementation from K&R, Second Edition, Page 69
*/
int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; ++i) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k) 
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}

/*
 * Return the last index of pattern 't' in string 's' or -1
 * if it is not found.
 * 
 * Solution to Chapter 4, Exercise 1 in K&R, Page 71
*/
int strrindex(char s[], char t[]) {
    int i, j, k;
    int last_found = -1;

    for (i = 0; s[i] != '\0'; ++i) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k) 
            ;
        if (k > 0 && t[k] == '\0')
            last_found = i;
    }

    return last_found;
}