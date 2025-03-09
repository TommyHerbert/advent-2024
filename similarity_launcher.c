#include "similarity.h"
#include "args.h"
#include "paths.h"
#include <stdio.h>

int main(int argc, char **argv) {
    struct inputDetails details = {INPUT01, 5, 3, 1000};
    parse(argc, argv, &details);
    printf("similarity score for input01.txt: %d\n", similarity(&details));
    return 0;
}

