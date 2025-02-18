#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "reader.h"

int compare(const void *value1, const void *value2) {
    return *(const int *)value1 - *(const int *)value2;
}

int distance(struct inputDetails *input) {
    int column1[input->linesInFile];
    int column2[input->linesInFile];
    struct counterArray counterArray1 = {column1, 0};
    struct counterArray counterArray2 = {column2, 0};
    struct data output = {&counterArray1, &counterArray2};
    read(input, &output);
    qsort(column1, counterArray1.elements, sizeof(int), compare);
    qsort(column2, counterArray2.elements, sizeof(int), compare);
    int total = 0;
    for (int i = 0; i < counterArray1.elements; ++i) {
        total += abs(column1[i] - column2[i]);
    }
    return total;
}

int similarity(struct inputDetails *input) {
    return 0;
}

int testDistanceExample() {
    struct inputDetails details = {"example01.txt", 1, 3, 6};
    if (distance(&details) == 11) return 1;
    else {
        printf("failed test: example.txt distance\n");
        return 0;
    }
}

int testDistanceInput() {
    struct inputDetails details = {"input01.txt", 5, 3, 1000};
    if (distance(&details) == 2000468) return 1;
    else {
        printf("failed test: input.txt distance\n");
        return 0;
    }
}

int testSimilarityExample() {
    struct inputDetails details = {"example01.txt", 1, 3, 6};
    if (similarity(&details) == 31) return 1;
    else {
        printf("failed test: example.txt similarity\n");
        return 0;
    }
}

int testSimilarityInput() {
    struct inputDetails details = {"input01.txt", 5, 3, 1000};
    printf("similarity score for input.txt: %d", similarity(&details));
}

void testAll(void) {
    if (
        testDistanceExample() &&
        testDistanceInput() &&
        testSimilarityExample() &&
        testSimilarityInput()
    ) printf("all tests succeeded\n");
}

int main(void) {
    testAll();
    return 0;
}

