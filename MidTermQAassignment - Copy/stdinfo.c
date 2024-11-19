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
#define MAX_GRADE_NAME_LENGTH 10



struct Student {
    int sl;
    char roll[20];
    char name[100];
};

typedef struct {
    char roll[MAX_ROLL_LENGTH];
    int marks[MAX_SUBJECTS];
} StudentMarks;

typedef struct {
    int lowerBound;
    int upperBound;
    char gradeName[MAX_GRADE_NAME_LENGTH];
    float gradePoint;
} GradeInfo;

typedef struct {
    char subject[MAX_SUBJECT_NAME_LENGTH];
    float credit;
} Subject;






int main() {
     // Open the file for reading
    FILE *studentFile = fopen("StudentInf.txt", "r");

    if (studentFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Skip the header line
    char header[256];
    fgets(header, sizeof(header), studentFile);

    // Initialize an array to store Student data
    struct Student students[100];  // Assuming a maximum of 100 students

    int numStudents = 0;
    int sl;
    char roll[20];
    char name[100];

    // Read and process each line
    while (fscanf(studentFile, "%d\t%s\t%[^\n]", &sl, roll, name) != EOF) {
        // Store the data into the array
        students[numStudents].sl = sl;
        strcpy(students[numStudents].roll, roll);
        strcpy(students[numStudents].name, name);

        numStudents++;

        // Ensure we don't exceed the array size
        if (numStudents >= 100) {
            break;
        }
    }

    // Close the file
    fclose(studentFile);

    // Print Sl, Roll, and Corresponding Names
    printf("Sl\tRoll\tName\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s\t%s\n", students[i].sl, students[i].roll, students[i].name);
    }



/**************************************************************/
/**************************************************************/
/**************************************************************/


        FILE *subjectFile = fopen("SubjectInf.txt", "r"); // SubjectInf.txt

    if (subjectFile == NULL)   // SubjectInf.txt
        {
        printf("Error opening SubjectInf.txt.\n"); //SubjectInf.txt
        fclose(subjectFile);
        return 1;
    }


    Subject subjects[MAX_SUBJECTS];
    int numSubjects = 0;

      char line[MAX_ROLL_LENGTH + MAX_NAME_LENGTH + 2]; // +2 for potential newline and null terminator

    // Skip the first line in subject file (attribute headers)

    fgets(line, sizeof(line), subjectFile); // SubjectInf.txt

    while (fgets(line, sizeof(line), subjectFile)) // SubjectInf.txt
        {
        if (line[0] == '\n') {
            // Skip empty lines
            continue;
        }

        // Extract subject and credit using sscanf
        char subjectName[MAX_SUBJECT_NAME_LENGTH];
        float credit;
        if (sscanf(line, "%[^\t] %f", subjectName, &credit) != 2) {
            printf("Error parsing subject line: %s\n", line);
            fclose(studentFile);
            fclose(subjectFile); // SubjectInf.txt
            return 1;
        }
        printf("\n");
        strcpy(subjects[numSubjects].subject, subjectName);
        subjects[numSubjects].credit = credit;

        numSubjects++;

        if (numSubjects >= MAX_SUBJECTS) {
            printf("Maximum number of subjects reached.\n");
            break;
        }
    }

    fclose(studentFile);
    fclose(subjectFile); // SubjectInf.txt

    /***********************************************************/

/***********************************************************/



    // Print Roll and Corresponding Names
    printf("Sl\tRoll\tName\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s\t%s\n", students[i].roll, students[i].name);
    }
        printf("\n");



    // Print Subject and Corresponding Credit
    printf("\nSubject\tCredit\n");
    float CI =0;
    float StCi =0;

    for (int i = 0; i < numSubjects; i++) {
        printf("%s\t%.2f\n", subjects[i].subject, subjects[i].credit);

        CI = subjects[i].credit;
        StCi+=CI;

    }


        /***********************************************************/

    /***********************************************************/

