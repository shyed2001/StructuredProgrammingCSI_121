<<<<<<< Updated upstream
<<<<<<< Updated upstream
/* Write a single program with  different  program sections (using functions in different variations, types and ways in each instances / implementations ) using C for students grading system, those ask for marks and credit hours for each and calculate letter grade for the given number/points. 1: Using Functions for GPA and CGPA Calculation, 2: Using Arrays and Loop for GPA Calculation, 3: Using Functions and Arrays for CGPA Calculation, using switch case statements
 *
 * GPA stands for Grade Point Average, and it is a measure of your academic performance based on the grades you earn in your courses. CGPA stands for Cumulative Grade Point Average, and it is a measure of your overall academic performance based on the GPA of all your courses.
 *
 * To calculate your GPA for a single semester, you need to follow these steps:
 *
 * Ask for numbers/marks of subjects for user input, Assign a grade according to the table you provided.
 For example, A+ = 4.0, A = 3.75, A- = 3.5, and so on....... given below
 *
 * Ask for subject marks and credit hours separately.
 * Dont ask for letter grades or cgpa or gpa from the user.
 * Calculate the Letter grade and Grade point according to the marks and credit hours.
 * Marks are max 100% or 100, cgpa or gpa max 4.00
 * Marks Range || Letter Grade  || Grade Point
 * 80% or 80 and above||	A+	(A Plus)	||4.0
 * 75% or 75 to  less than 80%||	A	(A regular)||	3.75
 * 70% or 70 to  less than 75%||	A-	(A minus)||	3.50
 * 65% or 65 to  less than 70%||	B+	(B Plus)||	3.25
 * 60% or 60 to less than 65%||	B	(B regular)||	3.0
 * 55%  or  60 to less than 60%||	B-	(B minus)||	2.75
 * 50% or 50 to less than 55%||	C+	(C Plus)||	2.50
 * 45% or  45 to less than 50%||	C	(C regular)||	2.25
 * 40% or 40 to less than 45%||	D||	 	2.0
 * Less than 40% or 45 ||	F	|| 	0.0
 *
 * Multiply the grade point value by the credit hours of each course. For example, if you got an A in a 3-credit course,
  you would multiply 3.75 by 3 to get 11.25.
 * Add up the total grade points for all your courses in that semester.
 * Divide the total grade points by the total credit hours for that semester. This is your GPA for that semester.
 *
 * To calculate your CGPA for your entire program, you need to follow these steps:
 * gpa and letter grades for individual subjects also
 * Calculate the GPA for each semester using the steps above.
 * Multiply the GPA of each semester by the total credit hours of that semester. For example, if your GPA for the first semester was 3.5 and you took 15 credits, you would multiply 3.5 by 15 to get 52.5.
 * Add up the total grade points for all your semesters.
 * Divide the total grade points by the total credit hours for all your semesters. This is your CGPA for your program.
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate GPA for a subject
float calculate_subject_gpa(int marks);  // this is function prototype, the function definition is at the bottom

// Function to determine letter grade based on GPA
// Function to determine letter grade based on GPA
char* get_letter_grade(float gpa) {
    if (gpa >= 4.0) return "A+";
    else if (gpa >= 3.75) return "A";
    else if (gpa >= 3.5) return "A-";
    else if (gpa >= 3.25) return "B+";
    else if (gpa >= 3.0) return "B";
    else if (gpa >= 2.75) return "B-";
    else if (gpa >= 2.5) return "C+";
    else if (gpa >= 2.25) return "C";
    else if (gpa >= 2.0) return "D";
    else return "F";
}

// Function to calculate CGPA based on individual subject GPAs
float calculate_semester_cgpa(float subject_gpas[], int num_subjects, int subject_credit_hours[]) {
    float total_grade_points = 0.0;
    float total_credit_hours = 0.0;

    // Calculate total GPA for all subjects
    for (int i = 0; i < num_subjects; i++) {
        total_grade_points += subject_gpas[i] * subject_credit_hours[i];
        total_credit_hours += subject_credit_hours[i];
    }

    // Calculate semester CGPA and return
    float semester_cgpa = total_grade_points / total_credit_hours;
    return semester_cgpa;
}

void input_subjects_switch(int num_subjects, int marks_switch[], int credit_hours_switch[]) {
    for (int i = 0; i < num_subjects; i++) {
        printf("For switch - Enter marks for subject %d: ", i + 1);
        scanf("%d", &marks_switch[i]);

        printf("For switch - Enter credit hours for subject %d: ", i + 1);
        scanf("%d", &credit_hours_switch[i]);
    }
}

// Define the struct outside of the main function
struct subject_struct {
    int marks;
    int credit_hours;
};

int main() {
    // First part
    printf("Using various Functions \n");
    int num_subjects;
    printf("Enter the number of subjects: ");
    scanf_s("%d", &num_subjects);

    // Arrays to store marks and credit hours for each subject
    int marks[10];
    int subject_credit_hours[10];

    // Get marks and credit hours for each subject
    for (int i = 0; i < num_subjects; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        printf("Enter credit hours for subject %d: ", i + 1);
        scanf("%d", &subject_credit_hours[i]);
    }

    // Calculate GPA for each subject and display individual subject information
    printf("\nIndividual Subject Information:\n");
    for (int i = 0; i < num_subjects; i++) {
        float subject_gpa = calculate_subject_gpa(marks[i]);
        char* subject_letter_grade = get_letter_grade(subject_gpa);

        printf("Subject %d - Marks: %d, Credit Hours: %d, GPA: %.2f, Letter Grade: %s\n",
               i + 1, marks[i], subject_credit_hours[i], subject_gpa, subject_letter_grade);
    }

    // Calculate CGPA using individual subject GPAs
    float subject_gpas[10];
    for (int i = 0; i < num_subjects; i++) {
        subject_gpas[i] = calculate_subject_gpa(marks[i]);
    }

    // Calculate CGPA and determine letter grade based on CGPA
    float program_cgpa = calculate_semester_cgpa(subject_gpas, num_subjects, subject_credit_hours);
    char* cgpa_letter_grade = get_letter_grade(program_cgpa);

    // Display CGPA and CGPA letter grade
    printf("\nSemester CGPA: %.2f\n", program_cgpa);
    printf("Semester Letter Grade for CGPA: %s\n", cgpa_letter_grade);


        // Second part of the main function for switch case calculations

    puts("Using various switch cases and Functions");
    // Second part of the main function for switch case calculations

    int num_subjects_switch;
    printf("\nFrom Switch- Enter the number of subjects: ");
    scanf("%d", &num_subjects_switch);

    // Arrays to store marks and credit hours for each subject
    int marks_switch[10];
    int credit_hours_switch[10];

    // Get marks and credit hours for subjects using switch-case
    input_subjects_switch(num_subjects_switch, marks_switch, credit_hours_switch);

    // Calculate GPA for the semester using switch case
    float total_grade_points = 0.0;
    int total_credit_hours_switch = 0;

    for (int i = 0; i < num_subjects_switch; i++) {
        switch (marks_switch[i]) {
            case 80 ... 100:
                total_grade_points += 4.0 * credit_hours_switch[i];
                break;
            case 75 ... 79:
                total_grade_points += 3.75 * credit_hours_switch[i];
                break;
            case 70 ... 74:
                total_grade_points += 3.5 * credit_hours_switch[i];
                break;
            case 65 ... 69:
                total_grade_points += 3.25 * credit_hours_switch[i];
                break;
            case 60 ... 64:
                total_grade_points += 3.0 * credit_hours_switch[i];
                break;
            case 55 ... 59:
                total_grade_points += 2.75 * credit_hours_switch[i];
                break;
            case 50 ... 54:
                total_grade_points += 2.5 * credit_hours_switch[i];
                break;
            case 45 ... 49:
                total_grade_points += 2.25 * credit_hours_switch[i];
                break;
            case 40 ... 44:
                total_grade_points += 2.0 * credit_hours_switch[i];
                break;
            default:
                total_credit_hours_switch -= credit_hours_switch[i]; // Exclude this subject from total_credit_hours_switch
        }
        total_credit_hours_switch += credit_hours_switch[i];
    }

  float semester_gpa = total_grade_points / total_credit_hours_switch;
char gpa_letter_grade[5]; // Changed size to 3 to accommodate two characters and null terminator

switch ((int)(semester_gpa * 100)) {
    case 400:
        strcpy(gpa_letter_grade, "A+");
        break;
    case 375 ... 399:
        strcpy(gpa_letter_grade, "A");
        break;
    case 350 ... 374:
        strcpy(gpa_letter_grade, "A-");
        break;
    case 325 ... 349:
        strcpy(gpa_letter_grade, "B+");
        break;
    case 300 ... 324:
        strcpy(gpa_letter_grade, "B");
        break;
    case 275 ... 299:
        strcpy(gpa_letter_grade, "B-");
        break;
    case 250 ... 274:
        strcpy(gpa_letter_grade, "C+");
        break;
    case 225 ... 249:
        strcpy(gpa_letter_grade, "C");
        break;
    case 200 ... 224:
        strcpy(gpa_letter_grade, "D");
        break;
    default:
        strcpy(gpa_letter_grade, "F");
}


    printf("From Switch- Semester CGPA: %.2f\n", semester_gpa);
    printf("From Switch- Semester Letter Grade for CGPA: %s\n", gpa_letter_grade);

    // Calculate CGPA using individual subject GPAs
    float subject_gpas_switch[10];

    for (int i = 0; i < num_subjects_switch; i++) {
        float subject_gpa;

        switch (marks_switch[i]) {
            case 80 ... 100:
                subject_gpa = 4.0;
                break;
            case 75 ... 79:
                subject_gpa = 3.75;
                break;
            case 70 ... 74:
                subject_gpa = 3.5;
                break;
            case 65 ... 69:
                subject_gpa = 3.25;
                break;
            case 60 ... 64:
                subject_gpa = 3.0;
                break;
            case 55 ... 59:
                subject_gpa = 2.75;
                break;
            case 50 ... 54:
                subject_gpa = 2.5;
                break;
            case 45 ... 49:
                subject_gpa = 2.25;
                break;
            case 40 ... 44:
                subject_gpa = 2.0;
                break;
            default:
                subject_gpa = 0.0;
        }

        subject_gpas_switch[i] = subject_gpa;
    }

    // Calculate CGPA and determine letter grade based on CGPA using switch case
    float total_gpa_for_cgpa = 0.0;

    for (int i = 0; i < num_subjects_switch; i++) {
        total_gpa_for_cgpa += subject_gpas_switch[i] * credit_hours_switch[i];
    }

    float program_cgpa_switch = total_gpa_for_cgpa / total_credit_hours_switch;
char cgpa_letter_grade_switch[5]; // Changed size to 3 to accommodate two characters and null terminator

switch ((int)(program_cgpa_switch * 100)) {
    case 400:
        strcpy(cgpa_letter_grade_switch, "A+");
        break;
    case 375 ... 399:
        strcpy(cgpa_letter_grade_switch, "A");
        break;
    case 350 ... 374:
        strcpy(cgpa_letter_grade_switch, "A-");
        break;
    case 325 ... 349:
        strcpy(cgpa_letter_grade_switch, "B+");
        break;
    case 300 ... 324:
        strcpy(cgpa_letter_grade_switch, "B");
        break;
    case 275 ... 299:
        strcpy(cgpa_letter_grade_switch, "B-");
        break;
    case 250 ... 274:
        strcpy(cgpa_letter_grade_switch, "C+");
        break;
    case 225 ... 249:
        strcpy(cgpa_letter_grade_switch, "C");
        break;
    case 200 ... 224:
        strcpy(cgpa_letter_grade_switch, "D");
        break;
    default:
        strcpy(cgpa_letter_grade_switch, "F");
}

    // Display CGPA and CGPA letter grade
    printf("From Switch- Individual Subject Information:\n");
    for (int i = 0; i < num_subjects_switch; i++) {
        float subject_gpa_switch = calculate_subject_gpa(marks_switch[i]);
        char* subject_letter_grade_switch = get_letter_grade(subject_gpa_switch);

        printf("Subject %d - Marks: %d, Credit Hours: %d, GPA: %.2f, Letter Grade: %s\n",
               i + 1, marks_switch[i], credit_hours_switch[i], subject_gpa_switch, subject_letter_grade_switch);
    }

    printf("From Switch- Semester CGPA: %.2f\n", program_cgpa_switch);
    printf("From Switch- Semester Letter Grade for CGPA: %s\n", cgpa_letter_grade_switch);

    // Part 3, calculate GPA, CGPA, and letter grades using structs
    // Part 4: calculate GPA, CGPA, and letter grades using arrays of structs

    // Get number of subjects
    int num_subjects_array_struct;
    printf("Enter number of subjects: ");
    scanf("%d", &num_subjects_array_struct);

    // Declare an array of structs
    struct subject_struct subjects_array_struct[num_subjects_array_struct];

    for (int i = 0; i < num_subjects_array_struct; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &subjects_array_struct[i].marks);

        printf("Enter credit hours for subject %d: ", i + 1);
        scanf("%d", &subjects_array_struct[i].credit_hours);
    }

    // Calculate GPA and determine letter grade based on GPA using arrays of structs
    float total_gpa_for_semester_array_struct = 0.0;
    int total_credit_hours_array_struct = 0;

    for (int i = 0; i < num_subjects_array_struct; i++) {
        total_gpa_for_semester_array_struct += calculate_subject_gpa(subjects_array_struct[i].marks) * subjects_array_struct[i].credit_hours;
        total_credit_hours_array_struct += subjects_array_struct[i].credit_hours;
    }

    float semester_gpa_array_struct = total_gpa_for_semester_array_struct / total_credit_hours_array_struct;
    char semester_letter_grade_array_struct[3]; // Changed size to 3 to accommodate two characters and null terminator
    strcpy(semester_letter_grade_array_struct, get_letter_grade(semester_gpa_array_struct));

    // Display GPA and letter grade
    printf("From Struct- Individual Subject Information:\n");

    for (int i = 0; i < num_subjects_array_struct; i++) {
        float subject_gpa_array_struct = calculate_subject_gpa(subjects_array_struct[i].marks);
        char* subject_letter_grade_array_struct = get_letter_grade(subject_gpa_array_struct);

        printf("Subject %d - Marks: %d, Credit Hours: %d, GPA: %.2f, Letter Grade: %s\n",
            i + 1, subjects_array_struct[i].marks, subjects_array_struct[i].credit_hours,
            subject_gpa_array_struct, subject_letter_grade_array_struct);
    }

    printf("From Struct- Semester GPA: %.2f\n", semester_gpa_array_struct);
    printf("From Struct- Semester Letter Grade for GPA: %s\n", semester_letter_grade_array_struct);



// Part 4, calculate GPA, CGPA, and letter grades using arrays of structs

// Get number of subjects

int num_subjects_array_struct_2;

printf("Enter number of subjects: ");

scanf("%d", &num_subjects_array_struct_2);

// Get marks and credit hours for each subject


	struct subject_struct subjects_array_struct_2[num_subjects_array_struct_2];

for (int i = 0; i < num_subjects_array_struct_2; i++) {
printf("Enter marks for subject %d: ", i + 1);

scanf("%d", &subjects_array_struct_2[i].marks);

printf("Enter credit hours for subject %d: ", i + 1);

scanf("%d", &subjects_array_struct_2[i].credit_hours);

}

// Calculate GPA and determine letter grade based on GPA using arrays of structs

float total_gpa_for_semester_array_struct_2 = 0.0;

for (int i = 0; i < num_subjects_array_struct_2; i++) {

total_gpa_for_semester_array_struct_2 += subjects_array_struct_2[i].marks * subjects_array_struct_2[i].credit_hours;

}
float total_credit_hours_struct;
float semester_gpa_array_struct_2 = total_gpa_for_semester_array_struct_2 / total_credit_hours_struct;

char semester_letter_grade_array_struct_2[5]; // Changed size to 3 to accommodate two characters and null terminator

// using previous function

strcpy(semester_letter_grade_array_struct, get_letter_grade(semester_gpa_array_struct_2));

// Display GPA and letter grade

printf("From Array of Struct- Individual Subject Information:\n");

for (int i = 0; i < num_subjects_array_struct_2; i++) {

float subject_gpa_array_struct = calculate_subject_gpa(subjects_array_struct_2[i].marks);

char* subject_letter_grade_array_struct = get_letter_grade(subject_gpa_array_struct);

printf("Subject %d - Marks: %d, Credit Hours: %d, GPA: %.2f, Letter Grade: %s\n",

i + 1, subjects_array_struct_2[i].marks, subjects_array_struct_2[i].credit_hours, subject_gpa_array_struct, subject_letter_grade_array_struct);

}

printf("From Array of Struct- Semester GPA: %.2f\n", semester_gpa_array_struct_2);

printf("From Array of Struct- Semester Letter Grade for GPA: %s\n", semester_letter_grade_array_struct);

    return 0;
}

// Function to calculate GPA for a subject
float calculate_subject_gpa(int marks) {
    if (marks >= 80) return 4.0;
    else if (marks >= 75) return 3.75;
    else if (marks >= 70) return 3.5;
    else if (marks >= 65) return 3.25;
    else if (marks >= 60) return 3.0;
    else if (marks >= 55) return 2.75;
    else if (marks >= 50) return 2.5;
    else if (marks >= 45) return 2.25;
    else if (marks >= 40) return 2.0;
    else return 0.0;
}



/* Write a single program with  different  program sections (using functions in different variations, types and ways in each instances / implementations ) using C for students grading system, those ask for marks and credit hours for each and calculate letter grade for the given number/points. 1: Using Functions for GPA and CGPA Calculation, 2: Using Arrays and Loop for GPA Calculation, 3: Using Functions and Arrays for CGPA Calculation, using switch case statements
 *
 * GPA stands for Grade Point Average, and it is a measure of your academic performance based on the grades you earn in your courses. CGPA stands for Cumulative Grade Point Average, and it is a measure of your overall academic performance based on the GPA of all your courses.
 *
 * To calculate your GPA for a single semester, you need to follow these steps:
 *
 * Ask for numbers/marks of subjects for user input, Assign a grade according to the table you provided. For example, A+ = 4.0, A = 3.75, A- = 3.5, and so on....... given below
 *
 * Ask for subject marks and credit hours separately.
 * Dont ask for letter grades or cgpa or gpa from the user.
 * Calculate the Letter grade and Grade point according to the marks and credit hours.
 * Marks are max 100% or 100, cgpa or gpa max 4.00
 * Marks Range || Letter Grade  || Grade Point
 * 80% or 80 and above||	A+	(A Plus)	||4.0
 * 75% or 75 to  less than 80%||	A	(A regular)||	3.75
 * 70% or 70 to  less than 75%||	A-	(A minus)||	3.50
 * 65% or 65 to  less than 70%||	B+	(B Plus)||	3.25
 * 60% or 60 to less than 65%||	B	(B regular)||	3.0
 * 55%  or  60 to less than 60%||	B-	(B minus)||	2.75
 * 50% or 50 to less than 55%||	C+	(C Plus)||	2.50
 * 45% or  45 to less than 50%||	C	(C regular)||	2.25
 * 40% or 40 to less than 45%||	D||	 	2.0
 * Less than 40% or 45 ||	F	|| 	0.0
 *
 * Multiply the grade point value by the credit hours of each course. For example, if you got an A in a 3-credit course, you would multiply 3.75 by 3 to get 11.25.
 * Add up the total grade points for all your courses in that semester.
 * Divide the total grade points by the total credit hours for that semester. This is your GPA for that semester.
 *
 * To calculate your CGPA for your entire program, you need to follow these steps:
 * gpa and letter grades for individual subjects also
 * Calculate the GPA for each semester using the steps above.
 * Multiply the GPA of each semester by the total credit hours of that semester. For example, if your GPA for the first semester was 3.5 and you took 15 credits, you would multiply 3.5 by 15 to get 52.5.
 * Add up the total grade points for all your semesters.
 * Divide the total grade points by the total credit hours for all your semesters. This is your CGPA for your program.
 *
 *
 */
