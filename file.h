#ifndef READER
#define READER

struct inputDetails {
    const char *filename;
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

// first parameter for input, second for output
void read(struct inputDetails*, struct data*);

#endif
