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

