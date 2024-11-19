<<<<<<< Updated upstream
<<<<<<< Updated upstream
/// QA 7
//Write a C program that takes Student Information and Marks from two different files and
//write student wise individual subject grade and GPA in another file. [File Templates and
//Instructions will be provided]

#include <stdio.h>
#include <string.h>

// Define some constants for the maximum number of students, subjects, and length of names
#define MAX_STUDENTS 20
#define MAX_SUBJECTS 5  // Change subjects accordingly
#define MAX_STUDENT_NAME_LENGTH 30
#define MAX_SUBJECT_NAME_LENGTH 10

/// Define a struct to store the student information
struct StudentInfo {
    char roll[15]; // The student roll number
    char name[MAX_STUDENT_NAME_LENGTH]; // The student name
    char subjectNames[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH]; // The subject names
    int marks[MAX_SUBJECTS]; // The marks in each subject
    float gpa[MAX_SUBJECTS]; // The GPA in each subject
    char letterGrade[MAX_SUBJECTS][3]; // The letter grade in each subject
    float cgpa; // The cumulative GPA
};

/// Function to calculate GPA from marks
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

/// Function to calculate letter grade from marks
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

/// Function to calculate CGPA from GPA and credit hours
float calculateCGPA(float gpa[], int creditHours[], int numSubjects) {
    float totalPoints = 0; // The total grade points earned
    float totalCredits = 0; // The total credit hours attempted
    for (int i = 0; i < numSubjects; i++) {
        totalPoints += gpa[i] * creditHours[i]; // Multiply GPA by credit hours for each subject
        if (gpa[i] == 0.0)
            continue; // dont add creditHours[i] to totalCredits if letterGrade is F
             totalCredits += creditHours[i]; // Add credit hours for each subject
    }
    return totalPoints / totalCredits; // Divide total grade points by total credit hours
}

/// Function to calculate Earned credit hours
float calculateEarnedCredits(float gpa[], int creditHours[], int numSubjects) {

    float totalCredits = 0; // The total credit hours attempted
    for (int i = 0; i < numSubjects; i++) {
           if (gpa[i] == 0.0)
            continue; // dont add creditHours[i] to totalCredits if letterGrade is F
             totalCredits += creditHours[i]; // Add credit hours for each subject
    }
    return totalCredits; // total grade points, Earned total credit hours
}


