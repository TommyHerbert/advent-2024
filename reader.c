/*
10 is new line
32 is space
48 is 0
*/

#include <stdio.h>
#include <locale.h>

int main(void) {
    FILE *inputFile;
    inputFile = fopen("example.txt", "r");
    char c;
    char numberString[] = {0, 0, 0, 0, 0};
    while((c = fgetc(inputFile)) != EOF) {
        
        printf("%c %d\n", c, c);
    }
    fclose(inputFile);
    return 0;
}

