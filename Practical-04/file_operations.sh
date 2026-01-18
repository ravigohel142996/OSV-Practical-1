#!/bin/bash

# ============================================================================
# Program: File Operations Menu
# Author: Marwadi University
# Course: Operating System & Virtualization (01AI0403)
# Practical: 4(a)
# ============================================================================

# AIM:
# To write a menu-driven shell script for file operations (copy, move, delete)

# ALGORITHM:
# Step 1: Start
# Step 2: Display menu with options: Copy, Move, Delete, Exit
# Step 3: Read user choice
# Step 4: Use case statement to execute selected operation
# Step 5: For copy: read source and destination, use cp command
# Step 6: For move: read source and destination, use mv command
# Step 7: For delete: read file name, use rm command
# Step 8: Repeat until user chooses exit
# Step 9: Stop

# PROGRAM:

while true
do
    echo
    echo "=========================================="
    echo "       FILE OPERATIONS MENU"
    echo "=========================================="
    echo "1. Copy File"
    echo "2. Move File"
    echo "3. Delete File"
    echo "4. Exit"
    echo "=========================================="
    read -p "Enter your choice [1-4] : " choice

    case $choice in
        1)
            echo
            echo "--- COPY FILE ---"
            read -p "Enter source file path      : " source
            read -p "Enter destination file path : " dest
            
            if [ -f "$source" ]; then
                cp "$source" "$dest"
                if [ $? -eq 0 ]; then
                    echo "Success: File copied from $source to $dest"
                else
                    echo "Error: Failed to copy file"
                fi
            else
                echo "Error: Source file does not exist"
            fi
            ;;
        
        2)
            echo
            echo "--- MOVE FILE ---"
            read -p "Enter source file path      : " source
            read -p "Enter destination file path : " dest
            
            if [ -f "$source" ]; then
                mv "$source" "$dest"
                if [ $? -eq 0 ]; then
                    echo "Success: File moved from $source to $dest"
                else
                    echo "Error: Failed to move file"
                fi
            else
                echo "Error: Source file does not exist"
            fi
            ;;
        
        3)
            echo
            echo "--- DELETE FILE ---"
            read -p "Enter file path to delete : " file
            
            if [ -f "$file" ]; then
                read -p "Are you sure? (y/n) : " confirm
                if [ "$confirm" == "y" ] || [ "$confirm" == "Y" ]; then
                    rm "$file"
                    if [ $? -eq 0 ]; then
                        echo "Success: File deleted"
                    else
                        echo "Error: Failed to delete file"
                    fi
                else
                    echo "Operation cancelled"
                fi
            else
                echo "Error: File does not exist"
            fi
            ;;
        
        4)
            echo
            echo "Exiting program. Thank you!"
            exit 0
            ;;
        
        *)
            echo
            echo "Error: Invalid choice! Please enter 1-4"
            ;;
    esac
done

# SAMPLE INPUT:
# Choice: 1
# Source: /home/user/file1.txt
# Destination: /home/user/backup/file1.txt

# SAMPLE OUTPUT:
# Success: File copied from /home/user/file1.txt to /home/user/backup/file1.txt

# COMMANDS TO RUN:
# chmod +x file_operations.sh
# ./file_operations.sh

# VIVA EXPLANATION:
# This script provides a menu-driven interface for file operations using case statement.
# It includes error checking to verify if files exist before performing operations.
# The while loop keeps the menu running until user chooses to exit.
