#include "Commons.h"

using namespace std;

// Declaración de funciones
void explorarCasa(Inventario& inventario);
void caerAlAbismo();
void atravesarHabitacion(int numeroHabitacion, Inventario& inventario);
void huirDeEnemigo();
void usarHuachicoltsen(Inventario& inventario);
void eventoHabitacionSecreta(Inventario& inventario);
void nuevaHabitacionConCafe(Inventario& inventario);
void abrirHabitacionSecreta(Inventario& inventario);

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Inventario inventario;

    explorarCasa(inventario);
    return 0;
}

// Función para iniciar la exploración de la casa
void explorarCasa(Inventario& inventario) {
    cout << "Estás explorando una casa misteriosa...\n";
    caerAlAbismo();

    for (int i = 1; i <= 10; ++i) {
        atravesarHabitacion(i, inventario);
    }

    char opcion;  // Mover la declaración de 'opcion' aquí
    if (inventario.tieneLlave()) {
        cout << "Miras frente a ti y encuentras una puerta con cerradura. ¿Quieres usar la llave para abrirla? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            abrirHabitacionSecreta(inventario);
        }
    }

    cout << "Lograste escapar... por ahora.\n";
}

// Función para simular la caída al abismo
void caerAlAbismo() {
    cout << "Al estar investigando no ves por donde caminas y caes por una grieta, llegando así a un abismo.\n";
}

// Función para atravesar una habitación específica
void atravesarHabitacion(int numeroHabitacion, Inventario& inventario) {
    cout << "\n----- Habitación " << numeroHabitacion << " -----\n";
    int evento = rand() % 8;  // Ajusta el rango según sea necesario

    switch (evento) {
    case 0:
        cout << "Te encuentras con una habitación vacía.\n";
        break;
    case 1:
        cout << "Encuentras una llave, ¿quieres recogerla? (s/n): ";
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            if (inventario.agregarObjeto("Llave")) {
                
            }
        }
        else {
            cout << "Decides dejar la llave.\n";
        }
        break;
    case 2:
        cout << "¡Sientes una presencia desde las sombras! Debes escapar.\n";
        cout << "¿Correr hacia la izquierda o hacia la derecha? (i/d): ";
        cin >> opcion;
        if (opcion == 'i' || opcion == 'I') {
            cout << "Escapas hacia la izquierda.\n";
        }
        else {
            cout << "Escapas hacia la derecha.\n";
        }
        break;
    case 3:
        cout << "En la habitación, ves una figura distorsionada.\n";
        huirDeEnemigo();
        break;
    case 4:
        cout << "Encuentras un objeto tirado en la habitación. ¿Quieres recogerlo? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            if (inventario.agregarObjeto("Huachicoltsen")) {
                cout << "Has recogido el objeto: Huachicoltsen\n";
            }
        }
        else {
            cout << "Decides no tomarlo.\n";
        }
        break;
    case 5:
        cout << "Entras a una habitacion y ves una sombra en la lejanía.\n";
        cout << "Se te aparece una persona la cual te dice lo siguiente\n";
        cout << "Miko: 'Y tomorrow chaquetOn'.\n";
        cout << "Miko te ha dejado libre, puedes continuar.\n";
        break;

    case 6:
        cout << "Te encuentras en una habitación tranquila. Decides mirar alrededor.\n";
        cout << "No parece haber nada interesante. ¿Quieres tomar un descanso? (s/n): ";
        char opcionDescanso;
        cin >> opcionDescanso;
        if (opcionDescanso == 's' || opcionDescanso == 'S') {
            cout << "Decides tomar un descanso. Te sientes revitalizado y avanzas a la siguiente habitación.\n";
            return;  // Salir de la función sin realizar más acciones en esta habitación
        }
        else {
            cout << "Decides no descansar y continúas explorando.\n";
        }
        break;

    case 7:

        nuevaHabitacionConCafe(inventario);

        break;

    }

    if (inventario.tieneObjeto("Huachicoltsen")) {
        usarHuachicoltsen(inventario);
    }
}

