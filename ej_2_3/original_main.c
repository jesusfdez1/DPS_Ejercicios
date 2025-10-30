#include <stdio.h>

void f(int i) {
    printf("Función f llamada con i = %d\n", i);
}

void func(int expr)
{
    switch (expr)
    {
        int i = 4;
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

