// 2000468


#include <stdio.h>
#include <stdlib.h>

int compare(const void *value1, const void *value2) {
    return *(const int *)value1 - *(const int *) value2;
}

int totalDifference(void) {
    FILE *inputFile;
    inputFile = fopen("input.txt", "r");
    char buffer[15];
    int leftColumn[1000];
    int rightColumn[1000];
    int leftCounter = 0;
    int rightCounter = 0;
    while(fgets(buffer, 15, inputFile)) {
        leftColumn[leftCounter++] = atoi(buffer);
        rightColumn[rightCounter++] = atoi(buffer + 8);
    }
    fclose(inputFile);

    qsort(leftColumn, leftCounter, sizeof(int), compare);
    qsort(rightColumn, rightCounter, sizeof(int), compare);

    int total = 0;
    for (int i = 0; i < leftCounter; ++i) {
        total += abs(leftColumn[i] - rightColumn[i]);
    }
    return total;
}

void test(void) {
    if (totalDifference() == 2000468) printf("test passed\n");
    else printf("test failed\n");
}

int main(void) {
    test();
    return 0;
}

