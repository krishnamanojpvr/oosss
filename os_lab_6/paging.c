#include <stdio.h>
#include <stdlib.h>
#define PAGE_SIZE 1024
#define NUM_PAGES 32
#define MEMORY_SIZE (PAGE_SIZE * NUM_PAGES)
char physical_memory[MEMORY_SIZE];

void initialize_memory()
{
    for (int i = 0; i < MEMORY_SIZE; ++i)
    {
        physical_memory[i] = 0;
    }
}

void page_fault(int address)
{
    int page_number = address / PAGE_SIZE;
    printf("Page fault occurred for page %d\n", page_number);
    printf("Loading page %d into physical memory...\n", page_number);
    for (int i = page_number * PAGE_SIZE; i < (page_number + 1) * PAGE_SIZE; ++i)
    {
        physical_memory[i] = page_number + 1;
    }
}

void access_memory(int address)
{
    if (physical_memory[address] == 0)
    {
        page_fault(address);
    }
    printf("Accessing memory location %d: Value = %d\n", address, physical_memory[address]);
    printf("\n");
}

int main()
{
    initialize_memory();
    access_memory(4096);
    access_memory(2048);
    access_memory(8192);
    access_memory(10240);
    access_memory(3072);
    access_memory(4096);
    return 0;
}