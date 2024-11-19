<<<<<<< Updated upstream
<<<<<<< Updated upstream
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Convert Grading.txt to Grading.csv
    FILE *gradingInputFile = fopen("Grading.txt", "r");
    // Open input file Grading.txt in read mode.
    if (gradingInputFile == NULL) {
        printf("Failed to open Grading.txt\n");
        return 1;
    }

    FILE *gradingOutputFile = fopen("Grading.csv", "w");
    // Open output file Grading.csv in write mode.
    if (gradingOutputFile == NULL) {
        printf("Failed to create Grading.csv\n");
        fclose(gradingInputFile);
        return 1;
    }

    char gradingLine[100];
    while (fgets(gradingLine, sizeof(gradingLine), gradingInputFile)) {
        // Read a line from the input file into gradingLine array.
        char *token = strtok(gradingLine, "\t\n");
        // Split the line into tokens using tabs and newlines as delimiters. Store the first token in the token variable.
        while (token != NULL) {
            fprintf(gradingOutputFile, "%s,", token);
            // Write the token to the output file, followed by a comma.
            token = strtok(NULL, "\t\n");
            // Get the next token from the line.
        }
        fseek(gradingOutputFile, -1, SEEK_CUR);
        // Move the file pointer back one character to remove the last comma.
        fprintf(gradingOutputFile, "\n");
        // Write a newline character to the output file.
    }

    fclose(gradingInputFile);
    // Close the input file.
    fclose(gradingOutputFile);
    // Close the output file.

    printf("CSV file 'Grading.csv' has been generated successfully.\n");

    // Convert StudentInf.txt to StudentInf.csv
    FILE *studentInputFile = fopen("StudentInf.txt", "r");
    // Open input file StudentInf.txt in read mode.
    if (studentInputFile == NULL) {
        printf("Failed to open StudentInf.txt\n");
        return 1;
    }

    FILE *studentOutputFile = fopen("StudentInf.csv", "w");
    // Open output file StudentInf.csv in write mode.
    if (studentOutputFile == NULL) {
        printf("Failed to create StudentInf.csv\n");
        fclose(studentInputFile);
        return 1;
    }

    char studentLine[100];
    while (fgets(studentLine, sizeof(studentLine), studentInputFile)) {
        // Read a line from the input file into studentLine array.
        char *token = strtok(studentLine, "\t\n");
        // Split the line into tokens using tabs and newlines as delimiters. Store the first token in the token variable.
        while (token != NULL) {
            fprintf(studentOutputFile, "%s,", token);
            // Write the token to the output file, followed by a comma.
            token = strtok(NULL, "\t\n");
            // Get the next token from the line.
        }
        fseek(studentOutputFile, -1, SEEK_CUR);
        // Move the file pointer back one character to remove the last comma.
        fprintf(studentOutputFile, "\n");
        // Write a newline character to the output file.
    }

    fclose(studentInputFile);
    // Close the input file.
    fclose(studentOutputFile);
    // Close the output file.

    printf("CSV file 'StudentInf.csv' has been generated successfully.\n");

    // Convert SubjectMark.txt to SubjectMark.csv
    FILE *subjectInputFile = fopen("SubjectMark.txt", "r");
    // Open input file SubjectMark.txt in read mode.
    if (subjectInputFile == NULL) {
        printf("Failed to open SubjectMark.txt\n");
        return 1;
    }

    FILE *subjectOutputFile = fopen("SubjectMark.csv", "w");
    // Open output file SubjectMark.csv in write mode.
    if (subjectOutputFile == NULL) {
        printf("Failed to create SubjectMark.csv\n");
        fclose(subjectInputFile);
        return 1;
    }

    char subjectLine[100];
    while (fgets(subjectLine, sizeof(subjectLine), subjectInputFile)) {
        // Read a line from the input file into subjectLine array.
        char *token = strtok(subjectLine, "\t\n");
        // Split the line into tokens using tabs and newlines as delimiters. Store the first token in the token variable.
        while (token != NULL) {
            fprintf(subjectOutputFile, "%s,", token);
            // Write the token to the output file, followed by a comma.
            token = strtok(NULL, "\t\n");
            // Get the next token from the line.
        }
        fseek(subjectOutputFile, -1, SEEK_CUR);
        // Move the file pointer back one character to remove the last comma.
        fprintf(subjectOutputFile, "\n");
        // Write a newline character to the output file.
    }

    fclose(subjectInputFile);
    // Close the input file.
    fclose(subjectOutputFile);
    // Close the output file.

    printf("CSV file 'SubjectMark.csv' has been generated successfully.\n");

    return 0;
    // Return 0 to indicate successful execution.
}


