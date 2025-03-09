#include "distance.h"
#include "args.h"
#include <stdio.h>

int main(int argc, char **argv) {
    struct inputDetails details = {"data/input01.txt", 5, 3, 1000};
    parse(argc, argv, &details);
    printf("distance score for %s: %d\n", details.filename, distance(&details));
    return 0;
}

