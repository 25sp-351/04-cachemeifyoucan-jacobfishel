#include <stdio.h>
#include <stdlib.h>
#include "cache.h"

#define CACHE_SIZE 10

typedef struct {
    float rod_length;
    float value;
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cache_count = 0;

void initialize_cache() {
    cache_count = 0;
}

int get_cached_value(float rod_length, float *value) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i].rod_length == rod_length) {
            *value = cache[i].value;

            // Move to front (LRU behavior)
            CacheEntry temp = cache[i];
            for (int j = i; j > 0; j--) {
                cache[j] = cache[j - 1];
            }
            cache[0] = temp;

            return 1;
        }
    }
    return 0;
}

void store_in_cache(float rod_length, float value) {
    if (cache_count < CACHE_SIZE) {
        cache_count++;
    }

    // Shift entries down
    for (int i = cache_count - 1; i > 0; i--) {
        cache[i] = cache[i - 1];
    }

    cache[0].rod_length = rod_length;
    cache[0].value = value;
}
