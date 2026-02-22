#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_COUNT 100
#define DIGITS 50
#define MAX_SUM_LEN 60

int main() {
    FILE *f = fopen("./numbers.txt", "r");
    if (f == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    int sum[MAX_SUM_LEN] = {0};
    char line[DIGITS + 2];

    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\r\n")] = 0;
        if (strlen(line) < DIGITS) continue;

        for (int i = 0; i < DIGITS; i++) {
            sum[MAX_SUM_LEN - 1 - i] += line[DIGITS - 1 - i] - '0'; // Think of an abacus
        }
    }
    fclose(f);

    for (int i = MAX_SUM_LEN - 1; i > 0; i--) {
        sum[i - 1] += sum[i] / 10;
        sum[i] %= 10;
    }

    int count = 0;
    int started = 0;
    for (int i = 0; i < MAX_SUM_LEN; i++) {
        if (sum[i] != 0) started = 1;
        if (started && count < 10) {
            printf("%d", sum[i]);
            count++;
        }
    }
    printf("\n");

    return 0;
}
