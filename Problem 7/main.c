#include <stdbool.h>
#include <stdio.h>

bool is_prime(long int n){
    for (long int i = 2;i <= n/2;i++) {
        if (n % i == 0) {
            return false;
        }
    } 
    return true;
}

int main(int argc, char *argv[])
{
    int primes = 0;
    int limit = 10001;
    int counter = 2;
    int last_prime = 0;
    while (primes != limit) {
        if (is_prime(counter)){
            primes++;
            last_prime = counter;
        }
        counter++; 
    }
    printf("%d\n",last_prime);
    return 0;
}
