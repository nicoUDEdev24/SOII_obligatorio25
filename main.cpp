#include <stdio.h>
#include <thread>
#include "funciones.h"

int main()
{
    printf("========================================");
    printf("\n");
    printf("BUFFER CIRCULAR (PRODUCTOR-CONSUMIDOR):");
    printf("\n");
    printf("========================================");
    printf("\n\n");
    String n1("Manzana"), n2("Pera"), n3("Naranja"), n4("Banana"), n5("Kiwi");
    // Creación de productos con código y precio
    Producto p1(101, n1, 10.50);
    Producto p2(102, n2, 12.00);
    Producto p3(103, n3, 8.75);
    Producto p4(104, n4, 7.35);
    Producto p5(105, n5, 15.00);

    // Instanciación del buffer circular
    Buffer buffer_circular;

    // Creación de hilos productores
    // Cada hilo llama a la función 'productor' que inserta un producto en el buffer
    std::thread t_prod1(productor, std::ref(buffer_circular), std::cref(p1), 100);
    std::thread t_prod2(productor, std::ref(buffer_circular), std::cref(p2), 200);
    std::thread t_prod3(productor, std::ref(buffer_circular), std::cref(p3), 50);
    std::thread t_prod4(productor, std::ref(buffer_circular), std::cref(p4), 300);
    std::thread t_prod5(productor, std::ref(buffer_circular), std::cref(p5), 0);

    // Creación de hilos consumidores
    // Cada hilo llama a la función 'consumidor' que extrae un producto del buffer
    std::thread t_cons1(consumidor, std::ref(buffer_circular), 150);
    std::thread t_cons2(consumidor, std::ref(buffer_circular), 100);
    std::thread t_cons3(consumidor, std::ref(buffer_circular), 250);
    std::thread t_cons4(consumidor, std::ref(buffer_circular), 50);
    std::thread t_cons5(consumidor, std::ref(buffer_circular), 0);

    // Espera a que todos los hilos terminen
    // join() bloquea el hilo principal hasta que el hilo correspondiente finalice
    t_prod1.join();
    t_prod2.join();
    t_prod3.join();
    t_prod4.join();
    t_prod5.join();

    t_cons1.join();
    t_cons2.join();
    t_cons3.join();
    t_cons4.join();
    t_cons5.join();
}
