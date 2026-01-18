/*
============================================================================
Program: First Come First Serve (FCFS) CPU Scheduling
Author: Marwadi University
Course: Operating System & Virtualization (01AI0403)
Practical: 8(a)
============================================================================

AIM:
To write a C program to simulate FCFS CPU scheduling algorithm

ALGORITHM:
Step 1: Start
Step 2: Read number of processes
Step 3: Read burst time for each process
Step 4: Calculate waiting time for each process
        - First process waiting time = 0
        - For others: WT[i] = WT[i-1] + BT[i-1]
Step 5: Calculate turnaround time for each process
        - TAT[i] = WT[i] + BT[i]
Step 6: Calculate average waiting time and turnaround time
Step 7: Display the results
Step 8: Stop
*/

#include <stdio.h>

int main() {
    int n, i;
    float avg_wt = 0, avg_tat = 0;
    
    printf("==========================================\n");
    printf("   FCFS CPU SCHEDULING ALGORITHM\n");
    printf("==========================================\n\n");
    
    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int burst_time[n], waiting_time[n], turnaround_time[n];
    
    // Input burst time for each process
    printf("\nEnter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    
    // Calculate waiting time
    waiting_time[0] = 0;  // First process has 0 waiting time
    for (i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }
    
    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        avg_wt += waiting_time[i];
        avg_tat += turnaround_time[i];
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
               i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
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
Process P1: 5
Process P2: 3
Process P3: 8
Process P4: 6

SAMPLE OUTPUT:
Process	Burst Time	Waiting Time	Turnaround Time
P1	5		0		5
P2	3		5		8
P3	8		8		16
P4	6		16		22

Average Waiting Time: 7.25
Average Turnaround Time: 12.75

COMMANDS TO RUN:
gcc fcfs.c -o fcfs
./fcfs

VIVA EXPLANATION:
FCFS is the simplest scheduling algorithm where processes are executed in order of arrival.
Waiting time increases for later processes, which can lead to convoy effect.
It's non-preemptive and easy to implement but not optimal for short jobs.
*/
