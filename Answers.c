Write three different  programs (using functions in different variations, types and ways in each instances / implementations ) using C for students grading system, those ask for grade points and calculates the cgpa and letter grade for the given number/points.
Marks Range

Letter Grade
Grade Point

80% and above	A+	(A Plus)	4.0
75% to less than 80%	A	(A regular)	3.75
70% to less than 75%	A-	(A minus)	3.50
65% to less than 70%	B+	(B Plus)	3.25
60% to less than 65%	B	(B regular)	3.0
55% to less than 60%	B-	(B minus)	2.75
50% to less than 55%	C+	(C Plus)	2.50
45% to less than 50%	C	(C regular)	2.25
40% to less than 45%	D	 	2.0
Less than 40%	F	 	0.0
- One way to write a program is to use an array of structures to store the grade points and letter grades for each marks range. Then, you can use a loop to ask the user for their marks and compare them with the array elements to find the corresponding grade point and letter grade. You can also use a variable to keep track of the total grade points and calculate the CGPA by dividing it by the number of subjects.
- Another way to write a program is to use a switch-case statement to assign the grade point and letter grade based on the marks. You can use a function to take the marks as input and return the grade point as output. You can also use another function to take the grade point as input and return the letter grade as output. You can use these functions in a loop to ask the user for their marks and display their grade point and letter grade. You can also use a variable to keep track of the total grade points and calculate the CGPA by dividing it by the number of subjects.
- A third way to write a program is to use if-else statements to assign the grade point and letter grade based on the marks. You can use a function to take the marks as input and return both the grade point and letter grade as output using pointers. You can use this function in a loop to ask the user for their marks and display their grade point and letter grade. You can also use a variable to keep track of the total grade points and calculate the CGPA by dividing it by the number of subjects.



Sure, here are three different C programs for student grading system using functions in different variations, types and ways in each instances / implementations:

Program 1: Using an array of structures

C
#include <stdio.h>

struct grade_point {
  float grade_point;
  char letter_grade;
};

int main() {
  int num_subjects;
  float marks;
  float total_grade_points = 0.0;
  struct grade_point grade_points[10];

  // Initialize the grade points array
  for (int i = 0; i < 10; i++) {
    grade_points[i].grade_point = 0.0;
    grade_points[i].letter_grade = 'F';
  }

  // Get the number of subjects
  printf("Enter the number of subjects: ");
  scanf("%d", &num_subjects);

  // Get the marks for each subject
  for (int i = 0; i < num_subjects; i++) {
    printf("Enter the marks for subject %d: ", i + 1);
    scanf("%f", &marks);

    // Find the grade point and letter grade for the marks
    for (int j = 0; j < 10; j++) {
      if (marks >= grade_points[j].grade_point) {
        grade_points[j].grade_point = marks;
        grade_points[j].letter_grade = 'A' + j;
        break;
      }
    }
  }

  // Calculate the total grade points
  for (int i = 0; i < 10; i++) {
    total_grade_points += grade_points[i].grade_point;
  }

  // Calculate the CGPA
  float cgpa = total_grade_points / num_subjects;

  // Display the grade points and letter grades
  for (int i = 0; i < 10; i++) {
    printf("Subject %d: %.2f (%c)\n", i + 1, grade_points[i].grade_point, grade_points[i].letter_grade);
  }

  // Display the CGPA
  printf("CGPA: %.2f\n", cgpa);

  return 0;
}
Use code with caution. Learn more
Program 2: Using a switch-case statement

C
#include <stdio.h>

float get_grade_point(float marks) {
  float grade_point = 0.0;

  switch (marks / 10) {
  case 8:
    grade_point = 4.0;
    break;
  case 7:
    grade_point = 3.75;
    break;
  case 6:
    grade_point = 3.5;
    break;
  case 5:
    grade_point = 3.25;
    break;
  case 4:
    grade_point = 3.0;
    break;
  case 3:
    grade_point = 2.75;
    break;
  case 2:
    grade_point = 2.5;
    break;
  case 1:
    grade_point = 2.25;
    break;
  case 0:
    grade_point = 2.0;
    break;
  default:
    grade_point = 0.0;
    break;
  }

  return grade_point;
}

