# Ejercicio 3.1 
## 1. ¿Qué hace el siguiente segmento de código?
Este código intenta modificar elementos de una lista durante la iteración usando un enhanced for loop (for-each).

El código:
- Crea una lista de enteros con valores `[13, 14, 15]` usando `Arrays.asList()`
- Intenta cambiar el primer elemento a `99` durante la iteración
- Imprime los elementos durante la primera iteración
- Verifica si la lista fue modificada en una segunda iteración


## 2. De haber algún problema ¿Podrías decir la línea en la que se encuentra?

Sí, hay un problema en la línea 9 del código original.

La asignación `i = new Integer(99);` dentro del enhanced for loop (línea 9) viola la regla **DCL02-J: Do not modify the collection's elements during an enhanced for statement** del estándar SEI CERT Java.

El problema es que en un enhanced for loop, la variable de iteración (`i`) es solo una copia del elemento de la colección, no una referencia directa. Por tanto, modificar `i` no modifica el elemento original en la lista. Además, `Arrays.asList()` devuelve una lista inmutable o de tamaño fijo, lo que puede causar problemas adicionales si se intenta modificar.


## 3. Crea un fichero .java con un main, adapta y ejecuta el segmento de código.

Se ha creado el archivo `answer.java` que incluye una implementación completa con `main` y la solución corregida. El código original puede compilarse pero la modificación no tendrá efecto sobre la lista.

## 4. Propón una solución al ejemplo que cumpla con las normas del CMU SEI CERT Java

El código original incumple la regla **DCL02-J: Do not modify the collection's elements during an enhanced for statement** del estándar SEI CERT Java.

Esta regla establece que no se deben modificar los elementos de una colección durante un enhanced for statement (for-each loop) porque la variable de iteración es solo una copia del elemento, no una referencia directa al elemento en la colección. Modificar la variable de iteración no afecta a la colección original.

La solución conforme al estándar SEI CERT Java consiste en:

1. **Usar un `ListIterator`**: Para listas, se puede usar `ListIterator` que permite modificar elementos usando el método `set()`. Esto permite modificar el elemento actual durante la iteración.

2. **Usar un bucle for tradicional con índice**: Otra alternativa es usar un bucle for tradicional con índice para acceder y modificar elementos directamente por su posición.

3. **Usar una lista mutable**: En lugar de `Arrays.asList()` que devuelve una lista inmutable o de tamaño fijo, usar `ArrayList` que permite modificaciones.

En la solución aplicada:
- Se usa `ArrayList` en lugar de `Arrays.asList()` para tener una lista mutable
- Se utiliza `ListIterator` con el método `set()` para modificar el elemento actual durante la iteración

**Código corregido disponible en:** `answer.java`

## 5. Indica la versión de Java que estás utilizando y cómo has hecho para compilar y ejecutar.

### Versión de Java

Para verificar la versión de Java instalada:

```bash
java -version
```

Resultado:
```
java version "21.0.2" 2024-01-16 LTS
Java(TM) SE Runtime Environment (build 21.0.2+13-LTS-58)
Java HotSpot(TM) 64-Bit Server VM (build 21.0.2+13-LTS-58, mixed mode, sharing)
```

### Compilación y ejecución

El comando `javac` compila el archivo `.java` generando el archivo `.class` con el bytecode.

```bash
javac answer.java
```
El comando `java` ejecuta el bytecode. Se usa el nombre de la clase sin la extensión `.class`.

```bash
java answer
```

**Resultado:**
```
Processing list ... 
 New item: 99
 New item: 14
 New item: 15
Modified list?
List item: 99
List item: 14
List item: 15
```

El resultado muestra que la lista fue modificada correctamente. El primer elemento cambió de `13` a `99`, demostrando que la solución con `ListIterator.set()` funciona correctamente.
