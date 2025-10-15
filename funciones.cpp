#include "funciones.h"

void productor(Buffer &b, Producto nuevo, int delay_ms)
{
    if (delay_ms > 0)
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));

    b.insertar_producto(nuevo);
    printf("Producto insertado al buffer!\nCodigo: %d\nPrecio: $%.2f\n\n",
           nuevo.get_codigo(), nuevo.get_precio());
}

void consumidor(Buffer &b, int delay_ms)
{
    if (delay_ms > 0)
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));

    Producto p = b.extraer_producto();
    printf("Se extrajo el producto Cod: %d\n\n", p.get_codigo());
}
