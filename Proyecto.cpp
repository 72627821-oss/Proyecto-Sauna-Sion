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

    cout << "Ingrese servicio solicitado(Basico/Sauna/Vip): ";
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

// Buscar cliente
void buscarCliente() {

    int idBuscar;
    bool encontrado = false;

    cout << "\nIngrese ID del cliente: ";
    cin >> idBuscar;

    Cliente* aux = lista;

    while(aux != NULL) {

        if(aux->id == idBuscar) {

            cout << "\nCliente encontrado\n";
            cout << "Nombre: " << aux->nombre << endl;
            cout << "Servicio: " << aux->servicio << endl;
            cout << "Prioridad: " << aux->prioridad << endl;

            encontrado = true;
        }

        aux = aux->siguiente;
    }

    if(!encontrado) {
        cout << "Cliente no encontrado.\n";
    }
}

// Eliminar cliente
void eliminarCliente() {

    int idEliminar;

    cout << "\nIngrese ID del cliente a eliminar: ";
    cin >> idEliminar;

    Cliente* aux = lista;
    Cliente* anterior = NULL;

    while(aux != NULL && aux->id != idEliminar) {

        anterior = aux;
        aux = aux->siguiente;
    }

    if(aux == NULL) {

        cout << "Cliente no encontrado.\n";
        return;
    }

    if(anterior == NULL) {

        lista = aux->siguiente;

    } else {

        anterior->siguiente = aux->siguiente;
    }

    delete aux;

    cout << "Cliente eliminado correctamente.\n";
}
/*==========================
        COLA
   ATENCION DE CLIENTES
===========================*/

struct NodoCola {

    string nombre;
    NodoCola* siguiente;
};

NodoCola* frente = NULL;
NodoCola* finCola = NULL;

// Encolar cliente
void ingresarCola() {

    NodoCola* nuevo = new NodoCola();

    cin.ignore();

    cout << "\nIngrese nombre del cliente: ";
    getline(cin, nuevo->nombre);

    nuevo->siguiente = NULL;

    if(frente == NULL) {

        frente = nuevo;
        finCola = nuevo;

    } else {

        finCola->siguiente = nuevo;
        finCola = nuevo;
    }

    cout << "Cliente agregado a la cola.\n";
}
// Atender cliente
void atenderCliente() {

    if(frente == NULL) {

        cout << "\nNo hay clientes en espera.\n";
        return;
    }

    NodoCola* aux = frente;

    cout << "\nAtendiendo a: " << aux->nombre << endl;

    frente = frente->siguiente;

    delete aux;
}

int main() {

    int opcion;

    do {

        cout << "\n========== SAUNA SION DE SOL DE ORO ==========\n";
        cout << "1. Registrar cliente\n";
        cout << "2. Mostrar clientes\n";
        cout << "3. Buscar cliente\n";
        cout << "4. Eliminar cliente\n";
        cout << "5. Ingresar cliente a cola\n";
        cout << "6. Atender cliente\n";
        cout << "7. Salir\n"<<endl;
       
       

        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                registrarCliente();
                break;

            case 2:
                mostrarClientes();
                break;

            case 3:
                buscarCliente();
                break;

            case 4:
                eliminarCliente();
                break;

            case 5:
                ingresarCola();
                break;

            case 6:
                atenderCliente();
                break;

        

            case 7:
                cout << "\nSaliendo del sistema...\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while(opcion != 0);

    return 0;
}
