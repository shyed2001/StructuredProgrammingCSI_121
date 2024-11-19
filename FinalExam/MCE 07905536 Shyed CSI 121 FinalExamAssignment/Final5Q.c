<<<<<<< Updated upstream
<<<<<<< Updated upstream
/// Q 5.Write a C program to calculate value of S for first n number of elements like S= 8 + 88 + 888 + 8888 +
////MCE07905536 Shyed Shahriar
///Ans:

#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer for n.\n");
        return 1;  // Return an error code
    }

    long long sum = 0;
    long long term = 8;

    for (int i = 1; i <= n; ++i) {
        sum += term;
        term = term * 10 + 8;
    }

    printf("The value of S for the first %d elements is: %lld\n", n, sum);

    return 0;
}



=======
=======
>>>>>>> Stashed changes
/// Q 5.Write a C program to calculate value of S for first n number of elements like S= 8 + 88 + 888 + 8888 +
////MCE07905536 Shyed Shahriar
///Ans:

#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer for n.\n");
        return 1;  // Return an error code
    }

    long long sum = 0;
    long long term = 8;

    for (int i = 1; i <= n; ++i) {
        sum += term;
        term = term * 10 + 8;
    }

    printf("The value of S for the first %d elements is: %lld\n", n, sum);

    return 0;
}



<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
