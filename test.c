#include "distance.h"
#include "similarity.h"
#include <stdio.h>

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

void testAll(void) {
    if (
        testDistanceExample() &&
        testDistanceInput() &&
        testSimilarityExample()
    ) printf("all tests succeeded\n");
}

int main(void) {
    testAll();
    return 0;
}

