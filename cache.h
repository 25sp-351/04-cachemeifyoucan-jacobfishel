#ifndef CACHE_H
#define CACHE_H

void initialize_cache();
int get_cached_value(float rod_length, float *value);
void store_in_cache(float rod_length, float value);

#endif
