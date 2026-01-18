/*
============================================================================
Program: Contiguous Memory Allocation (First Fit, Best Fit, Worst Fit)
Author: Marwadi University
Course: Operating System & Virtualization (01AI0403)
Practical: 11
============================================================================

AIM:
To write a C program to simulate contiguous memory allocation using First Fit,
Best Fit, and Worst Fit algorithms

ALGORITHM:

First Fit:
- Allocate the first hole that is big enough
- Search can start from beginning or where previous search ended

Best Fit:
- Allocate the smallest hole that is big enough
- Must search entire list to find smallest sufficient hole

Worst Fit:
- Allocate the largest hole
- Must search entire list to find largest hole
*/

#include <stdio.h>

#define MAX 25

void first_fit(int block_size[], int m, int process_size[], int n);
void best_fit(int block_size[], int m, int process_size[], int n);
void worst_fit(int block_size[], int m, int process_size[], int n);

// First Fit Algorithm
void first_fit(int block_size[], int m, int process_size[], int n) {
    int allocation[MAX], i, j;
    
    // Initialize all allocations as -1 (not allocated)
    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    
    // Allocate memory to processes
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (block_size[j] >= process_size[i]) {
                allocation[i] = j;
                block_size[j] -= process_size[i];
                break;
            }
        }
    }
    
    // Display results
    printf("\n==========================================\n");
    printf("       FIRST FIT ALLOCATION\n");
    printf("==========================================\n");
    printf("Process\tSize\tBlock\tFragment\n");
    printf("==========================================\n");
    
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t", i + 1, process_size[i]);
        if (allocation[i] != -1) {
            printf("%d\t%d\n", allocation[i] + 1, block_size[allocation[i]]);
        } else {
            printf("Not Allocated\t--\n");
        }
    }
    printf("==========================================\n");
}

// Best Fit Algorithm
void best_fit(int block_size[], int m, int process_size[], int n) {
    int allocation[MAX], i, j;
    
    // Initialize all allocations as -1
    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    
    // Allocate memory to processes
    for (i = 0; i < n; i++) {
        int best_idx = -1;
        for (j = 0; j < m; j++) {
            if (block_size[j] >= process_size[i]) {
                if (best_idx == -1 || block_size[j] < block_size[best_idx]) {
                    best_idx = j;
                }
            }
        }
        
        if (best_idx != -1) {
            allocation[i] = best_idx;
            block_size[best_idx] -= process_size[i];
        }
    }
    
    // Display results
    printf("\n==========================================\n");
    printf("       BEST FIT ALLOCATION\n");
    printf("==========================================\n");
    printf("Process\tSize\tBlock\tFragment\n");
    printf("==========================================\n");
    
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t", i + 1, process_size[i]);
        if (allocation[i] != -1) {
            printf("%d\t%d\n", allocation[i] + 1, block_size[allocation[i]]);
        } else {
            printf("Not Allocated\t--\n");
        }
    }
    printf("==========================================\n");
}

// Worst Fit Algorithm
void worst_fit(int block_size[], int m, int process_size[], int n) {
    int allocation[MAX], i, j;
    
    // Initialize all allocations as -1
    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    
    // Allocate memory to processes
    for (i = 0; i < n; i++) {
        int worst_idx = -1;
        for (j = 0; j < m; j++) {
            if (block_size[j] >= process_size[i]) {
                if (worst_idx == -1 || block_size[j] > block_size[worst_idx]) {
                    worst_idx = j;
                }
            }
        }
        
        if (worst_idx != -1) {
            allocation[i] = worst_idx;
            block_size[worst_idx] -= process_size[i];
        }
    }
    
    // Display results
    printf("\n==========================================\n");
    printf("       WORST FIT ALLOCATION\n");
    printf("==========================================\n");
    printf("Process\tSize\tBlock\tFragment\n");
    printf("==========================================\n");
    
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t", i + 1, process_size[i]);
        if (allocation[i] != -1) {
            printf("%d\t%d\n", allocation[i] + 1, block_size[allocation[i]]);
        } else {
            printf("Not Allocated\t--\n");
        }
    }
    printf("==========================================\n");
}

int main() {
    int block_size[MAX], process_size[MAX];
    int m, n, i, choice;
    int temp_block[MAX];
    
    printf("==========================================\n");
    printf("   MEMORY ALLOCATION SIMULATION\n");
    printf("==========================================\n\n");
    
    // Input number of memory blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    
    printf("Enter size of each block:\n");
    for (i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block_size[i]);
    }
    
    // Input number of processes
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    
    printf("Enter size of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &process_size[i]);
    }
    
    while (1) {
        printf("\n==========================================\n");
        printf("1. First Fit\n");
        printf("2. Best Fit\n");
        printf("3. Worst Fit\n");
        printf("4. Exit\n");
        printf("==========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Reset block sizes for each algorithm
        for (i = 0; i < m; i++) {
            temp_block[i] = block_size[i];
        }
        
        switch (choice) {
            case 1:
                first_fit(temp_block, m, process_size, n);
                break;
            case 2:
                best_fit(temp_block, m, process_size, n);
                break;
            case 3:
                worst_fit(temp_block, m, process_size, n);
                break;
            case 4:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}

/*
SAMPLE INPUT:
Enter number of memory blocks: 5
Block 1: 100
Block 2: 500
Block 3: 200
Block 4: 300
Block 5: 600

Enter number of processes: 4
Process 1: 212
Process 2: 417
Process 3: 112
Process 4: 426

SAMPLE OUTPUT (First Fit):
Process	Size	Block	Fragment
P1	212	2	288
P2	417	5	183
P3	112	2	176
P4	426	Not Allocated	--

COMMANDS TO RUN:
gcc memory_allocation.c -o memory_allocation
./memory_allocation

VIVA EXPLANATION:
First Fit allocates the first sufficient block, it's fast but may leave small fragments.
Best Fit finds the smallest sufficient block, minimizing wasted space but slower.
Worst Fit allocates the largest block, leaving larger usable fragments but may be inefficient.
*/
