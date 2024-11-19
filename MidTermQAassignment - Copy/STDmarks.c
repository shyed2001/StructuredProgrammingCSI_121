<<<<<<< Updated upstream
<<<<<<< Updated upstream
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_ROLL_LENGTH 20
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 5
#define MAX_SUBJECT_NAME_LENGTH 50

#define MAX_GRADES 10
#define MAX_GRADE_NAME_LENGTH 10ng.h>

// Structure to store Subject marks for a student
struct SubjectMarks {
    char roll[20];
    char subjectName[100];
    int marks[5]; // Assuming 5 subjects
};

int main() {
FILE *subjectMarkFile = fopen("SubjectMark.txt", "r");
    if (subjectMarkFile == NULL) {
        printf("Error opening SubjectMark.txt.\n");
        return 1;
    }

 struct SubjectMarks studentMarks[MAX_STUDENTS];

    int numStudents33 = 0;

    char Lline[200]; // Adjust buffer size as needed

    // Read the header line to get subject names dynamically
    if (fgets(Lline, sizeof(Lline), subjectMarkFile) == NULL) {
        printf("Error reading header Lline.\n");
        fclose(subjectMarkFile);
        return 1;
    }
        printf("\n");

    // Extract subject names from the header line
    char subjectNames[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH];
    // scan or read the file
    sscanf(Lline, "%*s %*s %[^\t] %[^\t] %[^\t] %[^\t] %[^\t]",
           subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4]);


           // // Trim trailing newline characters from subject names
                      // // Trim trailing newline characters from subject names
for (int i = 0; i < 5; i++) {
    size_t len = strlen(subjectNames[i]);
    if (len > 0 && subjectNames[i][len - 1] == '\n') {
        subjectNames[i][len - 1] = '\0';
    }
}

    // Print header
    printf("Sl\tRoll\t%s\t%s\t%s\t%s\t%sGPA\n",
           subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4]);

    // Print header with for loop
              printf("Sl\tRoll\t");
            for (int i = 0; i < 5; i++)
            {    printf("%s\t", subjectNames[i]);

            }

   // // Print extracted subject names and their lengths
for (int i = 0; i < 5; i++) {
    printf("Subject %d: \"%s\" (Length: %zu)\n", i + 1, subjectNames[i], strlen(subjectNames[i]));
}

    while (fgets(Lline, sizeof(Lline), subjectMarkFile)) {
        if (Lline[0] == '\n') {
            // Skip empty lines
            continue;
        }

        // Extract values using sscanf
        char roll[MAX_ROLL_LENGTH];
        int marks[MAX_SUBJECTS];

        if (sscanf(Lline, "%*d %s %d %d %d %d %d", roll, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]) != 6) {
            printf("Error parsing student mark line: %s\n", Lline);
            fclose(subjectMarkFile);
            return 1;
        }

        strcpy(studentMarks[numStudents33].roll, roll);
        for (int i = 0; i < MAX_SUBJECTS; i++) {
            studentMarks[numStudents33].marks[i] = marks[i];
        }

        numStudents33++;

        if (numStudents33 >= MAX_STUDENTS) {
            printf("Maximum number of students reached.\n");
            break;
        }
    }

    fclose(subjectMarkFile);
        printf("\n");
    // Print Student Marks Information
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s", i + 1, studentMarks[i].roll);
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("\t%d", studentMarks[i].marks[j]);
        }
        printf("\n");
    }

//    Result result;
//
//    Result RESULT[numStudents];

    printf("________ %d \n ", studentMarks[numStudents33].marks[3]);

printf("____________________________________%d\n " , numStudents33);
printf("____________________________________%d\n" , numStudents);



     //Print Roll and Corresponding Names

//    printf("Sl\tRoll\tName\t");
//        // Print header with for loop
//            for (int i = 0; i <= 4; i++)
//            {    printf("%s\t", subjectNames[i]);
//                 //printf("\t");
//            }

printf("Sl    Roll    %s    %s    %s    %s    %s    GPA\n",subjectNames[0],subjectNames[1],subjectNames[2],subjectNames[3],subjectNames[4]);

    for (int i = 0, j = 0; i < numStudents, j < MAX_SUBJECTS; i++,j++) {
        printf("%s\t%s\t%d\n", students[i].roll, students[i].name,  studentMarks[i].marks[j]);

    }

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
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_ROLL_LENGTH 20
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 5
#define MAX_SUBJECT_NAME_LENGTH 50

