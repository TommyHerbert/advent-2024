#include "parse.h"
#include <stdlib.h>

void parse(int argc, char **argv, struct inputDetails *details) {
    if (argc > 1) details->inputFilename = argv[1];
    if (argc > 2) details->lengthOfEntries = atoi(argv[2]);
    if (argc > 3) details->spaceBetweenEntries = atoi(argv[3]);
    if (argc > 4) details->linesInFile = atoi(argv[4]);
}

