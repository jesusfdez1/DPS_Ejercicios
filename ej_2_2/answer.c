#include <stdlib.h>

/*
 * CÓDIGO CORREGIDO - DLC38-C: Flexible Array Members
 * Ver README.md para explicaciones detalladas
 */

struct flexArrayStruct {
  int num;
  int data[];  /* Flexible array member correcto */
};

void func(size_t array_size) {
  /* Asignar memoria para la estructura + array dinámico */
  struct flexArrayStruct *structP = (struct flexArrayStruct *) malloc(
    sizeof(struct flexArrayStruct) + sizeof(int) * array_size);
  
  if (structP == NULL) {
    return;  /* Manejar fallo de malloc */
  }
  
  structP->num = array_size;

  /* Acceder a data[] como si fuera data[array_size] */
  for (size_t i = 0; i < array_size; ++i) {
    structP->data[i] = 1;
  }
  
  free(structP);  /* Liberar memoria */
}