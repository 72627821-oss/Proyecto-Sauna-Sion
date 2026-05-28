#include <iostream>
#include <string>

using namespace std;

/*==========================
   LISTA ENLAZADA
   REGISTRO DE CLIENTES
===========================*/

struct Cliente {
    int id;
    string nombre;
    string servicio;
    int prioridad;
    Cliente* siguiente;
};

Cliente* lista = NULL;

// Registrar cliente
void registrarCliente() {

    Cliente* nuevo = new Cliente();

    cout << "\n=== REGISTRO DE CLIENTE ===\n";

    cout << "Ingrese ID: ";
    cin >> nuevo->id;

    cin.ignore();

    cout << "Ingrese nombre: ";
    getline(cin, nuevo->nombre);

    cout << "Ingrese servicio solicitado: ";
    getline(cin, nuevo->servicio);

    cout << "Ingrese prioridad (1-5): ";
    cin >> nuevo->prioridad;

    nuevo->siguiente = NULL;

    if(lista == NULL) {

        lista = nuevo;

    } else {

        Cliente* aux = lista;

        while(aux->siguiente != NULL) {
            aux = aux->siguiente;
        }

        aux->siguiente = nuevo;
    }

    cout << "Cliente registrado correctamente.\n";
}

// Mostrar clientes
void mostrarClientes() {

    Cliente* aux = lista;

    if(lista == NULL) {

        cout << "\nNo existen clientes registrados.\n";
        return;
    }

    cout << "\n=== CLIENTES REGISTRADOS ===\n";

    while(aux != NULL) {

        cout << "ID: " << aux->id << endl;
        cout << "Nombre: " << aux->nombre << endl;
        cout << "Servicio: " << aux->servicio << endl;
        cout << "Prioridad: " << aux->prioridad << endl;
        cout << "--------------------------\n";

        aux = aux->siguiente;
    }
}
