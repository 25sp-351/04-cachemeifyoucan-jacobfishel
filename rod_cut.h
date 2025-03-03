#ifndef ROD_CUT_H
#define ROD_CUT_H

float **read_length_value_pairs(const char *filename, int *size);
float cut_rod(float rod_length, float **length_and_value, int size);
void free_memory(float **data, int size);

#endif
