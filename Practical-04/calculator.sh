#!/bin/bash

# ============================================================================
# Program: Menu-Driven Calculator
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 4(b)
# ============================================================================

# AIM:
# To write a menu-driven calculator using case statement

# ALGORITHM:
# Step 1: Start
# Step 2: Display menu with arithmetic operations
# Step 3: Read user choice
# Step 4: Read two numbers from user
# Step 5: Use case statement to perform selected operation
# Step 6: Display result
# Step 7: Repeat until user chooses exit
# Step 8: Stop

# PROGRAM:

while true
do
    echo
    echo "=========================================="
    echo "         CALCULATOR MENU"
    echo "=========================================="
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Modulus"
    echo "6. Exit"
    echo "=========================================="
    read -p "Enter your choice [1-6] : " choice

    # Exit if user chooses option 6
    if [ $choice -eq 6 ]; then
        echo
        echo "Exiting calculator. Thank you!"
        exit 0
    fi

    # Read numbers for calculation
    if [ $choice -ge 1 ] && [ $choice -le 5 ]; then
        echo
        read -p "Enter first number  : " num1
        read -p "Enter second number : " num2
        echo
        echo "=========================================="
    fi

    case $choice in
        1)
            result=$((num1 + num2))
            echo "Result: $num1 + $num2 = $result"
            ;;
        
        2)
            result=$((num1 - num2))
            echo "Result: $num1 - $num2 = $result"
            ;;
        
        3)
            result=$((num1 * num2))
            echo "Result: $num1 * $num2 = $result"
            ;;
        
        4)
            if [ $num2 -eq 0 ]; then
                echo "Error: Cannot divide by zero"
            else
                result=$(echo "scale=2; $num1 / $num2" | bc)
                echo "Result: $num1 / $num2 = $result"
            fi
            ;;
        
        5)
            if [ $num2 -eq 0 ]; then
                echo "Error: Cannot find modulus with zero"
            else
                result=$((num1 % num2))
                echo "Result: $num1 % $num2 = $result"
            fi
            ;;
        
        *)
            echo
            echo "Error: Invalid choice! Please enter 1-6"
            ;;
    esac
    
    echo "=========================================="
done

# SAMPLE INPUT:
# Choice: 1
# First number: 25
# Second number: 15

# SAMPLE OUTPUT:
# Result: 25 + 15 = 40

# COMMANDS TO RUN:
# chmod +x calculator.sh
# ./calculator.sh

# VIVA EXPLANATION:
# This calculator uses case statement to perform different arithmetic operations.
# It runs in a loop until the user chooses to exit (option 6).
# Division by zero is handled with proper error checking.
