/*
============================================================================
Program: Producer-Consumer Problem using Semaphores
Author: Marwadi University
Course: Operating System & Virtualization (01AI0403)
Practical: 9
============================================================================

AIM:
To write a C program to simulate the Producer-Consumer problem using semaphores

ALGORITHM:
Step 1: Start
Step 2: Initialize semaphores: mutex=1, empty=buffer_size, full=0
Step 3: Display menu with options: Produce, Consume, Exit
Step 4: For Producer:
        a) Wait on empty semaphore
        b) Wait on mutex
        c) Add item to buffer
        d) Signal mutex
        e) Signal full semaphore
Step 5: For Consumer:
        a) Wait on full semaphore
        b) Wait on mutex
        c) Remove item from buffer
        d) Signal mutex
        e) Signal empty semaphore
Step 6: Repeat until user exits
Step 7: Stop
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int mutex = 1;          // Binary semaphore for mutual exclusion
int full = 0;           // Counting semaphore for filled slots
int empty = BUFFER_SIZE; // Counting semaphore for empty slots
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

// Wait operation on semaphore
int wait(int s) {
    return --s;
}

// Signal operation on semaphore
int signal(int s) {
    return ++s;
}

// Producer function
void producer() {
    int item;
    
    if (empty == 0) {
        printf("\nBuffer is FULL! Cannot produce.\n");
        return;
    }
    
    empty = wait(empty);
    mutex = wait(mutex);
    
    // Critical Section - Produce item
    item = rand() % 100 + 1;
    buffer[in] = item;
    printf("\nProducer produced item %d at position %d\n", item, in);
    in = (in + 1) % BUFFER_SIZE;
    
    mutex = signal(mutex);
    full = signal(full);
    
    printf("Buffer status: %d items in buffer\n", full);
}

// Consumer function
void consumer() {
    int item;
    
    if (full == 0) {
        printf("\nBuffer is EMPTY! Cannot consume.\n");
        return;
    }
    
    full = wait(full);
    mutex = wait(mutex);
    
    // Critical Section - Consume item
    item = buffer[out];
    printf("\nConsumer consumed item %d from position %d\n", item, out);
    out = (out + 1) % BUFFER_SIZE;
    
    mutex = signal(mutex);
    empty = signal(empty);
    
    printf("Buffer status: %d items in buffer\n", full);
}

// Display buffer contents
void display_buffer() {
    int i, count;
    printf("\nCurrent Buffer Status:\n");
    printf("Empty slots: %d, Filled slots: %d\n", empty, full);
    printf("Buffer contents: [");
    
    if (full == 0) {
        printf(" EMPTY ");
    } else {
        count = 0;
        i = out;
        while (count < full) {
            printf(" %d ", buffer[i]);
            i = (i + 1) % BUFFER_SIZE;
            count++;
        }
    }
    printf("]\n");
}

int main() {
    int choice;
    
    printf("==========================================\n");
    printf("  PRODUCER-CONSUMER PROBLEM SIMULATION\n");
    printf("==========================================\n");
    printf("Buffer Size: %d\n", BUFFER_SIZE);
    printf("==========================================\n");
    
    while (1) {
        printf("\n1. Produce\n");
        printf("2. Consume\n");
        printf("3. Display Buffer\n");
        printf("4. Exit\n");
        printf("==========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                display_buffer();
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

/*
SAMPLE INPUT/OUTPUT:

Enter your choice: 1
Producer produced item 45 at position 0
Buffer status: 1 items in buffer

Enter your choice: 1
Producer produced item 67 at position 1
Buffer status: 2 items in buffer

Enter your choice: 2
Consumer consumed item 45 from position 0
Buffer status: 1 items in buffer

Enter your choice: 3
Current Buffer Status:
Empty slots: 4, Filled slots: 1
Buffer contents: [ 67 ]

COMMANDS TO RUN:
gcc producer_consumer.c -o producer_consumer
./producer_consumer

VIVA EXPLANATION:
The Producer-Consumer problem demonstrates process synchronization using semaphores.
Three semaphores are used: mutex for mutual exclusion, empty for tracking empty slots, and full for tracking filled slots.
This prevents race conditions and ensures that producers don't overflow the buffer and consumers don't underflow it.
*/
