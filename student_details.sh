#!/bin/bash

echo "Enter details of Student 1"
read -p "Name: " name1
read -p "Roll No: " roll1
read -p "Class: " class1
read -p "Branch: " branch1
read -p "Batch: " batch1
read -p "City: " city1
read -p "CGPA: " cgpa1

echo
echo "Enter details of Student 2"
read -p "Name: " name2
read -p "Roll No: " roll2
read -p "Class: " class2
read -p "Branch: " branch2
read -p "Batch: " batch2
read -p "City: " city2
read -p "CGPA: " cgpa2

echo
echo "-------- STUDENT DETAILS --------"

echo "Student 1:"
echo "Name   : $name1"
echo "Roll No: $roll1"
echo "Class  : $class1"
echo "Branch : $branch1"
echo "Batch  : $batch1"
echo "City   : $city1"
echo "CGPA   : $cgpa1"

echo
echo "Student 2:"
echo "Name   : $name2"
echo "Roll No: $roll2"
echo "Class  : $class2"
echo "Branch : $branch2"
echo "Batch  : $batch2"
echo "City   : $city2"
echo "CGPA   : $cgpa2"
