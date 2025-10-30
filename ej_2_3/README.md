# Ejercicio 2.3 

## 1. ¿Qué hace el siguiente segmento de código si invocamos la función func con un 0?

Este código intenta ejecutar una función `func` que recibe un parámetro `expr`. Si se invoca con `expr = 0`:

1. El control del programa entra en el bloque `switch (expr)`
2. Se declara e inicializa la variable `int i = 4;` 
3. Se llama a la función `f(i)`
4. El control salta al `case 0:`
5. Se asigna `i = 17`
6. Continúa con el `default:` y ejecuta `printf("%d\n", i);`, imprimiendo 17

Sin embargo, **hay un problema crítico**: la declaración de la variable `i` está dentro del bloque `switch` pero antes del primer `case label`. Esto puede causar comportamiento indefinido porque si el control salta directamente a un `case`, se puede saltar la inicialización de la variable.

## 2. De haber algún problema ¿Podrías decir la línea en la que se encuentra?

Sí, hay un problema en la línea 9 del código original.

La declaración `int i = 4;` y la llamada `f(i);` están dentro del bloque `switch` pero antes del primer `case label`. Esto viola la regla **DCL41-C: Do not declare variables inside a switch statement before the first case label** del estándar SEI CERT C.

El problema es que si el flujo de control salta directamente a un `case` (por ejemplo, cuando `expr = 0`), el compilador puede omitir la inicialización de la variable durante optimizaciones, resultando en comportamiento indefinido. Además, la llamada a `f(i)` nunca se ejecutará si el control salta directamente a un `case label`.

## 3. Crea un fichero con un main y ejecuta el segmento de código.

Se ha creado el archivo `original_main.c` que incluye una implementación de prueba. El código original puede compilarse pero mostrará comportamiento indefinido o inesperado dependiendo del compilador y las optimizaciones aplicadas.

## 4. Propón una solución al ejemplo que cumpla con las normas del CMU SEI CERT C

Como se ha mencionado en el apartado 2, el código original incumple la regla **DCL41-C: Do not declare variables inside a switch statement before the first case label** del estándar SEI CERT C.

La solución conforme al estándar SEI CERT C consiste en mover la declaración de la variable `i` antes del bloque `switch`. De esta manera, la variable se declara e inicializa antes de entrar al bloque `switch`, garantizando que siempre esté inicializada independientemente del flujo de control y evitando el comportamiento indefinido.

**Código corregido disponible en:** `answer.c`

## 5. Realiza un análisis estático del código erróneo y copia en tu solución el resultado. Utiliza las herramientas:

Para realizar el análisis estático, ejecuta los siguientes comandos y copia los resultados obtenidos:

### (a) rats

```bash
rats original_main.c
```

Resultado:
```
Prácticas/ej_2_3$ rats original_main.c
Entries in perl database: 33
Entries in ruby database: 46
Entries in python database: 62
Entries in c database: 334
Entries in php database: 55
Analyzing original_main.c
Total lines analyzed: 30
Total time 0.037924 seconds
791 lines per second
```

### (b) cppcheck

```bash
cppcheck --enable=all original_main.c
```

Resultado:
```
nofile:0:0: information: Cppcheck cannot find all the include files (use --check-config for details) [missingIncludeSystem]
```

### (c) splint

```bash
splint original_main.c
```

