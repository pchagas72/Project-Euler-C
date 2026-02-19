#include <stdio.h>

int fibonacci(int n){
    if (n == 0){
        return 1;
    }
    if (n == 1){
        return 2;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char *argv[])
{
    int sum = 0;
    int counter = 0;
    int limit = 4000000;
    int placeholder = 0;
    while (placeholder < limit){
        placeholder = fibonacci(counter);
        if (placeholder % 2 == 0){
            sum += placeholder;  
        }
        counter++;
    }
    printf("%d\n", sum);
    return 0;
}
