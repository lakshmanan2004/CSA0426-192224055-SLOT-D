#include <stdio.h>
#include <stdlib.h>

// Structure to represent a block of memory
struct memoryBlock {
    int size;
    int allocated;
};

int main() {
    int memorySize, numBlocks;

    printf("Enter the total memory size: ");
    scanf("%d", &memorySize);

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    // Allocate memory for the memory blocks
    struct memoryBlock *mem = (struct memoryBlock*) malloc(numBlocks * sizeof(struct memoryBlock));

    // Initialize memory blocks
    for(int i = 0; i < numBlocks; i++) {
        printf("Enter the size of memory block %d: ", i+1);
        scanf("%d", &mem[i].size);
        mem[i].allocated = 0;
    }

    // Memory allocation
    int reqSize;
    printf("\nEnter the size of memory to be allocated: ");
    scanf("%d", &reqSize);

    int bestBlock = -1;
    for(int i = 0; i < numBlocks; i++) {
        if(mem[i].size >= reqSize && !mem[i].allocated) {
            if(bestBlock == -1 || mem[i].size < mem[bestBlock].size) {
                bestBlock = i;
            }
        }
    }

    if(bestBlock != -1) {
        mem[bestBlock].allocated = 1;
        printf("Memory allocated from block %d\n", bestBlock+1);
    } else {
        printf("Memory cannot be allocated\n");
    }

    free(mem);

    return 0;
}
