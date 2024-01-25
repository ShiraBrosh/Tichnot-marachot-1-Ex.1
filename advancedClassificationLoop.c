#include "NumClass.h"
#include <stdbool.h>

int length2(int);
int power2(int,int);

int length2(int number){
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


    int isPalindrome(int number) {
    int original = number;
    int backwards = 0;
    int digits;

    while (number > 0) {
        digits = number % 10;
        backwards = (backwards*10) + digits;
        number /= 10;
    }

    return(original == backwards);
}



int power2(int base, int exponent) {
    if (exponent == 0) {
        return 1; // Any number to the power of 0 is 1
    } else if (exponent > 0) {
        double result = 1;
        for (int i = 1; i <= exponent; i++) {
            result *= base;
        }
        return result;
    } else {
        // Handling negative exponent by taking the reciprocal
        double result = 1;
        for (int i = 1; i <= -exponent; i++) {
            result /= base;
        }
        return result;
    }
}


int isArmstrong(int number){

 int the_power = length2(number);
 int digits = 0;
 int result = 0;
 int sum = 0;
 int originalNumber = number;
 

while(number != 0){
 
  digits = number%10;
  result = power2(digits,the_power);
  sum = sum + result;
 
 number = number/10;
}

 return(sum == originalNumber);

}
