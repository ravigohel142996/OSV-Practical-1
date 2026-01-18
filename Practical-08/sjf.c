/*
============================================================================
Program: Shortest Job First (SJF) CPU Scheduling
Author: Marwadi University
Course: Operating System & Virtualization (01AI0403)
Practical: 8(b)
============================================================================

AIM:
To write a C program to simulate SJF (non-preemptive) CPU scheduling algorithm

ALGORITHM:
Step 1: Start
Step 2: Read number of processes
Step 3: Read burst time for each process
Step 4: Sort processes based on burst time (shortest first)
Step 5: Calculate waiting time for each process
        - First process waiting time = 0
        - For others: WT[i] = WT[i-1] + BT[i-1]
Step 6: Calculate turnaround time for each process
        - TAT[i] = WT[i] + BT[i]
Step 7: Calculate average waiting time and turnaround time
Step 8: Display the results
Step 9: Stop
*/

#include <stdio.h>

// Structure to store process information
struct Process {
    int pid;        // Process ID
    int burst_time; // Burst Time
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n, i, j;
    float avg_wt = 0, avg_tat = 0;
    struct Process temp;
    
    printf("==========================================\n");
    printf("    SJF CPU SCHEDULING ALGORITHM\n");
    printf("==========================================\n\n");
    
    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct Process p[n];
    
    // Input burst time for each process
    printf("\nEnter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process P%d: ", i + 1);
        scanf("%d", &p[i].burst_time);
    }
    
    // Sort processes by burst time (Shortest Job First)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].burst_time > p[j].burst_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    
    // Calculate waiting time
    p[0].waiting_time = 0;  // First process has 0 waiting time
    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    }
    
    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        avg_wt += p[i].waiting_time;
        avg_tat += p[i].turnaround_time;
    }
    
    // Calculate averages
    avg_wt /= n;
    avg_tat /= n;
    
    // Display results
    printf("\n==========================================\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("==========================================\n");
    
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", 
               p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    
    printf("==========================================\n");
    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("==========================================\n");
    
    return 0;
}

/*
SAMPLE INPUT:
Enter number of processes: 4
Process P1: 6
Process P2: 2
Process P3: 8
Process P4: 3

SAMPLE OUTPUT:
(After sorting by burst time)
Process	Burst Time	Waiting Time	Turnaround Time
P2	2		0		2
P4	3		2		5
P1	6		5		11
P3	8		11		19

Average Waiting Time: 4.50
Average Turnaround Time: 9.25

COMMANDS TO RUN:
gcc sjf.c -o sjf
./sjf

VIVA EXPLANATION:
SJF scheduling selects the process with the smallest burst time for execution next.
It minimizes average waiting time and is optimal for non-preemptive scheduling.
However, it can cause starvation for longer processes if short processes keep arriving.
*/
