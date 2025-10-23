# Ejercicio 4 
## 1. ¿Qué hace el siguiente segmento de código?

```python
def greeting(name: str) -> str:
    return 'Hello' + name
```

Este código define una función con anotaciones de tipo. `name: str` indica que el parámetro es de tipo cadena, y `-> str` que retorna una cadena. La función concatena `'Hello'` con el valor de `name`.

Las anotaciones de tipo en Python son opcionales y no fuerzan el tipo en tiempo de ejecución. Sirven para documentación, autocompletado en IDEs, y verificación estática con `mypy`.

El código tiene un fallo: falta un espacio entre `'Hello'` y `name`. Debería ser `return 'Hello ' + name` o `return f'Hello {name}'`.

## 2. ¿Cuál es la diferencia entre estas dos trazas de código?

La diferencia está en el uso de alias de tipos. La Traza 1 define `Vector = Iterable[Tuple[T, T]]` y lo reutiliza como `Vector[T]` en las funciones. La Traza 2 repite `Iterable[Tuple[T, T]]` cada vez.

La Traza 1 es mejor porque si cambias la estructura del vector lo haces en un sitio. El nombre `Vector` es más legible que `Iterable[Tuple[T, T]]` y sigue el principio DRY. La Traza 2 es más verbosa y propensa a errores al tener que repetir la definición completa cada vez.

Ambas son correctas según el PEP 484, pero la Traza 1 aplica mejores prácticas.

## 3. ¿Qué hace el siguiente segmento de código? ¿Se debería declarar de alguna otra forma?

```python
f = lambda x: 2 * x
```

Define una función lambda que recibe `x` y retorna `2 * x`. Es equivalente a `def f(x): return 2 * x`.

**No debería declararse así.** El PEP 8 dice que hay que usar `def` en lugar de asignar lambdas a variables.

La forma correcta:

```python
def f(x: float) -> float:
    return 2 * x
```

Las funciones con `def` tienen nombre en los tracebacks, pueden llevar docstrings y type hints, y facilitan el debugging. Las lambdas son apropiadas cuando se usan inline: `sorted(items, key=lambda x: x.name)`.

## 4. ¿Qué son los Python Enhancement Proposals y para qué se utilizan?

Los **Python Enhancement Proposals (PEPs)** son documentos que usa la comunidad Python para proponer, discutir y documentar cambios al lenguaje. Funcionan como especificaciones técnicas de características, procesos o convenciones.

Hay tres tipos: **Standards Track** (nuevas características), **Informational** (pautas generales) y **Process** (procesos de desarrollo).

El proceso empieza con un borrador que se discute en Python-Dev. Tras revisiones, el Steering Council lo acepta o rechaza. Si se acepta, pasa a Final y se convierte en especificación oficial.

En relación con los ejemplos anteriores:
- **PEP 8 - Style Guide for Python Code** está relacionado con la pregunta 3. Establece las convenciones de estilo y dice que no se deben asignar lambdas a variables. Es el documento más importante para mantener consistencia en el código Python.
- **PEP 484 - Type Hints** está relacionado con las preguntas 1 y 2. Introdujo las anotaciones de tipo en Python 3.5, define cómo usar `typing`, `TypeVar` y los alias de tipo de la Traza 1.
- **PEP 3107 - Function Annotations** introdujo la sintaxis `param: annotation` y `-> return_annotation` en Python 3.0. El PEP 484 estandarizó su uso para tipos.
- **PEP 483 - The Theory of Type Hints** da la base teórica del sistema de tipos. Explica conceptos como covarianza y contravarianza, relevante para entender `TypeVar` de la pregunta 2.

Todos los PEPs están en https://peps.python.org/, donde el **PEP 0** es el índice