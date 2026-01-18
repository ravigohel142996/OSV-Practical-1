#!/bin/bash

# ============================================================================
# Program: Simple Interest Calculator
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 3(a)
# ============================================================================

# AIM:
# To write a shell script to calculate simple interest

# ALGORITHM:
# Step 1: Start
# Step 2: Read Principal amount, Rate of interest, and Time period
# Step 3: Calculate Simple Interest using formula: SI = (P * R * T) / 100
# Step 4: Display the calculated simple interest
# Step 5: Stop

# PROGRAM:

echo "=========================================="
echo "    SIMPLE INTEREST CALCULATOR"
echo "=========================================="
echo

# Reading input values
read -p "Enter Principal Amount (P) : " principal
read -p "Enter Rate of Interest (R) : " rate
read -p "Enter Time Period in Years (T) : " time

# Calculating Simple Interest: SI = (P * R * T) / 100
si=$(echo "scale=2; ($principal * $rate * $time) / 100" | bc)

# Calculating Total Amount: A = P + SI
amount=$(echo "scale=2; $principal + $si" | bc)

echo
echo "=========================================="
echo "           CALCULATION RESULT"
echo "=========================================="
echo "Principal Amount    : Rs. $principal"
echo "Rate of Interest    : $rate %"
echo "Time Period         : $time years"
echo "Simple Interest     : Rs. $si"
echo "Total Amount        : Rs. $amount"
echo "=========================================="

# SAMPLE INPUT:
# Enter Principal Amount (P) : 10000
# Enter Rate of Interest (R) : 5
# Enter Time Period in Years (T) : 2

# SAMPLE OUTPUT:
# Principal Amount    : Rs. 10000
# Rate of Interest    : 5 %
# Time Period         : 2 years
# Simple Interest     : Rs. 1000.00
# Total Amount        : Rs. 11000.00

# COMMANDS TO RUN:
# chmod +x simple_interest.sh
# ./simple_interest.sh

# VIVA EXPLANATION:
# This script calculates simple interest using the formula SI = (P*R*T)/100.
# The bc command is used for floating-point arithmetic with scale=2 for two decimal places.
# It also calculates the total amount by adding principal and interest.
