#include <stdio.h>
#include <stdbool.h>

int factors(long n){
    long int biggestLol = 0;
    bool isPrime;
    for (long int i = 2; i <= n/2; i++) {
        if (n%i == 0) { // It's a factor
            isPrime = true;
            for (int j = 2; j <= i/2; j++) { // Check if it's not a prime number
                if (i%j == 0){
                    isPrime = false;
                    break;
                }
            }
            if (isPrime){
                printf("%li is prime and factor\n",i);
                if (i > biggestLol){ biggestLol = i; };
            }
        }
    }
    return biggestLol;
}

int main(int argc, char *argv[]){

    long n = 600851475143; 
    //long n = 13195;
    long r = factors(n);
    printf("%li is so biiiiig loooooool\n",r);
    return 0;
}
