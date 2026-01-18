#!/bin/bash

# ============================================================================
# Program: Factorial Calculator
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 5(a)
# ============================================================================

# AIM:
# To write a shell script to find factorial of a number

# ALGORITHM:
# Step 1: Start
# Step 2: Read a number from user
# Step 3: Initialize factorial = 1
# Step 4: Use for loop from 1 to n
# Step 5: Multiply factorial with each number
# Step 6: Display the factorial result
# Step 7: Stop

# PROGRAM:

echo "=========================================="
echo "       FACTORIAL CALCULATOR"
echo "=========================================="
echo

read -p "Enter a number : " num

# Check for negative number
if [ $num -lt 0 ]; then
    echo
    echo "Error: Factorial of negative number doesn't exist"
    exit 1
fi

# Initialize factorial
fact=1

# Calculate factorial using for loop
for ((i=1; i<=num; i++))
do
    fact=$((fact * i))
done

echo
echo "=========================================="
echo "Factorial of $num = $fact"
echo "=========================================="

# SAMPLE INPUT:
# Enter a number : 5

# SAMPLE OUTPUT:
# Factorial of 5 = 120

# Explanation: 5! = 5 × 4 × 3 × 2 × 1 = 120

# COMMANDS TO RUN:
# chmod +x factorial.sh
# ./factorial.sh

# VIVA EXPLANATION:
# This script calculates factorial using a for loop that multiplies numbers from 1 to n.
# Factorial of n (n!) is the product of all positive integers less than or equal to n.
# Special case: 0! = 1 by definition.
