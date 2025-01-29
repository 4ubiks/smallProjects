#include <stdio.h>

int main() {
    int number = 255;
    unsigned char upper;

    upper = (number >> 4);

    // Debugging outputs
    printf("upper (decimal) = %d\n", upper);
    printf("upper (hex) = 0x%X\n", upper);
    printf("upper (binary) = 0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (upper >> i) & 1);
    }
    printf("\n");

    return 0;
}
