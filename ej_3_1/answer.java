import java.util.*;

/*
 * CÓDIGO CORREGIDO - DCL02-J: Do not modify the collection's elements during an enhanced for statement
 * Ver README.md para explicaciones detalladas
 */

public class answer {
    public static void main(String[] args) {
        // Crear una lista mutable (ArrayList en lugar de Arrays.asList que es inmutable)
        List<Integer> list = new ArrayList<>(Arrays.asList(13, 14, 15));
        boolean first = true;

        System.out.println("Processing list ... ");

        // Solución: Usar un iterador tradicional o bucle for con índice
        // Usar ListIterator para modificar elementos
        ListIterator<Integer> iterator = list.listIterator();
        while (iterator.hasNext()) {
            Integer i = iterator.next();
            if (first) {
                first = false;
                // Usar set() para modificar el elemento en la lista
                iterator.set(99);
                i = 99; // Actualizar también la variable local para mostrar el valor correcto
            }
            System.out.println(" New item: " + i);
        }

        System.out.println("Modified list?");

        for (Integer i: list) {
            System.out.println("List item: " + i);
        }
    }
}

