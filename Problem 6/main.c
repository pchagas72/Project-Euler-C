#include "stdio.h"

int square_sum(int n){
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += i*i; 
    }
    return sum;
}

int sum_squared(int n){
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += i; 
    }
    return sum*sum;
}

int main(){
    int n = 100;
    printf("Diff=%d\n",sum_squared(n)-square_sum(n));
    return 0;
}