/* It reads data from three input text files (Grading.txt, StudentInf.txt, SubjectMark.txt) and converts them into corresponding CSV files (Grading.csv, StudentInf.csv, SubjectMark.csv).
 * It uses the strtok function to tokenize lines from input files using tab and newline characters as delimiters.
 * It writes the tokenized data into the respective output CSV files, separating values with commas and adding newlines at the end of each line.
 * It handles file I/O errors and closes the input and output files properly.
 * Finally, it provides feedback to the user about the success of the conversion proces
 */
//* #include <stdio.h>
// * #include <stdlib.h>
// * #include <string.h>
// *
// * /* This program converts a text file to a CSV file. */
// *
// * int main() {
// *     /* Open the input file. */
// *     FILE *inputFile = fopen("Grading.txt", "r");
// *     if (inputFile == NULL) {
// *         printf("Failed to open Grading.txt\n");
// *         return 1;
// *     }
// *
// *     /* Open the output file. */
// *     FILE *outputFile = fopen("Grading.csv", "w");
// *     if (outputFile == NULL) {
// *         printf("Failed to create Grading.csv\n");
// *         fclose(inputFile);
// *         return 1;
// *     }
// *
// *     /* Read each line from the input file. */
// *     char line[100];
// *     while (fgets(line, sizeof(line), inputFile)) {
// *         /* Split the line into tokens. */
// *         char *token = strtok(line, "\t\n");
// *
// *         /* Iterate over the tokens. */
// *         while (token != NULL) {
// *             /* Write the token to the output file, followed by a comma. */
// *             fprintf(outputFile, "%s,", token);
// *
// *             /* Get the next token. */
// *             token = strtok(NULL, "\t\n");
// *         }
// *
// *         /* Remove the last comma from the output file. */
// *         fseek(outputFile, -1, SEEK_CUR);
// *         fprintf(outputFile, "\n");
// *     }
// *
// *     /* Close the input file. */
// *     fclose(inputFile);
// *
// *     /* Close the output file. */
// *     fclose(outputFile);
// *
// *     /* Print a success message. */
// *     printf("CSV file 'Grading.csv' has been generated successfully.\n");
// *
// *     return 0;
// * }
// * /*
// *  * FILE *inputFile = fopen("Grading.txt", "r"); opens the input file Grading.txt in read mode.
// *  * if (inputFile == NULL) { checks if the file was opened successfully. If not, the program prints an error message and returns 1.
// *  * FILE *outputFile = fopen("Grading.csv", "w"); opens the output file Grading.csv in write mode.
// *  * if (outputFile == NULL) { checks if the file was created successfully. If not, the program prints an error message and closes the input file.
// *  * char line[100]; declares a character array to store each line from the input file.
// *  * while (fgets(line, sizeof(line), inputFile)) { reads a line from the input file and stores it in the line array. The loop continues as long as there are more lines to read.
// *  * char *token = strtok(line, "\t\n"); splits the line array into tokens, separated by tabs (\t) and newline characters (\n). The first token is stored in the token variable.
// *  * while (token != NULL) { iterates over the tokens.
// *  * fprintf(outputFile, "%s,", token); writes the token variable to the output file, followed by a comma.
// *  * token = strtok(NULL, "\t\n"); gets the next token from the line array.
// *  * fseek(outputFile, -1, SEEK_CUR); moves the file pointer back one character in the output file. This removes the last comma from the output file.
// *  * fprintf(outputFile, "\n"); writes a newline character to the output file.
// *  * fclose(inputFile); closes the input file.
// *  * fclose(outputFile); closes the output file.
// *  * printf("CSV file 'Grading.csv' has been generated successfully.\n"); prints a success message.
// *  * return 0; returns 0, indicating that the program was successful. */
// */



