#!/bin/bash

# ============================================================================
# Program: Print Natural Numbers
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 5(b)
# ============================================================================

# AIM:
# To write a shell script to print natural numbers from 1 to n

# ALGORITHM:
# Step 1: Start
# Step 2: Read value of n from user
# Step 3: Initialize counter i = 1
# Step 4: Use for loop from 1 to n
# Step 5: Print each number
# Step 6: Stop

# PROGRAM:

echo "=========================================="
echo "     PRINT NATURAL NUMBERS 1 TO N"
echo "=========================================="
echo

read -p "Enter the value of n : " n

# Check for valid input
if [ $n -le 0 ]; then
    echo
    echo "Error: Please enter a positive number"
    exit 1
fi

echo
echo "Natural numbers from 1 to $n:"
echo "=========================================="

# Print natural numbers using for loop
for ((i=1; i<=n; i++))
do
    echo -n "$i "
done

echo
echo "=========================================="

# SAMPLE INPUT:
# Enter the value of n : 10

# SAMPLE OUTPUT:
# Natural numbers from 1 to 10:
# 1 2 3 4 5 6 7 8 9 10

# COMMANDS TO RUN:
# chmod +x natural_numbers.sh
# ./natural_numbers.sh

# VIVA EXPLANATION:
# This script uses a for loop to iterate from 1 to n and prints each number.
# The echo -n option prints numbers on the same line without newline.
# Natural numbers are positive integers starting from 1.