// Función para huir de un enemigo en una habitación
void huirDeEnemigo() {
    cout << "La figura te persigue. Debes huir de la habitacion, corre.\n";
    cout << "¿Correr hacia la puerta o esconderse en un rincón? Sientes un mal presagio si vas al rincon (p/e): ";
    char opcion;
    cin >> opcion;
    if (opcion == 'p' || opcion == 'P') {
        cout << "Corres hacia la puerta y logras escapar de la habitacion.\n";
    }
    else {
        cout << "Corres al rincon pero la figura te ha encontrado.\n";
        cout << "Hasta aquí has llegado.\n";
        exit(0);
    }
}

// Función para usar el objeto Huachicoltsen en una habitación
void usarHuachicoltsen(Inventario& inventario) {
    cout << "Encuentras a la figura distorsionada en la habitacion. ¿Quieres usar Huachicoltsen? (s/n): ";
    char opcion;
    cin >> opcion;
    int cantidadHuachicoltsen = inventario.contarObjeto("Huachicoltsen");

    if (opcion == 's' || opcion == 'S') {
        if (cantidadHuachicoltsen > 0) {
            cout << "Usas Huachicoltsen contra la figura distorsionada. La figura ha sido neutralizada.\n";
            inventario.eliminarObjeto("Huachicoltsen");
        }
        else {
            cout << "No tienes mas Huachicoltsen en tu inventario.\n";
        }
    }
    else {
        cout << "Decides no usar Huachicoltsen.\n";
    }
}

void nuevaHabitacionConCafe(Inventario& inventario) {
    cout << "Miras alrededor y encuentras una taza de café.\n";
    cout << "¿Quieres tomar la taza de café? (s/n): ";
    char opcion;
    cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        cout << "Decides tomar la taza de cafe, pero tiene demasiada azucar. Escupes el cafe.\n";
    }
    else {
        cout << "Decides no tomar la taza de cafe. De repente, una sombra te la avienta y recibes 4 de dmg.\n";
        // Ajusta la lógica según sea necesario (puedes reducir la salud del jugador, por ejemplo)
    }
}

// Función para abrir la habitación secreta
void abrirHabitacionSecreta(Inventario& inventario) {
    char opcion;
    cout << "Abres la puerta y descubres una habitacion oculta.\n";

    // Agrega eventos adicionales para la habitación secreta
    for (int i = 0; i < 3; ++i) {  // Cambia el número de eventos según sea necesario
        eventoHabitacionSecreta(inventario);
    }

    // Ofrece a Teemo
    cout << "En el rincon oscuro de la habitacion, encuentras a Teemo. Te ofrece hongos para pasar un buen rato.\n";
    cout << "¿Aceptas los hongos de Teemo? (s/n): ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S') {
        cout << "Tomas los poderosos hongos de Teemo y de la nada estas fuera de la casa, gracias TeemoDeidad\n";
        exit(0);
    }
    else {
        cout << "No aceptas los hongos. Teemo se emperra y te manda al primer nivel\n";
        explorarCasa(inventario);  // Vuelve a empezar la exploración
    }
}

// Función para manejar eventos en la habitación secreta
void eventoHabitacionSecreta(Inventario& inventario) {
    int evento = rand() % 9;

    switch (evento) {
    case 0:
        cout << "Encuentras un cofre en la habitacion secreta. ¿Quieres abrirlo? (s/n): ";
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            if (inventario.agregarObjeto("ObjetoSecreto")) {
                cout << "Has recogido un objeto secreto.\n";
            }
        }
        else {
            cout << "Decides no abrir el cofre.\n";
        }
        break;
    case 1:
        cout << "Te encuentras con una extraña inscripcion en la pared. ¿La investigas? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            cout << "Descifras la inscripcion y ganas conocimiento.\n";
        }
        else {
            cout << "Decides no investigar la inscripcion.\n";
        }
        break;
    case 2:
        cout << "Sientes una corriente de aire. ¿Quieres buscar la fuente? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            cout << "Encuentras una abertura secreta. ¿Quieres explorarla? (s/n): ";
            cin >> opcion;
            if (opcion == 's' || opcion == 'S') {
                cout << "Exploras la abertura y descubres un pasadizo secreto.\n";
            }
            else {
                cout << "Decides no explorar la abertura.\n";
            }
        }
        else {
            cout << "Decides no buscar la fuente de la corriente de aire.\n";
        }
        break;
   
    
    }
}
