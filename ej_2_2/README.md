# Ejercicio 2.2 

## 1. ¿Qué hace el siguiente segmento de código?

Este código originalmente intentaba implementar una estructura con un "flexible array-like member" usando la técnica antigua de array de un elemento.

Define una estructura `flexArrayStruct` con:
- Un campo `num` para almacenar el tamaño del array
- Un campo `data` que se pretende usar como array de tamaño variable

La función `func`:
- Recibe un tamaño de array como parámetro (`array_size`)
- Reserva memoria dinámicamente para la estructura más espacio adicional
- Inicializa todos los elementos del array con el valor 1


## 2. De haber algún problema ¿Podrías decir la línea en la que se encuentra?

Sí, hay problemas en dos líneas del código original:

### Línea 5 (código original): `int data[1];`
Usa un array de un elemento (técnica pre-C99) en lugar de un flexible array member conforme al estándar C (C99 y posteriores). Esto es un problema porque:
  - Provoca **comportamiento indefinido (UB 59)** al acceder a cualquier elemento más allá de `data[0]`, según el estándar C 6.5.7.
  - El compilador puede generar código optimizado que no devuelve los valores esperados al acceder a `data[1]`, `data[2]`, etc.
  - Puede causar corrupciones de memoria, fallos de segmentación o vulnerabilidades de seguridad explotables.


### Línea 10 (código original): `malloc(sizeof(struct flexArrayStruct) + sizeof(int) * (array_size - 1))`
El cálculo resta 1 porque asume que `data[1]` ya ocupa espacio en `sizeof(struct flexArrayStruct)`, lo cual es una solución basada en el "struct hack" no estándar. Esto es un problema porque:
  - Depende de suposiciones sobre cómo el compilador calcula el tamaño de la estructura —incluyendo el padding y la alineación—, por lo que si el compilador añade relleno adicional o reorganiza la memoria, el cálculo puede ser incorrecto.
  - Si se cambia el tamaño del array en la declaración, hay que recordar ajustar también el cálculo de malloc.
  - Dificulta la lectura y mantenimiento del código porque no es inmediatamente obvio por qué se resta 1.

## 3. Define la regla que se incumple y propón alternativa correcta (SEI CERT C)

### Regla incumplida

El código original incumple la regla **DLC38-C: Flexible Array Members** del estándar SEI CERT C.

Esta regla establece que los flexible array members deben declararse utilizando la sintaxis estándar de C99 mediante un tipo de array incompleto (sin especificar tamaño). El uso de la técnica antigua del "struct hack" con arrays de un elemento (`int data[1]`) provoca comportamiento indefinido, ya que acceder a cualquier elemento más allá del primero viola las garantías del lenguaje.

La solución conforme al estándar SEI CERT C consiste en declarar el flexible array member utilizando la sintaxis `int data[]`, que denota un tipo de array incompleto. 

Al utilizar un flexible array member conforme al estándar, `sizeof(struct flexArrayStruct)` no incluye espacio para el array `data[]`, lo que simplifica el cálculo de memoria en `malloc()`: ahora debe asignarse `sizeof(struct flexArrayStruct) + sizeof(int) * array_size`, eliminando la resta de 1 que era necesaria con el "struct hack".

Esta solución permite tratar la estructura como si el miembro `data[]` hubiera sido declarado con el tamaño exacto `data[array_size]`, cumpliendo con las especificaciones del estándar C y las directrices de programación segura de SEI CERT.

**Código corregido disponible en:** `answer.c`

