#ifndef BUFFER_CIRCULAR_H_INCLUDED
#define BUFFER_CIRCULAR_H_INCLUDED
#include "producto.h"
#include <stdio.h>
#include <mutex>              // biblioteca para poder manejar exclusion mutua
#include <condition_variable> // biblioteca para poder manejar condiciones
#include <iostream>

const int N = 5;

class Buffer
{
private:
    Producto buffer[N];
    int in, out, count_b;
    std::mutex mtx;                       // Sem�foro binario para garantizar exclusi�n mutua
    std::condition_variable full_buffer;  // condici�n: buffer lleno (sem�foro contador)
    std::condition_variable empty_buffer; // condici�n: buffer vac�o (sem�foro contador)
public:
    // Constructor por defecto
    Buffer();
    // Destructor
    ~Buffer();
    // Procedimientos del buffer //
    Producto extraer_producto();      // extraer un producto del buffer circular
    void insertar_producto(Producto); // insertar un producto en el buffer circular
};

#endif // BUFFER_CIRCULAR_H_INCLUDED
