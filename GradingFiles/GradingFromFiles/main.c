<<<<<<< Updated upstream
<<<<<<< Updated upstream
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GradeMapping {
    int lowerBound;
    char grade[3];
    float gpa;
};

struct StudentInfo {
    char roll[20];
    char name[100];
};

struct SubjectMark {
    char roll[20];
    int marks[5];
    int creditHours [3];
};

int numGrades = 10;
struct GradeMapping gradeMappings[10];
int numSubjects = 5;
char subjectNames[5][10] = {"Sub1", "Sub2", "Sub3", "Sub4", "Sub5"};

int loadGradeMappings(const char *filename, struct GradeMapping *grades) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open %s\n", filename);
        return 1;
    }

    for (int i = 0; i < numGrades; i++) {
        fscanf(file, ">= %d %s %f\n", &grades[i].lowerBound, grades[i].grade, &grades[i].gpa);
    }

    fclose(file);
    return 0;
}

int loadStudentInfo(const char *filename, struct StudentInfo *students, int *numStudents) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open %s\n", filename);
        return 1;
    }

    *numStudents = 0;
    while ((*numStudents < 100) && fscanf(file, "%s %s\n", students[*numStudents].roll, students[*numStudents].name) == 2) {
        (*numStudents)++;
    }

    fclose(file);
    return 0;
}

int loadSubjectMarks(const char *filename, struct SubjectMark *marks, int *numMarks) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open %s\n", filename);
        return 1;
    }

    *numMarks = 0;
    while ((*numMarks < 100) && fscanf(file, "%s", marks[*numMarks].roll) == 1) {
        for (int i = 0; i < numSubjects; i++) {
            fscanf(file, "%d", &marks[*numMarks].marks[i]);
        }
        (*numMarks)++;
    }

    fclose(file);
    return 0;
}

float calculateSubjectGPA(int marks) {
    for (int i = 0; i < numGrades; i++) {
        if (marks >= gradeMappings[i].lowerBound) {
            return gradeMappings[i].gpa;
        }
    }
    return 0.0;
}

int main() {
    struct GradeMapping grades[10];
    if (loadGradeMappings("Grading.txt", grades) != 0) {
        return 1;
    }

    struct StudentInfo students[100];
    int numStudents;
    if (loadStudentInfo("StudentInf.txt", students, &numStudents) != 0) {
        return 1;
    }

    struct SubjectMark marks[100];
    int numMarks;
    if (loadSubjectMarks("SubjectMark.txt", marks, &numMarks) != 0) {
        return 1;
    }

    FILE *resultFile = fopen("Result.txt", "w");
    if (resultFile == NULL) {
        printf("Failed to open Result.txt for writing\n");
        return 1;
    }

    fprintf(resultFile, "Roll\tName");
    for (int i = 0; i < numSubjects; i++) {
        fprintf(resultFile, "\t%s", subjectNames[i]);
    }
    fprintf(resultFile, "\tGPA\n");

    for (int i = 0; i < numStudents; i++) {
        float totalGPA = 0.0;
        fprintf(resultFile, "%s\t%s", students[i].roll, students[i].name);
        for (int j = 0; j < numSubjects; j++) {
            float subjectGPA = calculateSubjectGPA(marks[i].marks[j]);
            totalGPA += subjectGPA;
            fprintf(resultFile, "\t%d(%.2f)", marks[i].marks[j], subjectGPA);
        }
        fprintf(resultFile, "\t%.2f\n", totalGPA / numSubjects);
    }

    fclose(resultFile);

    printf("Result.txt has been generated successfully.\n");

    return 0;
}
=======
=======
>>>>>>> Stashed changes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GradeMapping {
    int lowerBound;
    char grade[3];
    float gpa;
};

struct StudentInfo {
    char roll[20];
    char name[100];
};

struct SubjectMark {
    char roll[20];
    int marks[5];
    int creditHours [3];
};

int numGrades = 10;
struct GradeMapping gradeMappings[10];
int numSubjects = 5;
char subjectNames[5][10] = {"Sub1", "Sub2", "Sub3", "Sub4", "Sub5"};

int loadGradeMappings(const char *filename, struct GradeMapping *grades) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open %s\n", filename);
        return 1;
    }

    for (int i = 0; i < numGrades; i++) {
        fscanf(file, ">= %d %s %f\n", &grades[i].lowerBound, grades[i].grade, &grades[i].gpa);
    }

    fclose(file);
    return 0;
}

int loadStudentInfo(const char *filename, struct StudentInfo *students, int *numStudents) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open %s\n", filename);
        return 1;
    }

    *numStudents = 0;
    while ((*numStudents < 100) && fscanf(file, "%s %s\n", students[*numStudents].roll, students[*numStudents].name) == 2) {
        (*numStudents)++;
    }

    fclose(file);
    return 0;
}

int loadSubjectMarks(const char *filename, struct SubjectMark *marks, int *numMarks) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open %s\n", filename);
        return 1;
    }

    *numMarks = 0;
    while ((*numMarks < 100) && fscanf(file, "%s", marks[*numMarks].roll) == 1) {
        for (int i = 0; i < numSubjects; i++) {
            fscanf(file, "%d", &marks[*numMarks].marks[i]);
        }
        (*numMarks)++;
    }

    fclose(file);
    return 0;
}

float calculateSubjectGPA(int marks) {
    for (int i = 0; i < numGrades; i++) {
        if (marks >= gradeMappings[i].lowerBound) {
            return gradeMappings[i].gpa;
        }
    }
    return 0.0;
}

int main() {
    struct GradeMapping grades[10];
    if (loadGradeMappings("Grading.txt", grades) != 0) {
        return 1;
    }

    struct StudentInfo students[100];
    int numStudents;
    if (loadStudentInfo("StudentInf.txt", students, &numStudents) != 0) {
        return 1;
    }

    struct SubjectMark marks[100];
    int numMarks;
    if (loadSubjectMarks("SubjectMark.txt", marks, &numMarks) != 0) {
        return 1;
    }

    FILE *resultFile = fopen("Result.txt", "w");
    if (resultFile == NULL) {
        printf("Failed to open Result.txt for writing\n");
        return 1;
    }

    fprintf(resultFile, "Roll\tName");
    for (int i = 0; i < numSubjects; i++) {
        fprintf(resultFile, "\t%s", subjectNames[i]);
    }
    fprintf(resultFile, "\tGPA\n");

    for (int i = 0; i < numStudents; i++) {
        float totalGPA = 0.0;
        fprintf(resultFile, "%s\t%s", students[i].roll, students[i].name);
        for (int j = 0; j < numSubjects; j++) {
            float subjectGPA = calculateSubjectGPA(marks[i].marks[j]);
            totalGPA += subjectGPA;
            fprintf(resultFile, "\t%d(%.2f)", marks[i].marks[j], subjectGPA);
        }
        fprintf(resultFile, "\t%.2f\n", totalGPA / numSubjects);
    }

    fclose(resultFile);

    printf("Result.txt has been generated successfully.\n");

    return 0;
}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