Resultado:
```
Splint 3.1.2 --- 21 Feb 2021

/mnt/c/Users/\377\377mbito acad\377\377mico/Desktop/M\377\377ster Universitario en Investigaci\377\377n en Ciberseguridad/1C/DISE\377\377O Y PROGRAMACI\377\377N SEGURAS/Ejercicios/Pr\377\377cticas/ej_2_3/original_main.c: (in function func)
/mnt/c/Users/\377\377mbito acad\377\377mico/Desktop/M\377\377ster Universitario
    en Investigaci\377\377n en Ciberseguridad/1C/DISE\377\377O Y
    PROGRAMACI\377\377N SEGURAS/Ejercicios/Pr\377\377cticas/ej_2_3/original_main
    .c:13:10: Fall through case (no preceding break)
  Execution falls through from the previous case (use /*@fallthrough@*/ to mark
  fallthrough cases). (Use -casebreak to inhibit warning)
/mnt/c/Users/\377\377mbito acad\377\377mico/Desktop/M\377\377ster Universitario
    en Investigaci\377\377n en Ciberseguridad/1C/DISE\377\377O Y
    PROGRAMACI\377\377N SEGURAS/Ejercicios/Pr\377\377cticas/ej_2_3/original_main
    .c:15:13: Fall through case (no preceding break)
/mnt/c/Users/\377\377mbito acad\377\377mico/Desktop/M\377\377ster Universitario
    en Investigaci\377\377n en Ciberseguridad/1C/DISE\377\377O Y
    PROGRAMACI\377\377N SEGURAS/Ejercicios/Pr\377\377cticas/ej_2_3/original_main
    .c:11:19: Statement after switch is not a case: int i = 4
  The first statement after a switch is not a case. (Use -firstcase to inhibit
  warning)
/mnt/c/Users/\377\377mbito acad\377\377mico/Desktop/M\377\377ster Universitario
    en Investigaci\377\377n en Ciberseguridad/1C/DISE\377\377O Y
    PROGRAMACI\377\377N SEGURAS/Ejercicios/Pr\377\377cticas/ej_2_3/original_main
    .c:3:6: Function exported but not used outside original_main: f
  A declaration is exported, but not used outside this module. Declaration can
  use static qualifier. (Use -exportlocal to inhibit warning)
   /mnt/c/Users/\377\377mbito acad\377\377mico/Desktop/M\377\377ster
   Universitario en Investigaci\377\377n en Ciberseguridad/1C/DISE\377\377O Y
   PROGRAMACI\377\377N SEGURAS/Ejercicios/Pr\377\377cticas/ej_2_3/original_main.
   c:5:1: Definition of f
/mnt/c/Users/\377\377mbito acad\377\377mico/Desktop/M\377\377ster Universitario
    en Investigaci\377\377n en Ciberseguridad/1C/DISE\377\377O Y
    PROGRAMACI\377\377N SEGURAS/Ejercicios/Pr\377\377cticas/ej_2_3/original_main
    .c:7:6: Function exported but not used outside original_main: func
   /mnt/c/Users/\377\377mbito acad\377\377mico/Desktop/M\377\377ster
   Universitario en Investigaci\377\377n en Ciberseguridad/1C/DISE\377\377O Y
   PROGRAMACI\377\377N SEGURAS/Ejercicios/Pr\377\377cticas/ej_2_3/original_main.
   c:18:1: Definition of func

Finished checking --- 5 code warnings
```

### (d) vera++

```bash
vera++ original_main.c
```

Resultado:
```
original_main.c:1: trailing whitespace
original_main.c:1: no copyright notice found
original_main.c:2: trailing whitespace
original_main.c:3: trailing whitespace
original_main.c:4: trailing whitespace
original_main.c:5: trailing whitespace
original_main.c:5: closing curly bracket not in the same line or column
original_main.c:6: trailing whitespace
original_main.c:7: trailing whitespace
original_main.c:8: trailing whitespace
original_main.c:9: trailing whitespace
original_main.c:10: trailing whitespace
original_main.c:11: trailing whitespace
original_main.c:12: trailing whitespace
original_main.c:13: trailing whitespace
original_main.c:14: trailing whitespace
original_main.c:15: trailing whitespace
original_main.c:16: trailing whitespace
original_main.c:17: trailing whitespace
original_main.c:18: trailing whitespace
original_main.c:19: trailing whitespace
original_main.c:20: trailing whitespace
original_main.c:21: trailing whitespace
original_main.c:22: trailing whitespace
original_main.c:23: trailing whitespace
original_main.c:24: trailing whitespace
original_main.c:25: trailing whitespace
original_main.c:26: trailing whitespace
original_main.c:27: trailing whitespace
original_main.c:28: trailing whitespace
original_main.c:28: closing curly bracket not in the same line or column
original_main.c:29: trailing whitespace
original_main.c:29: trailing empty line(s)
```

