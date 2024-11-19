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
