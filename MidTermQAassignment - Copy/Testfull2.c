<<<<<<< Updated upstream
<<<<<<< Updated upstream
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define some constants for the maximum length of names
#define MAX_STUDENT_NAME_LENGTH 30
#define MAX_SUBJECT_NAME_LENGTH 10

// Define a struct to store the student information
struct StudentInfo {
    char roll[15]; // The student roll number
    char name[MAX_STUDENT_NAME_LENGTH]; // The student name
    char **subjectNames; // The subject names
    int *marks; // The marks in each subject
    float *gpa; // The GPA in each subject
    char **letterGrade; // The letter grade in each subject
    float cgpa; // The cumulative GPA
};

// Function to calculate GPA from marks
float calculateGPA(int marks) {
    if (marks >= 80) return 4.00;
    else if (marks >= 75) return 3.75;
    else if (marks >= 70) return 3.50;
    else if (marks >= 65) return 3.25;
    else if (marks >= 60) return 3.00;
    else if (marks >= 55) return 2.75;
    else if (marks >= 50) return 2.50;
    else if (marks >= 45) return 2.25;
    else if (marks >= 40) return 2.00;
    else return 0.00;
}

// Function to calculate letter grade from marks
void calculateLetterGrade(int marks, char letterGrade[3]) {
    if (marks >= 80) strcpy(letterGrade, "A+");
    else if (marks >= 75) strcpy(letterGrade, "A");
    else if (marks >= 70) strcpy(letterGrade, "A-");
    else if (marks >= 65) strcpy(letterGrade, "B+");
    else if (marks >= 60) strcpy(letterGrade, "B");
    else if (marks >= 55) strcpy(letterGrade, "B-");
    else if (marks >= 50) strcpy(letterGrade, "C+");
    else if (marks >= 45) strcpy(letterGrade, "C");
    else if (marks >= 40) strcpy(letterGrade, "D");
    else strcpy(letterGrade, "F");
}

// Function to calculate CGPA from GPA and credit hours
float calculateCGPA(float gpa[], int creditHours[], int numSubjects) {
    float totalPoints = 0; // The total grade points earned
    float totalCredits = 0; // The total credit hours attempted
    for (int i = 0; i < numSubjects; i++) {
        totalPoints += gpa[i] * creditHours[i]; // Multiply GPA by credit hours for each subject
        totalCredits += creditHours[i]; // Add credit hours for each subject
    }
    return totalPoints / totalCredits; // Divide total grade points by total credit hours
}

