#include <stdio.h>
#include <stddef.h>

/* DCL30-C: Declare objects with appropriate storage durations
 *
 * Problema: Se devolvían o conservaban direcciones de objetos con
 * duración automática (pila) fuera de su ámbito, lo que constituye
 * comportamiento indefinido al referenciarlos tras el final de su vida útil.
 *
 * Solución (patrón "Return Values" de la guía del CERT C):
 * 1) El búfer de trabajo se declara en main (el llamante controla su vida).
 * 2) Las funciones 1 y 2 reciben y escriben en dicho búfer sin devolver punteros a almacenamiento automático.
 * 3) Las funcion 3 recibe const char * y no almacenan direcciones de objetos de menor duración para uso posterior.
*/

void funcion1(char *array, size_t len)
{
    /* Initialize array */
    snprintf(array, len, "%s", "Mi Cadena");
}
void funcion2(char *array, size_t len)
{
    snprintf(array, len, "%s", "Todo va bien");
}

void funcion3(const char *s)
{
    printf("%s\n", s);
}

int main(void)
{
    char array[32];  // Array declarado en main con misma duración que p - ambos en mismo ámbito 
                    // Se pone un número porque si no se pone, el compilador no sabe el tamaño del array
                    // y no puede hacer el cast de la función snprintf.
    const char *p;

    funcion1(array, sizeof array);
    p = array;
    printf("%s\n", p);

    funcion2(array, sizeof array);
    funcion3(p);

    printf("%s\n", p);

    return 0;
}