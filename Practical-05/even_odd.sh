#!/bin/bash

# ============================================================================
# Program: Print Even and Odd Numbers
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 5(c)
# ============================================================================

# AIM:
# To write a shell script to print even and odd numbers from 1 to n using while loop

# ALGORITHM:
# Step 1: Start
# Step 2: Read value of n from user
# Step 3: Initialize counter i = 1
# Step 4: Use while loop from 1 to n
# Step 5: Check if number is even (i % 2 == 0) or odd
# Step 6: Store in respective lists
# Step 7: Display even and odd numbers separately
# Step 8: Stop

# PROGRAM:

echo "=========================================="
echo "      EVEN AND ODD NUMBERS (1 TO N)"
echo "=========================================="
echo

read -p "Enter the value of n : " n

# Check for valid input
if [ $n -le 0 ]; then
    echo
    echo "Error: Please enter a positive number"
    exit 1
fi

# Initialize variables
even_nums=""
odd_nums=""
i=1

# Separate even and odd numbers using while loop
while [ $i -le $n ]
do
    if [ $((i % 2)) -eq 0 ]; then
        even_nums="$even_nums$i "
    else
        odd_nums="$odd_nums$i "
    fi
    i=$((i + 1))
done

echo
echo "=========================================="
echo "Even numbers from 1 to $n:"
echo "$even_nums"
echo
echo "Odd numbers from 1 to $n:"
echo "$odd_nums"
echo "=========================================="

# SAMPLE INPUT:
# Enter the value of n : 15

# SAMPLE OUTPUT:
# Even numbers from 1 to 15:
# 2 4 6 8 10 12 14
#
# Odd numbers from 1 to 15:
# 1 3 5 7 9 11 13 15

# COMMANDS TO RUN:
# chmod +x even_odd.sh
# ./even_odd.sh

# VIVA EXPLANATION:
# This script uses while loop to iterate through numbers and modulus operator to check even/odd.
# A number is even if divisible by 2 (remainder = 0), otherwise it's odd.
# The results are collected in separate strings and displayed at the end.
