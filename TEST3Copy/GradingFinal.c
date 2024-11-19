<<<<<<< Updated upstream
<<<<<<< Updated upstream
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_ROLL_LENGTH 20
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 5
#define MAX_SUBJECT_NAME_LENGTH 50

#define MAX_GRADES 10
#define MAX_GRADE_NAME_LENGTH 10

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
    char roll[MAX_ROLL_LENGTH];
    char name[MAX_NAME_LENGTH];
} Student;

typedef struct {
    char subject[MAX_SUBJECT_NAME_LENGTH];
    float credit;
} Subject;

//typedef struct {
//  Student student; //roll name
//  Subject subject; // subjectName CreditHours
//  StudentMarks studentmarks; // stdRoll marks
//  GradeInfo gradeinfo;
//} Result;

    /***********************************************************/

/***********************************************************/


int main() {
    FILE *studentFile = fopen("StudentInf.txt", "r");
    if (studentFile == NULL) {
        printf("Error opening StudentInf.txt.\n");
        return 1;
    }



    FILE *subjectFile = fopen("SubjectInf.txt", "r");
    if (subjectFile == NULL) {
        printf("Error opening SubjectInf.txt.\n");
        fclose(studentFile);
        return 1;
    }

    Student students[MAX_STUDENTS];
    int numStudents = 0;

    Subject subjects[MAX_SUBJECTS];
    int numSubjects = 0;

    char line[MAX_ROLL_LENGTH + MAX_NAME_LENGTH + 2]; // +2 for potential newline and null terminator

    // Skip the first line in student file (attribute headers)
    fgets(line, sizeof(line), studentFile);

    while (fgets(line, sizeof(line), studentFile)) {
        if (line[0] == '\n') {
            // Skip empty lines
            continue;
        }

        // Extract roll and name using sscanf
        if (sscanf(line, "%s %[^\n]", students[numStudents].roll, students[numStudents].name) != 2) {
            printf("Error parsing student line: %s\n", line);
            fclose(studentFile);
            fclose(subjectFile);
            return 1;
        }

        numStudents++;

        if (numStudents >= MAX_STUDENTS) {
            printf("Maximum number of students reached.\n");
            break;
        }
    }

    printf("____________________________________%d" , numStudents);
    // Skip the first line in subject file (attribute headers)
    fgets(line, sizeof(line), subjectFile);

    while (fgets(line, sizeof(line), subjectFile)) {
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
            fclose(subjectFile);
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
    fclose(subjectFile);



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


        // Open or create a file named result.txt in write mode

        // Open a file named result in write mode
FILE *fp = fopen("Result.txt", "w");
//FILE *fp = fopen("resultsTest.txt", "w");

if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
}

if (fp != NULL) {
    printf("Successfully created and opened the file Result.txt\n");

}



                   // Print header with for loop
      char str0[] = "Sl";
      char str1[] = "Roll";
      char str2[] = "Name";
      char str3[20]; // allocate enough space for str3
      sprintf(str3, "%s    %s    %s    ",str0, str1, str2); // write formatted data to str3

      //fprintf(fp,"%s",str3); // prints Sl\tRoll\tName
          fputs(str3, fp); // prints Sl\tRoll\tName
                      // Print header with for loop
  //fprintf(fp, "Sl\tRoll\tName\t");
  for (int i = 0; i < 5; i++)
  {
      if (i<4)
      {
          fprintf(fp, "%s    ", subjectNames[i]);
          //fputs(subjectNames[i], fp);
      }
      else

          fprintf(fp, "    Weighted Credit   Earned Credit Hours    GPA\n");
          //fputs(subjectNames[i], fp);
          // fputs("GPA", fp);

       //fprintf(fp, "\t");
  }

//  // Print header
//fprintf(fp, "Sl\tRoll\tName\t");
//for (int i = 0; i < 5; i++) {
//    fprintf(fp, "%s    ", subjectNames[i]);
////    if (i < 4) {
////        fprintf(fp, "\t");
////    }
//}
//fprintf(fp, "GPA\n");
//




                          float sgpa = 0;
                          float cgpa = 0;
                          float WG = 0;
                          float StWG =0;

  printf("numGrades = %d , numSubjects = %d,  Sum Total Credit Hours StCi %f\n", numGrades, numSubjects, StCi);

     // Print student details with for loop
      for (int i = 0; i < numStudents; i++) {
         fprintf(fp, "%s\t%s", students[i].roll, students[i].name);
          for (int j = 0; j < MAX_SUBJECTS; j++) {
                for (int k = 0; k < numGrades; k++)
                  {
                  if((studentMarks[i].marks[j]>=grades[k].lowerBound)&&(studentMarks[i].marks[j]<=grades[k].upperBound))

                         {fprintf(fp,"\t%s", grades[k].gradeName);
                           //fprintf(fp, "\t%.2f %.2f",grades[k].gradePoint, subjects[j].credit);

                          WG = (grades[k].gradePoint*subjects[j].credit);
                          StWG+=WG;

                          if( grades[k].gradePoint == 0)
                                       {
                                         StCi = StCi-subjects[j].credit;
                                       }

                          }

                          sgpa= grades[k].gradePoint;

                          cgpa +=sgpa;

                          }


          }


       //fprintf(fp, "\t%.3f , %.3f %.2f %.3f \n", cgpa, StWG, StCi, (StWG/StCi) );
       //fprintf(fp, "cgpa, StWG, StCi, (StWG/StCi) \t%.3f , %.3f %.2f %.3f \n", cgpa, StWG, StCi, (StWG/StCi) );
       printf("cgpa, StWG, StCi, (StWG/StCi) \t%.3f , %.3f %.2f %.3f \n", cgpa, StWG, StCi, (StWG/StCi) );

       fprintf(fp, "    %.3f    %.3f    %.3f\n", StWG, StCi,(StWG/StCi) );  //Print to file,  Sum of Weighter Grade, Earned Credits and GPA
       sgpa = 0;
       cgpa = 0;
       WG = 0;
       StWG =0;
       StCi = 10.25;

      }




     //Print Grade Information
//    for (int k = 0; k < numGrades; k++) {
//        fprintf(fp,"%d\t%d\t%s\t%.2f\n", grades[k].lowerBound, grades[k].upperBound, grades[k].gradeName, grades[k].gradePoint);
//    }
//
//        for (int i = 0; i < numSubjects; i++) {
//        fprintf(fp, "%s\t%.2f\n", subjects[i].subject, subjects[i].credit);
//
//    }

    // Close the file


    fclose(fp);


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
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_ROLL_LENGTH 20
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 5
#define MAX_SUBJECT_NAME_LENGTH 50

#define MAX_GRADES 10
#define MAX_GRADE_NAME_LENGTH 10

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
    char roll[MAX_ROLL_LENGTH];
    char name[MAX_NAME_LENGTH];
} Student;

