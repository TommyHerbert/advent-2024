#include "reader.h"

void read(struct inputDetails *input, struct data *output) {
    FILE *inputFile;
    inputFile = fopen(input->inputFilename, "r");

    // allow an extra character for the newline and another for the end of the buffer
    int lineLength = 2 * input->lengthOfEntries + input->spaceBetweenEntries + 2;

    char buffer[lineLength];
    int rightColumnOffset = input->lengthOfEntries + input->spaceBetweenEntries;
    while(fgets(buffer, lineLength, inputFile)) {
        output->column1->array[output->column1->elements++] = atoi(buffer);
        output->column2->array[output->column2->elements++] = atoi(buffer + rightColumnOffset);
    }
    fclose(inputFile);
}