FILE *gradingFile = fopen("Grading.txt", "r");
    if (gradingFile == NULL) {
        printf("Error opening Grading.txt.\n");
        return 1;
    }

    GradeInfo grades[MAX_GRADES];
    int numGrades = 0;

    char lineG[100]; // Adjust buffer size as needed

    // Skip the first lineG in the grading file (attribute headers)
    fgets(lineG, sizeof(lineG), gradingFile);

    while (fgets(lineG, sizeof(lineG), gradingFile)) {
        if (lineG[0] == '\n') {
            // Skip empty lines
            continue;
        }

        // Extract values using sscanf
        int lowerBound, upperBound;
        char gradeName[MAX_GRADE_NAME_LENGTH];
        float gradePoint;

        if (sscanf(lineG, "%d\t%d\t%s\t%f", &lowerBound, &upperBound, gradeName, &gradePoint) != 4) {
            printf("Error parsing grading line: %s\n", lineG);
            fclose(gradingFile);
            return 1;
        }

        grades[numGrades].lowerBound = lowerBound;
        grades[numGrades].upperBound = upperBound;
        strcpy(grades[numGrades].gradeName, gradeName);
        grades[numGrades].gradePoint = gradePoint;

        numGrades++;

        if (numGrades >= MAX_GRADES) {
            printf("Maximum number of grades reached.\n");
            break;
        }
    }

    fclose(gradingFile);
        printf("\n");
    // Print header
    printf("LowerBound\tUpperBound\tLetterGrade\tGradePoint\n");

    // Print Grade Information
    for (int i = 0; i < numGrades; i++) {
        printf("%d\t%d\t%s\t%.2f\n", grades[i].lowerBound, grades[i].upperBound, grades[i].gradeName, grades[i].gradePoint);
    }


        printf("\n");
/***********************************************************/

