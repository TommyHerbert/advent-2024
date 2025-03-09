#include "distance.h"
#include "similarity.h"
#include "paths.h"
#include <stdio.h>

int testDistanceExample() {
    struct inputDetails details = {EXAMPLE01, 1, 3, 6};
    int output = distance(&details);
    if (output == 11) return 1;
    else {
        printf("failed test: example.txt distance returned %d\n", output);
        return 0;
    }
}

int testDistanceInput() {
    struct inputDetails details = {INPUT01, 5, 3, 1000};
    int output = distance(&details);
    if (output == 2000468) return 1;
    else {
        printf("failed test: input.txt distance returned %d\n", output);
        return 0;
    }
}

int testSimilarityExample() {
    struct inputDetails details = {EXAMPLE01, 1, 3, 6};
    int output = similarity(&details);
    if (output == 31) return 1;
    else {
        printf("failed test: example.txt similarity returned %d\n", output);
        return 0;
    }
}

int testSimilarityInput() {
    struct inputDetails details = {INPUT01, 5, 3, 1000};
    int output = similarity(&details);
    if (output == 18567089) return 1;
    else {
        printf("failed test: input.txt similarity returned %d\n", output);
        return 0;
    }
}

int testAll(void) {
    if (
        testDistanceExample() &&
        testDistanceInput() &&
        testSimilarityExample() &&
        testSimilarityInput() 
    ) {
        printf("all tests succeeded\n");
        return 1;
    }
    else {
        return 0;
    }
}

int main(void) {
    return testAll();
}

