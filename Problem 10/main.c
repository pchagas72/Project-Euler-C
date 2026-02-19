#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

long long int sum_primes_up_to_N(long long int n) {
    if (n < 2) return -1;

    // Sieve of Eratosthenes (false=prime)
    bool *is_composite = (bool *)calloc(n + 1, sizeof(bool));
    if (is_composite == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    is_composite[0] = true;
    is_composite[1] = true;

    // Apply the sieve operations
    for (int p = 2; p * p <= n; p++) {
        if (!is_composite[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_composite[i] = true;
            }
        }
    }

    long long int sum = 0;

    for (int p = 2; p <= n; p++) {
        if (!is_composite[p]) {
            sum += p;
        }
    }

    free(is_composite);
    return sum;
}

int main(int argc, char *argv[])
{
    printf("%lli\n", sum_primes_up_to_N(2000000));
    return 0;
}
