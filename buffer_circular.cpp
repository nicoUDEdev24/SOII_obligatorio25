#include "buffer_circular.h"

// Constructor por defecto
Buffer::Buffer() : in(0), out(0), count_b(0) {}

// Destructor
Buffer::~Buffer() {}

// Extraer producto del Buffer
Producto Buffer::extraer_producto()
{
    // Se crea un bloqueo exclusivo utilizando un mutex, garantizando la exclusi�n mutua
    // para que solo el productor o el consumidor puedan acceder al buffer a la vez.
    // El mutex se libera autom�ticamente cuando finaliza la operaci�n gracias a unique_lock.
    std::unique_lock<std::mutex> lock(mtx);
    while (count_b == 0)
    {
        // Si el buffer est� vac�o, el consumidor no puede extraer ning�n producto.
        // El hilo queda bloqueado hasta que el productor inserte un nuevo elemento.
        full_buffer.wait(lock);
    }
    // --- INICIO DE SECCI�N CR�TICA ---
    // Se obtiene el producto ubicado en el �ndice "out",
    // el cual indica la posici�n del siguiente producto a extraer del buffer.
    Producto p = buffer[out];
    // Se avanza el �ndice de salida de forma circular.
    out = (out + 1) % N;
    // Se decrementa la cantidad de productos almacenados en el buffer.
    count_b--;
    // --- FIN DE SECCI�N CR�TICA ---
    // Se notifica al hilo productor que ahora hay espacio disponible para insertar nuevos productos.
    empty_buffer.notify_one();
    // Se devuelve el producto extra�do.
    return p;
}


// Inserta un producto en el buffer
void Buffer::insertar_producto(Producto nuevo_p)
{
    // Se crea un bloqueo exclusivo utilizando un mutex, garantizando la exclusi�n mutua
    // para que solo el productor o el consumidor puedan acceder al buffer al mismo tiempo.
    // El mutex se libera autom�ticamente al finalizar la operaci�n gracias a unique_lock.
    std::unique_lock<std::mutex> lock(mtx);
    while (count_b == N)
    {
        // Si el buffer est� lleno, el productor no puede insertar un nuevo producto.
        // El hilo queda bloqueado hasta que el consumidor extraiga un elemento.
        empty_buffer.wait(lock);
    }
    // --- INICIO DE SECCI�N CR�TICA ---
    // Se inserta el nuevo producto en la posici�n indicada por el �ndice "in".
    buffer[in] = nuevo_p;
    // Se avanza el �ndice de entrada de forma circular.
    in = (in + 1) % N;
    // Se incrementa el contador de productos almacenados en el buffer.
    count_b++;
    // --- FIN DE SECCI�N CR�TICA ---
    // Se notifica al hilo consumidor que ahora hay un nuevo producto disponible para extraer.
    full_buffer.notify_one();
}

