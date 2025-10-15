#include "buffer_circular.h"

// Constructor por defecto
Buffer::Buffer() : in(0), out(0), count_b(0) {}

// Destructor
Buffer::~Buffer() {}

// Extraer producto del Buffer
Producto Buffer::extraer_producto()
{
    std::unique_lock<std::mutex> lock(mtx);
    while (count_b == 0)
    {
        full_buffer.wait(lock);
    }
    Producto p = buffer[out];
    out = (out + 1) % N;
    count_b--;
    empty_buffer.notify_one();
    return p;
}

// Insertar producto al Buffer
void Buffer::insertar_producto(Producto nuevo_p)
{
    std::unique_lock<std::mutex> lock(mtx);
    while (count_b == N)
    {
        empty_buffer.wait(lock);
    }
    buffer[in] = nuevo_p;
    in = (in + 1) % N;
    count_b++;
    full_buffer.notify_one();
}