int main() {

    /// Open the StudentInf.txt file for reading
    FILE *studentInfoFile = fopen("StudentInf.txt", "r");

    // Check if the file is opened successfully
    if (studentInfoFile == NULL) {
        printf("Error opening StudentInf.txt.\n");
        return 1;
    }

    // Declare an array of StudentInfo structs to store the student information
    struct StudentInfo students[MAX_STUDENTS];

    // Declare a char array to store each line of the file
    char line[200];

    // Read and ignore the header line of the file
    fgets(line, sizeof(line), studentInfoFile);

    // Use a loop to read each line of the file until the end of the file is reached
    int numStudents = 0; // The number of students read from the file
    while (!feof(studentInfoFile)) {
        // Read a line from the file and store it in line
        fgets(line, sizeof(line), studentInfoFile);

        // Extract the roll and name from the line using sscanf()
        sscanf(line, "%*d %s %[^\n]", students[numStudents].roll, students[numStudents].name);

        // Increment the number of students
        numStudents++;

        // Break the loop if the maximum number of students is reached
        if (numStudents == MAX_STUDENTS) break;
    }

    // Close the StudentInf.txt file
    fclose(studentInfoFile);

    /// Open the SubjectMark.txt file for reading
    FILE *subjectMarkFile = fopen("SubjectMark.txt", "r");

    // Check if the file is opened successfully
    if (subjectMarkFile == NULL) {
        printf("Error opening SubjectMark.txt.\n");
        return 1;
    }

    // Read the header line of the file to get the subject names
    fgets(line, sizeof(line), subjectMarkFile);

    // Extract the subject names from the header line using sscanf()

//    char subjectNames[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH];
//
//    sscanf(line, "%*s %*s %[^\t] %[^\t] %[^\t] %[^\t] %[^\t]", subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4]);


// Declare an array to store subject names
char subjectNames[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH];

// Declare a char array to store the format string
char formatString[200] = "%*s %*s"; // Start with skipping the first two columns

// Use a loop to append the %[^\t] conversion specifier for each subject name
for (int i = 0; i < MAX_SUBJECTS; i++) {
    strcat(formatString, " %[^\t]");
}

// Use the format string and a variable argument list to extract the subject names from the line using sscanf()

sscanf(line, formatString, subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4]);



    // Use a loop to read each line of the file until the end of the file is reached
    int numStudents2 = 0; // The number of students read from the file
    while (!feof(subjectMarkFile)) {
        // Read a line from the file and store it in line
        fgets(line, sizeof(line), subjectMarkFile);

        // Extract the roll and marks from the line using sscanf()
        char roll[15]; // The roll number of the student
        int marks[MAX_SUBJECTS]; // The marks in each subject
        sscanf(line, "%*d %s %d %d %d %d %d", roll, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]);

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
            for (int i = 0; i < MAX_SUBJECTS; i++) {
                strcpy(students[index].subjectNames[i], subjectNames[i]); // Copy the subject name to the students array
                students[index].marks[i] = marks[i]; // Copy the mark to the students array
            }
        }

        // Increment the number of students
        numStudents2++;

        // Break the loop if the maximum number of students is reached
        if (numStudents2 == MAX_STUDENTS) break;
    }

    // Close the SubjectMark.txt file
    fclose(subjectMarkFile);

    // Declare an array of credit hours for each subject, assuming 3.0 credit hours for each subject
    int creditHours[MAX_SUBJECTS] = {3, 3, 3, 3, 3};

    // Use a loop to calculate and store the GPA, letter grade, and CGPA for each student in the students array
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            students[i].gpa[j] = calculateGPA(students[i].marks[j]); // Calculate and store the GPA for each subject using calculateGPA() function
            calculateLetterGrade(students[i].marks[j], students[i].letterGrade[j]); // Calculate and store the letter grade for each subject using calculateLetterGrade() function
        }
        students[i].cgpa = calculateCGPA(students[i].gpa, creditHours, MAX_SUBJECTS ); // Calculate and store the CGPA for each student using calculateCGPA() function
    }

    /// Open a new file called student_grades.txt for writing
    FILE *studentGradesFile = fopen("student_grades.txt", "w");

    // Check if the file is opened successfully
    if (studentGradesFile == NULL) {
        printf("Error opening student_grades.txt.\n");
        return 1;
    }

/// Write and print out a header line with column names to the file and console using fprintf() and printf()
fprintf(studentGradesFile, "Sl\tRoll\tName\tCSE 101\tCSE 102\tCSE 103\tCSE 104\tCSE 105\tEarned Credit Hours\tGPA\n");
printf("Sl\tRoll\tName\tCSE 101\tCSE 102\tCSE 103\tCSE 104\tCSE 105\tEarned Credit Hours\tGPA\n");

// Use a loop to write and print out each student's information to the file and console using fprintf() and printf()
for (int i = 0; i < numStudents; i++) {
    // Write and print out the serial number, roll number, and name of the student
    fprintf(studentGradesFile, "%d\t%s\t%s", i + 1, students[i].roll, students[i].name);
    printf("%d\t%s\t%s", i + 1, students[i].roll, students[i].name);

    // Use another loop to write and print out the letter grade for each subject
    for (int j = 0; j < MAX_SUBJECTS; j++) {

        fprintf(studentGradesFile, "\t%s", students[i].letterGrade[j]);
        printf("\t%s", students[i].letterGrade[j]);

    }

    float earnefCredit= calculateEarnedCredits(students[i].gpa, creditHours, MAX_SUBJECTS );


    // Write and print out the earned credit hours and the CGPA of the student
    fprintf(studentGradesFile, "\t%.3f\t%.3f\n", earnefCredit , students[i].cgpa);
    printf("\t%.3f\t%.3f\n", earnefCredit , students[i].cgpa);
}

/// Print a message to indicate that the program is done
fprintf(studentGradesFile, "The program assumes that all subjects ahs Credit hours of 3.0,\
        As it is required to only read from 2 files of Student Info and Student Subject Marks files, but no Subjuct info Files.\
         The program is done. The student grades are written to the student_grades.txt file.\n");

// Close the student_grades.txt file
fclose(studentGradesFile);

// Close the StudentInf.txt file
fclose(studentInfoFile);

// Close the SubjectMark.txt file
fclose(subjectMarkFile);

// Print a message to indicate that the program is done
printf("The program assumes that all subjects ahs Credit hours of 3.0,\
        As it is required to only read from 2 files of Student Info and Student Subject Marks files, but no Subjuct info Files.\
         The program is done. The student grades are written to the student_grades.txt file.\n");

