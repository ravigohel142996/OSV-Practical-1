#!/bin/bash

# ============================================================================
# Program: Check Number Type
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 3(b)
# ============================================================================

# AIM:
# To write a shell script to check if a number is Positive, Negative or Zero

# ALGORITHM:
# Step 1: Start
# Step 2: Read a number from user
# Step 3: Check if number is greater than 0 (Positive)
# Step 4: Else check if number is less than 0 (Negative)
# Step 5: Else the number is Zero
# Step 6: Display the result
# Step 7: Stop

# PROGRAM:

echo "=========================================="
echo "     NUMBER TYPE CHECKER"
echo "=========================================="
echo

# Reading number from user
read -p "Enter a number : " num

echo
echo "=========================================="

# Checking if number is positive, negative or zero
if [ $num -gt 0 ]; then
    echo "Result: $num is a POSITIVE number"
elif [ $num -lt 0 ]; then
    echo "Result: $num is a NEGATIVE number"
else
    echo "Result: The number is ZERO"
fi

echo "=========================================="

# SAMPLE INPUT 1:
# Enter a number : 45

# SAMPLE OUTPUT 1:
# Result: 45 is a POSITIVE number

# SAMPLE INPUT 2:
# Enter a number : -23

# SAMPLE OUTPUT 2:
# Result: -23 is a NEGATIVE number

# SAMPLE INPUT 3:
# Enter a number : 0

# SAMPLE OUTPUT 3:
# Result: The number is ZERO

# COMMANDS TO RUN:
# chmod +x number_check.sh
# ./number_check.sh

# VIVA EXPLANATION:
# This script uses if-elif-else to categorize a number as positive, negative, or zero.
# The -gt operator checks if number > 0, -lt checks if number < 0.
# If neither condition is true, the number must be zero.
