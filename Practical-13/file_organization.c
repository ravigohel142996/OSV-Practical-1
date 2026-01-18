/*
============================================================================
Program: File Organization (Single Level and Two Level Directory)
Author: Marwadi University
Course: Operating System & Virtualization (01AI0403)
Practical: 13
============================================================================

AIM:
To write a C program to simulate single level and two level directory structures

ALGORITHM:

Single Level Directory:
- All files are stored in a single directory
- Simple but no organization
- File names must be unique

Two Level Directory:
- Master File Directory (MFD) contains User File Directories (UFD)
- Each user has their own directory
- Same file names can exist in different user directories
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILES 20
#define MAX_USERS 10

// Structure for single level directory
struct SingleLevel {
    char files[MAX_FILES][30];
    int file_count;
};

// Structure for two level directory
struct UserDirectory {
    char username[30];
    char files[MAX_FILES][30];
    int file_count;
};

struct TwoLevel {
    struct UserDirectory users[MAX_USERS];
    int user_count;
};

// Single Level Directory Functions
void single_level_menu(struct SingleLevel *dir);
void add_file_single(struct SingleLevel *dir);
void delete_file_single(struct SingleLevel *dir);
void search_file_single(struct SingleLevel *dir);
void display_files_single(struct SingleLevel *dir);

// Two Level Directory Functions
void two_level_menu(struct TwoLevel *dir);
void add_user(struct TwoLevel *dir);
void add_file_two(struct TwoLevel *dir);
void delete_file_two(struct TwoLevel *dir);
void search_file_two(struct TwoLevel *dir);
void display_directory_two(struct TwoLevel *dir);

// Single Level Directory Implementation
void add_file_single(struct SingleLevel *dir) {
    if (dir->file_count >= MAX_FILES) {
        printf("\nDirectory is full!\n");
        return;
    }
    
    char filename[30];
    int i;
    
    printf("\nEnter file name: ");
    scanf("%s", filename);
    
    // Check if file already exists
    for (i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i], filename) == 0) {
            printf("File already exists!\n");
            return;
        }
    }
    
    strcpy(dir->files[dir->file_count], filename);
    dir->file_count++;
    printf("File '%s' added successfully!\n", filename);
}

void delete_file_single(struct SingleLevel *dir) {
    char filename[30];
    int i, j, found = 0;
    
    printf("\nEnter file name to delete: ");
    scanf("%s", filename);
    
    for (i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i], filename) == 0) {
            found = 1;
            // Shift files
            for (j = i; j < dir->file_count - 1; j++) {
                strcpy(dir->files[j], dir->files[j + 1]);
            }
            dir->file_count--;
            printf("File '%s' deleted successfully!\n", filename);
            break;
        }
    }
    
    if (!found) {
        printf("File not found!\n");
    }
}

void search_file_single(struct SingleLevel *dir) {
    char filename[30];
    int i, found = 0;
    
    printf("\nEnter file name to search: ");
    scanf("%s", filename);
    
    for (i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i], filename) == 0) {
            printf("File '%s' found at position %d\n", filename, i + 1);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("File not found!\n");
    }
}

void display_files_single(struct SingleLevel *dir) {
    int i;
    
    printf("\n==========================================\n");
    printf("       SINGLE LEVEL DIRECTORY\n");
    printf("==========================================\n");
    
    if (dir->file_count == 0) {
        printf("Directory is empty!\n");
    } else {
        printf("Total files: %d\n\n", dir->file_count);
        for (i = 0; i < dir->file_count; i++) {
            printf("%d. %s\n", i + 1, dir->files[i]);
        }
    }
    printf("==========================================\n");
}

void single_level_menu(struct SingleLevel *dir) {
    int choice;
    
    while (1) {
        printf("\n--- SINGLE LEVEL DIRECTORY ---\n");
        printf("1. Add File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display All Files\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: add_file_single(dir); break;
            case 2: delete_file_single(dir); break;
            case 3: search_file_single(dir); break;
            case 4: display_files_single(dir); break;
            case 5: return;
            default: printf("Invalid choice!\n");
        }
    }
}

// Two Level Directory Implementation
void add_user(struct TwoLevel *dir) {
    if (dir->user_count >= MAX_USERS) {
        printf("\nMaximum users reached!\n");
        return;
    }
    
    char username[30];
    int i;
    
    printf("\nEnter username: ");
    scanf("%s", username);
    
    // Check if user already exists
    for (i = 0; i < dir->user_count; i++) {
        if (strcmp(dir->users[i].username, username) == 0) {
            printf("User already exists!\n");
            return;
        }
    }
    
    strcpy(dir->users[dir->user_count].username, username);
    dir->users[dir->user_count].file_count = 0;
    dir->user_count++;
    printf("User '%s' added successfully!\n", username);
}

void add_file_two(struct TwoLevel *dir) {
    char username[30], filename[30];
    int i, j, user_idx = -1;
    
    printf("\nEnter username: ");
    scanf("%s", username);
    
    // Find user
    for (i = 0; i < dir->user_count; i++) {
        if (strcmp(dir->users[i].username, username) == 0) {
            user_idx = i;
            break;
        }
    }
    
    if (user_idx == -1) {
        printf("User not found!\n");
        return;
    }
    
    if (dir->users[user_idx].file_count >= MAX_FILES) {
        printf("User directory is full!\n");
        return;
    }
    
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // Check if file exists in user's directory
    for (i = 0; i < dir->users[user_idx].file_count; i++) {
        if (strcmp(dir->users[user_idx].files[i], filename) == 0) {
            printf("File already exists in this user's directory!\n");
            return;
        }
    }
    
    strcpy(dir->users[user_idx].files[dir->users[user_idx].file_count], filename);
    dir->users[user_idx].file_count++;
    printf("File '%s' added to user '%s' directory!\n", filename, username);
}

void delete_file_two(struct TwoLevel *dir) {
    char username[30], filename[30];
    int i, j, user_idx = -1, found = 0;
    
    printf("\nEnter username: ");
    scanf("%s", username);
    
    // Find user
    for (i = 0; i < dir->user_count; i++) {
        if (strcmp(dir->users[i].username, username) == 0) {
            user_idx = i;
            break;
        }
    }
    
    if (user_idx == -1) {
        printf("User not found!\n");
        return;
    }
    
    printf("Enter file name to delete: ");
    scanf("%s", filename);
    
    for (i = 0; i < dir->users[user_idx].file_count; i++) {
        if (strcmp(dir->users[user_idx].files[i], filename) == 0) {
            found = 1;
            // Shift files
            for (j = i; j < dir->users[user_idx].file_count - 1; j++) {
                strcpy(dir->users[user_idx].files[j], dir->users[user_idx].files[j + 1]);
            }
            dir->users[user_idx].file_count--;
            printf("File '%s' deleted from user '%s' directory!\n", filename, username);
            break;
        }
    }
    
    if (!found) {
        printf("File not found in user's directory!\n");
    }
}

void search_file_two(struct TwoLevel *dir) {
    char username[30], filename[30];
    int i, user_idx = -1, found = 0;
    
    printf("\nEnter username: ");
    scanf("%s", username);
    
    // Find user
    for (i = 0; i < dir->user_count; i++) {
        if (strcmp(dir->users[i].username, username) == 0) {
            user_idx = i;
            break;
        }
    }
    
    if (user_idx == -1) {
        printf("User not found!\n");
        return;
    }
    
    printf("Enter file name to search: ");
    scanf("%s", filename);
    
    for (i = 0; i < dir->users[user_idx].file_count; i++) {
        if (strcmp(dir->users[user_idx].files[i], filename) == 0) {
            printf("File '%s' found in user '%s' directory at position %d\n", 
                   filename, username, i + 1);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("File not found in user's directory!\n");
    }
}

void display_directory_two(struct TwoLevel *dir) {
    int i, j;
    
    printf("\n==========================================\n");
    printf("       TWO LEVEL DIRECTORY\n");
    printf("==========================================\n");
    
    if (dir->user_count == 0) {
        printf("No users in directory!\n");
    } else {
        for (i = 0; i < dir->user_count; i++) {
            printf("\nUser: %s\n", dir->users[i].username);
            printf("Files: ");
            if (dir->users[i].file_count == 0) {
                printf("(empty)");
            } else {
                for (j = 0; j < dir->users[i].file_count; j++) {
                    printf("%s ", dir->users[i].files[j]);
                }
            }
            printf("\n");
        }
    }
    printf("==========================================\n");
}

void two_level_menu(struct TwoLevel *dir) {
    int choice;
    
    while (1) {
        printf("\n--- TWO LEVEL DIRECTORY ---\n");
        printf("1. Add User\n");
        printf("2. Add File\n");
        printf("3. Delete File\n");
        printf("4. Search File\n");
        printf("5. Display Directory\n");
        printf("6. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: add_user(dir); break;
            case 2: add_file_two(dir); break;
            case 3: delete_file_two(dir); break;
            case 4: search_file_two(dir); break;
            case 5: display_directory_two(dir); break;
            case 6: return;
            default: printf("Invalid choice!\n");
        }
    }
}

int main() {
    struct SingleLevel single_dir = {.file_count = 0};
    struct TwoLevel two_dir = {.user_count = 0};
    int choice;
    
    printf("==========================================\n");
    printf("   FILE ORGANIZATION SIMULATION\n");
    printf("==========================================\n");
    
    while (1) {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Single Level Directory\n");
        printf("2. Two Level Directory\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                single_level_menu(&single_dir);
                break;
            case 2:
                two_level_menu(&two_dir);
                break;
            case 3:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}

/*
SAMPLE INPUT/OUTPUT:

Choose: 2 (Two Level Directory)
1. Add User -> Enter: john
   User 'john' added successfully!
2. Add File -> User: john, File: report.doc
   File 'report.doc' added to user 'john' directory!
5. Display Directory

TWO LEVEL DIRECTORY
User: john
Files: report.doc

COMMANDS TO RUN:
gcc file_organization.c -o file_organization
./file_organization

VIVA EXPLANATION:
Single level directory stores all files in one place, simple but limited.
Two level directory provides user-specific directories, allowing better organization and isolation.
Two level prevents naming conflicts as different users can have files with same names.
*/