return 0;
}
=======
=======
>>>>>>> Stashed changes
/// QA 7
//Write a C program that takes Student Information and Marks from two different files and
//write student wise individual subject grade and GPA in another file. [File Templates and
//Instructions will be provided]

#include <stdio.h>
#include <string.h>

// Define some constants for the maximum number of students, subjects, and length of names
#define MAX_STUDENTS 20
#define MAX_SUBJECTS 5  // Change subjects accordingly
#define MAX_STUDENT_NAME_LENGTH 30
#define MAX_SUBJECT_NAME_LENGTH 10

/// Define a struct to store the student information
struct StudentInfo {
    char roll[15]; // The student roll number
    char name[MAX_STUDENT_NAME_LENGTH]; // The student name
    char subjectNames[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH]; // The subject names
    int marks[MAX_SUBJECTS]; // The marks in each subject
    float gpa[MAX_SUBJECTS]; // The GPA in each subject
    char letterGrade[MAX_SUBJECTS][3]; // The letter grade in each subject
    float cgpa; // The cumulative GPA
};

/// Function to calculate GPA from marks
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

/// Function to calculate letter grade from marks
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

/// Function to calculate CGPA from GPA and credit hours
float calculateCGPA(float gpa[], int creditHours[], int numSubjects) {
    float totalPoints = 0; // The total grade points earned
    float totalCredits = 0; // The total credit hours attempted
    for (int i = 0; i < numSubjects; i++) {
        totalPoints += gpa[i] * creditHours[i]; // Multiply GPA by credit hours for each subject
        if (gpa[i] == 0.0)
            continue; // dont add creditHours[i] to totalCredits if letterGrade is F
             totalCredits += creditHours[i]; // Add credit hours for each subject
    }
    return totalPoints / totalCredits; // Divide total grade points by total credit hours
}

/// Function to calculate Earned credit hours
float calculateEarnedCredits(float gpa[], int creditHours[], int numSubjects) {

    float totalCredits = 0; // The total credit hours attempted
    for (int i = 0; i < numSubjects; i++) {
           if (gpa[i] == 0.0)
            continue; // dont add creditHours[i] to totalCredits if letterGrade is F
             totalCredits += creditHours[i]; // Add credit hours for each subject
    }
    return totalCredits; // total grade points, Earned total credit hours
}


int main() {

    /// Open the StudentInf.txt file for reading
    FILE *studentInfoFile = fopen("StudentInf.txt", "r");

    // Check if the file is opened successfully
    if (studentInfoFile == NULL) {
        printf("Error opening StudentInf.txt.\n");
        return 1;
    }

    // Declare an array of StudentInfo structs to store the student information
    struct StudentInfo students[MAX_STUDENTS];

    // Declare a char array to store each line of the file
    char line[200];

    // Read and ignore the header line of the file
    fgets(line, sizeof(line), studentInfoFile);

    // Use a loop to read each line of the file until the end of the file is reached
    int numStudents = 0; // The number of students read from the file
    while (!feof(studentInfoFile)) {
        // Read a line from the file and store it in line
        fgets(line, sizeof(line), studentInfoFile);

        // Extract the roll and name from the line using sscanf()
        sscanf(line, "%*d %s %[^\n]", students[numStudents].roll, students[numStudents].name);

        // Increment the number of students
        numStudents++;

        // Break the loop if the maximum number of students is reached
        if (numStudents == MAX_STUDENTS) break;
    }

    // Close the StudentInf.txt file
    fclose(studentInfoFile);

    /// Open the SubjectMark.txt file for reading
    FILE *subjectMarkFile = fopen("SubjectMark.txt", "r");

    // Check if the file is opened successfully
    if (subjectMarkFile == NULL) {
        printf("Error opening SubjectMark.txt.\n");
        return 1;
    }

    // Read the header line of the file to get the subject names
    fgets(line, sizeof(line), subjectMarkFile);

    // Extract the subject names from the header line using sscanf()

//    char subjectNames[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH];
//
//    sscanf(line, "%*s %*s %[^\t] %[^\t] %[^\t] %[^\t] %[^\t]", subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4]);


// Declare an array to store subject names
char subjectNames[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH];

// Declare a char array to store the format string
char formatString[200] = "%*s %*s"; // Start with skipping the first two columns

// Use a loop to append the %[^\t] conversion specifier for each subject name
for (int i = 0; i < MAX_SUBJECTS; i++) {
    strcat(formatString, " %[^\t]");
}

// Use the format string and a variable argument list to extract the subject names from the line using sscanf()

sscanf(line, formatString, subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4]);



    // Use a loop to read each line of the file until the end of the file is reached
    int numStudents2 = 0; // The number of students read from the file
    while (!feof(subjectMarkFile)) {
        // Read a line from the file and store it in line
        fgets(line, sizeof(line), subjectMarkFile);

        // Extract the roll and marks from the line using sscanf()
        char roll[15]; // The roll number of the student
        int marks[MAX_SUBJECTS]; // The marks in each subject
        sscanf(line, "%*d %s %d %d %d %d %d", roll, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]);

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
            for (int i = 0; i < MAX_SUBJECTS; i++) {
                strcpy(students[index].subjectNames[i], subjectNames[i]); // Copy the subject name to the students array
                students[index].marks[i] = marks[i]; // Copy the mark to the students array
            }
        }

        // Increment the number of students
        numStudents2++;

        // Break the loop if the maximum number of students is reached
        if (numStudents2 == MAX_STUDENTS) break;
    }

    // Close the SubjectMark.txt file
    fclose(subjectMarkFile);

    // Declare an array of credit hours for each subject, assuming 3.0 credit hours for each subject
    int creditHours[MAX_SUBJECTS] = {3, 3, 3, 3, 3};

    // Use a loop to calculate and store the GPA, letter grade, and CGPA for each student in the students array
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            students[i].gpa[j] = calculateGPA(students[i].marks[j]); // Calculate and store the GPA for each subject using calculateGPA() function
            calculateLetterGrade(students[i].marks[j], students[i].letterGrade[j]); // Calculate and store the letter grade for each subject using calculateLetterGrade() function
        }
        students[i].cgpa = calculateCGPA(students[i].gpa, creditHours, MAX_SUBJECTS ); // Calculate and store the CGPA for each student using calculateCGPA() function
    }

    /// Open a new file called student_grades.txt for writing
    FILE *studentGradesFile = fopen("student_grades.txt", "w");

    // Check if the file is opened successfully
    if (studentGradesFile == NULL) {
        printf("Error opening student_grades.txt.\n");
        return 1;
    }

