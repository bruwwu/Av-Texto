// Inventario.h
#pragma once

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Commons.h"
#include <vector>



class Inventario {
public:
    Inventario();
    ~Inventario();

    bool agregarObjeto(const string& objeto);
    void eliminarObjeto(const std::string& objeto);
    bool tieneEspacio() const;
    bool tieneObjeto(const string& objeto) const;
    int contarObjeto(const string& objeto) const;
    bool tieneLlave() const;



  

    const vector<string>& getObjetos() const;

private:
    vector<string> objetos;
    static const int capacidadMaxima = 3;

};

#endif // INVENTARIO_H
