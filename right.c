#include <stdio.h>
#include <string.h>


void circularShiftRight(char bin[], int shift_bits, int bit_size) {
   
    char temp[shift_bits];

   
    for (int i = 0; i < shift_bits; i++) {
        temp[i] = bin[bit_size - shift_bits + i];
    }

    
    for (int i = bit_size - 1; i >= shift_bits; i--) {
        bin[i] = bin[i - shift_bits];
    }

   
    for (int i = 0; i < shift_bits; i++) {
        bin[i] = temp[i];
    }
}


void printBinary(char bin[], int bit_size) {
    printf("Binary number: ");
    for (int i = 0; i < bit_size; i++) {
        printf("%c", bin[i]);
    }
    printf("\n");
}

int main() {
    char bin[33]; 
    int shift_bits;
    int bit_size = 8;  

    
    printf("Enter a binary number (up to %d bits): ", bit_size);
    scanf("%s", bin);

    
    printf("Enter number of bits that you want to shift right: ");
    scanf("%d", &shift_bits);

   
    if (strlen(bin) != bit_size) {
        printf("Error: Binary input must be %d bits long.\n", bit_size);
        return 1;
    }

   
    printBinary(bin, bit_size);

   
    circularShiftRight(bin, shift_bits, bit_size);

    
    printf("After circular right shift by %d: ", shift_bits);
    printBinary(bin, bit_size);

    return 0;
}