/// Write and print out a header line with column names to the file and console using fprintf() and printf()
fprintf(studentGradesFile, "Sl\tRoll\tName\tCSE 101\tCSE 102\tCSE 103\tCSE 104\tCSE 105\tEarned Credit Hours\tGPA\n");
printf("Sl\tRoll\tName\tCSE 101\tCSE 102\tCSE 103\tCSE 104\tCSE 105\tEarned Credit Hours\tGPA\n");

// Use a loop to write and print out each student's information to the file and console using fprintf() and printf()
for (int i = 0; i < numStudents; i++) {
    // Write and print out the serial number, roll number, and name of the student
    fprintf(studentGradesFile, "%d\t%s\t%s", i + 1, students[i].roll, students[i].name);
    printf("%d\t%s\t%s", i + 1, students[i].roll, students[i].name);

    // Use another loop to write and print out the letter grade for each subject
    for (int j = 0; j < MAX_SUBJECTS; j++) {

        fprintf(studentGradesFile, "\t%s", students[i].letterGrade[j]);
        printf("\t%s", students[i].letterGrade[j]);

    }

    float earnefCredit= calculateEarnedCredits(students[i].gpa, creditHours, MAX_SUBJECTS );


    // Write and print out the earned credit hours and the CGPA of the student
    fprintf(studentGradesFile, "\t%.3f\t%.3f\n", earnefCredit , students[i].cgpa);
    printf("\t%.3f\t%.3f\n", earnefCredit , students[i].cgpa);
}

/// Print a message to indicate that the program is done
fprintf(studentGradesFile, "The program assumes that all subjects ahs Credit hours of 3.0,\
        As it is required to only read from 2 files of Student Info and Student Subject Marks files, but no Subjuct info Files.\
         The program is done. The student grades are written to the student_grades.txt file.\n");

// Close the student_grades.txt file
fclose(studentGradesFile);

// Close the StudentInf.txt file
fclose(studentInfoFile);

// Close the SubjectMark.txt file
fclose(subjectMarkFile);

// Print a message to indicate that the program is done
printf("The program assumes that all subjects ahs Credit hours of 3.0,\
        As it is required to only read from 2 files of Student Info and Student Subject Marks files, but no Subjuct info Files.\
         The program is done. The student grades are written to the student_grades.txt file.\n");

return 0;
}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
