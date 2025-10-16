#include "buffer_circular.h"

// Constructor por defecto
Buffer::Buffer() : in(0), out(0), count_b(0) {}

// Destructor
Buffer::~Buffer() {}

// Extraer producto del Buffer
Producto Buffer::extraer_producto()
{
    // Se crea un bloqueo exclusivo utilizando un mutex, garantizando la exclusión mutua
    // para que solo el productor o el consumidor puedan acceder al buffer a la vez.
    // El mutex se libera automáticamente cuando finaliza la operación gracias a unique_lock.
    std::unique_lock<std::mutex> lock(mtx);
    while (count_b == 0)
    {
        // Si el buffer está vacío, el consumidor no puede extraer ningún producto.
        // El hilo queda bloqueado hasta que el productor inserte un nuevo elemento.
        full_buffer.wait(lock);
    }
    // --- INICIO DE SECCIÓN CRÍTICA ---
    // Se obtiene el producto ubicado en el índice "out",
    // el cual indica la posición del siguiente producto a extraer del buffer.
    Producto p = buffer[out];
    // Se avanza el índice de salida de forma circular.
    out = (out + 1) % N;
    // Se decrementa la cantidad de productos almacenados en el buffer.
    count_b--;
    // --- FIN DE SECCIÓN CRÍTICA ---
    // Se notifica al hilo productor que ahora hay espacio disponible para insertar nuevos productos.
    empty_buffer.notify_one();
    // Se devuelve el producto extraído.
    return p;
}


// Inserta un producto en el buffer
void Buffer::insertar_producto(Producto nuevo_p)
{
    // Se crea un bloqueo exclusivo utilizando un mutex, garantizando la exclusión mutua
    // para que solo el productor o el consumidor puedan acceder al buffer al mismo tiempo.
    // El mutex se libera automáticamente al finalizar la operación gracias a unique_lock.
    std::unique_lock<std::mutex> lock(mtx);
    while (count_b == N)
    {
        // Si el buffer está lleno, el productor no puede insertar un nuevo producto.
        // El hilo queda bloqueado hasta que el consumidor extraiga un elemento.
        empty_buffer.wait(lock);
    }
    // --- INICIO DE SECCIÓN CRÍTICA ---
    // Se inserta el nuevo producto en la posición indicada por el índice "in".
    buffer[in] = nuevo_p;
    // Se avanza el índice de entrada de forma circular.
    in = (in + 1) % N;
    // Se incrementa el contador de productos almacenados en el buffer.
    count_b++;
    // --- FIN DE SECCIÓN CRÍTICA ---
    // Se notifica al hilo consumidor que ahora hay un nuevo producto disponible para extraer.
    full_buffer.notify_one();
}