=======
=======
>>>>>>> Stashed changes
/* Write a single program with  different  program sections (using functions in different variations, types and ways in each instances / implementations ) using C for students grading system, those ask for marks and credit hours for each and calculate letter grade for the given number/points. 1: Using Functions for GPA and CGPA Calculation, 2: Using Arrays and Loop for GPA Calculation, 3: Using Functions and Arrays for CGPA Calculation, using switch case statements
 *
 * GPA stands for Grade Point Average, and it is a measure of your academic performance based on the grades you earn in your courses. CGPA stands for Cumulative Grade Point Average, and it is a measure of your overall academic performance based on the GPA of all your courses.
 *
 * To calculate your GPA for a single semester, you need to follow these steps:
 *
 * Ask for numbers/marks of subjects for user input, Assign a grade according to the table you provided.
 For example, A+ = 4.0, A = 3.75, A- = 3.5, and so on....... given below
 *
 * Ask for subject marks and credit hours separately.
 * Dont ask for letter grades or cgpa or gpa from the user.
 * Calculate the Letter grade and Grade point according to the marks and credit hours.
 * Marks are max 100% or 100, cgpa or gpa max 4.00
 * Marks Range || Letter Grade  || Grade Point
 * 80% or 80 and above||	A+	(A Plus)	||4.0
 * 75% or 75 to  less than 80%||	A	(A regular)||	3.75
 * 70% or 70 to  less than 75%||	A-	(A minus)||	3.50
 * 65% or 65 to  less than 70%||	B+	(B Plus)||	3.25
 * 60% or 60 to less than 65%||	B	(B regular)||	3.0
 * 55%  or  60 to less than 60%||	B-	(B minus)||	2.75
 * 50% or 50 to less than 55%||	C+	(C Plus)||	2.50
 * 45% or  45 to less than 50%||	C	(C regular)||	2.25
 * 40% or 40 to less than 45%||	D||	 	2.0
 * Less than 40% or 45 ||	F	|| 	0.0
 *
 * Multiply the grade point value by the credit hours of each course. For example, if you got an A in a 3-credit course,
  you would multiply 3.75 by 3 to get 11.25.
 * Add up the total grade points for all your courses in that semester.
 * Divide the total grade points by the total credit hours for that semester. This is your GPA for that semester.
 *
 * To calculate your CGPA for your entire program, you need to follow these steps:
 * gpa and letter grades for individual subjects also
 * Calculate the GPA for each semester using the steps above.
 * Multiply the GPA of each semester by the total credit hours of that semester. For example, if your GPA for the first semester was 3.5 and you took 15 credits, you would multiply 3.5 by 15 to get 52.5.
 * Add up the total grade points for all your semesters.
 * Divide the total grade points by the total credit hours for all your semesters. This is your CGPA for your program.
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate GPA for a subject
float calculate_subject_gpa(int marks);  // this is function prototype, the function definition is at the bottom

// Function to determine letter grade based on GPA
// Function to determine letter grade based on GPA
char* get_letter_grade(float gpa) {
    if (gpa >= 4.0) return "A+";
    else if (gpa >= 3.75) return "A";
    else if (gpa >= 3.5) return "A-";
    else if (gpa >= 3.25) return "B+";
    else if (gpa >= 3.0) return "B";
    else if (gpa >= 2.75) return "B-";
    else if (gpa >= 2.5) return "C+";
    else if (gpa >= 2.25) return "C";
    else if (gpa >= 2.0) return "D";
    else return "F";
}

// Function to calculate CGPA based on individual subject GPAs
float calculate_semester_cgpa(float subject_gpas[], int num_subjects, int subject_credit_hours[]) {
    float total_grade_points = 0.0;
    float total_credit_hours = 0.0;

    // Calculate total GPA for all subjects
    for (int i = 0; i < num_subjects; i++) {
        total_grade_points += subject_gpas[i] * subject_credit_hours[i];
        total_credit_hours += subject_credit_hours[i];
    }

    // Calculate semester CGPA and return
    float semester_cgpa = total_grade_points / total_credit_hours;
    return semester_cgpa;
}

void input_subjects_switch(int num_subjects, int marks_switch[], int credit_hours_switch[]) {
    for (int i = 0; i < num_subjects; i++) {
        printf("For switch - Enter marks for subject %d: ", i + 1);
        scanf("%d", &marks_switch[i]);

        printf("For switch - Enter credit hours for subject %d: ", i + 1);
        scanf("%d", &credit_hours_switch[i]);
    }
}

// Define the struct outside of the main function
struct subject_struct {
    int marks;
    int credit_hours;
};

int main() {
    // First part
    printf("Using various Functions \n");
    int num_subjects;
    printf("Enter the number of subjects: ");
    scanf_s("%d", &num_subjects);

    // Arrays to store marks and credit hours for each subject
    int marks[10];
    int subject_credit_hours[10];

    // Get marks and credit hours for each subject
    for (int i = 0; i < num_subjects; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        printf("Enter credit hours for subject %d: ", i + 1);
        scanf("%d", &subject_credit_hours[i]);
    }

    // Calculate GPA for each subject and display individual subject information
    printf("\nIndividual Subject Information:\n");
    for (int i = 0; i < num_subjects; i++) {
        float subject_gpa = calculate_subject_gpa(marks[i]);
        char* subject_letter_grade = get_letter_grade(subject_gpa);

        printf("Subject %d - Marks: %d, Credit Hours: %d, GPA: %.2f, Letter Grade: %s\n",
               i + 1, marks[i], subject_credit_hours[i], subject_gpa, subject_letter_grade);
    }

    // Calculate CGPA using individual subject GPAs
    float subject_gpas[10];
    for (int i = 0; i < num_subjects; i++) {
        subject_gpas[i] = calculate_subject_gpa(marks[i]);
    }

    // Calculate CGPA and determine letter grade based on CGPA
    float program_cgpa = calculate_semester_cgpa(subject_gpas, num_subjects, subject_credit_hours);
    char* cgpa_letter_grade = get_letter_grade(program_cgpa);

    // Display CGPA and CGPA letter grade
    printf("\nSemester CGPA: %.2f\n", program_cgpa);
    printf("Semester Letter Grade for CGPA: %s\n", cgpa_letter_grade);


        // Second part of the main function for switch case calculations

    puts("Using various switch cases and Functions");
    // Second part of the main function for switch case calculations

    int num_subjects_switch;
    printf("\nFrom Switch- Enter the number of subjects: ");
    scanf("%d", &num_subjects_switch);

    // Arrays to store marks and credit hours for each subject
    int marks_switch[10];
    int credit_hours_switch[10];

    // Get marks and credit hours for subjects using switch-case
    input_subjects_switch(num_subjects_switch, marks_switch, credit_hours_switch);

    // Calculate GPA for the semester using switch case
    float total_grade_points = 0.0;
    int total_credit_hours_switch = 0;

    for (int i = 0; i < num_subjects_switch; i++) {
        switch (marks_switch[i]) {
            case 80 ... 100:
                total_grade_points += 4.0 * credit_hours_switch[i];
                break;
            case 75 ... 79:
                total_grade_points += 3.75 * credit_hours_switch[i];
                break;
            case 70 ... 74:
                total_grade_points += 3.5 * credit_hours_switch[i];
                break;
            case 65 ... 69:
                total_grade_points += 3.25 * credit_hours_switch[i];
                break;
            case 60 ... 64:
                total_grade_points += 3.0 * credit_hours_switch[i];
                break;
            case 55 ... 59:
                total_grade_points += 2.75 * credit_hours_switch[i];
                break;
            case 50 ... 54:
                total_grade_points += 2.5 * credit_hours_switch[i];
                break;
            case 45 ... 49:
                total_grade_points += 2.25 * credit_hours_switch[i];
                break;
            case 40 ... 44:
                total_grade_points += 2.0 * credit_hours_switch[i];
                break;
            default:
                total_credit_hours_switch -= credit_hours_switch[i]; // Exclude this subject from total_credit_hours_switch
        }
        total_credit_hours_switch += credit_hours_switch[i];
    }

  float semester_gpa = total_grade_points / total_credit_hours_switch;
char gpa_letter_grade[5]; // Changed size to 3 to accommodate two characters and null terminator

switch ((int)(semester_gpa * 100)) {
    case 400:
        strcpy(gpa_letter_grade, "A+");
        break;
    case 375 ... 399:
        strcpy(gpa_letter_grade, "A");
        break;
    case 350 ... 374:
        strcpy(gpa_letter_grade, "A-");
        break;
    case 325 ... 349:
        strcpy(gpa_letter_grade, "B+");
        break;
    case 300 ... 324:
        strcpy(gpa_letter_grade, "B");
        break;
    case 275 ... 299:
        strcpy(gpa_letter_grade, "B-");
        break;
    case 250 ... 274:
        strcpy(gpa_letter_grade, "C+");
        break;
    case 225 ... 249:
        strcpy(gpa_letter_grade, "C");
        break;
    case 200 ... 224:
        strcpy(gpa_letter_grade, "D");
        break;
    default:
        strcpy(gpa_letter_grade, "F");
}


    printf("From Switch- Semester CGPA: %.2f\n", semester_gpa);
    printf("From Switch- Semester Letter Grade for CGPA: %s\n", gpa_letter_grade);

    // Calculate CGPA using individual subject GPAs
    float subject_gpas_switch[10];

    for (int i = 0; i < num_subjects_switch; i++) {
        float subject_gpa;

        switch (marks_switch[i]) {
            case 80 ... 100:
                subject_gpa = 4.0;
                break;
            case 75 ... 79:
                subject_gpa = 3.75;
                break;
            case 70 ... 74:
                subject_gpa = 3.5;
                break;
            case 65 ... 69:
                subject_gpa = 3.25;
                break;
            case 60 ... 64:
                subject_gpa = 3.0;
                break;
            case 55 ... 59:
                subject_gpa = 2.75;
                break;
            case 50 ... 54:
                subject_gpa = 2.5;
                break;
            case 45 ... 49:
                subject_gpa = 2.25;
                break;
            case 40 ... 44:
                subject_gpa = 2.0;
                break;
            default:
                subject_gpa = 0.0;
        }

        subject_gpas_switch[i] = subject_gpa;
    }

    // Calculate CGPA and determine letter grade based on CGPA using switch case
    float total_gpa_for_cgpa = 0.0;

    for (int i = 0; i < num_subjects_switch; i++) {
        total_gpa_for_cgpa += subject_gpas_switch[i] * credit_hours_switch[i];
    }

    float program_cgpa_switch = total_gpa_for_cgpa / total_credit_hours_switch;
char cgpa_letter_grade_switch[5]; // Changed size to 3 to accommodate two characters and null terminator

switch ((int)(program_cgpa_switch * 100)) {
    case 400:
        strcpy(cgpa_letter_grade_switch, "A+");
        break;
    case 375 ... 399:
        strcpy(cgpa_letter_grade_switch, "A");
        break;
    case 350 ... 374:
        strcpy(cgpa_letter_grade_switch, "A-");
        break;
    case 325 ... 349:
        strcpy(cgpa_letter_grade_switch, "B+");
        break;
    case 300 ... 324:
        strcpy(cgpa_letter_grade_switch, "B");
        break;
    case 275 ... 299:
        strcpy(cgpa_letter_grade_switch, "B-");
        break;
    case 250 ... 274:
        strcpy(cgpa_letter_grade_switch, "C+");
        break;
    case 225 ... 249:
        strcpy(cgpa_letter_grade_switch, "C");
        break;
    case 200 ... 224:
        strcpy(cgpa_letter_grade_switch, "D");
        break;
    default:
        strcpy(cgpa_letter_grade_switch, "F");
}

    // Display CGPA and CGPA letter grade
    printf("From Switch- Individual Subject Information:\n");
    for (int i = 0; i < num_subjects_switch; i++) {
        float subject_gpa_switch = calculate_subject_gpa(marks_switch[i]);
        char* subject_letter_grade_switch = get_letter_grade(subject_gpa_switch);

        printf("Subject %d - Marks: %d, Credit Hours: %d, GPA: %.2f, Letter Grade: %s\n",
               i + 1, marks_switch[i], credit_hours_switch[i], subject_gpa_switch, subject_letter_grade_switch);
    }

    printf("From Switch- Semester CGPA: %.2f\n", program_cgpa_switch);
    printf("From Switch- Semester Letter Grade for CGPA: %s\n", cgpa_letter_grade_switch);

    // Part 3, calculate GPA, CGPA, and letter grades using structs
    // Part 4: calculate GPA, CGPA, and letter grades using arrays of structs

    // Get number of subjects
    int num_subjects_array_struct;
    printf("Enter number of subjects: ");
    scanf("%d", &num_subjects_array_struct);

    // Declare an array of structs
    struct subject_struct subjects_array_struct[num_subjects_array_struct];

    for (int i = 0; i < num_subjects_array_struct; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &subjects_array_struct[i].marks);

        printf("Enter credit hours for subject %d: ", i + 1);
        scanf("%d", &subjects_array_struct[i].credit_hours);
    }

    // Calculate GPA and determine letter grade based on GPA using arrays of structs
    float total_gpa_for_semester_array_struct = 0.0;
    int total_credit_hours_array_struct = 0;

    for (int i = 0; i < num_subjects_array_struct; i++) {
        total_gpa_for_semester_array_struct += calculate_subject_gpa(subjects_array_struct[i].marks) * subjects_array_struct[i].credit_hours;
        total_credit_hours_array_struct += subjects_array_struct[i].credit_hours;
    }

    float semester_gpa_array_struct = total_gpa_for_semester_array_struct / total_credit_hours_array_struct;
    char semester_letter_grade_array_struct[3]; // Changed size to 3 to accommodate two characters and null terminator
    strcpy(semester_letter_grade_array_struct, get_letter_grade(semester_gpa_array_struct));

    // Display GPA and letter grade
    printf("From Struct- Individual Subject Information:\n");

    for (int i = 0; i < num_subjects_array_struct; i++) {
        float subject_gpa_array_struct = calculate_subject_gpa(subjects_array_struct[i].marks);
        char* subject_letter_grade_array_struct = get_letter_grade(subject_gpa_array_struct);

        printf("Subject %d - Marks: %d, Credit Hours: %d, GPA: %.2f, Letter Grade: %s\n",
            i + 1, subjects_array_struct[i].marks, subjects_array_struct[i].credit_hours,
            subject_gpa_array_struct, subject_letter_grade_array_struct);
    }

    printf("From Struct- Semester GPA: %.2f\n", semester_gpa_array_struct);
    printf("From Struct- Semester Letter Grade for GPA: %s\n", semester_letter_grade_array_struct);



// Part 4, calculate GPA, CGPA, and letter grades using arrays of structs

// Get number of subjects

int num_subjects_array_struct_2;

printf("Enter number of subjects: ");

scanf("%d", &num_subjects_array_struct_2);

// Get marks and credit hours for each subject


	struct subject_struct subjects_array_struct_2[num_subjects_array_struct_2];

for (int i = 0; i < num_subjects_array_struct_2; i++) {
printf("Enter marks for subject %d: ", i + 1);

scanf("%d", &subjects_array_struct_2[i].marks);

printf("Enter credit hours for subject %d: ", i + 1);

scanf("%d", &subjects_array_struct_2[i].credit_hours);

}

// Calculate GPA and determine letter grade based on GPA using arrays of structs

float total_gpa_for_semester_array_struct_2 = 0.0;

for (int i = 0; i < num_subjects_array_struct_2; i++) {

total_gpa_for_semester_array_struct_2 += subjects_array_struct_2[i].marks * subjects_array_struct_2[i].credit_hours;

}
float total_credit_hours_struct;
float semester_gpa_array_struct_2 = total_gpa_for_semester_array_struct_2 / total_credit_hours_struct;

char semester_letter_grade_array_struct_2[5]; // Changed size to 3 to accommodate two characters and null terminator

// using previous function

strcpy(semester_letter_grade_array_struct, get_letter_grade(semester_gpa_array_struct_2));

// Display GPA and letter grade

printf("From Array of Struct- Individual Subject Information:\n");

for (int i = 0; i < num_subjects_array_struct_2; i++) {

float subject_gpa_array_struct = calculate_subject_gpa(subjects_array_struct_2[i].marks);

char* subject_letter_grade_array_struct = get_letter_grade(subject_gpa_array_struct);

printf("Subject %d - Marks: %d, Credit Hours: %d, GPA: %.2f, Letter Grade: %s\n",

i + 1, subjects_array_struct_2[i].marks, subjects_array_struct_2[i].credit_hours, subject_gpa_array_struct, subject_letter_grade_array_struct);

}

printf("From Array of Struct- Semester GPA: %.2f\n", semester_gpa_array_struct_2);

printf("From Array of Struct- Semester Letter Grade for GPA: %s\n", semester_letter_grade_array_struct);

    return 0;
}

// Function to calculate GPA for a subject
float calculate_subject_gpa(int marks) {
    if (marks >= 80) return 4.0;
    else if (marks >= 75) return 3.75;
    else if (marks >= 70) return 3.5;
    else if (marks >= 65) return 3.25;
    else if (marks >= 60) return 3.0;
    else if (marks >= 55) return 2.75;
    else if (marks >= 50) return 2.5;
    else if (marks >= 45) return 2.25;
    else if (marks >= 40) return 2.0;
    else return 0.0;
}



/* Write a single program with  different  program sections (using functions in different variations, types and ways in each instances / implementations ) using C for students grading system, those ask for marks and credit hours for each and calculate letter grade for the given number/points. 1: Using Functions for GPA and CGPA Calculation, 2: Using Arrays and Loop for GPA Calculation, 3: Using Functions and Arrays for CGPA Calculation, using switch case statements
 *
 * GPA stands for Grade Point Average, and it is a measure of your academic performance based on the grades you earn in your courses. CGPA stands for Cumulative Grade Point Average, and it is a measure of your overall academic performance based on the GPA of all your courses.
 *
 * To calculate your GPA for a single semester, you need to follow these steps:
 *
 * Ask for numbers/marks of subjects for user input, Assign a grade according to the table you provided. For example, A+ = 4.0, A = 3.75, A- = 3.5, and so on....... given below
 *
 * Ask for subject marks and credit hours separately.
 * Dont ask for letter grades or cgpa or gpa from the user.
 * Calculate the Letter grade and Grade point according to the marks and credit hours.
 * Marks are max 100% or 100, cgpa or gpa max 4.00
 * Marks Range || Letter Grade  || Grade Point
 * 80% or 80 and above||	A+	(A Plus)	||4.0
 * 75% or 75 to  less than 80%||	A	(A regular)||	3.75
 * 70% or 70 to  less than 75%||	A-	(A minus)||	3.50
 * 65% or 65 to  less than 70%||	B+	(B Plus)||	3.25
 * 60% or 60 to less than 65%||	B	(B regular)||	3.0
 * 55%  or  60 to less than 60%||	B-	(B minus)||	2.75
 * 50% or 50 to less than 55%||	C+	(C Plus)||	2.50
 * 45% or  45 to less than 50%||	C	(C regular)||	2.25
 * 40% or 40 to less than 45%||	D||	 	2.0
 * Less than 40% or 45 ||	F	|| 	0.0
 *
 * Multiply the grade point value by the credit hours of each course. For example, if you got an A in a 3-credit course, you would multiply 3.75 by 3 to get 11.25.
 * Add up the total grade points for all your courses in that semester.
 * Divide the total grade points by the total credit hours for that semester. This is your GPA for that semester.
 *
 * To calculate your CGPA for your entire program, you need to follow these steps:
 * gpa and letter grades for individual subjects also
 * Calculate the GPA for each semester using the steps above.
 * Multiply the GPA of each semester by the total credit hours of that semester. For example, if your GPA for the first semester was 3.5 and you took 15 credits, you would multiply 3.5 by 15 to get 52.5.
 * Add up the total grade points for all your semesters.
 * Divide the total grade points by the total credit hours for all your semesters. This is your CGPA for your program.
 *
 *
 */
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
