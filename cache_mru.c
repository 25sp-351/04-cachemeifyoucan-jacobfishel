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
    if (cache_count > 0 && cache[cache_count - 1].rod_length == rod_length) {
        *value = cache[cache_count - 1].value;
        return 1;
    }
    return 0;
}

void store_in_cache(float rod_length, float value) {
    if (cache_count < CACHE_SIZE) {
        cache_count++;
    }

    cache[cache_count - 1].rod_length = rod_length;
    cache[cache_count - 1].value = value;
}
