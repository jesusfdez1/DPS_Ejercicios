#include <stdio.h>
#include <stddef.h>

const char *p;

char *funcion1(void)
{
    char array[10] = "Mi Cadena";
    /* Initialize array */
    return array;
}
void funcion2(void)
{
    const char c_str[] = "Todo va bien";
    p = c_str;
}

void funcion3(void)
{
    printf("%s\n", p);
}

int main(void)
{

    p = funcion1();
    printf("%s\n", p);
    funcion2();
    funcion3();
    printf("%s\n", p);

    return 0;
}