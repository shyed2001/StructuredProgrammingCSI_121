<<<<<<< Updated upstream
<<<<<<< Updated upstream
//The table below represents eggs a farmer sells each day.
//Write a C program that calculates the average egg sold by the farmer for the four days.
//Day 1 2 3 4
//Egg Sell 34, 37 , 33, 31
////MCE07905536 Shyed Shahriar
///Ans:

#include <stdio.h>

int main() {
  int eggs_sold[4] = {34, 37, 33, 31};
  int total_eggs_sold = 0;
  float average_eggs_sold;

  for (int i = 0; i < 4; i++) {
    total_eggs_sold += eggs_sold[i];
  }

  average_eggs_sold = (float)total_eggs_sold / 4;

  printf("The average number of eggs sold is: %f\n", average_eggs_sold);
  getchar();
  return 0;
}

=======
=======
>>>>>>> Stashed changes
//The table below represents eggs a farmer sells each day.
//Write a C program that calculates the average egg sold by the farmer for the four days.
//Day 1 2 3 4
//Egg Sell 34, 37 , 33, 31
////MCE07905536 Shyed Shahriar
///Ans:

#include <stdio.h>

int main() {
  int eggs_sold[4] = {34, 37, 33, 31};
  int total_eggs_sold = 0;
  float average_eggs_sold;

  for (int i = 0; i < 4; i++) {
    total_eggs_sold += eggs_sold[i];
  }

  average_eggs_sold = (float)total_eggs_sold / 4;

  printf("The average number of eggs sold is: %f\n", average_eggs_sold);
  getchar();
  return 0;
}

<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
