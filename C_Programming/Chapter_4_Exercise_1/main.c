#include <stdio.h>

#define MAXLINE 1000

int getline_kr(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "be";

int main(int argc, char** argv) {
    char line[MAXLINE];
    int found = 0;
    int found_index = 0;    

    while (getline_kr(line, MAXLINE) > 0) {        
        found_index = strindex(line, pattern);
        if (found_index > 0) {
            printf("%d at %s", found_index, line);
            found++;
        }

        found_index = strrindex(line, pattern);
        if (found_index > 0) {
            printf("%d at %s", found_index, line);
            found++;
        }
    }
        
    
    return found;
}