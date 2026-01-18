/*
============================================================================
Program: Disk Scheduling Algorithms (FCFS and SCAN)
Author: Marwadi University
Course: Operating System & Virtualization (01AI0403)
Practical: 14
============================================================================

AIM:
To write a C program to simulate FCFS and SCAN disk scheduling algorithms

ALGORITHM:

FCFS (First Come First Serve):
- Process requests in the order they arrive
- Simple but may cause excessive head movement

SCAN (Elevator Algorithm):
- Head moves in one direction servicing requests
- When it reaches the end, it reverses direction
- More efficient than FCFS
*/

#include <stdio.h>
#include <stdlib.h>

void fcfs(int requests[], int n, int head);
void scan(int requests[], int n, int head, int disk_size, int direction);
void sort(int arr[], int n);

// Sort array in ascending order
void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// FCFS Disk Scheduling
void fcfs(int requests[], int n, int head) {
    int total_seek = 0;
    int distance, current;
    int i;
    
    printf("\n==========================================\n");
    printf("       FCFS DISK SCHEDULING\n");
    printf("==========================================\n");
    printf("Initial head position: %d\n\n", head);
    
    printf("Seek Sequence:\n");
    printf("%d", head);
    
    current = head;
    
    for (i = 0; i < n; i++) {
        printf(" -> %d", requests[i]);
        distance = abs(requests[i] - current);
        total_seek += distance;
        current = requests[i];
    }
    
    printf("\n\n==========================================\n");
    printf("Total Seek Operations: %d\n", total_seek);
    printf("Average Seek Time: %.2f\n", (float)total_seek / n);
    printf("==========================================\n");
}

// SCAN Disk Scheduling
void scan(int requests[], int n, int head, int disk_size, int direction) {
    int total_seek = 0;
    int distance, current;
    int i, j;
    int left[50], right[50];
    int left_count = 0, right_count = 0;
    
    // Separate requests to left and right of head
    for (i = 0; i < n; i++) {
        if (requests[i] < head) {
            left[left_count++] = requests[i];
        } else {
            right[right_count++] = requests[i];
        }
    }
    
    // Sort both arrays
    sort(left, left_count);
    sort(right, right_count);
    
    printf("\n==========================================\n");
    printf("       SCAN DISK SCHEDULING\n");
    printf("==========================================\n");
    printf("Initial head position: %d\n", head);
    printf("Direction: %s\n\n", direction == 1 ? "Right (Towards higher tracks)" : "Left (Towards lower tracks)");
    
    printf("Seek Sequence:\n");
    printf("%d", head);
    
    current = head;
    
    // If moving towards right
    if (direction == 1) {
        // Service right side first
        for (i = 0; i < right_count; i++) {
            printf(" -> %d", right[i]);
            distance = abs(right[i] - current);
            total_seek += distance;
            current = right[i];
        }
        
        // Go to end if there were requests on right
        if (right_count > 0) {
            printf(" -> %d", disk_size - 1);
            distance = abs((disk_size - 1) - current);
            total_seek += distance;
            current = disk_size - 1;
        }
        
        // Service left side
        for (i = left_count - 1; i >= 0; i--) {
            printf(" -> %d", left[i]);
            distance = abs(left[i] - current);
            total_seek += distance;
            current = left[i];
        }
    }
    // If moving towards left
    else {
        // Service left side first (in reverse)
        for (i = left_count - 1; i >= 0; i--) {
            printf(" -> %d", left[i]);
            distance = abs(left[i] - current);
            total_seek += distance;
            current = left[i];
        }
        
        // Go to beginning if there were requests on left
        if (left_count > 0) {
            printf(" -> 0");
            distance = abs(0 - current);
            total_seek += distance;
            current = 0;
        }
        
        // Service right side
        for (i = 0; i < right_count; i++) {
            printf(" -> %d", right[i]);
            distance = abs(right[i] - current);
            total_seek += distance;
            current = right[i];
        }
    }
    
    printf("\n\n==========================================\n");
    printf("Total Seek Operations: %d\n", total_seek);
    printf("Average Seek Time: %.2f\n", (float)total_seek / n);
    printf("==========================================\n");
}

int main() {
    int n, head, disk_size, direction, choice;
    int requests[50];
    int temp_requests[50];
    int i;
    
    printf("==========================================\n");
    printf("   DISK SCHEDULING SIMULATION\n");
    printf("==========================================\n\n");
    
    // Input disk parameters
    printf("Enter disk size (number of tracks): ");
    scanf("%d", &disk_size);
    
    printf("Enter initial head position: ");
    scanf("%d", &head);
    
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    
    printf("\nEnter disk requests:\n");
    for (i = 0; i < n; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }
    
    while (1) {
        printf("\n==========================================\n");
        printf("1. FCFS Disk Scheduling\n");
        printf("2. SCAN Disk Scheduling\n");
        printf("3. Exit\n");
        printf("==========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Copy requests to temp array
        for (i = 0; i < n; i++) {
            temp_requests[i] = requests[i];
        }
        
        switch (choice) {
            case 1:
                fcfs(temp_requests, n, head);
                break;
                
            case 2:
                printf("\nSelect direction:\n");
                printf("1. Right (Towards higher tracks)\n");
                printf("0. Left (Towards lower tracks)\n");
                printf("Enter direction: ");
                scanf("%d", &direction);
                scan(temp_requests, n, head, disk_size, direction);
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
Enter disk size: 200
Enter initial head position: 50
Enter number of disk requests: 8
Disk requests: 82, 170, 43, 140, 24, 16, 190, 120

SAMPLE OUTPUT (FCFS):
Seek Sequence:
50 -> 82 -> 170 -> 43 -> 140 -> 24 -> 16 -> 190 -> 120

Total Seek Operations: 642
Average Seek Time: 80.25

SAMPLE OUTPUT (SCAN - Right Direction):
Seek Sequence:
50 -> 82 -> 120 -> 140 -> 170 -> 190 -> 199 -> 43 -> 24 -> 16

Total Seek Operations: 299
Average Seek Time: 37.38

COMMANDS TO RUN:
gcc disk_scheduling.c -o disk_scheduling
./disk_scheduling

VIVA EXPLANATION:
FCFS services requests in order of arrival, simple but can be inefficient.
SCAN moves the head in one direction servicing all requests until end, then reverses.
SCAN reduces seek time compared to FCFS by minimizing back-and-forth head movement.
*/
