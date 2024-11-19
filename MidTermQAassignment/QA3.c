

#include <stdio.h>

/* This program creates a 3x10 array and initializes it to zeros. */
int main(void) {
  /* Declare an array of integers with a rows and b columns. */
  int a, b;
  // Takes input from the user for rows and Columns
    printf( "\n Enter two numbers for rows and columns. \n");
     printf( "\n Enter first number for rows: ");
     scanf( "%d",&a);
     printf( "\n Enter second number for columns: ");
     scanf( "%d",&b);

  int array[a][b]; // Correct the dimensions of the array

  /* Declare variables for the loop counters. */
  int x, y;
  int crt = 0; /* Initialize the counter variable. */

  /* Initialize the array to zeros. */
  for (x = 0; x < a; x++) {
    for (y = 0; y < b; y++) {
      array[x][y] = crt;
      crt++;
      printf("%d ", array[x][y]); /* Print the element value. */
    }
    printf("\n"); /* Add a newline after each row. */
  }

  return 0;
}
/// This code takes input from the user for rows and Columns and prints the rows and columns with numbers
