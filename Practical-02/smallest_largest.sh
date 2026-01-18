#!/bin/bash

# ============================================================================
# Program: Find Smallest and Largest of Three Numbers
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 2(c)
# ============================================================================

# AIM:
# To write a shell script to find smallest and largest of three numbers

# ALGORITHM:
# Step 1: Start
# Step 2: Read three numbers from user
# Step 3: Assume first number as both smallest and largest
# Step 4: Compare with second number and update smallest/largest if needed
# Step 5: Compare with third number and update smallest/largest if needed
# Step 6: Display the smallest and largest numbers
# Step 7: Stop

# PROGRAM:

echo "=========================================="
echo "  FIND SMALLEST & LARGEST OF 3 NUMBERS"
echo "=========================================="
echo

# Reading three numbers
read -p "Enter first number  : " num1
read -p "Enter second number : " num2
read -p "Enter third number  : " num3

# Initialize smallest and largest with first number
smallest=$num1
largest=$num1

# Compare with second number
if [ $num2 -lt $smallest ]; then
    smallest=$num2
fi
if [ $num2 -gt $largest ]; then
    largest=$num2
fi

# Compare with third number
if [ $num3 -lt $smallest ]; then
    smallest=$num3
fi
if [ $num3 -gt $largest ]; then
    largest=$num3
fi

echo
echo "=========================================="
echo "Smallest number : $smallest"
echo "Largest number  : $largest"
echo "=========================================="

# SAMPLE INPUT:
# Enter first number  : 25
# Enter second number : 67
# Enter third number  : 12

# SAMPLE OUTPUT:
# Smallest number : 12
# Largest number  : 67

# COMMANDS TO RUN:
# chmod +x smallest_largest.sh
# ./smallest_largest.sh

# VIVA EXPLANATION:
# This script finds the smallest and largest numbers by comparing each number sequentially.
# It uses -lt (less than) and -gt (greater than) operators for comparison.
# Variables are updated when a smaller or larger value is found.
