/// QA 3. What do you mean by Compile Time error and Run-time error?
// Does the following code fragment return any error?
// Justify your answer. Rewrite the code fragment as usable
//
//#include <stdio.h>
//int x, y;
//int array[10][3];
//int main( void )
//    { for ( x = 0; x < 3; x++)
//        for ( y = 0; y < 10; y++)
//            array[x][y] = 0;
//
// return 0;
// }


/// Answer:-

/// Compile-time errors:- Compile-time errors are errors that prevent the compiler from translating the program into machine code. These errors are usually caused by syntax errors, such as missing semicolons or parentheses, misspelled keywords, or undefined variables.
/// Runtime errors :- Runtime errors are errors that occur when the program is running. These errors are usually caused by logic errors, such as dividing by zero, accessing an array element that is out of bounds, or trying to open a file that does not exist.
//Compile time errors prevent the code from running, while run-time errors may stop the code from completing its execution.
//Compile time errors are easier to find and fix, as the compiler will point out the exact line and cause of the error. Run-time errors are harder to find and fix, as they may depend on the input or the state of the program at a certain point.
//Compile time errors are also called syntax errors or compilation errors, while run-time errors are also called logic errors or exceptions.

 /// The code fragment dose not return any compile time error or does not show any error on the console.
 ///It shows the message Process returned 0 (0x0), means that the program ran and has finished successfully without any errors.
 ///The 0 is the exit code of the program, which indicates the status of its execution.
 // A non-zero exit code usually means that the program encountered some problems or exceptions. The (0x0) is the hexadecimal representation of the exit code, which is sometimes used for debugging purposes.
// But there is a logical error, because the program actually does not show any output.
/// The array declaration was not correct. Or the for loop to access the array was not correct, resulting in unexpected behaviour.
/// int array[10][3]; should be changed to
/// int array[3][10]; // Correct the dimensions of the array to access the array later by two for loops as [3][10] array.
/// The correct and usable code should be---

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