### (e) valgrind

```bash
# Compilar con símbolos de depuración
gcc -g -o test_original original_main.c
valgrind --leak-check=full ./test_original
```

Resultado:
```
==202491== Memcheck, a memory error detector
==202491== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==202491== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==202491== Command: ./test_original
==202491==
Llamando func(0):
17

Llamando func(1):
==202491== Conditional jump or move depends on uninitialised value(s)
==202491==    at 0x48DBAD6: __vfprintf_internal (vfprintf-internal.c:1516)
==202491==    by 0x48C579E: printf (printf.c:33)
==202491==    by 0x1091C8: func (original_main.c:16)
==202491==    by 0x109205: main (original_main.c:25)
==202491==
==202491== Use of uninitialised value of size 8
==202491==    at 0x48BF2EB: _itoa_word (_itoa.c:177)
==202491==    by 0x48DAABD: __vfprintf_internal (vfprintf-internal.c:1516)
==202491==    by 0x48C579E: printf (printf.c:33)
==202491==    by 0x1091C8: func (original_main.c:16)
==202491==    by 0x109205: main (original_main.c:25)
==202491==
==202491== Conditional jump or move depends on uninitialised value(s)
==202491==    at 0x48BF2FC: _itoa_word (_itoa.c:177)
==202491==    by 0x48DAABD: __vfprintf_internal (vfprintf-internal.c:1516)
==202491==    by 0x48C579E: printf (printf.c:33)
==202491==    by 0x1091C8: func (original_main.c:16)
==202491==    by 0x109205: main (original_main.c:25)
==202491==
==202491== Conditional jump or move depends on uninitialised value(s)
==202491==    at 0x48DB5C3: __vfprintf_internal (vfprintf-internal.c:1516)
==202491==    by 0x48C579E: printf (printf.c:33)
==202491==    by 0x1091C8: func (original_main.c:16)
==202491==    by 0x109205: main (original_main.c:25)
==202491==
==202491== Conditional jump or move depends on uninitialised value(s)
==202491==    at 0x48DAC05: __vfprintf_internal (vfprintf-internal.c:1516)
==202491==    by 0x48C579E: printf (printf.c:33)
==202491==    by 0x1091C8: func (original_main.c:16)
==202491==    by 0x109205: main (original_main.c:25)
==202491==
0
==202491== 
==202491== HEAP SUMMARY:
==202491==     in use at exit: 0 bytes in 0 blocks
==202491==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==202491==
==202491== All heap blocks were freed -- no leaks are possible
==202491==
==202491== Use --track-origins=yes to see where uninitialised values come from
==202491== For lists of detected and suppressed errors, rerun with: -s
==202491== ERROR SUMMARY: 5 errors from 5 contexts (suppressed: 0 from 0)
```



De los resultados del análisis estático anteriores, podemos decir que **Splint** fue la única herramienta que detectó directamente la violación de **DCL41-C**, mostrando el siguiente *warning*:

> *"Statement after switch is not a case: int i = 4"*

**Valgrind** confirmó en tiempo de ejecución que esta violación provoca **comportamiento indefinido**.  Detectó **5 errores** relacionados con valores no inicializados, lo que confirma el comportamiento indefinido causado por la violación de **DCL41-C**.

Respecto al resto de herramienta:
- **RATS**: No detectó el problema **DCL41-C**.  
- **Cppcheck**: No detectó el problema **DCL41-C**, solo mostró un aviso informativo sobre archivos de *include*.  
- **Vera++**: Solo detectó problemas de estilo (espacios en blanco finales, formato), no el problema de seguridad.

Esto demuestra la importancia de **utilizar múltiples herramientas de análisis** para obtener una evaluación más completa del código.


