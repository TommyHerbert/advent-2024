#include "distance.h"
#include <stdlib.h>
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

