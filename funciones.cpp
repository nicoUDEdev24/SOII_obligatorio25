#include "funciones.h"
#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"

void productor(Buffer &b, Producto nuevo, int delay_ms)
{
    if (delay_ms > 0)
    // Cuando el contador sea positivo comienza con la operacion de insertar el producto en el buffer,
    // mientras tanto el "sleep_for" suspende el hilo por el tiempo estimado en el delay_ms
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    printf("====================================\n");
    printf(GREEN "=> Producto insertado en el buffer!\n" RESET);
    printf("Codigo: %d\n", nuevo.get_codigo());
    printf("Nombre: ");
    nuevo.get_nombre().mostrar_string();
    printf("\n");
    printf("Precio: $%.2f\n", nuevo.get_precio());
    printf("====================================\n\n");
    // Se inserta el nuevo producto en el buffer circular
    b.insertar_producto(nuevo);
}

void consumidor(Buffer &b, int delay_ms)
{
    if (delay_ms > 0)
    // Cuando el contador sea positivo comienza la operacion de extraer el producto del buffer circular
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    // Se extrae el producto del buffer circular
    Producto p = b.extraer_producto();
    printf("====================================\n");
    printf(RED "<= Se extrajo el producto Cod: %d\n" RESET, p.get_codigo());
    printf("====================================\n\n");
}
