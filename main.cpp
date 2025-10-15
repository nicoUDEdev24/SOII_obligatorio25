#include <iostream>
#include <thread>
#include "funciones.h"
#include "buffer_circular.h"

int main()
{
    // Instanciaci�n de los productos
    String n1("Manzana");
    String n2("Pera");
    String n3("Naranja");
    String n4("Banana");
    String n5("Kiwi");

    Producto p1(101, n1, 10.50);
    Producto p2(102, n2, 12.00);
    Producto p3(103, n3, 8.75);
    Producto p4(104, n4, 7.35);
    Producto p5(105, n5, 15.00);

    // Instanciaci�n del buffer
    Buffer buffer_circular;

    // Lanzamos hilos productores
    std::thread t_prod1(productor, std::ref(buffer_circular), p1);
    std::thread t_prod2(productor, std::ref(buffer_circular), p2);
    std::thread t_prod3(productor, std::ref(buffer_circular), p3);
    std::thread t_prod4(productor, std::ref(buffer_circular), p4);
    std::thread t_prod5(productor, std::ref(buffer_circular), p5);

    // Lanzamos hilos consumidores
    std::thread t_cons1(consumidor, std::ref(buffer_circular));
    std::thread t_cons2(consumidor, std::ref(buffer_circular));
    std::thread t_cons3(consumidor, std::ref(buffer_circular));
    std::thread t_cons4(consumidor, std::ref(buffer_circular));
    std::thread t_cons5(consumidor, std::ref(buffer_circular));

    // Esperamos a que terminen todos los hilos //
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

    return 0;
}
