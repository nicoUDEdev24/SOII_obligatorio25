#include "producto.h"

// Constructor por defecto
Producto::Producto() {};

// Destructor
Producto::~Producto() {};

// Constructor parametrizado
Producto::Producto(int cod, String nom, float p)
{
    codigo_producto = cod;
    nombre_producto = nom;
    precio_producto = p;
}

// Constructor copia
Producto::Producto(const Producto &otro)
{
    codigo_producto = otro.codigo_producto;
    nombre_producto = otro.nombre_producto;
    precio_producto = otro.precio_producto;
}

// Getters //
int Producto::get_codigo()
{
    return this->codigo_producto;
}

String Producto::get_nombre()
{
    return this->nombre_producto;
}

float Producto::get_precio()
{
    return this->precio_producto;
}

// Setters //
void Producto::set_codigo(int nuevo)
{
    codigo_producto = nuevo;
}

void Producto::set_nombre(String nuevo)
{
    nombre_producto = nuevo;
}

void Producto::set_precio(float nuevo)
{
    precio_producto = nuevo;
}
