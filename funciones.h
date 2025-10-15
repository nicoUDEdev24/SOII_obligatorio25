#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include "buffer_circular.h"

void productor(Buffer &b, Producto nuevo);
void consumidor(Buffer &b);

#endif // FUNCIONES_H_INCLUDED
