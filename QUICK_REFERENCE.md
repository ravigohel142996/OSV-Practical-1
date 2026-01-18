# OSV Practicals - Quick Reference Guide

## 📋 Complete Program List

### Shell Scripts (Bash) - Practicals 1-7

#### Practical 1: Introduction to Shell Scripting
- `welcome.sh` - Display welcome message
- `student_details.sh` - Accept and display student information

#### Practical 2: Arithmetic Operations
- `arithmetic.sh` - Basic arithmetic operations (+, -, *, /, %)
- `greater.sh` - Find greater of two numbers
- `smallest_largest.sh` - Find smallest and largest of three numbers

#### Practical 3: Mathematical Programs
- `simple_interest.sh` - Calculate simple interest (SI = P*R*T/100)
- `number_check.sh` - Check if number is positive, negative, or zero
- `marksheet.sh` - Generate student marksheet with grade and result

#### Practical 4: Menu-Driven Programs
- `file_operations.sh` - Menu for copy, move, delete files
- `calculator.sh` - Menu-driven calculator
- `weekdays.sh` - Display day name from number (1-7)

#### Practical 5: Loops
- `factorial.sh` - Calculate factorial using for loop
- `natural_numbers.sh` - Print numbers 1 to n
- `even_odd.sh` - Separate even and odd numbers using while loop

#### Practical 6: Number & String Manipulation
- `reverse_number.sh` - Reverse a number
- `prime_check.sh` - Check if number is prime
- `palindrome.sh` - Check if string/number is palindrome

#### Practical 7: Advanced Concepts
- `fibonacci.sh` - Generate Fibonacci series
- `case_converter.sh` - Convert case using awk

---

### C Programs - Practicals 8-14

#### Practical 8: CPU Scheduling
- `fcfs.c` - First Come First Serve scheduling
- `sjf.c` - Shortest Job First scheduling

#### Practical 9: Process Synchronization
- `producer_consumer.c` - Producer-Consumer problem with semaphores

#### Practical 10: Deadlock
- `dining_philosophers.c` - Dining Philosophers problem

#### Practical 11: Memory Management
- `memory_allocation.c` - First Fit, Best Fit, Worst Fit algorithms

#### Practical 12: Virtual Memory
- `page_replacement.c` - FIFO and LRU page replacement

#### Practical 13: File Systems
- `file_organization.c` - Single and Two level directory structures

#### Practical 14: Disk Scheduling
- `disk_scheduling.c` - FCFS and SCAN disk scheduling

---

## 🚀 Quick Start Commands

### Running Shell Scripts
```bash
cd Practical-XX
chmod +x script.sh
./script.sh
```

### Running C Programs
```bash
cd Practical-XX
gcc program.c -o program
./program
```

---

## 📊 Statistics

- **Total Practicals:** 14
- **Shell Scripts:** 21 programs
- **C Programs:** 10 programs
- **Total Files:** 31 executable programs + 15 README files
- **Lines of Code:** ~4000+ lines (including comments and documentation)

---

## 🎯 Key Concepts Covered

### Operating Systems Concepts:
1. **Process Management:** CPU scheduling, process synchronization
2. **Memory Management:** Contiguous allocation, paging
3. **File Systems:** Directory structures
4. **Disk Management:** Disk scheduling algorithms
5. **Synchronization:** Semaphores, mutual exclusion, deadlock

### Programming Skills:
1. **Bash Scripting:** Variables, loops, conditionals, functions
2. **C Programming:** Structures, arrays, algorithms
3. **Problem Solving:** Algorithm design and implementation
4. **Documentation:** Code comments, viva preparation

---

## 📝 Important Formulas

### Simple Interest
```
SI = (P × R × T) / 100
where P = Principal, R = Rate, T = Time
```

### CPU Scheduling
```
Waiting Time (WT) = Start Time - Arrival Time
Turnaround Time (TAT) = Completion Time - Arrival Time
Response Time = First Run Time - Arrival Time
```

### Memory Allocation
```
Internal Fragmentation = Allocated Size - Process Size
```

### Disk Scheduling
```
Total Seek Time = Sum of all head movements
Average Seek Time = Total Seek Time / Number of Requests
```

---

## 🔍 Viva Preparation Tips

### For Shell Scripts:
1. Know the difference between `[ ]` and `[[ ]]`
2. Understand arithmetic operators: `-eq`, `-gt`, `-lt`, `-ge`, `-le`, `-ne`
3. Know loop types: `for`, `while`, `until`
4. Understand `case` statement syntax
5. Know file test operators: `-f`, `-d`, `-e`, `-r`, `-w`, `-x`

### For C Programs:
1. Understand time complexity of algorithms
2. Know data structures used (arrays, structures)
3. Be ready to explain the algorithm step by step
4. Understand the real-world applications
5. Know advantages and disadvantages of each algorithm

---

## 💡 Common Viva Questions

### Shell Scripting:
1. What is shebang (#!/bin/bash)?
2. How to read user input in bash?
3. What is the use of bc command?
4. How to make a script executable?
5. What are command line arguments?

### CPU Scheduling:
1. What is convoy effect in FCFS?
2. Can SJF cause starvation?
3. What is preemptive vs non-preemptive?
4. What is context switching?

### Synchronization:
1. What is race condition?
2. What is critical section?
3. What are semaphores?
4. What is mutex?
5. What are the conditions for deadlock?

### Memory Management:
1. What is fragmentation?
2. Internal vs external fragmentation?
3. Which algorithm is fastest?
4. Which minimizes wasted space?

### Page Replacement:
1. What is a page fault?
2. What is thrashing?
3. What is Belady's anomaly?
4. Why is LRU better than FIFO?

### Disk Scheduling:
1. What is seek time?
2. What is rotational latency?
3. Why is SCAN better than FCFS?
4. What is C-SCAN?

---

## 📚 Study Resources

### Recommended Books:
1. "Operating System Concepts" by Silberschatz, Galvin, Gagne
2. "Modern Operating Systems" by Andrew S. Tanenbaum
3. "Unix Shell Programming" by Yashavant Kanetkar

### Online Resources:
1. GeeksforGeeks - Operating Systems
2. TutorialsPoint - Unix/Linux Shell Scripting
3. Linux man pages (`man bash`, `man gcc`)

---

## ✅ Pre-Lab Checklist

Before coming to lab:
- [ ] Read the practical aim and algorithm
- [ ] Understand the concept
- [ ] Review sample input/output
- [ ] Prepare questions for instructor
- [ ] Bring notebook for observations

---

## 🎓 Lab Examination Tips

1. **Understand, don't memorize:** Focus on logic, not syntax
2. **Practice regularly:** Run programs multiple times
3. **Test edge cases:** Try different inputs
4. **Comment your code:** Helps in explanation
5. **Be confident:** If you understand the logic, you can explain it

---

## 📞 Need Help?

If you encounter any issues:
1. Check the README.md in each practical folder
2. Review the comments in the code
3. Test with sample input provided
4. Consult your lab instructor
5. Refer to the course textbook

---

**Good Luck with Your Practicals! 🎉**

*Prepared for B.Tech CSE (AI & ML), Semester 4*  
*Marwadi University*
