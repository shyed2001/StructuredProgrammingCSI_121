///Q 2) Does is the right side code will be complied or not? Correct it (if necessary) and rewrite it in more readable format.
//
//#include <stdio.h>
// int x,y;  int main(){ printf(
//"\nEnter two numbers");scanf(
//"%d %d",&x,&y); printf(
//"\n\n%d is   bigger",(x>y)?x:y); return 0;}

/// Answer:-
///Yes the right side code will be complied.
// Corrected for a space and a newline in the scanf/input from user
// Taking two inputs separately and rewritten for readability the code will be

#include <stdio.h>
 int x,y;
 int main( void )

 {
     printf( "\n Enter two numbers for comparison  \n");
     printf( "\n Enter first number: ");
     scanf( "%d",&x);
     printf( "\n Enter second number: ");
     scanf( "%d",&y);
     printf( "\n %d is bigger \n",(x>y)?x:y);
     return 0;
     }