#define MAX_GRADES 10
#define MAX_GRADE_NAME_LENGTH 10ng.h>

// Structure to store Subject marks for a student
struct SubjectMarks {
    char roll[20];
    char subjectName[100];
    int marks[5]; // Assuming 5 subjects
};

int main() {
FILE *subjectMarkFile = fopen("SubjectMark.txt", "r");
    if (subjectMarkFile == NULL) {
        printf("Error opening SubjectMark.txt.\n");
        return 1;
    }

 struct SubjectMarks studentMarks[MAX_STUDENTS];

    int numStudents33 = 0;

    char Lline[200]; // Adjust buffer size as needed

    // Read the header line to get subject names dynamically
    if (fgets(Lline, sizeof(Lline), subjectMarkFile) == NULL) {
        printf("Error reading header Lline.\n");
        fclose(subjectMarkFile);
        return 1;
    }
        printf("\n");

    // Extract subject names from the header line
    char subjectNames[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH];
    // scan or read the file
    sscanf(Lline, "%*s %*s %[^\t] %[^\t] %[^\t] %[^\t] %[^\t]",
           subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4]);


           // // Trim trailing newline characters from subject names
                      // // Trim trailing newline characters from subject names
for (int i = 0; i < 5; i++) {
    size_t len = strlen(subjectNames[i]);
    if (len > 0 && subjectNames[i][len - 1] == '\n') {
        subjectNames[i][len - 1] = '\0';
    }
}

    // Print header
    printf("Sl\tRoll\t%s\t%s\t%s\t%s\t%sGPA\n",
           subjectNames[0], subjectNames[1], subjectNames[2], subjectNames[3], subjectNames[4]);

    // Print header with for loop
              printf("Sl\tRoll\t");
            for (int i = 0; i < 5; i++)
            {    printf("%s\t", subjectNames[i]);

            }

   // // Print extracted subject names and their lengths
for (int i = 0; i < 5; i++) {
    printf("Subject %d: \"%s\" (Length: %zu)\n", i + 1, subjectNames[i], strlen(subjectNames[i]));
}

    while (fgets(Lline, sizeof(Lline), subjectMarkFile)) {
        if (Lline[0] == '\n') {
            // Skip empty lines
            continue;
        }

        // Extract values using sscanf
        char roll[MAX_ROLL_LENGTH];
        int marks[MAX_SUBJECTS];

        if (sscanf(Lline, "%*d %s %d %d %d %d %d", roll, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]) != 6) {
            printf("Error parsing student mark line: %s\n", Lline);
            fclose(subjectMarkFile);
            return 1;
        }

        strcpy(studentMarks[numStudents33].roll, roll);
        for (int i = 0; i < MAX_SUBJECTS; i++) {
            studentMarks[numStudents33].marks[i] = marks[i];
        }

        numStudents33++;

        if (numStudents33 >= MAX_STUDENTS) {
            printf("Maximum number of students reached.\n");
            break;
        }
    }

    fclose(subjectMarkFile);
        printf("\n");
    // Print Student Marks Information
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s", i + 1, studentMarks[i].roll);
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("\t%d", studentMarks[i].marks[j]);
        }
        printf("\n");
    }

//    Result result;
//
//    Result RESULT[numStudents];

    printf("________ %d \n ", studentMarks[numStudents33].marks[3]);

printf("____________________________________%d\n " , numStudents33);
printf("____________________________________%d\n" , numStudents);



     //Print Roll and Corresponding Names

//    printf("Sl\tRoll\tName\t");
//        // Print header with for loop
//            for (int i = 0; i <= 4; i++)
//            {    printf("%s\t", subjectNames[i]);
//                 //printf("\t");
//            }

printf("Sl    Roll    %s    %s    %s    %s    %s    GPA\n",subjectNames[0],subjectNames[1],subjectNames[2],subjectNames[3],subjectNames[4]);

    for (int i = 0, j = 0; i < numStudents, j < MAX_SUBJECTS; i++,j++) {
        printf("%s\t%s\t%d\n", students[i].roll, students[i].name,  studentMarks[i].marks[j]);

    }

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
