#include <stdio.h>
#include "NumClass.h"

int main() {
    
     //printf("isPrime(7): %d\n", isPrime(7));

    int first_number;
    int second_number;
    int max;
    int min;
    int a,b;

    scanf("%d%d",&a,&b);

    if(first_number > second_number ){
        max = first_number;
        min = second_number;
    }else{
        max = second_number;
        min = first_number;
    }

    printf("The Armstrong numbers are:");
    for (int i = a; i <= b; ++i)
    {
        if (isArmstrong(i))
            printf(" %d", i);
    }

    printf("\nThe Palindromes are:");
    for (int i = a; i <= b; ++i)
    {
        if (isPalindrome(i))
            printf(" %d", i);
    }

    printf("\nThe Prime numbers are:");
    for (int i = a; i <= b; ++i)
    {
        if (isPrime(i))
            printf(" %d", i);
    }
    
    printf("\nThe Strong numbers are:");
    for (int i = a; i <= b; ++i)
    {
        if (isStrong(i))
             printf(" %d", i);
    }

    printf("\n");

    return 0;
   }