/* It reads data from three input text files (Grading.txt, StudentInf.txt, SubjectMark.txt) and converts them into corresponding CSV files (Grading.csv, StudentInf.csv, SubjectMark.csv).
 * It uses the strtok function to tokenize lines from input files using tab and newline characters as delimiters.
 * It writes the tokenized data into the respective output CSV files, separating values with commas and adding newlines at the end of each line.
 * It handles file I/O errors and closes the input and output files properly.
 * Finally, it provides feedback to the user about the success of the conversion proces
 */
//* #include <stdio.h>
// * #include <stdlib.h>
// * #include <string.h>
// *
// * /* This program converts a text file to a CSV file. */
// *
// * int main() {
// *     /* Open the input file. */
// *     FILE *inputFile = fopen("Grading.txt", "r");
// *     if (inputFile == NULL) {
// *         printf("Failed to open Grading.txt\n");
// *         return 1;
// *     }
// *
// *     /* Open the output file. */
// *     FILE *outputFile = fopen("Grading.csv", "w");
// *     if (outputFile == NULL) {
// *         printf("Failed to create Grading.csv\n");
// *         fclose(inputFile);
// *         return 1;
// *     }
// *
// *     /* Read each line from the input file. */
// *     char line[100];
// *     while (fgets(line, sizeof(line), inputFile)) {
// *         /* Split the line into tokens. */
// *         char *token = strtok(line, "\t\n");
// *
// *         /* Iterate over the tokens. */
// *         while (token != NULL) {
// *             /* Write the token to the output file, followed by a comma. */
// *             fprintf(outputFile, "%s,", token);
// *
// *             /* Get the next token. */
// *             token = strtok(NULL, "\t\n");
// *         }
// *
// *         /* Remove the last comma from the output file. */
// *         fseek(outputFile, -1, SEEK_CUR);
// *         fprintf(outputFile, "\n");
// *     }
// *
// *     /* Close the input file. */
// *     fclose(inputFile);
// *
// *     /* Close the output file. */
// *     fclose(outputFile);
// *
// *     /* Print a success message. */
// *     printf("CSV file 'Grading.csv' has been generated successfully.\n");
// *
// *     return 0;
// * }
// * /*
// *  * FILE *inputFile = fopen("Grading.txt", "r"); opens the input file Grading.txt in read mode.
// *  * if (inputFile == NULL) { checks if the file was opened successfully. If not, the program prints an error message and returns 1.
// *  * FILE *outputFile = fopen("Grading.csv", "w"); opens the output file Grading.csv in write mode.
// *  * if (outputFile == NULL) { checks if the file was created successfully. If not, the program prints an error message and closes the input file.
// *  * char line[100]; declares a character array to store each line from the input file.
// *  * while (fgets(line, sizeof(line), inputFile)) { reads a line from the input file and stores it in the line array. The loop continues as long as there are more lines to read.
// *  * char *token = strtok(line, "\t\n"); splits the line array into tokens, separated by tabs (\t) and newline characters (\n). The first token is stored in the token variable.
// *  * while (token != NULL) { iterates over the tokens.
// *  * fprintf(outputFile, "%s,", token); writes the token variable to the output file, followed by a comma.
// *  * token = strtok(NULL, "\t\n"); gets the next token from the line array.
// *  * fseek(outputFile, -1, SEEK_CUR); moves the file pointer back one character in the output file. This removes the last comma from the output file.
// *  * fprintf(outputFile, "\n"); writes a newline character to the output file.
// *  * fclose(inputFile); closes the input file.
// *  * fclose(outputFile); closes the output file.
// *  * printf("CSV file 'Grading.csv' has been generated successfully.\n"); prints a success message.
// *  * return 0; returns 0, indicating that the program was successful. */
// */


