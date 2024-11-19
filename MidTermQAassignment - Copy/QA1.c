<<<<<<< Updated upstream
<<<<<<< Updated upstream
///Q 1) Explain the operation of every individual line the program.
//What will be output of the following program?
//Rewrite the code in compact form (may omit line and reduce code)
//allowing warnings
//
//#include <stdio.h>
//int main(void) {
//int ctr;
//for( ctr = 65; ctr < 91; ctr++ ) printf("%c", ctr );
//return 0;
//}

/// Answer:-

/// #include <stdio.h> //Only omitting this will produce warning.
// This line includes the standard input/output library, which is necessary for using functions like printf and scanf.

///int main(void) //  This line defines the main function, which is the entry point of the program. It returns an integer value and takes no arguments (void).

void main(void) // main function does not take or return any argument or value. But this will not show any warning

 {
     // int ctr;  // This declares an integer variable named ctr without initializing it. This variable will be used as a loop counter.

    for (int ctr = 65; ctr < 91; ctr++) // This line starts a for loop. It initializes ctr to 65, and the loop continues as long as ctr is less than 91. In each iteration, ctr is incremented by 1 (ctr++).


        printf("%c \t", ctr); //This line uses the printf function to print a character represented by an integer value stored in ctr , where %c is used as a format specifier to print the character corresponding to the integer value in ctr.

        ///return 0; // But this will not show any warning, main function does not take or return any value.

}
// The output of this program will be Capital A to Z , ASCII 65 to 90 letters.
// With added tabs between them because of edited code.
=======
=======
>>>>>>> Stashed changes
///Q 1) Explain the operation of every individual line the program.
//What will be output of the following program?
//Rewrite the code in compact form (may omit line and reduce code)
//allowing warnings
//
//#include <stdio.h>
//int main(void) {
//int ctr;
//for( ctr = 65; ctr < 91; ctr++ ) printf("%c", ctr );
//return 0;
//}

/// Answer:-

/// #include <stdio.h> //Only omitting this will produce warning.
// This line includes the standard input/output library, which is necessary for using functions like printf and scanf.

///int main(void) //  This line defines the main function, which is the entry point of the program. It returns an integer value and takes no arguments (void).

void main(void) // main function does not take or return any argument or value. But this will not show any warning

 {
     // int ctr;  // This declares an integer variable named ctr without initializing it. This variable will be used as a loop counter.

    for (int ctr = 65; ctr < 91; ctr++) // This line starts a for loop. It initializes ctr to 65, and the loop continues as long as ctr is less than 91. In each iteration, ctr is incremented by 1 (ctr++).


        printf("%c \t", ctr); //This line uses the printf function to print a character represented by an integer value stored in ctr , where %c is used as a format specifier to print the character corresponding to the integer value in ctr.

        ///return 0; // But this will not show any warning, main function does not take or return any value.

}
// The output of this program will be Capital A to Z , ASCII 65 to 90 letters.
// With added tabs between them because of edited code.
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
