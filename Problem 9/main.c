#include <stdio.h>

int main(void) {
    for (int a = 1; a <= 333; a++) {
        int numerator = 500000 - 1000 * a;  // Develop the equation (a² + b² = c²)
        int denominator = 1000 - a;         // Knowing that c = 1000 - (a + b)

        if (numerator % denominator == 0) {
            int b = numerator / denominator;
            int c = 1000 - (a + b);

            printf("Result: %d\n", a * b * c);
            return 0;
        }
    }
    return 0;
}