/* The code you provided appears to be a C program that reads data from three input text files ("Grading.txt," "StudentInf.txt," and "SubjectMark.txt") and then converts and writes the data into corresponding output CSV files ("Grading.csv," "StudentInf.csv," and "SubjectMark.csv"). The data in the input text files is assumed to be tab-separated.
 *
 * Here's a breakdown of how the code works:
 *
 * The program first opens the input text file ("Grading.txt") and checks if it was opened successfully. If not, it prints an error message and exits with a return code of 1.
 *
 * It then opens the corresponding output CSV file ("Grading.csv") in write mode. If this operation fails, it prints an error message, closes the input file, and exits with a return code of 1.
 *
 * The program reads lines from the input file, tokenizes each line using tab and newline characters as delimiters, and writes the tokens followed by commas into the output CSV file.
 *
 * After processing each line, the program moves the file pointer back by one character (using fseek) to remove the trailing comma, and then writes a newline character to start a new line in the CSV file.
 *
 * The same process is repeated for the other two input files ("StudentInf.txt" and "SubjectMark.txt") to generate their corresponding CSV output files.
 *
 * Finally, the program closes all opened files and prints a success message before returning 0 to indicate successful execution.
 *
 * It's worth noting that the code provided is repetitive and can be further optimized by creating a function to handle the conversion process for each input file. This would reduce code duplication and improve maintainability.
 *
 * Also, consider adding additional error handling and validation for potential issues, such as handling cases where the input data format is unexpected or corrupted.
 *
 * Please make sure you have the input files ("Grading.txt," "StudentInf.txt," and "SubjectMark.txt") in the same directory as the executable of this program before running it.
 *
 *
 *
 *
 */
