#include <stdio.h>
#include <stdlib.h>

/*
 * CÓDIGO CORREGIDO - Múltiples reglas DCL del SEI CERT C
 * Ver README.md para explicaciones detalladas
 */

/* DCL06-C: Use meaningful symbolic constants to represent literal values */
#define DEFAULT_FACTORIAL_VALUE 12

/* DCL01-C: Do not reuse variable names in subscopes */
/* DCL00-C: Const-qualify immutable objects */
unsigned long long int factorial(const unsigned int number) {
    if (number <= 1) {
        return 1;
    }
    return number * factorial(number - 1);
}

int main(int argc, char *argv[]) {
    /* DCL01-C: Do not reuse variable names in subscopes - using distinct names */
    /* DCL02-C: Use visually distinct identifiers */
    /* DCL04-C: Do not declare more than one variable per declaration */
    int default_value = DEFAULT_FACTORIAL_VALUE;

    if (argc == 1) {
        printf("Factorial of %d is %llu\n", default_value, factorial(default_value));
    } else {
        /* DCL19-C: Minimize the scope of variables and functions */
        /* MSC24-C: Do not use deprecated or obsolescent functions */
        int max_iterations = (int)strtol(argv[1], NULL, 10);
        int iteration;
        
        for (iteration = 0; iteration < max_iterations; iteration++) {
            printf("Factorial of %d is %llu\n", iteration, factorial(iteration));
        }
    }

    return 0;
}

