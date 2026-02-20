#include "stdio.h"
#include <string.h>

int main(){
    int mask_size = 13;
    char mask_buffer[mask_size];
    long int biggest = 0;

    char buffer[1000]; // Length is known
    FILE *f = fopen("./number.txt", "r");;

    if (f == NULL){
        printf("Error: Could not open file\n");
        return 1;
    }

    if (fgets(buffer, sizeof(buffer), f) == NULL){
        printf("Error: Could read file\n");
        return 1;
    }

    fclose(f);

    buffer[strcspn(buffer, "\r\n")] = 0; // Strcspn finds the specified characters in the provided buffer
                                         // And, in this case, removes them
    int len = strlen(buffer);
    if (mask_size > len){
            printf("Mask size is bigger than the number length\n");
    }
    
    for (int i = 0; i <= len - mask_size; i++) {
        strncpy(mask_buffer,&buffer[i], mask_size); // Reads N characters from a buffer to another
        mask_buffer[mask_size] = '\0';              // \0 = end of string
        long int current_product = 1;
        for (int j = 0; j < mask_size; j++) {
            current_product *= mask_buffer[j] - '0';    // Trick to parse char to integer
        }
        if (current_product > biggest) { biggest = current_product; };
    }

    printf("%li\n",biggest);
}
