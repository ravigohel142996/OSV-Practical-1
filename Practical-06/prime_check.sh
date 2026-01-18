#!/bin/bash

# ============================================================================
# Program: Prime Number Checker
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 6(b)
# ============================================================================

# AIM:
# To write a shell script to check if a number is prime

# ALGORITHM:
# Step 1: Start
# Step 2: Read a number from user
# Step 3: If number <= 1, it's not prime
# Step 4: If number == 2, it's prime
# Step 5: Check divisibility from 2 to sqrt(number)
# Step 6: If divisible by any number, it's not prime
# Step 7: Otherwise, it's prime
# Step 8: Stop

# PROGRAM:

echo "=========================================="
echo "       PRIME NUMBER CHECKER"
echo "=========================================="
echo

read -p "Enter a number : " num

echo
echo "=========================================="

# Check for numbers less than or equal to 1
if [ $num -le 1 ]; then
    echo "$num is NOT a prime number"
    echo "(Numbers less than or equal to 1 are not prime)"
    echo "=========================================="
    exit 0
fi

# Check for 2 (the only even prime number)
if [ $num -eq 2 ]; then
    echo "$num is a PRIME number"
    echo "=========================================="
    exit 0
fi

# Check for even numbers
if [ $((num % 2)) -eq 0 ]; then
    echo "$num is NOT a prime number"
    echo "(Even numbers greater than 2 are not prime)"
    echo "=========================================="
    exit 0
fi

# Check for divisibility from 3 to sqrt(num)
flag=0
for ((i=3; i*i<=num; i+=2))
do
    if [ $((num % i)) -eq 0 ]; then
        flag=1
        break
    fi
done

if [ $flag -eq 1 ]; then
    echo "$num is NOT a prime number"
else
    echo "$num is a PRIME number"
fi

echo "=========================================="

# SAMPLE INPUT 1:
# Enter a number : 17

# SAMPLE OUTPUT 1:
# 17 is a PRIME number

# SAMPLE INPUT 2:
# Enter a number : 24

# SAMPLE OUTPUT 2:
# 24 is NOT a prime number

# COMMANDS TO RUN:
# chmod +x prime_check.sh
# ./prime_check.sh

# VIVA EXPLANATION:
# A prime number is divisible only by 1 and itself (e.g., 2, 3, 5, 7, 11).
# This script checks divisibility up to square root of the number for efficiency.
# If no divisor is found, the number is prime; otherwise, it's composite.
