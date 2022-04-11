#ifndef STRUCT_H
#define STRUCT_H
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    double *body; //massive
    size_t memory;  //reserved size
    size_t size; //actual size
    size_t first; //first element
} test_struct;

#endif