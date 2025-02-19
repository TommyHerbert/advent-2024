#include "distance.h"
#include "parse.h"
#include <stdio.h>

int main(int argc, char **argv) {
    struct inputDetails details = {"input01.txt", 5, 3, 1000};
    parse(argc, argv, &details);
    printf("distance score for %s: %d\n", details.filename, distance(&details));
    return 0;
}

