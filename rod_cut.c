#include <stdio.h>
#include <stdlib.h>
#include "rod_cut.h"

float **read_length_value_pairs(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    int capacity = 10;
    float **data = malloc(capacity * sizeof(float *));
    *size = 0;

    float length, value;
    while (fscanf(file, "%f %f", &length, &value) == 2) {
        if (*size == capacity) {
            capacity *= 2;
            data = realloc(data, capacity * sizeof(float *));
        }
        data[*size] = malloc(2 * sizeof(float));
        data[*size][0] = length;
        data[*size][1] = value;
        (*size)++;
    }

    fclose(file);
    return data;
}

float cut_rod(float rod_length, float **length_and_value, int size) {
    float max_value = 0;

    for (int i = 0; i < size; i++) {
        float length = length_and_value[i][0];
        float value = length_and_value[i][1];

        if (length <= rod_length) {
            float total_value = (rod_length / length) * value;
            if (total_value > max_value) {
                max_value = total_value;
            }
        }
    }

    return max_value;
}

void free_memory(float **data, int size) {
    for (int i = 0; i < size; i++) {
        free(data[i]);
    }
    free(data);
}
