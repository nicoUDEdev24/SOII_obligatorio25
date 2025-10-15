#include "String.h"

// Constructor por defecto
String::String()
{
    cadena = new char[1];
    cadena[0] = '\0';
}

// Constructor desde un C-string
String::String(const char *cad)
{
    int largo = std::strlen(cad);
    cadena = new char[largo + 1];
    std::strcpy(cadena, cad);
}

// Constructor copia
String::String(const String &otro)
{
    int largo = std::strlen(otro.cadena);
    cadena = new char[largo + 1];
    std::strcpy(cadena, otro.cadena);
}

// Destructor
String::~String()
{
    delete[] cadena;
}

// Operador de asignaci�n
String &String::operator=(const String &otro)
{
    if (this != &otro)
    {
        delete[] cadena;
        int largo = std::strlen(otro.cadena);
        cadena = new char[largo + 1];
        std::strcpy(cadena, otro.cadena);
    }
    return *this;
}