=======
=======
>>>>>>> Stashed changes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Convert Grading.txt to Grading.csv
    FILE *gradingInputFile = fopen("Grading.txt", "r");
    // Open input file Grading.txt in read mode.
    if (gradingInputFile == NULL) {
        printf("Failed to open Grading.txt\n");
        return 1;
    }

    FILE *gradingOutputFile = fopen("Grading.csv", "w");
    // Open output file Grading.csv in write mode.
    if (gradingOutputFile == NULL) {
        printf("Failed to create Grading.csv\n");
        fclose(gradingInputFile);
        return 1;
    }

    char gradingLine[100];
    while (fgets(gradingLine, sizeof(gradingLine), gradingInputFile)) {
        // Read a line from the input file into gradingLine array.
        char *token = strtok(gradingLine, "\t\n");
        // Split the line into tokens using tabs and newlines as delimiters. Store the first token in the token variable.
        while (token != NULL) {
            fprintf(gradingOutputFile, "%s,", token);
            // Write the token to the output file, followed by a comma.
            token = strtok(NULL, "\t\n");
            // Get the next token from the line.
        }
        fseek(gradingOutputFile, -1, SEEK_CUR);
        // Move the file pointer back one character to remove the last comma.
        fprintf(gradingOutputFile, "\n");
        // Write a newline character to the output file.
    }

    fclose(gradingInputFile);
    // Close the input file.
    fclose(gradingOutputFile);
    // Close the output file.

    printf("CSV file 'Grading.csv' has been generated successfully.\n");

    // Convert StudentInf.txt to StudentInf.csv
    FILE *studentInputFile = fopen("StudentInf.txt", "r");
    // Open input file StudentInf.txt in read mode.
    if (studentInputFile == NULL) {
        printf("Failed to open StudentInf.txt\n");
        return 1;
    }

    FILE *studentOutputFile = fopen("StudentInf.csv", "w");
    // Open output file StudentInf.csv in write mode.
    if (studentOutputFile == NULL) {
        printf("Failed to create StudentInf.csv\n");
        fclose(studentInputFile);
        return 1;
    }

    char studentLine[100];
    while (fgets(studentLine, sizeof(studentLine), studentInputFile)) {
        // Read a line from the input file into studentLine array.
        char *token = strtok(studentLine, "\t\n");
        // Split the line into tokens using tabs and newlines as delimiters. Store the first token in the token variable.
        while (token != NULL) {
            fprintf(studentOutputFile, "%s,", token);
            // Write the token to the output file, followed by a comma.
            token = strtok(NULL, "\t\n");
            // Get the next token from the line.
        }
        fseek(studentOutputFile, -1, SEEK_CUR);
        // Move the file pointer back one character to remove the last comma.
        fprintf(studentOutputFile, "\n");
        // Write a newline character to the output file.
    }

    fclose(studentInputFile);
    // Close the input file.
    fclose(studentOutputFile);
    // Close the output file.

    printf("CSV file 'StudentInf.csv' has been generated successfully.\n");

    // Convert SubjectMark.txt to SubjectMark.csv
    FILE *subjectInputFile = fopen("SubjectMark.txt", "r");
    // Open input file SubjectMark.txt in read mode.
    if (subjectInputFile == NULL) {
        printf("Failed to open SubjectMark.txt\n");
        return 1;
    }

    FILE *subjectOutputFile = fopen("SubjectMark.csv", "w");
    // Open output file SubjectMark.csv in write mode.
    if (subjectOutputFile == NULL) {
        printf("Failed to create SubjectMark.csv\n");
        fclose(subjectInputFile);
        return 1;
    }

    char subjectLine[100];
    while (fgets(subjectLine, sizeof(subjectLine), subjectInputFile)) {
        // Read a line from the input file into subjectLine array.
        char *token = strtok(subjectLine, "\t\n");
        // Split the line into tokens using tabs and newlines as delimiters. Store the first token in the token variable.
        while (token != NULL) {
            fprintf(subjectOutputFile, "%s,", token);
            // Write the token to the output file, followed by a comma.
            token = strtok(NULL, "\t\n");
            // Get the next token from the line.
        }
        fseek(subjectOutputFile, -1, SEEK_CUR);
        // Move the file pointer back one character to remove the last comma.
        fprintf(subjectOutputFile, "\n");
        // Write a newline character to the output file.
    }

    fclose(subjectInputFile);
    // Close the input file.
    fclose(subjectOutputFile);
    // Close the output file.

    printf("CSV file 'SubjectMark.csv' has been generated successfully.\n");

    return 0;
    // Return 0 to indicate successful execution.
}


/* It reads data from three input text files (Grading.txt, StudentInf.txt, SubjectMark.txt) and converts them into corresponding CSV files (Grading.csv, StudentInf.csv, SubjectMark.csv).
 * It uses the strtok function to tokenize lines from input files using tab and newline characters as delimiters.
 * It writes the tokenized data into the respective output CSV files, separating values with commas and adding newlines at the end of each line.
 * It handles file I/O errors and closes the input and output files properly.
 * Finally, it provides feedback to the user about the success of the conversion proces
 */
