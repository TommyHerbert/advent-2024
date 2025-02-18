#include "distance.h"
#include <stdio.h>

int main(void) {
    struct inputDetails details = {"input01.txt", 5, 3, 1000};
    printf("distance score for input01.txt: %d\n", distance(&details));
    return 0;
}

