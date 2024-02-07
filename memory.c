#include <stdlib.h>

#include "memory.h"


void* reallocate(void* pointer, size_t oldSize, size_t newSize){
    //  This checks to see if we want to free
    //  And to do so if we do want to
    if(newSize == 0){
        free(pointer);
        return NULL;
    }


    //  Attempts to allocate with "realloc()"
    void* result = realloc(pointer, newSize);
    //  Basic error check for if we alloced succesfully
    if (result = NULL) exit(1);
    return result;
}

