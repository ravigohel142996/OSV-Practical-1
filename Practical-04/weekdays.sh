#!/bin/bash

# ============================================================================
# Program: Days of the Week
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 4(c)
# ============================================================================

# AIM:
# To write a shell script to print days of the week using case statement

# ALGORITHM:
# Step 1: Start
# Step 2: Read a number (1-7) from user
# Step 3: Use case statement to match the number
# Step 4: Display corresponding day name
# Step 5: If number is invalid, display error message
# Step 6: Stop

# PROGRAM:

echo "=========================================="
echo "        DAYS OF THE WEEK"
echo "=========================================="
echo

read -p "Enter a number (1-7) : " day

echo
echo "=========================================="

case $day in
    1)
        echo "Day: Monday"
        ;;
    2)
        echo "Day: Tuesday"
        ;;
    3)
        echo "Day: Wednesday"
        ;;
    4)
        echo "Day: Thursday"
        ;;
    5)
        echo "Day: Friday"
        ;;
    6)
        echo "Day: Saturday"
        ;;
    7)
        echo "Day: Sunday"
        ;;
    *)
        echo "Error: Invalid input! Please enter a number between 1 and 7"
        ;;
esac

echo "=========================================="

# SAMPLE INPUT:
# Enter a number (1-7) : 5

# SAMPLE OUTPUT:
# Day: Friday

# COMMANDS TO RUN:
# chmod +x weekdays.sh
# ./weekdays.sh

# VIVA EXPLANATION:
# This script uses case statement to map numbers (1-7) to corresponding weekday names.
# Case statement provides a cleaner alternative to multiple if-else conditions.
# The * pattern acts as default case for invalid inputs.
