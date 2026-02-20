#include <stdio.h>

int return_divisors(int n){
    int divisors = 0; 
    for (int i = 1; i*i < n; i++) {
        if (n % i == 0) { divisors += 2; };
    }
    return divisors;
}

int main(int argc, char *argv[])
{
    int counter = 1;
    int triangle = 0;
    int divisors = 0;
    while (divisors <= 500){
        triangle += counter;
        divisors = return_divisors(triangle);
        counter++;
    }
    printf("%d\n", triangle);
    return 0;
}
