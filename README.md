Problema: Buffer Circular (Productor – Consumidor)

1. Descripción:
El problema del buffer circular, también llamado problema productor-consumidor, es un caso clásico en sistemas operativos y programación concurrente. 
La programación concurrente se refiere a la técnica de diseñar programas en los que varios procesos o hilos pueden ejecutarse a la misma vez, compartiendo recursos e información, lo que requiere mecanismos de sincronización para evitar conflictos y garantizar la correcta ejecución.

2. Funcionamiento del programa:
El programa implementa un sistema concurrente de productores y consumidores utilizando hilos con “std::thread” de la biblioteca <thread>.
El programa crea cinco productos, cada uno con su respectivo código, nombre y precio. A continuación, se instancia un buffer circular que actúa como un espacio de almacenamiento temporal para dichos productos.
Luego, se generan hilos productores encargados de insertar productos en el buffer con distintos tiempos de espera (“delay”), e hilos consumidores que extraen productos, también con diferentes “delays” temporales a modo de efectuar pruebas de rendimiento dentro del programa.
Cada hilo, tanto productor como consumidor, ejecuta su función de manera concurrente, lo que permite que múltiples operaciones ocurran en paralelo.
El programa principal (“main”) utiliza el método “join()” para esperar a que todos los hilos finalicen su ejecución, asegurando que el proceso no termine hasta que todas las inserciones y extracciones hayan concluido.
En conjunto, el programa simula un escenario clásico de producción y consumo en paralelo, donde los productores generan datos y los consumidores los procesan.

3. Estructuras de datos y mecanismos de sincronización:
El programa utiliza diversas estructuras de datos y mecanismos de sincronización para gestionar correctamente la interacción entre los hilos productores y consumidores.

- Clase Producto: representa cada elemento del sistema y contiene tres atributos principales: un código (identificador numérico), un nombre (instancia de la clase “String”) y un precio.
- Buffer Circular: contenedor intermedio para almacenar un número limitado de productos. Opera bajo la política FIFO (First In, First Out). Su estructura permite manejar los elementos de forma circular, reiniciando los índices una vez alcanzado el final del arreglo, optimizando el uso del espacio disponible.

Mecanismos de sincronización:
- Mutex (std::mutex): protege las operaciones de inserción y extracción, garantizando que solo un hilo acceda al recurso compartido a la vez.
- Variables de condición (std::condition_variable): coordinan la ejecución entre productores y consumidores, notificando a los hilos cuando hay productos disponibles o espacio libre, evitando la espera activa innecesaria.

4. Análisis de sincronización y prevención de condiciones de carrera:
Las condiciones de carrera ocurren cuando varios hilos acceden simultáneamente a un mismo recurso compartido sin sincronización adecuada, lo que puede producir resultados inconsistentes o errores de memoria.

Este programa las evita mediante:
- Protección del buffer con “mutex”, impidiendo modificaciones simultáneas.
- Uso de “condition_variable” para que los consumidores esperen cuando el buffer está vacío y los productores cuando está lleno.
- Simulación de “delays” para representar ritmos distintos de producción y consumo.
- Método “join()” que asegura que el hilo principal espere la finalización de todos los hilos antes de cerrar el programa.

En conjunto, estos mecanismos garantizan la sincronización y coherencia de los datos, previniendo conflictos y condiciones de carrera en un entorno concurrente.