int main() {

    // Open the StudentInf.txt file for reading
    FILE *studentInfoFile = fopen("StudentInf.txt", "r");

    // Check if the file is opened successfully
    if (studentInfoFile == NULL) {
        printf("Error opening StudentInf.txt.\n");
        return 1;
    }

    // Declare an array of StudentInfo structs to store the student information
    struct StudentInfo *students;

    // Declare a char array to store each line of the file
    char line[200];

    // Read and ignore the header line of the file
    fgets(line, sizeof(line), studentInfoFile);

    // Use a loop to read each line of the file until the end of the file is reached
    int numStudents = 0; // The number of students read from the file

    while (!feof(studentInfoFile)) {
        // Read a line from the file and store it in line
        fgets(line, sizeof(line), studentInfoFile);

        // Reallocate memory for the students array to add one more element
        students = realloc(students, (numStudents + 1) * sizeof(struct StudentInfo));
        if (students == NULL) {
            printf("Error reallocating memory for students.\n");
            return 1;
        }

        // Extract the roll and name from the line using sscanf()
        sscanf(line, "%*d %s %[^\n]", students[numStudents].roll, students[numStudents].name);

        // Increment the number of students
        numStudents++;

        // Break the loop if an empty line is encountered
        if (strcmp(line, "\n") == 0 || strcmp(line, "\r\n") == 0) break;

        // TODO: Add a limit to the number of students that can be read from the file
        // For example, you can use a constant like MAX_STUDENTS and compare it with numStudents
    }

    // Close the StudentInf.txt file
    fclose(studentInfoFile);

    // Open the SubjectMark.txt file for reading
    FILE *subjectMarkFile = fopen("SubjectMark.txt", "r");

    // Check if the file is opened successfully
    if (subjectMarkFile == NULL) {
        printf("Error opening SubjectMark.txt.\n");
        return 1;
    }

    // Read the header line of the file to get the subject names
    fgets(line, sizeof(line), subjectMarkFile);

    // Declare a variable to store the number of subjects
    int numSubjects = 0;

    // Use a loop to count the number of tabs in the header line
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == '\t') numSubjects++;
    }

    // Subtract 2 from the number of tabs to get the actual number of subjects
    numSubjects -= 2;

    // Allocate memory for the subject names array
    char **subjectNames = malloc(numSubjects * sizeof(char *));
    if (subjectNames == NULL) {
        printf("Error allocating memory for subject names.\n");
        return 1;
    }

    // Allocate memory for each subject name
    for (int i = 0; i < numSubjects; i++) {
        subjectNames[i] = malloc(MAX_SUBJECT_NAME_LENGTH * sizeof(char));
        if (subjectNames[i] == NULL) {
            printf("Error allocating memory for subject name %d.\n", i + 1);
            return 1;
        }
    }

    // Generate a format string for reading subject names from the header line
    char formatString[200] = "%*s %*s"; // Start with skipping the first two columns
    for (int i = 0; i < numSubjects; i++) {
        strcat(formatString, " %[^\t]"); // Add a conversion specifier for each subject name
    }

    // Use the format string to extract subject names from the header line using sscanf()
    sscanf(line, formatString, subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4], subjectNames[5], subjectNames[6], subjectNames[7]);

    // Use a loop to read each line of the file until the end of the file is reached
    int numStudents2 = 0; // The number of students read from the file

    while (!feof(subjectMarkFile)) {
        // Read a line from the file and store it in line
        fgets(line, sizeof(line), subjectMarkFile);

        // Allocate memory for the marks array
        int *marks = malloc(numSubjects * sizeof(int));
        if (marks == NULL) {
            printf("Error allocating memory for marks.\n");
            return 1;
        }

        // Extract the roll and marks from the line using sscanf()
        char roll[15]; // The roll number of the student

        // Generate a format string for reading roll and marks from each line
        char formatString2[200] = "%*d %s"; // Start with skipping the first column and reading the roll number
        for (int i = 0; i < numSubjects; i++) {
            strcat(formatString2, " %d"); // Add a conversion specifier for each mark
        }

        // Use the format string to extract roll and marks from each line using sscanf()
        sscanf(line, formatString2, roll, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4], &marks[5], &marks[6], &marks[7]);

        // Find the index of the student with the same roll number in the students array
        int index = -1; // The index of the student, initialized to -1
        for (int i = 0; i < numStudents; i++) {
            if (strcmp(roll, students[i].roll) == 0) {
                index = i; // Set the index to i if the roll numbers match
                break;
            }
        }

        // If the index is not -1, then store and connect the roll and subject name and mark values in the students array
        if (index != -1) {
            // Allocate memory for the subject names array in the students array
            students[index].subjectNames = malloc(numSubjects * sizeof(char *));
            if (students[index].subjectNames == NULL) {
                printf("Error allocating memory for subject names in students array.\n");
                return 1;
            }

            // Allocate memory for each subject name in the students array
            for (int i = 0; i < numSubjects; i++) {
                students[index].subjectNames[i] = malloc(MAX_SUBJECT_NAME_LENGTH * sizeof(char));
                if (students[index].subjectNames[i] == NULL) {
                    printf("Error allocating memory for subject name %d in students array.\n", i + 1);
                    return 1;
                }
            }

            // Allocate memory for the marks array in the students array
            students[index].marks = malloc(numSubjects * sizeof(int));
            if (students[index].marks == NULL) {
                printf("Error allocating memory for marks in students array.\n");
                return 1;
            }

            // Allocate memory for the gpa array in the students array
            students[index].gpa = malloc(numSubjects * sizeof(float));
            if (students[index].gpa == NULL) {
                printf("Error allocating memory for gpa in students array.\n");
                return 1;
            }

            // Allocate memory for the letter grade array in the students array
            students[index].letterGrade = malloc(numSubjects * sizeof(char *));
            if (students[index].letterGrade == NULL) {
                printf("Error allocating memory for letter grade in students array.\n");
                return 1;
            }

            // Allocate memory for each letter grade in the students array
            for (int i = 0; i < numSubjects; i++) {
                students[index].letterGrade[i] = malloc(3 * sizeof(char));
                if (students[index].letterGrade[i] == NULL) {
                    printf("Error allocating memory for letter grade %d in students array.\n", i + 1);
                    return 1;
                }
            }

            // Copy the subject name, mark, gpa, and letter grade to the students array
            for (int i = 0; i < numSubjects; i++) {
                strcpy(students[index].subjectNames[i], subjectNames[i]); // Copy the subject name
                students[index].marks[i] = marks[i]; // Copy the mark
                students[index].gpa[i] = calculateGPA(marks[i]); // Calculate and copy the gpa
                calculateLetterGrade(marks[i], students[index].letterGrade[i]); // Calculate and copy the letter grade
            }
        }

        // Increment the number of students
        numStudents2++;

        // Break the loop if an empty line is encountered
        if (strcmp(line, "\n") == 0 || strcmp(line, "\r\n") == 0) break;

        // Free the memory allocated for the marks array
        free(marks);

        // TODO: Add a limit to the number of students that can be read from the file
        // For example, you can use a constant like MAX_STUDENTS and compare it with numStudents2
    }

    // Close the SubjectMark.txt file
    fclose(subjectMarkFile);

    // Allocate memory for the credit hours array
    int *creditHours = malloc(numSubjects * sizeof(int));
    if (creditHours == NULL) {
        printf("Error allocating memory for credit hours.\n");
        return 1;
    }

    // Assign 3.0 credit hours to each subject
    for (int i = 0; i < numSubjects; i++) {
        creditHours[i] = 3;
    }

    // Use a loop to calculate and store the CGPA for each student in the students array
    for (int i = 0; i < numStudents; i++) {
        students[i].cgpa = calculateCGPA(students[i].gpa, creditHours, numSubjects); // Calculate and store the CGPA using calculateCGPA() function
    }

    // Open a new file called student_grades.txt for writing
    FILE *studentGradesFile = fopen("student_grades.txt", "w");

    // Check if the file is opened successfully
    if (studentGradesFile == NULL) {
        printf("Error opening student_grades.txt.\n");
        return 1;
    }

    // Write and print out a header line with column names to the file and console using fprintf() and printf()
    fprintf(studentGradesFile, "Sl\tRoll\tName");
    printf("Sl\tRoll\tName");

    // Use a loop to write and print out the subject names as column names
    for (int i = 0; i < numSubjects; i++) {
        fprintf(studentGradesFile, "\t%s", subjectNames[i]);
        printf("\t%s", subjectNames[i]);
    }

    // Write and print out the earned credit hours and GPA as column names
    fprintf(studentGradesFile, "\tEarned Credit Hours\tGPA\n");
    printf("\tEarned Credit Hours\tGPA\n");

    // Use a loop to write and print out each student's information to the file and console using fprintf() and printf()
    for (int i = 0; i < numStudents; i++) {
        // Write and print out the serial number, roll number, and name of the student
        fprintf(studentGradesFile, "%d\t%s\t%s", i + 1, students[i].roll, students[i].name);
        printf("%d\t%s\t%s", i + 1, students[i].roll, students[i].name);

        // Use another loop to write and print out the letter grade for each subject
        for (int j = 0; j < numSubjects; j++) {
            fprintf(studentGradesFile, "\t%s", students[i].letterGrade[j]);
            printf("\t%s", students[i].letterGrade[j]);
        }

        // Write and print out the earned credit hours and the CGPA of the student
        fprintf(studentGradesFile, "\t%d\t%.2f\n", numSubjects * 3, students[i].cgpa);
        printf("\t%d\t%.2f\n", numSubjects * 3, students[i].cgpa);
    }

    // Close the student_grades.txt file
    fclose(studentGradesFile);

    // Print a message to indicate that the program is done
    printf("The program is done. The student grades are written to the student_grades.txt file.\n");

    // Free the memory allocated for the subject names array
    for (int i = 0; i < numSubjects; i++) {
        free(subjectNames[i]);
    }
    free(subjectNames);

    // Free the memory allocated for the credit hours array
    free(creditHours);

    // Free the memory allocated for the students array
    for (int i = 0; i < numStudents; i++) {
        // Free the memory allocated for the subject names array in the students array
        for (int j = 0; j < numSubjects; j++) {
            free(students[i].subjectNames[j]);
        }
        free(students[i].subjectNames);

        // Free the memory allocated for the marks array in the students array
        free(students[i].marks);

        // Free the memory allocated for the gpa array in the students array
        free(students[i].gpa);

        // Free the memory allocated for the letter grade array in the students array
        for (int j = 0; j < numSubjects; j++) {
            free(students[i].letterGrade[j]);
        }
        free(students[i].letterGrade);
    }
    free(students);

    return 0;
}
=======
=======
>>>>>>> Stashed changes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define some constants for the maximum length of names
#define MAX_STUDENT_NAME_LENGTH 30
#define MAX_SUBJECT_NAME_LENGTH 10

