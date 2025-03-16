# Student Grade Management System

A simple C program to manage student grades and records with basic CRUD operations.

## Visuals
<img width="776" alt="Screenshot 2025-03-16 at 9 33 10 PM" src="https://github.com/user-attachments/assets/b84fd6da-3338-41d9-a9a3-9a4f91114428" />

## Features

- Add new students with their details:
  - Student ID
  - Name
  - Marks for three subjects
  - Automatic average calculation
- Display all student records in a tabulated format
- Delete students by their ID
- Persistent data storage using binary files

## How to Compile and Run

1. Compile the program using make:
```bash
make
```
2. Run the program:
```bash
./student_system
 ```

## Menu Options
1. Add Student - Enter new student details
2. Display All Students - View all stored records
3. Delete Student - Remove a student by ID
4. Save and Exit - Save changes and close program

## File Structure
- main.c - Contains the main program code
- Makefile - Build configuration
- students.dat - Binary file for data storage (auto-generated)

## Requirements
- GCC compiler
- Make utility

## Author
Miloni Patel
