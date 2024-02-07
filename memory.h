#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"


//  Grow Capacity seems to take capacity then grows it
//      i would of rather used a function that returns a value

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)


//  Reallocate the array to the new size
//      again seems like this could be much less complex than it needs to be
//      i need to learn macros more if this is common

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount),\
        sizeof(type) * (newCount))


//  Takes the "type", "pointer" and "oldCount"
//  And uses "reallocate" to free the array attatched to "pointer"

#define FREE_ARRAY(type, pointer, oldCount) \
        reallocate(pointer, sizeof(type) * oldCount)


//  defining reallocate assuming this is a realloc wraper

void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif
