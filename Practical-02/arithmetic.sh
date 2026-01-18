#!/bin/bash

# ============================================================================
# Program: Arithmetic Operations
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 2(a)
# ============================================================================

# AIM:
# To write a shell script to perform arithmetic operations on two numbers

# ALGORITHM:
# Step 1: Start
# Step 2: Read two numbers from user
# Step 3: Perform addition, subtraction, multiplication, division, and modulus
# Step 4: Display all results
# Step 5: Stop

# PROGRAM:

echo "=========================================="
echo "     ARITHMETIC OPERATIONS"
echo "=========================================="
echo

# Reading two numbers
read -p "Enter first number  : " num1
read -p "Enter second number : " num2

echo
echo "=========================================="
echo "           RESULTS"
echo "=========================================="

# Performing arithmetic operations
add=$((num1 + num2))
sub=$((num1 - num2))
mul=$((num1 * num2))
mod=$((num1 % num2))

echo "Addition       : $num1 + $num2 = $add"
echo "Subtraction    : $num1 - $num2 = $sub"
echo "Multiplication : $num1 * $num2 = $mul"

# Check for division by zero
if [ $num2 -eq 0 ]; then
    echo "Division       : Cannot divide by zero"
else
    div=$((num1 / num2))
    echo "Division       : $num1 / $num2 = $div"
fi

# Check for modulus by zero
if [ $num2 -eq 0 ]; then
    echo "Modulus        : Cannot find modulus with zero"
else
    echo "Modulus        : $num1 % $num2 = $mod"
fi

echo "=========================================="

# SAMPLE INPUT:
# Enter first number  : 20
# Enter second number : 5

# SAMPLE OUTPUT:
# Addition       : 20 + 5 = 25
# Subtraction    : 20 - 5 = 15
# Multiplication : 20 * 5 = 100
# Division       : 20 / 5 = 4
# Modulus        : 20 % 5 = 0

# COMMANDS TO RUN:
# chmod +x arithmetic.sh
# ./arithmetic.sh

# VIVA EXPLANATION:
# This script demonstrates arithmetic operations using $(( )) syntax in bash.
# It performs five basic operations: addition, subtraction, multiplication, division, and modulus.
# Division by zero is handled with a conditional check.
