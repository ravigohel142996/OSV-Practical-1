#!/bin/bash

# ============================================================================
# Program: Reverse a Number
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 6(a)
# ============================================================================

# AIM:
# To write a shell script to reverse a number

# ALGORITHM:
# Step 1: Start
# Step 2: Read a number from user
# Step 3: Initialize reverse = 0
# Step 4: While number > 0
#         a) Extract last digit: digit = number % 10
#         b) Add to reverse: reverse = reverse * 10 + digit
#         c) Remove last digit: number = number / 10
# Step 5: Display the reversed number
# Step 6: Stop

# PROGRAM:

echo "=========================================="
echo "         REVERSE A NUMBER"
echo "=========================================="
echo

read -p "Enter a number : " num

# Store original number
original=$num

# Initialize reverse
reverse=0

# Reverse the number
while [ $num -gt 0 ]
do
    digit=$((num % 10))
    reverse=$((reverse * 10 + digit))
    num=$((num / 10))
done

echo
echo "=========================================="
echo "Original number : $original"
echo "Reversed number : $reverse"
echo "=========================================="

# SAMPLE INPUT:
# Enter a number : 12345

# SAMPLE OUTPUT:
# Original number : 12345
# Reversed number : 54321

# COMMANDS TO RUN:
# chmod +x reverse_number.sh
# ./reverse_number.sh

# VIVA EXPLANATION:
# This script reverses a number by extracting digits from right to left using modulus.
# Each digit is added to the reversed number after multiplying previous result by 10.
# The original number is progressively divided by 10 to remove processed digits.