typedef struct {
    char subject[MAX_SUBJECT_NAME_LENGTH];
    float credit;
} Subject;

//typedef struct {
//  Student student; //roll name
//  Subject subject; // subjectName CreditHours
//  StudentMarks studentmarks; // stdRoll marks
//  GradeInfo gradeinfo;
//} Result;

    /***********************************************************/

/***********************************************************/


int main() {
    FILE *studentFile = fopen("StudentInf.txt", "r");
    if (studentFile == NULL) {
        printf("Error opening StudentInf.txt.\n");
        return 1;
    }



    FILE *subjectFile = fopen("SubjectInf.txt", "r");
    if (subjectFile == NULL) {
        printf("Error opening SubjectInf.txt.\n");
        fclose(studentFile);
        return 1;
    }

    Student students[MAX_STUDENTS];
    int numStudents = 0;

    Subject subjects[MAX_SUBJECTS];
    int numSubjects = 0;

    char line[MAX_ROLL_LENGTH + MAX_NAME_LENGTH + 2]; // +2 for potential newline and null terminator

    // Skip the first line in student file (attribute headers)
    fgets(line, sizeof(line), studentFile);

    while (fgets(line, sizeof(line), studentFile)) {
        if (line[0] == '\n') {
            // Skip empty lines
            continue;
        }

        // Extract roll and name using sscanf
        if (sscanf(line, "%s %[^\n]", students[numStudents].roll, students[numStudents].name) != 2) {
            printf("Error parsing student line: %s\n", line);
            fclose(studentFile);
            fclose(subjectFile);
            return 1;
        }

        numStudents++;

        if (numStudents >= MAX_STUDENTS) {
            printf("Maximum number of students reached.\n");
            break;
        }
    }

    printf("____________________________________%d" , numStudents);
    // Skip the first line in subject file (attribute headers)
    fgets(line, sizeof(line), subjectFile);

    while (fgets(line, sizeof(line), subjectFile)) {
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
            fclose(subjectFile);
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
    fclose(subjectFile);



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


        // Open or create a file named result.txt in write mode

        // Open a file named result in write mode
FILE *fp = fopen("Result.txt", "w");
//FILE *fp = fopen("resultsTest.txt", "w");

if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
}

if (fp != NULL) {
    printf("Successfully created and opened the file Result.txt\n");

}



                   // Print header with for loop
      char str0[] = "Sl";
      char str1[] = "Roll";
      char str2[] = "Name";
      char str3[20]; // allocate enough space for str3
      sprintf(str3, "%s    %s    %s    ",str0, str1, str2); // write formatted data to str3

      //fprintf(fp,"%s",str3); // prints Sl\tRoll\tName
          fputs(str3, fp); // prints Sl\tRoll\tName
                      // Print header with for loop
  //fprintf(fp, "Sl\tRoll\tName\t");
  for (int i = 0; i < 5; i++)
  {
      if (i<4)
      {
          fprintf(fp, "%s    ", subjectNames[i]);
          //fputs(subjectNames[i], fp);
      }
      else

          fprintf(fp, "    Weighted Credit   Earned Credit Hours    GPA\n");
          //fputs(subjectNames[i], fp);
          // fputs("GPA", fp);

       //fprintf(fp, "\t");
  }

//  // Print header
//fprintf(fp, "Sl\tRoll\tName\t");
//for (int i = 0; i < 5; i++) {
//    fprintf(fp, "%s    ", subjectNames[i]);
////    if (i < 4) {
////        fprintf(fp, "\t");
////    }
//}
//fprintf(fp, "GPA\n");
//




                          float sgpa = 0;
                          float cgpa = 0;
                          float WG = 0;
                          float StWG =0;

  printf("numGrades = %d , numSubjects = %d,  Sum Total Credit Hours StCi %f\n", numGrades, numSubjects, StCi);

     // Print student details with for loop
      for (int i = 0; i < numStudents; i++) {
         fprintf(fp, "%s\t%s", students[i].roll, students[i].name);
          for (int j = 0; j < MAX_SUBJECTS; j++) {
                for (int k = 0; k < numGrades; k++)
                  {
                  if((studentMarks[i].marks[j]>=grades[k].lowerBound)&&(studentMarks[i].marks[j]<=grades[k].upperBound))

                         {fprintf(fp,"\t%s", grades[k].gradeName);
                           //fprintf(fp, "\t%.2f %.2f",grades[k].gradePoint, subjects[j].credit);

                          WG = (grades[k].gradePoint*subjects[j].credit);
                          StWG+=WG;

                          if( grades[k].gradePoint == 0)
                                       {
                                         StCi = StCi-subjects[j].credit;
                                       }

                          }

                          sgpa= grades[k].gradePoint;

                          cgpa +=sgpa;

                          }


          }


       //fprintf(fp, "\t%.3f , %.3f %.2f %.3f \n", cgpa, StWG, StCi, (StWG/StCi) );
       //fprintf(fp, "cgpa, StWG, StCi, (StWG/StCi) \t%.3f , %.3f %.2f %.3f \n", cgpa, StWG, StCi, (StWG/StCi) );
       printf("cgpa, StWG, StCi, (StWG/StCi) \t%.3f , %.3f %.2f %.3f \n", cgpa, StWG, StCi, (StWG/StCi) );

       fprintf(fp, "    %.3f    %.3f    %.3f\n", StWG, StCi,(StWG/StCi) );  //Print to file,  Sum of Weighter Grade, Earned Credits and GPA
       sgpa = 0;
       cgpa = 0;
       WG = 0;
       StWG =0;
       StCi = 10.25;

      }




     //Print Grade Information
//    for (int k = 0; k < numGrades; k++) {
//        fprintf(fp,"%d\t%d\t%s\t%.2f\n", grades[k].lowerBound, grades[k].upperBound, grades[k].gradeName, grades[k].gradePoint);
//    }
//
//        for (int i = 0; i < numSubjects; i++) {
//        fprintf(fp, "%s\t%.2f\n", subjects[i].subject, subjects[i].credit);
//
//    }

    // Close the file


    fclose(fp);


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
