<<<<<<< Updated upstream
<<<<<<< Updated upstream
//Write a C program that accepts weights of 10 students and stores them in an array,
//the program should then prompt the user to enter a weight and then serach through
//the array of the entered weights to check weather the weight entered is found.
////MCE07905536 Shyed Shahriar
///Ans:-

#include <stdio.h>
#include <stdlib.h>

int main() {
  int student_weights[10];
  int weight_to_find;
  int found = 0;

  printf("Enter the weights of 10 students: \n");

  for (int i = 0; i < 10; i++) {
    scanf("%d", &student_weights[i]);
  }

  printf("Enter the weight you want to find: \n");
  scanf("%d", &weight_to_find);

  for (int i = 0; i < 10; i++) {
    if (student_weights[i] == weight_to_find) {
      found = 1;
      break;
    }
  }

  if (found == 1) {
    printf("The weight %d is found in the array.\n", weight_to_find);
  } else {
    printf("The weight %d is not found in the array.\n", weight_to_find);
  }

  return 0;
}
=======
=======
>>>>>>> Stashed changes
//Write a C program that accepts weights of 10 students and stores them in an array,
//the program should then prompt the user to enter a weight and then serach through
//the array of the entered weights to check weather the weight entered is found.
////MCE07905536 Shyed Shahriar
///Ans:-

#include <stdio.h>
#include <stdlib.h>

int main() {
  int student_weights[10];
  int weight_to_find;
  int found = 0;

  printf("Enter the weights of 10 students: \n");

  for (int i = 0; i < 10; i++) {
    scanf("%d", &student_weights[i]);
  }

  printf("Enter the weight you want to find: \n");
  scanf("%d", &weight_to_find);

  for (int i = 0; i < 10; i++) {
    if (student_weights[i] == weight_to_find) {
      found = 1;
      break;
    }
  }

  if (found == 1) {
    printf("The weight %d is found in the array.\n", weight_to_find);
  } else {
    printf("The weight %d is not found in the array.\n", weight_to_find);
  }

  return 0;
}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
