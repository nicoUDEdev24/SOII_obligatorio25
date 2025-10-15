#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <cstring>
#include <cstdio>

class String
{
private:
    char *cadena;

public:
    // Constructor por defecto
    String();
    // Destructor
    ~String();
    // Constructor de copia
    String(const String &);
    // Sobrecarga del operador de asignaci�n
    String &operator=(const String &);
    // Constructor desde un C-string
    String(const char *);
};

#endif // STRING_H_INCLUDED
