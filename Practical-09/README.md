# Practical 9: Producer-Consumer Problem

## Aim
To write a C program to simulate the Producer-Consumer problem using Semaphores

## Theory
The Producer-Consumer problem is a classic synchronization problem where:
- Producer produces items and puts them in a buffer
- Consumer consumes items from the buffer
- Buffer has limited size
- Must prevent race conditions and ensure mutual exclusion

## Program Included
`producer_consumer.c` - Producer-Consumer simulation

## Commands to Compile and Run
```bash
gcc producer_consumer.c -o producer_consumer
./producer_consumer
```

## Viva Questions
1. What is the Producer-Consumer problem?
2. What are semaphores?
3. Why do we need synchronization?
4. What is a race condition?
5. What is mutual exclusion?
