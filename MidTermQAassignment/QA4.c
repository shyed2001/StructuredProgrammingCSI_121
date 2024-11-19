<<<<<<< Updated upstream
<<<<<<< Updated upstream
/// QA 4

// Look at right-side code fragment with if else if.
// Rewrite task with altering if – else if with another suitable statement.
//

/*
if (test expression1) {
 statement(s) }
else if(test expression2) {
 statement(s) }
else {
 statement(s) }
*/


/// Answer:-

///Can achieve similar functionality using a switch statement in some cases.
///switch statements work well when we need to compare a single variable/Boolean against multiple values.
//If conditions are more complex or involve multiple variables, then if-else if-else is a better choice.
//Rewritten given code using a switch statement:


#include <stdio.h>

int main() {
    // Define a variable to represent the selected case
    int selectedCase = 0;

    // Define the test expressions

    int testExpression1 = 0;  // Can change these values to test different cases
    int testExpression2 = 0;  // value 1 set it as true and value 0 set it to false

    printf( "\n Enter two numbers for true and false,\n value 1 set it as true and value 0 set it to false . \n");
     printf( "\n Enter first value 0 or 1 for test Expression1: ");
     scanf( "%d",&testExpression1);
     printf( "\n Enter second value 0 or 1 for test Expression2: ");
     scanf( "%d",&testExpression2);

    // Determine the selected case based on the test expressions
    if (testExpression1) {
        selectedCase = 1; // If testExpression1 is true, set selectedCase to 1
    } else if (testExpression2) {
        selectedCase = 2; // If testExpression2 is true, set selectedCase to 2
    } else {
        selectedCase = 3; // If neither is true, set selectedCase to 3
    }

    // Use a switch statement to perform actions based on the selected case
    switch (selectedCase) {
        case 1:
            printf("Test Expression 1 is true.\n");
            // Statement(s) if testExpression1 is true
            break;

        case 2:
            printf("Test Expression 2 is true.\n");
            // Statement(s) if testExpression2 is true
            break;

        default:
            printf("None of the expressions are true.\n");
            // Statement(s) if none of the expressions is true
            break;
    }

    // Output will depend on the values of testExpression1 and testExpression2
    getchar();
    return 0;
}
=======
=======
>>>>>>> Stashed changes
/// QA 4

// Look at right-side code fragment with if else if.
// Rewrite task with altering if – else if with another suitable statement.
//

/*
if (test expression1) {
 statement(s) }
else if(test expression2) {
 statement(s) }
else {
 statement(s) }
*/


/// Answer:-

///Can achieve similar functionality using a switch statement in some cases.
///switch statements work well when we need to compare a single variable/Boolean against multiple values.
//If conditions are more complex or involve multiple variables, then if-else if-else is a better choice.
//Rewritten given code using a switch statement:


#include <stdio.h>

int main() {
    // Define a variable to represent the selected case
    int selectedCase = 0;

    // Define the test expressions

    int testExpression1 = 0;  // Can change these values to test different cases
    int testExpression2 = 0;  // value 1 set it as true and value 0 set it to false

    printf( "\n Enter two numbers for true and false,\n value 1 set it as true and value 0 set it to false . \n");
     printf( "\n Enter first value 0 or 1 for test Expression1: ");
     scanf( "%d",&testExpression1);
     printf( "\n Enter second value 0 or 1 for test Expression2: ");
     scanf( "%d",&testExpression2);

    // Determine the selected case based on the test expressions
    if (testExpression1) {
        selectedCase = 1; // If testExpression1 is true, set selectedCase to 1
    } else if (testExpression2) {
        selectedCase = 2; // If testExpression2 is true, set selectedCase to 2
    } else {
        selectedCase = 3; // If neither is true, set selectedCase to 3
    }

    // Use a switch statement to perform actions based on the selected case
    switch (selectedCase) {
        case 1:
            printf("Test Expression 1 is true.\n");
            // Statement(s) if testExpression1 is true
            break;

        case 2:
            printf("Test Expression 2 is true.\n");
            // Statement(s) if testExpression2 is true
            break;

        default:
            printf("None of the expressions are true.\n");
            // Statement(s) if none of the expressions is true
            break;
    }

    // Output will depend on the values of testExpression1 and testExpression2
    getchar();
    return 0;
}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