char get_letter_grade(float grade_point) {
  char letter_grade = 'F';

  switch (grade_point) {
  case 4.0:
    letter_grade = 'A+';
    break;
  case 3.75:
    letter_grade = 'A';
    break;
  case 3.5:
    letter_grade = 'A-';
    break;
  case 3.25:
    letter_grade = 'B+';
    break;
  case 3.0:
    letter_grade = 'B';
    break;

Use code with caution. Learn more
profile picture
give the third one
View other drafts







Sure, here is the third C program for student grading system using if-else statements:

C
#include <stdio.h>

float get_grade_point_and_letter_grade(float marks) {
  float grade_point = 0.0;
  char letter_grade = 'F';

  if (marks >= 80) {
    grade_point = 4.0;
    letter_grade = 'A+';
  } else if (marks >= 75) {
    grade_point = 3.75;
    letter_grade = 'A';
  } else if (marks >= 70) {
    grade_point = 3.5;
    letter_grade = 'A-';
  } else if (marks >= 65) {
    grade_point = 3.25;
    letter_grade = 'B+';
  } else if (marks >= 60) {
    grade_point = 3.0;
    letter_grade = 'B';
  } else if (marks >= 55) {
    grade_point = 2.75;
    letter_grade = 'B-';
  } else if (marks >= 50) {
    grade_point = 2.5;
    letter_grade = 'C+';
  } else if (marks >= 45) {
    grade_point = 2.25;
    letter_grade = 'C';
  } else if (marks >= 40) {
    grade_point = 2.0;
    letter_grade = 'D';
  } else {
    grade_point = 0.0;
    letter_grade = 'F';
  }

  return grade_point, letter_grade;
}

int main() {
  int num_subjects;
  float marks;
  float total_grade_points = 0.0;
  float *grade_point;
  char *letter_grade;

  // Get the number of subjects
  printf("Enter the number of subjects: ");
  scanf("%d", &num_subjects);

  // Allocate memory for the grade points and letter grades
  grade_point = (float *)malloc(num_subjects * sizeof(float));
  letter_grade = (char *)malloc(num_subjects * sizeof(char));

  // Get the marks for each subject
  for (int i = 0; i < num_subjects; i++) {
    printf("Enter the marks for subject %d: ", i + 1);
    scanf("%f", &marks);

    // Get the grade point and letter grade
    grade_point[i], letter_grade[i] = get_grade_point_and_letter_grade(marks);

    // Calculate the total grade points
    total_grade_points += grade_point[i];
  }

  // Calculate the CGPA
  float cgpa = total_grade_points / num_subjects;

  // Display the grade points and letter grades
  for (int i = 0; i < num_subjects; i++) {
    printf("Subject %d: %.2f (%c)\n", i + 1, grade_point[i], letter_grade[i]);
  }

  // Display the CGPA
  printf("CGPA: %.2f\n", cgpa);

  // Free the memory allocated for the grade points and letter grades
  free(grade_point);
  free(letter_grade);

  return 0;
}
Use code with caution. Learn more
I hope this helps! Let me know if you have any other questions.



Write three different  programs (using functions in different variations, types and ways in each instances / implementations ) using C for students grading system, those ask for grade points and calculates the cgpa and letter grade for the given number/points.
Marks Range

Letter Grade
Grade Point

80% and above	A+	(A Plus)	4.0
75% to less than 80%	A	(A regular)	3.75
70% to less than 75%	A-	(A minus)	3.50
65% to less than 70%	B+	(B Plus)	3.25
60% to less than 65%	B	(B regular)	3.0
55% to less than 60%	B-	(B minus)	2.75
50% to less than 55%	C+	(C Plus)	2.50
45% to less than 50%	C	(C regular)	2.25
40% to less than 45%	D	 	2.0
Less than 40%	F	 	0.0

Sure, here are three different C programs that you can use to calculate the CGPA and letter grade for a student's grades.

Program 1: Using a single function

C
#include <stdio.h>

// Function to calculate the CGPA
float calculate_cgpa(int n, float grades[]) {
  float cgpa = 0.0;
  for (int i = 0; i < n; i++) {
    cgpa += grades[i];
  }
  cgpa /= n;
  return cgpa;
}

// Function to calculate the letter grade
char calculate_letter_grade(float grade) {
  if (grade >= 80) {
    return 'A';
  } else if (grade >= 75) {
    return 'B';
  } else if (grade >= 70) {
    return 'C';
  } else if (grade >= 65) {
    return 'D';
  } else {
    return 'F';
  }
}

int main() {
  int n;
  float grades[100];

  // Get the number of subjects
  printf("Enter the number of subjects: ");
  scanf("%d", &n);

  // Get the grades for each subject
  for (int i = 0; i < n; i++) {
    printf("Enter the grade for subject %d: ", i + 1);
    scanf("%f", &grades[i]);
  }

  // Calculate the CGPA
  float cgpa = calculate_cgpa(n, grades);

  // Calculate the letter grade
  char letter_grade = calculate_letter_grade(cgpa);

  // Print the results
  printf("The CGPA is: %.2f\n", cgpa);
  printf("The letter grade is: %c\n", letter_grade);

  return 0;
}
Use code with caution. Learn more
Program 2: Using multiple functions

C
#include <stdio.h>

// Function to calculate the grade point
float calculate_grade_point(float grade) {
  if (grade >= 80) {
    return 4.0;
  } else if (grade >= 75) {
    return 3.75;
  } else if (grade >= 70) {
    return 3.50;
  } else if (grade >= 65) {
    return 3.25;
  } else if (grade >= 60) {
    return 3.0;
  } else if (grade >= 55) {
    return 2.75;
  } else if (grade >= 50) {
    return 2.50;
  } else if (grade >= 45) {
    return 2.25;
  } else {
    return 2.0;
  }
}

// Function to calculate the CGPA
float calculate_cgpa(int n, float grades[]) {
  float cgpa = 0.0;
  for (int i = 0; i < n; i++) {
    cgpa += calculate_grade_point(grades[i]);
  }
  cgpa /= n;
  return cgpa;
}

// Function to calculate the letter grade
char calculate_letter_grade(float grade_point) {
  if (grade_point >= 4.0) {
    return 'A';
  } else if (grade_point >= 3.75) {
    return 'B';
  } else if (grade_point >= 3.50) {
    return 'C';
  } else if (grade_point >= 3.25) {
    return 'D';
  } else {
    return 'F';
  }
}

int main() {
  int n;
  float grades[100];

  // Get the number of subjects
  printf("Enter the number of subjects: ");
  scanf("%d", &n);

  // Get the grades for each subject
  for (int i = 0; i < n; i++) {
    printf("Enter the grade for subject %d: ", i +
Use code with caution. Learn more
profile picture
give the third one too
View other drafts








Sure, here is the third C program:

C
#include <stdio.h>

// Structure to store the grade information
struct grade {
  float grade;
  char letter_grade;
};

// Function to calculate the grade point
float calculate_grade_point(float grade) {
  if (grade >= 80) {
    return 4.0;
  } else if (grade >= 75) {
    return 3.75;
  } else if (grade >= 70) {
    return 3.50;
  } else if (grade >= 65) {
    return 3.25;
  } else if (grade >= 60) {
    return 3.0;
  } else if (grade >= 55) {
    return 2.75;
  } else if (grade >= 50) {
    return 2.50;
  } else if (grade >= 45) {
    return 2.25;
  } else {
    return 2.0;
  }
}

// Function to calculate the CGPA
float calculate_cgpa(int n, struct grade grades[]) {
  float cgpa = 0.0;
  for (int i = 0; i < n; i++) {
    cgpa += grades[i].grade;
  }
  cgpa /= n;
  return cgpa;
}

// Function to calculate the letter grade
char calculate_letter_grade(float grade_point) {
  if (grade_point >= 4.0) {
    return 'A';
  } else if (grade_point >= 3.75) {
    return 'B';
  } else if (grade_point >= 3.50) {
    return 'C';
  } else if (grade_point >= 3.25) {
    return 'D';
  } else {
    return 'F';
  }
}

int main() {
  int n;
  struct grade grades[100];

  // Get the number of subjects
  printf("Enter the number of subjects: ");
  scanf("%d", &n);

  // Get the grades for each subject
  for (int i = 0; i < n; i++) {
    printf("Enter the grade for subject %d: ", i + 1);
    scanf("%f", &grades[i].grade);
    grades[i].letter_grade = calculate_letter_grade(grades[i].grade);
  }

  // Calculate the CGPA
  float cgpa = calculate_cgpa(n, grades);

  // Print the results
  printf("The CGPA is: %.2f\n", cgpa);
  printf("The letter grades are: ");
  for (int i = 0; i < n; i++) {
    printf("%c ", grades[i].letter_grade);
  }

  return 0;
}
Use code with caution. Learn more
This program uses a structure to store the grade information. This makes it easier to calculate the letter grade, since we can simply look up the letter grade in the structure based on the grade point.

Enter a prompt here
Bard may
