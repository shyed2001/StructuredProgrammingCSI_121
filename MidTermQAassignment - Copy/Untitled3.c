<<<<<<< Updated upstream
<<<<<<< Updated upstream
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store Subject marks for a student
struct SubjectMarks {
    char roll[20];
    char subjectName[100];
    int marks[5]; // Assuming 5 subjects
};

int main() {
    // Open the file for reading
    FILE *file = fopen("SubjectMark.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Skip the header line
    char header[256];
    fgets(header, sizeof(header), file);

    // Initialize an array to store Subject marks
    struct SubjectMarks subjectMarks[100]; // Assuming a maximum of 100 students

    int num_students = 0;

    // Read and process each line
    while (fgets(header, sizeof(header), file)) {
        // Parse the line into Roll, SubjectName, and SubjectMarks using tabs as delimiters
        char *token = strtok(header, "\t");
        if (token == NULL) {
            continue; // Skip empty lines
        }

        // Copy Roll into the struct
        strcpy(subjectMarks[num_students].roll, token);

        // Parse SubjectName
        token = strtok(NULL, "\t");
        if (token == NULL) {
            continue; // Skip incomplete lines
        }
        strcpy(subjectMarks[num_students].subjectName, token);

        // Parse and store SubjectMarks
        for (int i = 0; i < 5; i++) {
            token = strtok(NULL, "\t\n");
            if (token == NULL) {
                continue; // Skip incomplete lines
            }
            subjectMarks[num_students].marks[i] = atoi(token);
        }

        num_students++;

        // Ensure we don't exceed the array size
        if (num_students >= 100) {
            break;
        }
    }

    // Close the file
    fclose(file);

    // Print Roll, SubjectName, and SubjectMarks
    printf("Roll\tSubjectName\tCSE 101\tCSE 102\tCSE 103\tCSE 104\tCSE 105\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s\t%s", subjectMarks[i].roll, subjectMarks[i].subjectName);
        for (int j = 0; j < 5; j++) {
            printf("\t%d", subjectMarks[i].marks[j]);
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

// Structure to store Subject marks for a student
struct SubjectMarks {
    char roll[20];
    char subjectName[100];
    int marks[5]; // Assuming 5 subjects
};

int main() {
    // Open the file for reading
    FILE *file = fopen("SubjectMark.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Skip the header line
    char header[256];
    fgets(header, sizeof(header), file);

    // Initialize an array to store Subject marks
    struct SubjectMarks subjectMarks[100]; // Assuming a maximum of 100 students

    int num_students = 0;

    // Read and process each line
    while (fgets(header, sizeof(header), file)) {
        // Parse the line into Roll, SubjectName, and SubjectMarks using tabs as delimiters
        char *token = strtok(header, "\t");
        if (token == NULL) {
            continue; // Skip empty lines
        }

        // Copy Roll into the struct
        strcpy(subjectMarks[num_students].roll, token);

        // Parse SubjectName
        token = strtok(NULL, "\t");
        if (token == NULL) {
            continue; // Skip incomplete lines
        }
        strcpy(subjectMarks[num_students].subjectName, token);

        // Parse and store SubjectMarks
        for (int i = 0; i < 5; i++) {
            token = strtok(NULL, "\t\n");
            if (token == NULL) {
                continue; // Skip incomplete lines
            }
            subjectMarks[num_students].marks[i] = atoi(token);
        }

        num_students++;

        // Ensure we don't exceed the array size
        if (num_students >= 100) {
            break;
        }
    }

    // Close the file
    fclose(file);

    // Print Roll, SubjectName, and SubjectMarks
    printf("Roll\tSubjectName\tCSE 101\tCSE 102\tCSE 103\tCSE 104\tCSE 105\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s\t%s", subjectMarks[i].roll, subjectMarks[i].subjectName);
        for (int j = 0; j < 5; j++) {
            printf("\t%d", subjectMarks[i].marks[j]);
        }
        printf("\n");
    }

    return 0;
}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
