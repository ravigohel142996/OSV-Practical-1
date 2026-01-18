# Practical 12: Page Replacement Algorithms

## Aim
To write a C program to simulate Page Replacement Algorithms:
- FIFO (First In First Out)
- LRU (Least Recently Used)

## Theory
Page replacement algorithms are used in virtual memory management. When a page fault occurs and all frames are occupied, the OS must select a page to replace. Different algorithms have different performance characteristics.

## Program Included
`page_replacement.c` - Page replacement simulation

## Commands to Compile and Run
```bash
gcc page_replacement.c -o page_replacement
./page_replacement
```

## Viva Questions
1. What is a page fault?
2. What is virtual memory?
3. Explain FIFO page replacement
4. Explain LRU page replacement
5. What is Belady's anomaly?
