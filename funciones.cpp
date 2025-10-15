#include "funciones.h"

void productor(Buffer &b, Producto nuevo)
{
    b.insertar_producto(nuevo);
    printf("Producto insertado al buffer!\nCodigo: %d\nPrecio: $%.2f\n\n", nuevo.get_codigo(), nuevo.get_precio());
}

void consumidor(Buffer &b)
{
    Producto p = b.extraer_producto();
    printf("Se extrajo el producto Cod: %d\n\n", p.get_codigo());
}
