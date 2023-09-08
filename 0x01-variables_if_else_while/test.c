#include <stdio.h>

int main() {
    int i, j;

    for (i = 0; i <= 99; i++) {
        for (j = i; j <= 99; j++) {
            // Print the tens digit of the first number
            putchar('0' + (i / 10));
            // Print the ones digit of the first number
            putchar('0' + (i % 10));
            // Print a space
            putchar(' ');

            // Print the tens digit of the second number
            putchar('0' + (j / 10));
            // Print the ones digit of the second number
            putchar('0' + (j % 10));

            // If this is not the last combination, print a comma and space
            if (i != 99 || j != 99) {
                putchar(',');
                putchar(' ');
            }
        }
    }
	putchar('\n');

    return 0;
}

