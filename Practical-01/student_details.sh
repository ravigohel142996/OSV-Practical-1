#!/bin/bash

# ============================================================================
# Program: Student Details Management
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 1(b)
# ============================================================================

# AIM:
# To write a shell script to accept and display details of two students
# Details include: Name, Roll No, Class, Branch, Batch, City, CGPA

# ALGORITHM:
# Step 1: Start
# Step 2: Display prompt for Student 1 details
# Step 3: Read Name, Roll No, Class, Branch, Batch, City, CGPA for Student 1
# Step 4: Display prompt for Student 2 details
# Step 5: Read Name, Roll No, Class, Branch, Batch, City, CGPA for Student 2
# Step 6: Display all stored details in formatted manner
# Step 7: Stop

# PROGRAM:

echo "=========================================="
echo "   STUDENT INFORMATION SYSTEM"
echo "=========================================="
echo

# Reading Student 1 details
echo "Enter details of Student 1:"
echo "----------------------------"
read -p "Name    : " name1
read -p "Roll No : " roll1
read -p "Class   : " class1
read -p "Branch  : " branch1
read -p "Batch   : " batch1
read -p "City    : " city1
read -p "CGPA    : " cgpa1

echo

# Reading Student 2 details
echo "Enter details of Student 2:"
echo "----------------------------"
read -p "Name    : " name2
read -p "Roll No : " roll2
read -p "Class   : " class2
read -p "Branch  : " branch2
read -p "Batch   : " batch2
read -p "City    : " city2
read -p "CGPA    : " cgpa2

echo
echo "=========================================="
echo "        STUDENT DETAILS"
echo "=========================================="
echo

# Displaying Student 1 details
echo "Student 1 Information:"
echo "----------------------"
echo "Name    : $name1"
echo "Roll No : $roll1"
echo "Class   : $class1"
echo "Branch  : $branch1"
echo "Batch   : $batch1"
echo "City    : $city1"
echo "CGPA    : $cgpa1"

echo

# Displaying Student 2 details
echo "Student 2 Information:"
echo "----------------------"
echo "Name    : $name2"
echo "Roll No : $roll2"
echo "Class   : $class2"
echo "Branch  : $branch2"
echo "Batch   : $batch2"
echo "City    : $city2"
echo "CGPA    : $cgpa2"

echo
echo "=========================================="

# SAMPLE INPUT:
# Student 1:
# Name: Ravi Kumar
# Roll No: 101
# Class: B.Tech
# Branch: CSE (AI & ML)
# Batch: 2024
# City: Rajkot
# CGPA: 8.5
#
# Student 2:
# Name: Priya Sharma
# Roll No: 102
# Class: B.Tech
# Branch: CSE (AI & ML)
# Batch: 2024
# City: Ahmedabad
# CGPA: 9.0

# SAMPLE OUTPUT:
# (Displays formatted student details as shown above)

# COMMANDS TO RUN:
# chmod +x student_details.sh
# ./student_details.sh

# VIVA EXPLANATION:
# This script demonstrates the use of read command to accept user input.
# Variables store the input values which are then displayed in a formatted way.
# The read -p option is used to display prompt and read input in a single line.
