#!/bin/bash

# ============================================================================
# Program: Palindrome Checker
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 6(c)
# ============================================================================

# AIM:
# To write a shell script to check if a string or number is palindrome

# ALGORITHM:
# Step 1: Start
# Step 2: Read input (string or number) from user
# Step 3: Reverse the input
# Step 4: Compare original with reversed value
# Step 5: If they are same, it's a palindrome
# Step 6: Display the result
# Step 7: Stop

# PROGRAM:

echo "=========================================="
echo "       PALINDROME CHECKER"
echo "=========================================="
echo

read -p "Enter a string or number : " input

# Remove spaces and convert to lowercase for string comparison
input_cleaned=$(echo "$input" | tr -d ' ' | tr '[:upper:]' '[:lower:]')

# Reverse the input
reversed=$(echo "$input_cleaned" | rev)

echo
echo "=========================================="
echo "Original : $input"
echo "Reversed : $reversed"
echo "=========================================="

# Check if palindrome
if [ "$input_cleaned" == "$reversed" ]; then
    echo "Result: '$input' is a PALINDROME"
else
    echo "Result: '$input' is NOT a palindrome"
fi

echo "=========================================="

# SAMPLE INPUT 1:
# Enter a string or number : 12321

# SAMPLE OUTPUT 1:
# Original : 12321
# Reversed : 12321
# Result: '12321' is a PALINDROME

# SAMPLE INPUT 2:
# Enter a string or number : madam

# SAMPLE OUTPUT 2:
# Original : madam
# Reversed : madam
# Result: 'madam' is a PALINDROME

# SAMPLE INPUT 3:
# Enter a string or number : hello

# SAMPLE OUTPUT 3:
# Original : hello
# Reversed : olleh
# Result: 'hello' is NOT a palindrome

# COMMANDS TO RUN:
# chmod +x palindrome.sh
# ./palindrome.sh

# VIVA EXPLANATION:
# A palindrome reads the same forwards and backwards (e.g., 121, madam, radar).
# This script uses the 'rev' command to reverse the input and compares it with original.
# It handles both strings and numbers, ignoring spaces and case differences.