//* #include <stdio.h>
// * #include <stdlib.h>
// * #include <string.h>
// *
// * /* This program converts a text file to a CSV file. */
// *
// * int main() {
// *     /* Open the input file. */
// *     FILE *inputFile = fopen("Grading.txt", "r");
// *     if (inputFile == NULL) {
// *         printf("Failed to open Grading.txt\n");
// *         return 1;
// *     }
// *
// *     /* Open the output file. */
// *     FILE *outputFile = fopen("Grading.csv", "w");
// *     if (outputFile == NULL) {
// *         printf("Failed to create Grading.csv\n");
// *         fclose(inputFile);
// *         return 1;
// *     }
// *
// *     /* Read each line from the input file. */
// *     char line[100];
// *     while (fgets(line, sizeof(line), inputFile)) {
// *         /* Split the line into tokens. */
// *         char *token = strtok(line, "\t\n");
// *
// *         /* Iterate over the tokens. */
// *         while (token != NULL) {
// *             /* Write the token to the output file, followed by a comma. */
// *             fprintf(outputFile, "%s,", token);
// *
// *             /* Get the next token. */
// *             token = strtok(NULL, "\t\n");
// *         }
// *
// *         /* Remove the last comma from the output file. */
// *         fseek(outputFile, -1, SEEK_CUR);
// *         fprintf(outputFile, "\n");
// *     }
// *
// *     /* Close the input file. */
// *     fclose(inputFile);
// *
// *     /* Close the output file. */
// *     fclose(outputFile);
// *
// *     /* Print a success message. */
// *     printf("CSV file 'Grading.csv' has been generated successfully.\n");
// *
// *     return 0;
// * }
// * /*
// *  * FILE *inputFile = fopen("Grading.txt", "r"); opens the input file Grading.txt in read mode.
// *  * if (inputFile == NULL) { checks if the file was opened successfully. If not, the program prints an error message and returns 1.
// *  * FILE *outputFile = fopen("Grading.csv", "w"); opens the output file Grading.csv in write mode.
// *  * if (outputFile == NULL) { checks if the file was created successfully. If not, the program prints an error message and closes the input file.
// *  * char line[100]; declares a character array to store each line from the input file.
// *  * while (fgets(line, sizeof(line), inputFile)) { reads a line from the input file and stores it in the line array. The loop continues as long as there are more lines to read.
// *  * char *token = strtok(line, "\t\n"); splits the line array into tokens, separated by tabs (\t) and newline characters (\n). The first token is stored in the token variable.
// *  * while (token != NULL) { iterates over the tokens.
// *  * fprintf(outputFile, "%s,", token); writes the token variable to the output file, followed by a comma.
// *  * token = strtok(NULL, "\t\n"); gets the next token from the line array.
// *  * fseek(outputFile, -1, SEEK_CUR); moves the file pointer back one character in the output file. This removes the last comma from the output file.
// *  * fprintf(outputFile, "\n"); writes a newline character to the output file.
// *  * fclose(inputFile); closes the input file.
// *  * fclose(outputFile); closes the output file.
// *  * printf("CSV file 'Grading.csv' has been generated successfully.\n"); prints a success message.
// *  * return 0; returns 0, indicating that the program was successful. */
// */



/* It reads data from three input text files (Grading.txt, StudentInf.txt, SubjectMark.txt) and converts them into corresponding CSV files (Grading.csv, StudentInf.csv, SubjectMark.csv).
 * It uses the strtok function to tokenize lines from input files using tab and newline characters as delimiters.
 * It writes the tokenized data into the respective output CSV files, separating values with commas and adding newlines at the end of each line.
 * It handles file I/O errors and closes the input and output files properly.
 * Finally, it provides feedback to the user about the success of the conversion proces
 */
