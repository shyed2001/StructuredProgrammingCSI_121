<<<<<<< Updated upstream
<<<<<<< Updated upstream
///QA 6)
// What do you mean by Recursion? Write a C program calculate Factorial of a number using Recursion.

/// Answer:-

///Recursion is a programming technique in which a function calls itself to solve a problem.
//In a recursive function, the problem is divided into smaller subproblems,
// and each subproblem is solved using the same function.
//  Recursion is based on the concept of "divide and conquer,"
//  where a complex problem is broken down into simpler, more manageable parts.

///To calculate the factorial of a number using recursion,
// we can define a recursive function that repeatedly calls itself
//  with a smaller instance of the same problem until it reaches a base case,
//  which is a situation where the solution is known without further recursion.
//  In the case of calculating the factorial of a number n,
//  the base case is when n is 0 or 1 because the factorial of 0 and 1 is 1.

/// C program to calculate the factorial of a number using recursion:

#include <stdio.h>

// Recursive function to calculate the factorial
unsigned long long factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Recursive case: factorial(n) = n * factorial(n-1)
        return n * factorial(n - 1);
    }
}

int main() {
    int num;

    printf("Enter a non-negative integer of less than or equal to (<=) 65: ");
    scanf("%d", &num);

    if (num < 0 || num > 65 ) {
        printf("Factorial can not be defined for negative numbers or greater than 65 number.\n");
    } else {
        unsigned long long result = factorial(num);
        printf("Factorial of %d is %llu\n", num, result);
    }

    return 0;
}
=======
=======
>>>>>>> Stashed changes
///QA 6)
// What do you mean by Recursion? Write a C program calculate Factorial of a number using Recursion.

/// Answer:-

///Recursion is a programming technique in which a function calls itself to solve a problem.
//In a recursive function, the problem is divided into smaller subproblems,
// and each subproblem is solved using the same function.
//  Recursion is based on the concept of "divide and conquer,"
//  where a complex problem is broken down into simpler, more manageable parts.

///To calculate the factorial of a number using recursion,
// we can define a recursive function that repeatedly calls itself
//  with a smaller instance of the same problem until it reaches a base case,
//  which is a situation where the solution is known without further recursion.
//  In the case of calculating the factorial of a number n,
//  the base case is when n is 0 or 1 because the factorial of 0 and 1 is 1.

/// C program to calculate the factorial of a number using recursion:

#include <stdio.h>

// Recursive function to calculate the factorial
unsigned long long factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Recursive case: factorial(n) = n * factorial(n-1)
        return n * factorial(n - 1);
    }
}

int main() {
    int num;

    printf("Enter a non-negative integer of less than or equal to (<=) 65: ");
    scanf("%d", &num);

    if (num < 0 || num > 65 ) {
        printf("Factorial can not be defined for negative numbers or greater than 65 number.\n");
    } else {
        unsigned long long result = factorial(num);
        printf("Factorial of %d is %llu\n", num, result);
    }

    return 0;
}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
