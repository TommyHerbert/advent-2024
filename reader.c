#include <stdio.h>
#include <stdlib.h>

struct inputDetails {
    char *inputFilename;
    int lengthOfEntries;
    int spaceBetweenEntries;
    int linesInFile;
};

int compare(const void *value1, const void *value2) {
    return *(const int *)value1 - *(const int *) value2;
}

int totalDifference(struct inputDetails details) {
    FILE *inputFile;
    inputFile = fopen(details.inputFilename, "r");

    // allow an extra character for the newline and another for the end of the buffer
    int lineLength = 2 * details.lengthOfEntries + details.spaceBetweenEntries + 2;

    char buffer[lineLength];
    int leftColumn[details.linesInFile];
    int rightColumn[details.linesInFile];
    int leftCounter = 0;
    int rightCounter = 0;
    int rightColumnOffset = details.lengthOfEntries + details.spaceBetweenEntries;
    while(fgets(buffer, lineLength, inputFile)) {
        leftColumn[leftCounter++] = atoi(buffer);
        rightColumn[rightCounter++] = atoi(buffer + rightColumnOffset);
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

int testExample() {
    struct inputDetails details = {"example.txt", 1, 3, 6};
    if (totalDifference(details) == 11) return 1;
    else {
        printf("failed test: example.txt\n");
        return 0;
    }
}

int testInput() {
    struct inputDetails details = {"input.txt", 5, 3, 1000};
    if (totalDifference(details) == 2000468) return 1;
    else {
        printf("failed test: input.txt\n");
        return 0;
    }
}

void testAll(void) {
    if (testExample() && testInput()) printf("all tests succeeded\n");
}

int main(void) {
    testAll();
    return 0;
}

