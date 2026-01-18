#!/bin/bash

# ============================================================================
# Program: Fibonacci Series Generator
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 7(a)
# ============================================================================

# AIM:
# To write a shell script to generate first n Fibonacci numbers

# ALGORITHM:
# Step 1: Start
# Step 2: Read value of n from user
# Step 3: Initialize first two numbers: a=0, b=1
# Step 4: Print first two numbers
# Step 5: Use loop to generate next numbers
#         For i = 3 to n:
#         a) Calculate next = a + b
#         b) Print next
#         c) Update: a = b, b = next
# Step 6: Stop

# PROGRAM:

echo "=========================================="
echo "    FIBONACCI SERIES GENERATOR"
echo "=========================================="
echo

read -p "Enter number of terms : " n

# Check for valid input
if [ $n -le 0 ]; then
    echo
    echo "Error: Please enter a positive number"
    exit 1
fi

echo
echo "First $n terms of Fibonacci series:"
echo "=========================================="

# Initialize first two terms
a=0
b=1

# Print Fibonacci series
if [ $n -ge 1 ]; then
    echo -n "$a "
fi

if [ $n -ge 2 ]; then
    echo -n "$b "
fi

# Generate remaining terms
for ((i=3; i<=n; i++))
do
    next=$((a + b))
    echo -n "$next "
    a=$b
    b=$next
done

echo
echo "=========================================="

# SAMPLE INPUT:
# Enter number of terms : 10

# SAMPLE OUTPUT:
# First 10 terms of Fibonacci series:
# 0 1 1 2 3 5 8 13 21 34

# Explanation:
# Each number is the sum of the two preceding numbers
# 0, 1, 1 (0+1), 2 (1+1), 3 (1+2), 5 (2+3), 8 (3+5), etc.

# COMMANDS TO RUN:
# chmod +x fibonacci.sh
# ./fibonacci.sh

# VIVA EXPLANATION:
# Fibonacci series starts with 0 and 1, and each subsequent number is sum of previous two.
# This script uses two variables to track the last two numbers and generates the series.
# It's a famous mathematical sequence with applications in nature and computer science.
