# Prácticas de Diseño y Programación Seguras

## Descripción General

Este repositorio contiene ejercicios prácticos enfocados en el análisis y evaluación de código seguro en los lenguajes C, Java y Python. 

Los ejercicios abordan problemas de seguridad y malas prácticas de programación, proporcionando tanto código problemático como soluciones que cumplen con los estándares establecidos por el SEI CERT. Cada ejercicio incluye análisis detallados de las vulnerabilidades, herramientas de verificación utilizadas y justificaciones de las correcciones implementadas.

## Estructura del Proyecto

```
Prácticas/
├── ej_2_1/          
├── ej_2_2/          
├── ej_2_3/          
├── ej_3_1/          
├── ej_4/            
├── ej_5_1/          
└── README.md        
```

Cada directorio de ejercicio contiene los siguientes archivos:
- Código fuente original con problemas de seguridad o malas prácticas
- Solución corregida que cumple con los estándares de codificación
- Documentación respondiendo a las preugntas que se hacen en el enunciado

## Ejercicios de C

Los ejercicios en C se centran en las reglas de declaraciones e inicialización del SEI CERT C Coding Standard. Este estándar proporciona directrices para desarrollar sistemas software seguros, fiables y protegidos en lenguaje C.

**Ejercicio 2.1**: Aborda la problemática de retornar punteros a variables locales, una práctica que genera comportamiento indefinido y vulnerabilidades de memoria. El ejercicio analiza cómo el almacenamiento automático de variables locales se destruye al finalizar la función, haciendo que cualquier puntero a estas direcciones sea inválido.

**Ejercicio 2.2**: Examina el uso incorrecto de arrays flexibles en estructuras. Se analizan las restricciones del estándar C respecto a la ubicación de estos arrays y las consecuencias de violar estas reglas, incluyendo problemas de alineación de memoria y acceso a datos.

**Ejercicio 2.3**: Estudia la declaración de variables dentro de sentencias switch. El ejercicio ilustra los problemas que surgen cuando se declaran variables sin bloques de ámbito adecuados, lo que puede provocar que las variables se inicialicen incorrectamente o que el flujo de control salte sobre sus inicializaciones.

**Ejercicio 5.1**: Ejercicio avanzado que incluye análisis de rendimiento, profiling y desensamblado de código. Se exploran técnicas de optimización y se estudia cómo las decisiones de programación afectan al rendimiento y la seguridad del código generado.


## Ejercicio de Java

El ejercicio de Java se enfoca en las reglas de declaraciones del SEI CERT Oracle Coding Standard for Java, que establece prácticas de programación segura para aplicaciones empresariales y sistemas críticos.

**Ejercicio 3.1**: Analiza el problema de modificar colecciones mientras se está iterando sobre ellas utilizando bucles for mejorados. Esta práctica puede resultar en excepciones de concurrencia o comportamiento impredecible. El ejercicio presenta alternativas seguras, como el uso de iteradores explícitos con métodos de eliminación apropiados o la creación de colecciones auxiliares para las modificaciones.

## Ejercicio de Python 

El ejercicio de Python explora características del lenguaje relacionadas con el tipado estático opcional y las mejores prácticas definidas en los Python Enhancement Proposals.

**Ejercicio 4**: Cubre el uso de anotaciones de tipos en funciones y variables, permitiendo la verificación estática de tipos mediante herramientas como `mypy`. Se estudia el uso de tipos genéricos mediante `TypeVar`, el manejo apropiado de expresiones lambda, y la aplicación de PEPs relevantes para escribir código Python más robusto y mantenible. Las anotaciones de tipos mejoran la documentación del código y permiten detectar errores de tipo antes de la ejecución.