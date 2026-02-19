#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int get_len(int n){
    int counter = 0;
    while (n != 0){
        n /= 10;
        counter++;
    }
    return counter;
}

int reverse_number(int n){
    int result = 0;
    int len = get_len(n);
    int last_digit;
    while (len >= 0){
        last_digit = n % 10; 
        if (len > 1){
            result += last_digit * pow(10,len-1);
        } else{
            result += last_digit;
        }
        n /= 10;
        len--;
    }
    return result;
}

int main(int argc, char *argv[])
{
    int product;
    int answer = 0;
    for (int i = 999; i >= 100; i--) {
        for (int j = 999; j >= 100; j--) {
            product = j*i; 
            if (product == reverse_number(product)){
                if (product > answer){ answer = product; };
            }
        }
    }
    printf("%d\n",answer);
    return 0;
}
