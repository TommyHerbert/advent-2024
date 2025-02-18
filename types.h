#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

struct inputDetails {
    char *inputFilename;
    int lengthOfEntries;
    int spaceBetweenEntries;
    int linesInFile;
};

struct counterArray {
    int *array;
    int elements;
};

struct data {
    struct counterArray *column1;
    struct counterArray *column2;
};

#endif

