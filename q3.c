#include <stdio.h>
#include <math.h>

int convertBase4ToDecimal(int num) {
    int decimalNum = 0;
    int base = 1;

    while (num > 0) {
        int digit = num % 10; 
        decimalNum += digit * base; 
        num /= 10; 
        base *= 4; 
    }

    return decimalNum;
}

int main() {
    int base4Num;
    
    printf("Enter a number in base-4: ");
    scanf("%d", &base4Num);
    
    int decimalNum = convertBase4ToDecimal(base4Num);
    
    printf("The equivalent decimal number is: %d\n", decimalNum);
    
    return 0;
}
