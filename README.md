# Ejercicios de Diseño y Programación Seguras

Ejercicios prácticos de análisis y evaluación de código seguro en C, Java y Python, basados en los estándares SEI CERT. Cada ejercicio incluye código problemático, solución corregida y documentación detallada.


```
Prácticas/
├── ej_2_1/   # Punteros a variables locales (C)
├── ej_2_2/   # Arrays flexibles en estructuras (C)
├── ej_2_3/   # Declaraciones en switch (C)
├── ej_3_1/   # Modificación de colecciones durante iteración (Java)
├── ej_4/     # Anotaciones de tipos (Python)
├── ej_5_1/   # Análisis de rendimiento y optimización (C)
└── README.md
```

## Ejercicios de C

Basados en el SEI CERT C Coding Standard, enfocados en declaraciones e inicialización:

- **Ejercicio 2.1**: Retorno de punteros a variables locales. Analiza el comportamiento indefinido y vulnerabilidades de memoria cuando se retornan punteros a variables de almacenamiento automático.

- **Ejercicio 2.2**: Uso incorrecto de arrays flexibles en estructuras. Examina las restricciones del estándar C y problemas de alineación de memoria.

- **Ejercicio 2.3**: Declaración de variables en sentencias switch. Ilustra problemas de ámbito e inicialización incorrecta por saltos en el flujo de control.

- **Ejercicio 5.1**: Análisis de rendimiento, profiling y desensamblado. Explora técnicas de optimización y el impacto de las decisiones de programación en rendimiento y seguridad.

## Ejercicio de Java

Basado en el SEI CERT Oracle Coding Standard for Java:

- **Ejercicio 3.1**: Modificación de colecciones durante iteración con bucles for mejorados. Presenta alternativas seguras usando iteradores explícitos o colecciones auxiliares.

## Ejercicio de Python

Basado en Python Enhancement Proposals (PEPs):

- **Ejercicio 4**: Anotaciones de tipos con verificación estática mediante `mypy`. Cubre tipos genéricos con `TypeVar`, expresiones lambda y buenas prácticas para código robusto y mantenible.