FILE *subjectMarkFile = fopen("SubjectMark.txt", "r");
    if (subjectMarkFile == NULL) {
        printf("Error opening SubjectMark.txt.\n");
        return 1;
    }

    StudentMarks studentMarks[MAX_STUDENTS];

    int numStudents33 = 0;

    char Lline[200]; // Adjust buffer size as needed

    // Read the header line to get subject names dynamically
    if (fgets(Lline, sizeof(line), subjectMarkFile) == NULL) {
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


printf("numGrades = %d , numSubjects = %d,  Sum Total Credit Hours StCi %f\n", numGrades, numSubjects, StCi);

    // Print Subject and Corresponding Credit
    printf("\nSubject\tCredit\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("%s\t%.2f\n", subjects[i].subject, subjects[i].credit);
    }

        // //Print extracted subject names and their lengths
for (int i = 0; i < 5; i++) {
    printf("Subject %d: \"%s\" (Length: %zu)\n", i + 1, subjectNames[i], strlen(subjectNames[i]));
}




    return 0;  // of main program function


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
#define MAX_GRADE_NAME_LENGTH 10



struct Student {
    int sl;
    char roll[20];
    char name[100];
};

typedef struct {
    char roll[MAX_ROLL_LENGTH];
    int marks[MAX_SUBJECTS];
} StudentMarks;

typedef struct {
    int lowerBound;
    int upperBound;
    char gradeName[MAX_GRADE_NAME_LENGTH];
    float gradePoint;
} GradeInfo;

typedef struct {
    char subject[MAX_SUBJECT_NAME_LENGTH];
    float credit;
} Subject;






int main() {
     // Open the file for reading
    FILE *studentFile = fopen("StudentInf.txt", "r");

    if (studentFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Skip the header line
    char header[256];
    fgets(header, sizeof(header), studentFile);

    // Initialize an array to store Student data
    struct Student students[100];  // Assuming a maximum of 100 students

    int numStudents = 0;
    int sl;
    char roll[20];
    char name[100];

    // Read and process each line
    while (fscanf(studentFile, "%d\t%s\t%[^\n]", &sl, roll, name) != EOF) {
        // Store the data into the array
        students[numStudents].sl = sl;
        strcpy(students[numStudents].roll, roll);
        strcpy(students[numStudents].name, name);

        numStudents++;

        // Ensure we don't exceed the array size
        if (numStudents >= 100) {
            break;
        }
    }

    // Close the file
    fclose(studentFile);

    // Print Sl, Roll, and Corresponding Names
    printf("Sl\tRoll\tName\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s\t%s\n", students[i].sl, students[i].roll, students[i].name);
    }



/**************************************************************/
/**************************************************************/
/**************************************************************/


        FILE *subjectFile = fopen("SubjectInf.txt", "r"); // SubjectInf.txt

    if (subjectFile == NULL)   // SubjectInf.txt
        {
        printf("Error opening SubjectInf.txt.\n"); //SubjectInf.txt
        fclose(subjectFile);
        return 1;
    }


    Subject subjects[MAX_SUBJECTS];
    int numSubjects = 0;

      char line[MAX_ROLL_LENGTH + MAX_NAME_LENGTH + 2]; // +2 for potential newline and null terminator

    // Skip the first line in subject file (attribute headers)

    fgets(line, sizeof(line), subjectFile); // SubjectInf.txt

    while (fgets(line, sizeof(line), subjectFile)) // SubjectInf.txt
        {
        if (line[0] == '\n') {
            // Skip empty lines
            continue;
        }

        // Extract subject and credit using sscanf
        char subjectName[MAX_SUBJECT_NAME_LENGTH];
        float credit;
        if (sscanf(line, "%[^\t] %f", subjectName, &credit) != 2) {
            printf("Error parsing subject line: %s\n", line);
            fclose(studentFile);
            fclose(subjectFile); // SubjectInf.txt
            return 1;
        }
        printf("\n");
        strcpy(subjects[numSubjects].subject, subjectName);
        subjects[numSubjects].credit = credit;

        numSubjects++;

        if (numSubjects >= MAX_SUBJECTS) {
            printf("Maximum number of subjects reached.\n");
            break;
        }
    }

    fclose(studentFile);
    fclose(subjectFile); // SubjectInf.txt

    /***********************************************************/

/***********************************************************/



    // Print Roll and Corresponding Names
    printf("Sl\tRoll\tName\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s\t%s\n", students[i].roll, students[i].name);
    }
        printf("\n");



    // Print Subject and Corresponding Credit
    printf("\nSubject\tCredit\n");
    float CI =0;
    float StCi =0;

    for (int i = 0; i < numSubjects; i++) {
        printf("%s\t%.2f\n", subjects[i].subject, subjects[i].credit);

        CI = subjects[i].credit;
        StCi+=CI;

    }


        /***********************************************************/

    /***********************************************************/

FILE *gradingFile = fopen("Grading.txt", "r");
    if (gradingFile == NULL) {
        printf("Error opening Grading.txt.\n");
        return 1;
    }

    GradeInfo grades[MAX_GRADES];
    int numGrades = 0;

    char lineG[100]; // Adjust buffer size as needed

    // Skip the first lineG in the grading file (attribute headers)
    fgets(lineG, sizeof(lineG), gradingFile);

    while (fgets(lineG, sizeof(lineG), gradingFile)) {
        if (lineG[0] == '\n') {
            // Skip empty lines
            continue;
        }

        // Extract values using sscanf
        int lowerBound, upperBound;
        char gradeName[MAX_GRADE_NAME_LENGTH];
        float gradePoint;

        if (sscanf(lineG, "%d\t%d\t%s\t%f", &lowerBound, &upperBound, gradeName, &gradePoint) != 4) {
            printf("Error parsing grading line: %s\n", lineG);
            fclose(gradingFile);
            return 1;
        }

        grades[numGrades].lowerBound = lowerBound;
        grades[numGrades].upperBound = upperBound;
        strcpy(grades[numGrades].gradeName, gradeName);
        grades[numGrades].gradePoint = gradePoint;

        numGrades++;

        if (numGrades >= MAX_GRADES) {
            printf("Maximum number of grades reached.\n");
            break;
        }
    }

    fclose(gradingFile);
        printf("\n");
    // Print header
    printf("LowerBound\tUpperBound\tLetterGrade\tGradePoint\n");

    // Print Grade Information
    for (int i = 0; i < numGrades; i++) {
        printf("%d\t%d\t%s\t%.2f\n", grades[i].lowerBound, grades[i].upperBound, grades[i].gradeName, grades[i].gradePoint);
    }


        printf("\n");
/***********************************************************/

FILE *subjectMarkFile = fopen("SubjectMark.txt", "r");
    if (subjectMarkFile == NULL) {
        printf("Error opening SubjectMark.txt.\n");
        return 1;
    }

    StudentMarks studentMarks[MAX_STUDENTS];

    int numStudents33 = 0;

    char Lline[200]; // Adjust buffer size as needed

    // Read the header line to get subject names dynamically
    if (fgets(Lline, sizeof(line), subjectMarkFile) == NULL) {
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


printf("numGrades = %d , numSubjects = %d,  Sum Total Credit Hours StCi %f\n", numGrades, numSubjects, StCi);

    // Print Subject and Corresponding Credit
    printf("\nSubject\tCredit\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("%s\t%.2f\n", subjects[i].subject, subjects[i].credit);
    }

        // //Print extracted subject names and their lengths
for (int i = 0; i < 5; i++) {
    printf("Subject %d: \"%s\" (Length: %zu)\n", i + 1, subjectNames[i], strlen(subjectNames[i]));
}




    return 0;  // of main program function


}


<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
