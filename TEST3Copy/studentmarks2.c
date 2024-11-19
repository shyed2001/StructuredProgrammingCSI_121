<<<<<<< Updated upstream
<<<<<<< Updated upstream
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_ROLL_LENGTH 12
#define MAX_SUBJECTS 5
#define MAX_SUBJECT_NAME_LENGTH 20

typedef struct {
    char roll[MAX_ROLL_LENGTH];
    int marks[MAX_SUBJECTS];
} StudentMarks;

int main() {
    FILE *subjectMarkFile = fopen("SubjectMark.txt", "r");
    if (subjectMarkFile == NULL) {
        printf("Error opening SubjectMark.txt.\n");
        return 1;
    }

    StudentMarks studentMarks[MAX_STUDENTS];
    int numStudents = 0;

    char line[200]; // Adjust buffer size as needed

    // Read the header line to get subject names dynamically
    if (fgets(line, sizeof(line), subjectMarkFile) == NULL) {
        printf("Error reading header line.\n");
        fclose(subjectMarkFile);
        return 1;
    }

    // Extract subject names from the header line
    char subjectNames[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH];
    sscanf(line, "%*s %*s %[^\t] %[^\t] %[^\t] %[^\t] %[^\t]",
           subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4]);

    // Print header
    printf("Sl\tRoll\t%s\t%s\t%s\t%s\t%s\n",
           subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4]);

    while (fgets(line, sizeof(line), subjectMarkFile)) {
        if (line[0] == '\n') {
            // Skip empty lines
            continue;
        }

        // Extract values using sscanf
        char roll[MAX_ROLL_LENGTH];
        int marks[MAX_SUBJECTS];

        if (sscanf(line, "%*d %s %d %d %d %d %d", roll, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]) != 6) {
            printf("Error parsing student mark line: %s\n", line);
            fclose(subjectMarkFile);
            return 1;
        }

        strcpy(studentMarks[numStudents].roll, roll);
        for (int i = 0; i < MAX_SUBJECTS; i++) {
            studentMarks[numStudents].marks[i] = marks[i];
        }

        numStudents++;

        if (numStudents >= MAX_STUDENTS) {
            printf("Maximum number of students reached.\n");
            break;
        }
    }

    fclose(subjectMarkFile);

    // Print Student Marks Information
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s", i + 1, studentMarks[i].roll);
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("\t%d", studentMarks[i].marks[j]);
        }
        printf("\n");
    }

    return 0;
}
=======
=======
>>>>>>> Stashed changes
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_ROLL_LENGTH 12
#define MAX_SUBJECTS 5
#define MAX_SUBJECT_NAME_LENGTH 20

typedef struct {
    char roll[MAX_ROLL_LENGTH];
    int marks[MAX_SUBJECTS];
} StudentMarks;

int main() {
    FILE *subjectMarkFile = fopen("SubjectMark.txt", "r");
    if (subjectMarkFile == NULL) {
        printf("Error opening SubjectMark.txt.\n");
        return 1;
    }

    StudentMarks studentMarks[MAX_STUDENTS];
    int numStudents = 0;

    char line[200]; // Adjust buffer size as needed

    // Read the header line to get subject names dynamically
    if (fgets(line, sizeof(line), subjectMarkFile) == NULL) {
        printf("Error reading header line.\n");
        fclose(subjectMarkFile);
        return 1;
    }

    // Extract subject names from the header line
    char subjectNames[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH];
    sscanf(line, "%*s %*s %[^\t] %[^\t] %[^\t] %[^\t] %[^\t]",
           subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4]);

    // Print header
    printf("Sl\tRoll\t%s\t%s\t%s\t%s\t%s\n",
           subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4]);

    while (fgets(line, sizeof(line), subjectMarkFile)) {
        if (line[0] == '\n') {
            // Skip empty lines
            continue;
        }

        // Extract values using sscanf
        char roll[MAX_ROLL_LENGTH];
        int marks[MAX_SUBJECTS];

        if (sscanf(line, "%*d %s %d %d %d %d %d", roll, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]) != 6) {
            printf("Error parsing student mark line: %s\n", line);
            fclose(subjectMarkFile);
            return 1;
        }

        strcpy(studentMarks[numStudents].roll, roll);
        for (int i = 0; i < MAX_SUBJECTS; i++) {
            studentMarks[numStudents].marks[i] = marks[i];
        }

        numStudents++;

        if (numStudents >= MAX_STUDENTS) {
            printf("Maximum number of students reached.\n");
            break;
        }
    }

    fclose(subjectMarkFile);

    // Print Student Marks Information
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s", i + 1, studentMarks[i].roll);
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("\t%d", studentMarks[i].marks[j]);
        }
        printf("\n");
    }

    return 0;
}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
