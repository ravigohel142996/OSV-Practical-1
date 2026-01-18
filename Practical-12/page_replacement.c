/*
============================================================================
Program: Page Replacement Algorithms (FIFO and LRU)
Author: Marwadi University
Course: Operating System & Virtualization (01AI0403)
Practical: 12
============================================================================

AIM:
To write a C program to simulate FIFO and LRU page replacement algorithms

ALGORITHM:

FIFO (First In First Out):
- Replace the oldest page in memory
- Use a queue to track page order
- Simple but may not be optimal

LRU (Least Recently Used):
- Replace the page that hasn't been used for the longest time
- Keep track of when each page was last used
- More optimal but complex to implement
*/

#include <stdio.h>

void fifo(int pages[], int n, int capacity);
void lru(int pages[], int n, int capacity);
int search(int key, int frame[], int capacity);
void display_frames(int frame[], int capacity);

// Search for page in frames
int search(int key, int frame[], int capacity) {
    int i;
    for (i = 0; i < capacity; i++) {
        if (frame[i] == key) {
            return 1;  // Page found
        }
    }
    return 0;  // Page not found
}

// Display current frames
void display_frames(int frame[], int capacity) {
    int i;
    printf("Frames: [");
    for (i = 0; i < capacity; i++) {
        if (frame[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frame[i]);
        }
    }
    printf("]\n");
}

// FIFO Page Replacement
void fifo(int pages[], int n, int capacity) {
    int frame[capacity];
    int i, j, page_faults = 0;
    int index = 0;  // Points to oldest page
    
    // Initialize frames as empty
    for (i = 0; i < capacity; i++) {
        frame[i] = -1;
    }
    
    printf("\n==========================================\n");
    printf("       FIFO PAGE REPLACEMENT\n");
    printf("==========================================\n\n");
    
    for (i = 0; i < n; i++) {
        printf("Page %d: ", pages[i]);
        
        // Check if page is already in frame
        if (search(pages[i], frame, capacity)) {
            printf("Already in frame (No page fault)\n");
            display_frames(frame, capacity);
        } else {
            // Page fault occurs
            frame[index] = pages[i];
            index = (index + 1) % capacity;
            page_faults++;
            printf("Page fault! ");
            display_frames(frame, capacity);
        }
    }
    
    printf("\n==========================================\n");
    printf("Total Page Faults (FIFO): %d\n", page_faults);
    printf("Page Fault Rate: %.2f%%\n", (float)page_faults / n * 100);
    printf("==========================================\n");
}

// LRU Page Replacement
void lru(int pages[], int n, int capacity) {
    int frame[capacity];
    int recent[capacity];  // Store last used time
    int i, j, page_faults = 0;
    int lru_index, min_time;
    
    // Initialize frames as empty
    for (i = 0; i < capacity; i++) {
        frame[i] = -1;
        recent[i] = 0;
    }
    
    printf("\n==========================================\n");
    printf("       LRU PAGE REPLACEMENT\n");
    printf("==========================================\n\n");
    
    for (i = 0; i < n; i++) {
        printf("Page %d: ", pages[i]);
        
        // Check if page is already in frame
        if (search(pages[i], frame, capacity)) {
            printf("Already in frame (No page fault)\n");
            
            // Update recent usage time
            for (j = 0; j < capacity; j++) {
                if (frame[j] == pages[i]) {
                    recent[j] = i;
                    break;
                }
            }
            display_frames(frame, capacity);
        } else {
            // Page fault occurs
            page_faults++;
            
            // Find empty frame or LRU page
            lru_index = 0;
            min_time = recent[0];
            
            for (j = 1; j < capacity; j++) {
                if (frame[j] == -1) {
                    lru_index = j;
                    break;
                }
                if (recent[j] < min_time) {
                    min_time = recent[j];
                    lru_index = j;
                }
            }
            
            frame[lru_index] = pages[i];
            recent[lru_index] = i;
            
            printf("Page fault! ");
            display_frames(frame, capacity);
        }
    }
    
    printf("\n==========================================\n");
    printf("Total Page Faults (LRU): %d\n", page_faults);
    printf("Page Fault Rate: %.2f%%\n", (float)page_faults / n * 100);
    printf("==========================================\n");
}

int main() {
    int n, capacity, i, choice;
    int pages[50];
    
    printf("==========================================\n");
    printf("   PAGE REPLACEMENT SIMULATION\n");
    printf("==========================================\n\n");
    
    // Input page reference string
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }
    
    // Input number of frames
    printf("\nEnter number of frames: ");
    scanf("%d", &capacity);
    
    while (1) {
        printf("\n==========================================\n");
        printf("1. FIFO Page Replacement\n");
        printf("2. LRU Page Replacement\n");
        printf("3. Exit\n");
        printf("==========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                fifo(pages, n, capacity);
                break;
            case 2:
                lru(pages, n, capacity);
                break;
            case 3:
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
Enter number of pages: 12
Page reference string: 7 0 1 2 0 3 0 4 2 3 0 3
Enter number of frames: 3

SAMPLE OUTPUT (FIFO):
Page 7: Page fault! Frames: [ 7  -  - ]
Page 0: Page fault! Frames: [ 7  0  - ]
Page 1: Page fault! Frames: [ 7  0  1 ]
Page 2: Page fault! Frames: [ 2  0  1 ]
Page 0: Already in frame (No page fault)
Page 3: Page fault! Frames: [ 2  3  1 ]
...

Total Page Faults (FIFO): 9
Page Fault Rate: 75.00%

COMMANDS TO RUN:
gcc page_replacement.c -o page_replacement
./page_replacement

VIVA EXPLANATION:
FIFO replaces the oldest page in memory using a circular queue approach.
LRU replaces the page that hasn't been used for the longest time, requiring tracking of usage.
LRU generally performs better than FIFO but is more complex to implement.
*/
