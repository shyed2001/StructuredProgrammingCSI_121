<<<<<<< Updated upstream
<<<<<<< Updated upstream
/// QA 5
// What  are  the  significant  of  pointer  in  C  programming?
// Write  a  program  in  C  to  add  two numbers using pointers.


/// Answer:-

///Pointers are a fundamental concept in C programming and offer several significant advantages and capabilities:
//
///Direct Memory Access: Pointers allow us to directly access and manipulate memory locations,
//which is essential for tasks like dynamic memory allocation, data structures (e.g., linked lists, trees), and working with hardware.
//
///Efficiency: Pointers can make programs more memory-efficient because
//they enable you to work with data without creating unnecessary copies.
// This can be crucial in systems programming and resource-constrained environments.
//
///Functionality: Pointers enable us to create complex data structures, implement algorithms efficiently,
// and work with arrays and strings effectively.
//
///Dynamic Memory Allocation: Pointers are essential for allocating and managing memory
// dynamically using functions like malloc, calloc, and realloc.
//
///Interfacing with Hardware: Pointers are often used to interact with hardware
//devices and access memory-mapped I/O


/// A program  in  C  to  add  two numbers using pointers.

#include <stdio.h>


int main() {
    int num1, num2, sum, *ptr1, *ptr2;


    // Input two numbers
     printf( "\n Enter two integer numbers for addition  \n");
     printf( "\n Enter first int number: ");
     scanf( "%d",&num1);
     printf( "\n Enter second int number: ");
     scanf( "%d",&num2);

     // Initialize pointers to the addresses of num1 and num2
    ptr1 = &num1;
    ptr2 = &num2;

    // Calculate the sum using pointers
    sum = *ptr1 + *ptr2; // Pointer dereferencing

    // Display the result
    printf("\n Sum of %d and %d is %d \n", *ptr1, *ptr2, sum);

    return 0;
}
=======
=======
>>>>>>> Stashed changes
/// QA 5
// What  are  the  significant  of  pointer  in  C  programming?
// Write  a  program  in  C  to  add  two numbers using pointers.


/// Answer:-

///Pointers are a fundamental concept in C programming and offer several significant advantages and capabilities:
//
///Direct Memory Access: Pointers allow us to directly access and manipulate memory locations,
//which is essential for tasks like dynamic memory allocation, data structures (e.g., linked lists, trees), and working with hardware.
//
///Efficiency: Pointers can make programs more memory-efficient because
//they enable you to work with data without creating unnecessary copies.
// This can be crucial in systems programming and resource-constrained environments.
//
///Functionality: Pointers enable us to create complex data structures, implement algorithms efficiently,
// and work with arrays and strings effectively.
//
///Dynamic Memory Allocation: Pointers are essential for allocating and managing memory
// dynamically using functions like malloc, calloc, and realloc.
//
///Interfacing with Hardware: Pointers are often used to interact with hardware
//devices and access memory-mapped I/O


/// A program  in  C  to  add  two numbers using pointers.

#include <stdio.h>


int main() {
    int num1, num2, sum, *ptr1, *ptr2;


    // Input two numbers
     printf( "\n Enter two integer numbers for addition  \n");
     printf( "\n Enter first int number: ");
     scanf( "%d",&num1);
     printf( "\n Enter second int number: ");
     scanf( "%d",&num2);

     // Initialize pointers to the addresses of num1 and num2
    ptr1 = &num1;
    ptr2 = &num2;

    // Calculate the sum using pointers
    sum = *ptr1 + *ptr2; // Pointer dereferencing

    // Display the result
    printf("\n Sum of %d and %d is %d \n", *ptr1, *ptr2, sum);

    return 0;
}
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
