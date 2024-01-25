#include "NumClass.h"

int length(int);
int factorial(int);


int isPrime(int number) {
    if (number < 1) {
        return 0;  
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return 0;  
        }
    }

    return 1;
} 

int length(int number){
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

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; 
    } else {
        return n * factorial(n - 1);
    }
}

int isStrong(int number){
  
   int number_length = length(number);
   int sum=0;
   int originalNumber = number;

   int arr [number_length];

  for(int i=0; i<number_length; i++){
      arr[i] = number%10;
      number = number/10;
  }

  for(int i=0; i<number_length; i++){
     sum = sum + factorial(arr[i]);
  }
  return(sum == originalNumber);
  
}
 


 