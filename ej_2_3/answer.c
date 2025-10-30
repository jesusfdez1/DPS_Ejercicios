#include <stdio.h>

/*
 * CÓDIGO CORREGIDO - DCL41-C: Do not declare variables inside a switch statement before the first case label
 * Ver README.md para explicaciones detalladas
 */

void f(int i) {
    printf("Función f llamada con i = %d\n", i);
}

void func(int expr)
{
    int i = 4;  /* Declaración movida antes del switch para cumplir DCL41-C */
    
    switch (expr)
    {
        f(i);
    case 0:
        i = 17;
    default:
        printf("%d\n", i);
    }
}

int main(void) {
    printf("Llamando func(0):\n");
    func(0);
    
    printf("\nLlamando func(1):\n");
    func(1);
    
    return 0;
}