#include "similarity.h"
#include "file.h"

struct mapEntry {
    int key;
    int value;
};

int similarity(struct inputDetails *input) {
    int column1[input->linesInFile];
    int column2[input->linesInFile];
    struct counterArray counterArray1 = {column1, 0};
    struct counterArray counterArray2 = {column2, 0};
    struct data output = {&counterArray1, &counterArray2};
    read(input, &output);
    struct mapEntry frequencies[counterArray2.elements];
    for (int i = 0; i < counterArray2.elements; ++i) {
        struct mapEntry entry = {0, 0};
        frequencies[i] = entry;
    }
    for (int i = 0; i < counterArray2.elements; ++i) {
        int mapMarker = 0;
        while (mapMarker < counterArray2.elements && frequencies[mapMarker].key != column2[i] && frequencies[mapMarker].key != 0) {
            mapMarker++;
        }
        struct mapEntry frequency = frequencies[mapMarker];
        frequency.key = column2[i];
        frequency.value += 1;
        frequencies[mapMarker] = frequency;
    }
    int total = 0;
    for (int i = 0; i < counterArray1.elements; ++i) {
        int location = column1[i];
        int mapMarker = 0;
        while (mapMarker < counterArray2.elements && frequencies[mapMarker].key != location && frequencies[mapMarker].key != 0) {
            mapMarker++;
        }
        int frequency = 0;
        if (mapMarker < counterArray2.elements) {
           frequency = frequencies[mapMarker].value; 
        }
        total += location * frequency;
    }
    return total;
}
