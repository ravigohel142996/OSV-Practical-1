# Practical 8: CPU Scheduling Algorithms

## Aim
To write C programs to simulate CPU Scheduling Algorithms:
- First Come First Serve (FCFS)
- Shortest Job First (SJF)

## Theory
CPU Scheduling is the basis of multiprogramming. The OS decides which process gets the CPU when multiple processes are ready. The scheduling algorithm determines the order of execution.

## Programs Included
1. `fcfs.c` - First Come First Serve scheduling
2. `sjf.c` - Shortest Job First scheduling

## Commands to Compile and Run
```bash
gcc fcfs.c -o fcfs
./fcfs

gcc sjf.c -o sjf
./sjf
```

## Viva Questions
1. What is CPU scheduling?
2. What is the difference between FCFS and SJF?
3. What is turnaround time and waiting time?
4. What is convoy effect in FCFS?
5. What is the advantage of SJF over FCFS?
