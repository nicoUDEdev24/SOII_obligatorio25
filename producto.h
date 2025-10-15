#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <stdio.h>
#include "string.h"

class Producto
{
private:
    // Atributos //
    int codigo_producto;
    String nombre_producto;
    float precio_producto;

public:
    // Constructor por defecto
    Producto();
    // Constructor parametrizado
    Producto(int, String, float);
    // Constructor copia
    Producto(const Producto &);
    // Destructor
    ~Producto();
    // Getters //
    int get_codigo();
    String get_nombre();
    float get_precio();
    // Setters //
    void set_codigo(int);
    void set_nombre(String);
    void set_precio(float);
};

#endif // PRODUCTO_H_INCLUDED