// Define a struct to store the student information
struct StudentInfo {
    char roll[15]; // The student roll number
    char name[MAX_STUDENT_NAME_LENGTH]; // The student name
    char **subjectNames; // The subject names
    int *marks; // The marks in each subject
    float *gpa; // The GPA in each subject
    char **letterGrade; // The letter grade in each subject
    float cgpa; // The cumulative GPA
};

// Function to calculate GPA from marks
float calculateGPA(int marks) {
    if (marks >= 80) return 4.00;
    else if (marks >= 75) return 3.75;
    else if (marks >= 70) return 3.50;
    else if (marks >= 65) return 3.25;
    else if (marks >= 60) return 3.00;
    else if (marks >= 55) return 2.75;
    else if (marks >= 50) return 2.50;
    else if (marks >= 45) return 2.25;
    else if (marks >= 40) return 2.00;
    else return 0.00;
}

// Function to calculate letter grade from marks
void calculateLetterGrade(int marks, char letterGrade[3]) {
    if (marks >= 80) strcpy(letterGrade, "A+");
    else if (marks >= 75) strcpy(letterGrade, "A");
    else if (marks >= 70) strcpy(letterGrade, "A-");
    else if (marks >= 65) strcpy(letterGrade, "B+");
    else if (marks >= 60) strcpy(letterGrade, "B");
    else if (marks >= 55) strcpy(letterGrade, "B-");
    else if (marks >= 50) strcpy(letterGrade, "C+");
    else if (marks >= 45) strcpy(letterGrade, "C");
    else if (marks >= 40) strcpy(letterGrade, "D");
    else strcpy(letterGrade, "F");
}

