
#include "NumClass.h"


int length3(int);
int sumpower(int,int);
int digitsSum(int,int);

int length3(int number){
     int length = 0;

    if (number == 0) {
        return 1;
    }
    while (number != 0) {
        number /= 10;
        length++;
    }

    return length;
}

 int sumpower(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * sumpower(base, exponent - 1);
    }
}

int digitsSum(int number, int power) {
    if (number == 0)
        return 0;

    return sumpower((number%10), power) + digitsSum((number/10), power);
}

int isArmstrong(int number) {
    if((number != digitsSum(number, length3(number)))){
       return false;
    }
    return true;
}


int isPalindromeRec(int number,int originalN , int backwards){
    if(number == 0){
        return (originalN == backwards);
    }
    else {
        int digit = number %10;
        backwards = backwards*10 +digit;
        number = number/10;
        return isPalindromeRec(number,originalN,backwards);
    }
    
}

int isPalindrome(int number){
    return isPalindromeRec(number,number,0);
}