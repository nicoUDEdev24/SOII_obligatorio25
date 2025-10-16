#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include "buffer_circular.h"
#include <thread>
#include <chrono>

// Funciones productor - consumidor //
void productor(Buffer &b, Producto nuevo, int delay_ms);
void consumidor(Buffer &b, int delay_ms);

#endif // FUNCIONES_H_INCLUDED
