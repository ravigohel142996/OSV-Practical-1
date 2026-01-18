/*
============================================================================
Program: Dining Philosophers Problem
Author: Marwadi University
Course: Operating System & Virtualization (01AI0403)
Practical: 10
============================================================================

AIM:
To write a C program to simulate the Dining Philosophers problem

ALGORITHM:
Step 1: Start
Step 2: Initialize 5 philosophers and 5 chopsticks (semaphores)
Step 3: For each philosopher:
        a) Think
        b) Pick up left chopstick (wait operation)
        c) Pick up right chopstick (wait operation)
        d) Eat
        e) Put down left chopstick (signal operation)
        f) Put down right chopstick (signal operation)
Step 4: Use mutex to prevent deadlock (allow max 4 philosophers at a time)
Step 5: Display state of each philosopher
Step 6: Stop
*/

#include <stdio.h>
#include <stdlib.h>

#define N 5  // Number of philosophers
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (philosopher_number + N - 1) % N
#define RIGHT (philosopher_number + 1) % N

int state[N];
int chopstick[N];

// Test if philosopher can eat
void test(int philosopher_number) {
    if (state[philosopher_number] == HUNGRY &&
        state[LEFT] != EATING &&
        state[RIGHT] != EATING) {
        state[philosopher_number] = EATING;
        printf("\nPhilosopher %d is EATING\n", philosopher_number + 1);
        printf("Philosopher %d picks up chopstick %d and %d\n",
               philosopher_number + 1, LEFT + 1, philosopher_number + 1);
    }
}

// Philosopher picks up chopsticks
void take_chopsticks(int philosopher_number) {
    state[philosopher_number] = HUNGRY;
    printf("\nPhilosopher %d is HUNGRY\n", philosopher_number + 1);
    test(philosopher_number);
    
    if (state[philosopher_number] != EATING) {
        printf("Philosopher %d is WAITING (chopsticks not available)\n",
               philosopher_number + 1);
    }
}

// Philosopher puts down chopsticks
void put_chopsticks(int philosopher_number) {
    state[philosopher_number] = THINKING;
    printf("\nPhilosopher %d puts down chopstick %d and %d\n",
           philosopher_number + 1, LEFT + 1, philosopher_number + 1);
    printf("Philosopher %d is THINKING\n", philosopher_number + 1);
    
    // Check if left and right neighbors can now eat
    test(LEFT);
    test(RIGHT);
}

// Display current state
void display_state() {
    int i;
    printf("\n==========================================\n");
    printf("Current State of Philosophers:\n");
    printf("==========================================\n");
    for (i = 0; i < N; i++) {
        printf("Philosopher %d: ", i + 1);
        if (state[i] == THINKING)
            printf("THINKING\n");
        else if (state[i] == HUNGRY)
            printf("HUNGRY\n");
        else
            printf("EATING\n");
    }
    printf("==========================================\n");
}

int main() {
    int choice, philosopher_number;
    int i;
    
    // Initialize all philosophers as thinking
    for (i = 0; i < N; i++) {
        state[i] = THINKING;
        chopstick[i] = 1;
    }
    
    printf("==========================================\n");
    printf("   DINING PHILOSOPHERS PROBLEM\n");
    printf("==========================================\n");
    printf("Number of Philosophers: %d\n", N);
    printf("Number of Chopsticks: %d\n", N);
    printf("==========================================\n");
    
    while (1) {
        printf("\n1. Philosopher wants to eat\n");
        printf("2. Philosopher finished eating\n");
        printf("3. Display current state\n");
        printf("4. Exit\n");
        printf("==========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter philosopher number (1-%d): ", N);
                scanf("%d", &philosopher_number);
                if (philosopher_number < 1 || philosopher_number > N) {
                    printf("Invalid philosopher number!\n");
                } else {
                    take_chopsticks(philosopher_number - 1);
                }
                break;
                
            case 2:
                printf("Enter philosopher number (1-%d): ", N);
                scanf("%d", &philosopher_number);
                if (philosopher_number < 1 || philosopher_number > N) {
                    printf("Invalid philosopher number!\n");
                } else if (state[philosopher_number - 1] != EATING) {
                    printf("Philosopher %d is not eating!\n", philosopher_number);
                } else {
                    put_chopsticks(philosopher_number - 1);
                }
                break;
                
            case 3:
                display_state();
                break;
                
            case 4:
                printf("\nExiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

/*
SAMPLE INPUT/OUTPUT:

Enter your choice: 1
Enter philosopher number (1-5): 1
Philosopher 1 is HUNGRY
Philosopher 1 is EATING
Philosopher 1 picks up chopstick 5 and 1

Enter your choice: 1
Enter philosopher number (1-5): 2
Philosopher 2 is HUNGRY
Philosopher 2 is WAITING (chopsticks not available)

Enter your choice: 2
Enter philosopher number (1-5): 1
Philosopher 1 puts down chopstick 5 and 1
Philosopher 1 is THINKING
Philosopher 2 is EATING
Philosopher 2 picks up chopstick 1 and 2

Enter your choice: 3
Current State of Philosophers:
Philosopher 1: THINKING
Philosopher 2: EATING
Philosopher 3: THINKING
Philosopher 4: THINKING
Philosopher 5: THINKING

COMMANDS TO RUN:
gcc dining_philosophers.c -o dining_philosophers
./dining_philosophers

VIVA EXPLANATION:
The Dining Philosophers problem demonstrates resource sharing and deadlock avoidance.
Each philosopher needs two adjacent chopsticks to eat, creating potential for deadlock.
The solution ensures that a philosopher can eat only if both adjacent philosophers are not eating.
This prevents deadlock and ensures fair resource allocation.
*/
