#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME 50

struct Student {
    int id;
    char name[MAX_NAME];
    float marks[3];
    float average;
};

void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void calculateAverage(struct Student *student);
void saveToFile(struct Student students[], int count);
void loadFromFile(struct Student students[], int *count);
void deleteStudent(struct Student students[], int *count);  // Add this with other prototypes

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    loadFromFile(students, &count);

    do {
        // In main() function, update the menu:
        printf("\nStudent Grade Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Delete Student\n");  // New option
        printf("4. Save and Exit\n");   // Changed from 3 to 4
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                deleteStudent(students, &count);  // New case
                break;
            case 4:                              // Changed from 3 to 4
                saveToFile(students, count);
                printf("Data saved. Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);              // Changed from 3 to 4

    return 0;
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Maximum student limit reached!\n");
        return;
    }

    struct Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    getchar();

    printf("Enter student name: ");
    fgets(newStudent.name, MAX_NAME, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;

    printf("Enter marks for three subjects:\n");
    for (int i = 0; i < 3; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &newStudent.marks[i]);
    }

    calculateAverage(&newStudent);
    students[*count] = newStudent;
    (*count)++;
    printf("Student added successfully!\n");
}

void calculateAverage(struct Student *student) {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += student->marks[i];
    }
    student->average = sum / 3;
}

void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to display!\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("ID\tName\t\tSubject1\tSubject2\tSubject3\tAverage\n");
    printf("--------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
               students[i].id,
               students[i].name,
               students[i].marks[0],
               students[i].marks[1],
               students[i].marks[2],
               students[i].average);
    }
}

void saveToFile(struct Student students[], int count) {
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, file);
    fwrite(students, sizeof(struct Student), count, file);
    fclose(file);
}

void loadFromFile(struct Student students[], int *count) {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        *count = 0;
        return;
    }
    fread(count, sizeof(int), 1, file);
    fread(students, sizeof(struct Student), *count, file);
    fclose(file);
}

// Add this new function at the end of the file:
void deleteStudent(struct Student students[], int *count) {
    int id;
    int found = 0;
    
    if (*count == 0) {
        printf("No students to delete!\n");
        return;
    }

    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            // Move all elements after this one position back
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student with ID %d deleted successfully!\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}