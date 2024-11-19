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
