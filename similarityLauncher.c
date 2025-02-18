#include "similarity.h"
#include <stdio.h>

int main(void) {
    struct inputDetails details = {"input01.txt", 5, 3, 1000};
    printf("similarity score for input01.txt: %d\n", similarity(&details));
    return 0;
}

