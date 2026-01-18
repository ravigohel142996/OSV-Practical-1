#!/bin/bash

# ============================================================================
# Program: Student Marksheet Generator
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 3(c)
# ============================================================================

# AIM:
# To write a shell script to generate student marksheet for 3 subjects

# ALGORITHM:
# Step 1: Start
# Step 2: Read student details (Name, Roll No)
# Step 3: Read marks for 3 subjects
# Step 4: Calculate total marks and percentage
# Step 5: Determine grade based on percentage
# Step 6: Determine result (Pass/Fail - Pass if all subjects >= 40)
# Step 7: Display complete marksheet
# Step 8: Stop

# PROGRAM:

echo "=========================================="
echo "    STUDENT MARKSHEET GENERATOR"
echo "=========================================="
echo

# Reading student details
read -p "Enter Student Name : " name
read -p "Enter Roll Number  : " rollno

echo
echo "Enter marks for three subjects (out of 100):"
read -p "Subject 1 : " marks1
read -p "Subject 2 : " marks2
read -p "Subject 3 : " marks3

# Calculate total and percentage
total=$((marks1 + marks2 + marks3))
percentage=$(echo "scale=2; ($total * 100) / 300" | bc)

# Determine grade based on percentage
if (( $(echo "$percentage >= 90" | bc -l) )); then
    grade="A+"
elif (( $(echo "$percentage >= 80" | bc -l) )); then
    grade="A"
elif (( $(echo "$percentage >= 70" | bc -l) )); then
    grade="B+"
elif (( $(echo "$percentage >= 60" | bc -l) )); then
    grade="B"
elif (( $(echo "$percentage >= 50" | bc -l) )); then
    grade="C"
elif (( $(echo "$percentage >= 40" | bc -l) )); then
    grade="D"
else
    grade="F"
fi

# Determine result (Pass if all subjects >= 40)
if [ $marks1 -ge 40 ] && [ $marks2 -ge 40 ] && [ $marks3 -ge 40 ]; then
    result="PASS"
else
    result="FAIL"
fi

# Display Marksheet
echo
echo "=========================================="
echo "           MARKSHEET"
echo "=========================================="
echo "Student Name   : $name"
echo "Roll Number    : $rollno"
echo "=========================================="
echo "Subject 1      : $marks1"
echo "Subject 2      : $marks2"
echo "Subject 3      : $marks3"
echo "=========================================="
echo "Total Marks    : $total / 300"
echo "Percentage     : $percentage %"
echo "Grade          : $grade"
echo "Result         : $result"
echo "=========================================="

# SAMPLE INPUT:
# Enter Student Name : Ravi Kumar
# Enter Roll Number  : 101
# Subject 1 : 85
# Subject 2 : 92
# Subject 3 : 78

# SAMPLE OUTPUT:
# Student Name   : Ravi Kumar
# Roll Number    : 101
# Subject 1      : 85
# Subject 2      : 92
# Subject 3      : 78
# Total Marks    : 255 / 300
# Percentage     : 85.00 %
# Grade          : A
# Result         : PASS

# COMMANDS TO RUN:
# chmod +x marksheet.sh
# ./marksheet.sh

# VIVA EXPLANATION:
# This script generates a complete student marksheet with grade and result.
# It calculates percentage using bc for decimal precision and assigns grade based on ranges.
# Student passes only if all three subjects have marks >= 40 (no backlog).