//* #include <stdio.h>
// * #include <stdlib.h>
// * #include <string.h>
// *
// * /* This program converts a text file to a CSV file. */
// *
// * int main() {
// *     /* Open the input file. */
// *     FILE *inputFile = fopen("Grading.txt", "r");
// *     if (inputFile == NULL) {
// *         printf("Failed to open Grading.txt\n");
// *         return 1;
// *     }
// *
// *     /* Open the output file. */
// *     FILE *outputFile = fopen("Grading.csv", "w");
// *     if (outputFile == NULL) {
// *         printf("Failed to create Grading.csv\n");
// *         fclose(inputFile);
// *         return 1;
// *     }
// *
// *     /* Read each line from the input file. */
// *     char line[100];
// *     while (fgets(line, sizeof(line), inputFile)) {
// *         /* Split the line into tokens. */
// *         char *token = strtok(line, "\t\n");
// *
// *         /* Iterate over the tokens. */
// *         while (token != NULL) {
// *             /* Write the token to the output file, followed by a comma. */
// *             fprintf(outputFile, "%s,", token);
// *
// *             /* Get the next token. */
// *             token = strtok(NULL, "\t\n");
// *         }
// *
// *         /* Remove the last comma from the output file. */
// *         fseek(outputFile, -1, SEEK_CUR);
// *         fprintf(outputFile, "\n");
// *     }
// *
// *     /* Close the input file. */
// *     fclose(inputFile);
// *
// *     /* Close the output file. */
// *     fclose(outputFile);
// *
// *     /* Print a success message. */
// *     printf("CSV file 'Grading.csv' has been generated successfully.\n");
// *
// *     return 0;
// * }
// * /*
// *  * FILE *inputFile = fopen("Grading.txt", "r"); opens the input file Grading.txt in read mode.
// *  * if (inputFile == NULL) { checks if the file was opened successfully. If not, the program prints an error message and returns 1.
// *  * FILE *outputFile = fopen("Grading.csv", "w"); opens the output file Grading.csv in write mode.
// *  * if (outputFile == NULL) { checks if the file was created successfully. If not, the program prints an error message and closes the input file.
// *  * char line[100]; declares a character array to store each line from the input file.
// *  * while (fgets(line, sizeof(line), inputFile)) { reads a line from the input file and stores it in the line array. The loop continues as long as there are more lines to read.
// *  * char *token = strtok(line, "\t\n"); splits the line array into tokens, separated by tabs (\t) and newline characters (\n). The first token is stored in the token variable.
// *  * while (token != NULL) { iterates over the tokens.
// *  * fprintf(outputFile, "%s,", token); writes the token variable to the output file, followed by a comma.
// *  * token = strtok(NULL, "\t\n"); gets the next token from the line array.
// *  * fseek(outputFile, -1, SEEK_CUR); moves the file pointer back one character in the output file. This removes the last comma from the output file.
// *  * fprintf(outputFile, "\n"); writes a newline character to the output file.
// *  * fclose(inputFile); closes the input file.
// *  * fclose(outputFile); closes the output file.
// *  * printf("CSV file 'Grading.csv' has been generated successfully.\n"); prints a success message.
// *  * return 0; returns 0, indicating that the program was successful. */
// */


/* The code you provided appears to be a C program that reads data from three input text files ("Grading.txt," "StudentInf.txt," and "SubjectMark.txt") and then converts and writes the data into corresponding output CSV files ("Grading.csv," "StudentInf.csv," and "SubjectMark.csv"). The data in the input text files is assumed to be tab-separated.
 *
 * Here's a breakdown of how the code works:
 *
 * The program first opens the input text file ("Grading.txt") and checks if it was opened successfully. If not, it prints an error message and exits with a return code of 1.
 *
 * It then opens the corresponding output CSV file ("Grading.csv") in write mode. If this operation fails, it prints an error message, closes the input file, and exits with a return code of 1.
 *
 * The program reads lines from the input file, tokenizes each line using tab and newline characters as delimiters, and writes the tokens followed by commas into the output CSV file.
 *
 * After processing each line, the program moves the file pointer back by one character (using fseek) to remove the trailing comma, and then writes a newline character to start a new line in the CSV file.
 *
 * The same process is repeated for the other two input files ("StudentInf.txt" and "SubjectMark.txt") to generate their corresponding CSV output files.
 *
 * Finally, the program closes all opened files and prints a success message before returning 0 to indicate successful execution.
 *
 * It's worth noting that the code provided is repetitive and can be further optimized by creating a function to handle the conversion process for each input file. This would reduce code duplication and improve maintainability.
 *
 * Also, consider adding additional error handling and validation for potential issues, such as handling cases where the input data format is unexpected or corrupted.
 *
 * Please make sure you have the input files ("Grading.txt," "StudentInf.txt," and "SubjectMark.txt") in the same directory as the executable of this program before running it.
 *
 *
 *
 *
 */
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
