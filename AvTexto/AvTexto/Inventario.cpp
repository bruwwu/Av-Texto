#include "Commons.h"

// Resto del código de Inventario.h

// Constructor
Inventario::Inventario() {
    // Inicialización si es necesario
}

// Destructor
Inventario::~Inventario() {
    // Liberación de recursos si es necesario
}

// Agregar objeto de tipo string al inventario
bool Inventario::agregarObjeto(const string& objeto) {
    if (objeto == "Huachicoltsen") {
        if (!tieneEspacio()) {
            return false;
        }
    }

    if (objetos.size() < capacidadMaxima) {
        objetos.push_back(objeto);
        return true;
    }
    else {
        return false;
    }
}

// Eliminar objeto de tipo string del inventario
void Inventario::eliminarObjeto(const std::string& objeto) {
    objetos.erase(std::remove(objetos.begin(), objetos.end(), objeto), objetos.end());
}

// Verificar si hay espacio en el inventario
bool Inventario::tieneEspacio() const {
    return objetos.size() < capacidadMaxima;
}

// Verificar si el inventario contiene un objeto específico de tipo string
bool Inventario::tieneObjeto(const string& objeto) const {
    auto it = find(objetos.begin(), objetos.end(), objeto);
    return it != objetos.end();
}

// Contar la cantidad de un objeto específico de tipo string en el inventario
int Inventario::contarObjeto(const string& objeto) const {
    int contador = 0;
    for (const auto& obj : objetos) {
        if (obj == objeto) {
            contador++;
        }
    }
    return contador;
}

// Verificar si el inventario contiene la llave
bool Inventario::tieneLlave() const {
    return tieneObjeto("Llave");
}

// Obtener la lista de objetos de tipo string en el inventario
const vector<string>& Inventario::getObjetos() const {
    return objetos;
}

