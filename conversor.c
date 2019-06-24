#include <stdio.h>
#include <string.h>

#define max 512
#define length 8

char number[max];
int base, convert;
long long value;

long long power(int x, long long y) {
    long long output = 1, i = 0;
    while (i++ < y) output *= x;
    return output;
}

int chr2num(char c) {
    // Checking if the user input is alphanumeric
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return 10 + c - 'A';
    if (c >= 'a' && c <= 'z') return 10 + c - 'a';
    // Otherwise returns negative one
    return -1;
}

char num2chr(long long i) {
    // If it is out of range should return empty space
    if (i > 36) return ' ';
    // Returning the number converted into character
    return (i > 9) ? (char) (i - 10 + 'A') : (char) (i + '0');
}

long long num2dec(char num[], int base) {
    int size = (int) strlen(num) - 1;
    long long output = 0;
    // Counting down in the loop
    for (int i = size, exponent = 0; i >= 0; i--, exponent++) {
        // Getting the number representation (if is A, should be 15)
        int value = chr2num(num[i]);
        // If the chosen base does not support this value returns -1
        if (value >= base || value == -1) return -1;
        // Adding into the output variable the count
        output += value * power(base, exponent);
    }
    return output;
}

char *dec2num(long long num, int base) {
    // Creating the iterator and the output variable
    int i = 0;
    char output[max] = "";
    // While num divided by its base is smaller than 0
    do output[i++] = num2chr(num % base);
    while (num /= base);
    // Reversing the string and returning
    return strrev(output);
}

int main() {
    printf("Put values with the following syntax: [[number], [its base], [convert to]]: ");
    scanf("%s %d %d", number, &base, &convert);
    if (strlen(number) <= length && base <= 36 && base >= 2 && convert <= 36 && convert >= 2)
        // Checking if there is any error
        if ((value = num2dec(number, base)) != -1) {
            // Creating the output variable which contains the converted value
            char *output = dec2num(value, convert);
            printf("\nThe chosen number (%s)%d was converted!\nit's equals to (%s)%d\n", number, base, output, convert);
            // If the user got here, it should quit the program
            return 0;
        }
    // Quitting the program with a message
    printf("\nSorry! the values you've just put are out of range\n");
    return 0;
}