// Function to calculate CGPA from GPA and credit hours
float calculateCGPA(float gpa[], int creditHours[], int numSubjects) {
    float totalPoints = 0; // The total grade points earned
    float totalCredits = 0; // The total credit hours attempted
    for (int i = 0; i < numSubjects; i++) {
        totalPoints += gpa[i] * creditHours[i]; // Multiply GPA by credit hours for each subject
        totalCredits += creditHours[i]; // Add credit hours for each subject
    }
    return totalPoints / totalCredits; // Divide total grade points by total credit hours
}

int main() {

    // Open the StudentInf.txt file for reading
    FILE *studentInfoFile = fopen("StudentInf.txt", "r");

    // Check if the file is opened successfully
    if (studentInfoFile == NULL) {
        printf("Error opening StudentInf.txt.\n");
        return 1;
    }

    // Declare an array of StudentInfo structs to store the student information
    struct StudentInfo *students;

    // Declare a char array to store each line of the file
    char line[200];

    // Read and ignore the header line of the file
    fgets(line, sizeof(line), studentInfoFile);

    // Use a loop to read each line of the file until the end of the file is reached
    int numStudents = 0; // The number of students read from the file

    while (!feof(studentInfoFile)) {
        // Read a line from the file and store it in line
        fgets(line, sizeof(line), studentInfoFile);

        // Reallocate memory for the students array to add one more element
        students = realloc(students, (numStudents + 1) * sizeof(struct StudentInfo));
        if (students == NULL) {
            printf("Error reallocating memory for students.\n");
            return 1;
        }

        // Extract the roll and name from the line using sscanf()
        sscanf(line, "%*d %s %[^\n]", students[numStudents].roll, students[numStudents].name);

        // Increment the number of students
        numStudents++;

        // Break the loop if an empty line is encountered
        if (strcmp(line, "\n") == 0 || strcmp(line, "\r\n") == 0) break;

        // TODO: Add a limit to the number of students that can be read from the file
        // For example, you can use a constant like MAX_STUDENTS and compare it with numStudents
    }

    // Close the StudentInf.txt file
    fclose(studentInfoFile);

    // Open the SubjectMark.txt file for reading
    FILE *subjectMarkFile = fopen("SubjectMark.txt", "r");

    // Check if the file is opened successfully
    if (subjectMarkFile == NULL) {
        printf("Error opening SubjectMark.txt.\n");
        return 1;
    }

    // Read the header line of the file to get the subject names
    fgets(line, sizeof(line), subjectMarkFile);

    // Declare a variable to store the number of subjects
    int numSubjects = 0;

    // Use a loop to count the number of tabs in the header line
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == '\t') numSubjects++;
    }

    // Subtract 2 from the number of tabs to get the actual number of subjects
    numSubjects -= 2;

    // Allocate memory for the subject names array
    char **subjectNames = malloc(numSubjects * sizeof(char *));
    if (subjectNames == NULL) {
        printf("Error allocating memory for subject names.\n");
        return 1;
    }

    // Allocate memory for each subject name
    for (int i = 0; i < numSubjects; i++) {
        subjectNames[i] = malloc(MAX_SUBJECT_NAME_LENGTH * sizeof(char));
        if (subjectNames[i] == NULL) {
            printf("Error allocating memory for subject name %d.\n", i + 1);
            return 1;
        }
    }

    // Generate a format string for reading subject names from the header line
    char formatString[200] = "%*s %*s"; // Start with skipping the first two columns
    for (int i = 0; i < numSubjects; i++) {
        strcat(formatString, " %[^\t]"); // Add a conversion specifier for each subject name
    }

    // Use the format string to extract subject names from the header line using sscanf()
    sscanf(line, formatString, subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4], subjectNames[5], subjectNames[6], subjectNames[7]);

    // Use a loop to read each line of the file until the end of the file is reached
    int numStudents2 = 0; // The number of students read from the file

    while (!feof(subjectMarkFile)) {
        // Read a line from the file and store it in line
        fgets(line, sizeof(line), subjectMarkFile);

        // Allocate memory for the marks array
        int *marks = malloc(numSubjects * sizeof(int));
        if (marks == NULL) {
            printf("Error allocating memory for marks.\n");
            return 1;
        }

        // Extract the roll and marks from the line using sscanf()
        char roll[15]; // The roll number of the student

        // Generate a format string for reading roll and marks from each line
        char formatString2[200] = "%*d %s"; // Start with skipping the first column and reading the roll number
        for (int i = 0; i < numSubjects; i++) {
            strcat(formatString2, " %d"); // Add a conversion specifier for each mark
        }

        // Use the format string to extract roll and marks from each line using sscanf()
        sscanf(line, formatString2, roll, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4], &marks[5], &marks[6], &marks[7]);

        // Find the index of the student with the same roll number in the students array
        int index = -1; // The index of the student, initialized to -1
        for (int i = 0; i < numStudents; i++) {
            if (strcmp(roll, students[i].roll) == 0) {
                index = i; // Set the index to i if the roll numbers match
                break;
            }
        }

        // If the index is not -1, then store and connect the roll and subject name and mark values in the students array
        if (index != -1) {
            // Allocate memory for the subject names array in the students array
            students[index].subjectNames = malloc(numSubjects * sizeof(char *));
            if (students[index].subjectNames == NULL) {
                printf("Error allocating memory for subject names in students array.\n");
                return 1;
            }

            // Allocate memory for each subject name in the students array
            for (int i = 0; i < numSubjects; i++) {
                students[index].subjectNames[i] = malloc(MAX_SUBJECT_NAME_LENGTH * sizeof(char));
                if (students[index].subjectNames[i] == NULL) {
                    printf("Error allocating memory for subject name %d in students array.\n", i + 1);
                    return 1;
                }
            }

            // Allocate memory for the marks array in the students array
            students[index].marks = malloc(numSubjects * sizeof(int));
            if (students[index].marks == NULL) {
                printf("Error allocating memory for marks in students array.\n");
                return 1;
            }

            // Allocate memory for the gpa array in the students array
            students[index].gpa = malloc(numSubjects * sizeof(float));
            if (students[index].gpa == NULL) {
                printf("Error allocating memory for gpa in students array.\n");
                return 1;
            }

            // Allocate memory for the letter grade array in the students array
            students[index].letterGrade = malloc(numSubjects * sizeof(char *));
            if (students[index].letterGrade == NULL) {
                printf("Error allocating memory for letter grade in students array.\n");
                return 1;
            }

            // Allocate memory for each letter grade in the students array
            for (int i = 0; i < numSubjects; i++) {
                students[index].letterGrade[i] = malloc(3 * sizeof(char));
                if (students[index].letterGrade[i] == NULL) {
                    printf("Error allocating memory for letter grade %d in students array.\n", i + 1);
                    return 1;
                }
            }

            // Copy the subject name, mark, gpa, and letter grade to the students array
            for (int i = 0; i < numSubjects; i++) {
                strcpy(students[index].subjectNames[i], subjectNames[i]); // Copy the subject name
                students[index].marks[i] = marks[i]; // Copy the mark
                students[index].gpa[i] = calculateGPA(marks[i]); // Calculate and copy the gpa
                calculateLetterGrade(marks[i], students[index].letterGrade[i]); // Calculate and copy the letter grade
            }
        }

        // Increment the number of students
        numStudents2++;

        // Break the loop if an empty line is encountered
        if (strcmp(line, "\n") == 0 || strcmp(line, "\r\n") == 0) break;

        // Free the memory allocated for the marks array
        free(marks);

        // TODO: Add a limit to the number of students that can be read from the file
        // For example, you can use a constant like MAX_STUDENTS and compare it with numStudents2
    }

    // Close the SubjectMark.txt file
    fclose(subjectMarkFile);

    // Allocate memory for the credit hours array
    int *creditHours = malloc(numSubjects * sizeof(int));
    if (creditHours == NULL) {
        printf("Error allocating memory for credit hours.\n");
        return 1;
    }

    // Assign 3.0 credit hours to each subject
    for (int i = 0; i < numSubjects; i++) {
        creditHours[i] = 3;
    }

    // Use a loop to calculate and store the CGPA for each student in the students array
    for (int i = 0; i < numStudents; i++) {
        students[i].cgpa = calculateCGPA(students[i].gpa, creditHours, numSubjects); // Calculate and store the CGPA using calculateCGPA() function
    }

    // Open a new file called student_grades.txt for writing
    FILE *studentGradesFile = fopen("student_grades.txt", "w");

    // Check if the file is opened successfully
    if (studentGradesFile == NULL) {
        printf("Error opening student_grades.txt.\n");
        return 1;
    }

    // Write and print out a header line with column names to the file and console using fprintf() and printf()
    fprintf(studentGradesFile, "Sl\tRoll\tName");
    printf("Sl\tRoll\tName");

    // Use a loop to write and print out the subject names as column names
    for (int i = 0; i < numSubjects; i++) {
        fprintf(studentGradesFile, "\t%s", subjectNames[i]);
        printf("\t%s", subjectNames[i]);
    }

    // Write and print out the earned credit hours and GPA as column names
    fprintf(studentGradesFile, "\tEarned Credit Hours\tGPA\n");
    printf("\tEarned Credit Hours\tGPA\n");

    // Use a loop to write and print out each student's information to the file and console using fprintf() and printf()
    for (int i = 0; i < numStudents; i++) {
        // Write and print out the serial number, roll number, and name of the student
        fprintf(studentGradesFile, "%d\t%s\t%s", i + 1, students[i].roll, students[i].name);
        printf("%d\t%s\t%s", i + 1, students[i].roll, students[i].name);

        // Use another loop to write and print out the letter grade for each subject
        for (int j = 0; j < numSubjects; j++) {
            fprintf(studentGradesFile, "\t%s", students[i].letterGrade[j]);
            printf("\t%s", students[i].letterGrade[j]);
        }

        // Write and print out the earned credit hours and the CGPA of the student
        fprintf(studentGradesFile, "\t%d\t%.2f\n", numSubjects * 3, students[i].cgpa);
        printf("\t%d\t%.2f\n", numSubjects * 3, students[i].cgpa);
    }

    // Close the student_grades.txt file
    fclose(studentGradesFile);

    // Print a message to indicate that the program is done
    printf("The program is done. The student grades are written to the student_grades.txt file.\n");

    // Free the memory allocated for the subject names array
    for (int i = 0; i < numSubjects; i++) {
        free(subjectNames[i]);
    }
    free(subjectNames);

    // Free the memory allocated for the credit hours array
    free(creditHours);

    // Free the memory allocated for the students array
    for (int i = 0; i < numStudents; i++) {
        // Free the memory allocated for the subject names array in the students array
        for (int j = 0; j < numSubjects; j++) {
            free(students[i].subjectNames[j]);
        }
        free(students[i].subjectNames);

        // Free the memory allocated for the marks array in the students array
        free(students[i].marks);

        // Free the memory allocated for the gpa array in the students array
        free(students[i].gpa);

        // Free the memory allocated for the letter grade array in the students array
        for (int j = 0; j < numSubjects; j++) {
            free(students[i].letterGrade[j]);
        }
        free(students[i].letterGrade);
    }
    free(students);

    return 0;
}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
