#include <stdio.h>
#include <stdlib.h>
#include "rod_cut.h"
#include "cache.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Read length-value pairs from file
    int size;
    float **length_and_value = read_length_value_pairs(argv[1], &size);
    if (!length_and_value) {
        printf("Failed to read input file.\n");
        return 1;
    }

    initialize_cache();  // Set up caching

    // Read rod lengths from stdin and process them
    float rod_length;
    while (scanf("%f", &rod_length) == 1) {
        printf("Processing rod length: %.2f\n", rod_length);

        // Check cache first
        float cached_value;
        if (get_cached_value(rod_length, &cached_value)) {
            printf("Cached Value: %.2f\n", cached_value);
            continue;
        }

        // Compute optimal cuts and value
        float max_value = cut_rod(rod_length, length_and_value, size);
        printf("Max Value: %.2f\n", max_value);

        // Store in cache
        store_in_cache(rod_length, max_value);
    }

    free_memory(length_and_value, size);
    return 0;
}
