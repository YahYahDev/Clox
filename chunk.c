#include <stdint.h>
#include <stdlib.h>

#include "chunk.h"
#include "memory.h"


void initChunk(Chunk* chunk){

    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;

}

void freeChunk(Chunk* chunk){
    // Calls the macro "FREE_ARRAY"
    FREE_ARRAY(uint_t, chunk->code, chunk->capacity);
    initChunk(chunk);
}

void writeChunk(Chunk* chunk, uint8_t byte){

    //  Checks to see if Chunk Cap is greater than Chunk Count +1
    //  used for triggering a resize of the "chunk->code" array
    if(chunk->capacity < chunk->count +1){

        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code,
                                 oldCapacity, chunk->capacity);

    }
    //  So this seems to set a byte at the next avalable spot in the "chunk->code" array
    //  similar to the memory allocator that i made a while back
    chunk->code[chunk->count] = byte;
    chunk->count++;

}
