<<<<<<< Updated upstream
<<<<<<< Updated upstream
#include <stdio.h>


// QA 7
Write a C program that takes Student Information and Marks from two different files and
write student wise individual subject grade and GPA in another file. [File Templates and
Instructions will be provided]


//QA 6
What do you mean by Recursion? Write a C program calculate Factorial of a number using Recursion.





// QA 5
int main() {
    int num1, num2, sum, *ptr1, *ptr2;


    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Initialize pointers to the addresses of num1 and num2
    ptr1 = &num1;
    ptr2 = &num2;

    // Calculate the sum using pointers
    sum = *ptr1 + *ptr2;

    // Display the result
    printf("Sum of %d and %d is %d\n", *ptr1, *ptr2, sum);

    return 0;
}



// QA 4
Look at right-side
code fragment with if
else if. Rewrite task with altering if –
else if
with another suitable statement.
if (test expression1) {
// statement(s) }
else if(test expression2) {
// statement(s) }
else {
// statement(s) }

//// QA 3
//#include <stdio.h>
//
//int x, y;
//int array[10][3];
//int main( void )
//    { for ( x = 0; x < 3; x++)
//        for ( y = 0; y < 10; y++)
//            array[x][y] = 0;
//
// return 0;
// }
//
//// QA 3
//
//#include <stdio.h>
//
//int main(void) {
//    int array[3][10]; // Correct the dimensions of the array
//    int x, y;
//    int crt =0;
//
//    // Initialize the array to zeros
//    for (x = 0; x < 3; x++) {
//        for (y = 0; y < 10; y++) {
//            array[x][y] = crt;
//            crt++;
//             printf("%d ", array[x][y]);
//        }
//        printf("\n"); // Add a newline after each row
//    }
//
//    return 0;
//}
//// QA 3
//#include <stdio.h>
//
//int main(void) {
//    int array[3][10]; // Correct the dimensions of the array
//    int x, y;
//    int crt =0;
//
//    // Initialize the array to zeros
//    for (x = 0; x < 3; x++) {
//        for (y = 0; y < 10; y++) {
//            array[x][y] = crt;
//            crt++;
//             printf("%d ", array[x][y]);
//        }
//        printf("\n"); // Add a newline after each row
//    }
//
//    // Print the array
//    for (x = 0; x < 3; x++) {
//        for (y = 0; y < 10; y++) {
//            printf("%d ", array[x][y]);
//        }
//        printf("\n"); // Add a newline after each row
//    }
//
//    return 0;
//}

// QA 2
//#include <stdio.h>
// int x,y;  int main(){ printf(
//"\nEnter two numbers");scanf(
//"%d %d",&x,&y); printf(
//"\n\n%d is   bigger",(x>y)?x:y); return 0;}
//

// QA 1
//#include <stdio.h>
//
//int main(void) {
//    for (int ctr = 65; ctr < 91; ctr++)
//        printf("%c", ctr);
//    return 0;
//}
=======
=======
>>>>>>> Stashed changes
#include <stdio.h>


// QA 7
Write a C program that takes Student Information and Marks from two different files and
write student wise individual subject grade and GPA in another file. [File Templates and
Instructions will be provided]


//QA 6
What do you mean by Recursion? Write a C program calculate Factorial of a number using Recursion.





// QA 5
int main() {
    int num1, num2, sum, *ptr1, *ptr2;


    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Initialize pointers to the addresses of num1 and num2
    ptr1 = &num1;
    ptr2 = &num2;

    // Calculate the sum using pointers
    sum = *ptr1 + *ptr2;

    // Display the result
    printf("Sum of %d and %d is %d\n", *ptr1, *ptr2, sum);

    return 0;
}



// QA 4
Look at right-side
code fragment with if
else if. Rewrite task with altering if –
else if
with another suitable statement.
if (test expression1) {
// statement(s) }
else if(test expression2) {
// statement(s) }
else {
// statement(s) }

//// QA 3
//#include <stdio.h>
//
//int x, y;
//int array[10][3];
//int main( void )
//    { for ( x = 0; x < 3; x++)
//        for ( y = 0; y < 10; y++)
//            array[x][y] = 0;
//
// return 0;
// }
//
//// QA 3
//
//#include <stdio.h>
//
//int main(void) {
//    int array[3][10]; // Correct the dimensions of the array
//    int x, y;
//    int crt =0;
//
//    // Initialize the array to zeros
//    for (x = 0; x < 3; x++) {
//        for (y = 0; y < 10; y++) {
//            array[x][y] = crt;
//            crt++;
//             printf("%d ", array[x][y]);
//        }
//        printf("\n"); // Add a newline after each row
//    }
//
//    return 0;
//}
//// QA 3
//#include <stdio.h>
//
//int main(void) {
//    int array[3][10]; // Correct the dimensions of the array
//    int x, y;
//    int crt =0;
//
//    // Initialize the array to zeros
//    for (x = 0; x < 3; x++) {
//        for (y = 0; y < 10; y++) {
//            array[x][y] = crt;
//            crt++;
//             printf("%d ", array[x][y]);
//        }
//        printf("\n"); // Add a newline after each row
//    }
//
//    // Print the array
//    for (x = 0; x < 3; x++) {
//        for (y = 0; y < 10; y++) {
//            printf("%d ", array[x][y]);
//        }
//        printf("\n"); // Add a newline after each row
//    }
//
//    return 0;
//}

// QA 2
//#include <stdio.h>
// int x,y;  int main(){ printf(
//"\nEnter two numbers");scanf(
//"%d %d",&x,&y); printf(
//"\n\n%d is   bigger",(x>y)?x:y); return 0;}
//

// QA 1
//#include <stdio.h>
//
//int main(void) {
//    for (int ctr = 65; ctr < 91; ctr++)
//        printf("%c", ctr);
//    return 0;
//}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
