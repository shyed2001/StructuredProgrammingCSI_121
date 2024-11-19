<<<<<<< Updated upstream
<<<<<<< Updated upstream
// Write a C program to read roll and five subjects’ marks from MCSE.txt
// and write in another file name AvgMCSE.txt for roll and average marks.
//MCE07905536 Shyed Shahriar
///Ans:-

#include <stdio.h>

int main() {
    // Open MCSE.txt for reading
    FILE *mcseFile = fopen("MCSE.txt", "r");
    if (!mcseFile) {
        printf("Error opening MCSE.txt file.\n");
        return 1;
    }

    // Open AvgMCSE.txt for writing
    FILE *avgMCSEFile = fopen("AvgMCSE.txt", "w");
    if (!avgMCSEFile) {
        printf("Error opening AvgMCSE.txt file.\n");
        fclose(mcseFile);
        return 1;
    }

    int rollNumber;
    int marks[5];
    float averageMarks;

    // Read roll number and five subjects' marks from MCSE.txt
    while (fscanf(mcseFile, "%d %d %d %d %d %d\n", &rollNumber, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]) == 6) {
        // Check for division by zero
        if (marks[0] == 0 && marks[1] == 0 && marks[2] == 0 && marks[3] == 0 && marks[4] == 0) {
            printf("Warning: Division by zero for roll number %d. Skipping.\n", rollNumber);
            continue;
        }

        // Calculate average marks
        averageMarks = (marks[0] + marks[1] + marks[2] + marks[3] + marks[4]) / 5.0f;

        // Write roll number and average marks to AvgMCSE.txt
        fprintf(avgMCSEFile, "%d %.2f\n", rollNumber, averageMarks);
    }

    // Close both files
    fclose(mcseFile);
    fclose(avgMCSEFile);

    return 0;
}
=======
=======
>>>>>>> Stashed changes
// Write a C program to read roll and five subjects’ marks from MCSE.txt
// and write in another file name AvgMCSE.txt for roll and average marks.
//MCE07905536 Shyed Shahriar
///Ans:-

#include <stdio.h>

int main() {
    // Open MCSE.txt for reading
    FILE *mcseFile = fopen("MCSE.txt", "r");
    if (!mcseFile) {
        printf("Error opening MCSE.txt file.\n");
        return 1;
    }

    // Open AvgMCSE.txt for writing
    FILE *avgMCSEFile = fopen("AvgMCSE.txt", "w");
    if (!avgMCSEFile) {
        printf("Error opening AvgMCSE.txt file.\n");
        fclose(mcseFile);
        return 1;
    }

    int rollNumber;
    int marks[5];
    float averageMarks;

    // Read roll number and five subjects' marks from MCSE.txt
    while (fscanf(mcseFile, "%d %d %d %d %d %d\n", &rollNumber, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]) == 6) {
        // Check for division by zero
        if (marks[0] == 0 && marks[1] == 0 && marks[2] == 0 && marks[3] == 0 && marks[4] == 0) {
            printf("Warning: Division by zero for roll number %d. Skipping.\n", rollNumber);
            continue;
        }

        // Calculate average marks
        averageMarks = (marks[0] + marks[1] + marks[2] + marks[3] + marks[4]) / 5.0f;

        // Write roll number and average marks to AvgMCSE.txt
        fprintf(avgMCSEFile, "%d %.2f\n", rollNumber, averageMarks);
    }

    // Close both files
    fclose(mcseFile);
    fclose(avgMCSEFile);

    return 0;
}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
