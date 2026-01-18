#!/bin/bash

# ============================================================================
# Program: Case Converter using awk
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 7(b)
# ============================================================================

# AIM:
# To write a shell script to convert lowercase to uppercase and vice versa using awk

# ALGORITHM:
# Step 1: Start
# Step 2: Display menu for conversion choice
# Step 3: Read user's choice
# Step 4: Read input string
# Step 5: Use awk with toupper() or tolower() function based on choice
# Step 6: Display converted string
# Step 7: Stop

# PROGRAM:

echo "=========================================="
echo "     CASE CONVERTER USING AWK"
echo "=========================================="
echo

echo "Select conversion type:"
echo "1. Lowercase to Uppercase"
echo "2. Uppercase to Lowercase"
echo "=========================================="
read -p "Enter your choice (1-2) : " choice

echo

case $choice in
    1)
        read -p "Enter string in lowercase : " input
        echo
        echo "=========================================="
        echo "Original : $input"
        output=$(echo "$input" | awk '{print toupper($0)}')
        echo "Converted: $output"
        echo "=========================================="
        ;;
    
    2)
        read -p "Enter string in UPPERCASE : " input
        echo
        echo "=========================================="
        echo "Original : $input"
        output=$(echo "$input" | awk '{print tolower($0)}')
        echo "Converted: $output"
        echo "=========================================="
        ;;
    
    *)
        echo "Error: Invalid choice!"
        exit 1
        ;;
esac

# SAMPLE INPUT 1:
# Choice: 1
# Enter string: hello world

# SAMPLE OUTPUT 1:
# Original : hello world
# Converted: HELLO WORLD

# SAMPLE INPUT 2:
# Choice: 2
# Enter string: MARWADI UNIVERSITY

# SAMPLE OUTPUT 2:
# Original : MARWADI UNIVERSITY
# Converted: marwadi university

# COMMANDS TO RUN:
# chmod +x case_converter.sh
# ./case_converter.sh

# VIVA EXPLANATION:
# This script uses awk's built-in functions toupper() and tolower() for case conversion.
# awk is a powerful text processing tool that works line by line on input data.
# The $0 variable in awk represents the entire input line being processed.
