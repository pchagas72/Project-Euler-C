#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    bool not_found = true;
    int counter = 1;
    while (not_found){
        for (int i = 20; i >= 1; i--) {
            if (counter % i != 0) {
                break; 
            }
            if (i == 1){
                printf("%d\n",counter);
                not_found=false;
            }
        }
        counter++;
    }
    return 0;
}
