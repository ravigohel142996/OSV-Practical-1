#!/bin/bash

# ============================================================================
# Program: Find Greater of Two Numbers
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 2(b)
# ============================================================================

# AIM:
# To write a shell script to find the greater of two numbers

# ALGORITHM:
# Step 1: Start
# Step 2: Read two numbers from user
# Step 3: Compare the numbers using if-else
# Step 4: Display the greater number or if they are equal
# Step 5: Stop

# PROGRAM:

echo "=========================================="
echo "   FIND GREATER OF TWO NUMBERS"
echo "=========================================="
echo

# Reading two numbers
read -p "Enter first number  : " num1
read -p "Enter second number : " num2

echo
echo "=========================================="

# Comparing numbers
if [ $num1 -gt $num2 ]; then
    echo "Result: $num1 is greater than $num2"
elif [ $num1 -lt $num2 ]; then
    echo "Result: $num2 is greater than $num1"
else
    echo "Result: Both numbers are equal"
fi

echo "=========================================="

# SAMPLE INPUT:
# Enter first number  : 45
# Enter second number : 23

# SAMPLE OUTPUT:
# Result: 45 is greater than 23

# COMMANDS TO RUN:
# chmod +x greater.sh
# ./greater.sh

# VIVA EXPLANATION:
# This script uses if-elif-else statement to compare two numbers.
# The -gt operator checks if first number is greater, -lt checks if it's less.
# If neither condition is true, the numbers are equal.
