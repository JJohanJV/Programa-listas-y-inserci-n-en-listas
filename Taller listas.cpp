#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void insertarAlFinal(Nodo*& lista, int dato) {
   
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;
	
    if (!lista) {
        lista = nuevo_nodo;
    }
    else {

        Nodo* actual = lista;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = NULL;

}

void insertarAlInicio(Nodo*& lista, int dato) {
   
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;	
    Nodo* aux = lista;
    nuevo_nodo->siguiente = aux;
    lista = nuevo_nodo;

}

void insertarDespuesDe(Nodo*& lista, int dato, int valorDespuesde) {
   
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;	
    
    Nodo* actual = lista;
    
    while(actual->dato != valorDespuesde){
    	actual = actual->siguiente;
	}
    
    nuevo_nodo->siguiente = actual->siguiente;
    actual->siguiente = nuevo_nodo;

}

void insertarAntesDe(Nodo*& lista, int dato, int valorAntesde) {
   
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;	
    
    Nodo* actual = lista;
    
    while(actual->siguiente->dato != valorAntesde){
    	actual = actual->siguiente;
	}
	
    nuevo_nodo->siguiente = actual->siguiente;
    actual->siguiente = nuevo_nodo;

}

void print(Nodo*& lista, int n) {
   
    Nodo* actual = lista;
    cout << "[ ";
    for (int i = 0; i < n-1; i++) {
        actual = actual->siguiente;
    }
    cout << actual->dato;
	cout << " ]";
}

void print(Nodo*& lista) {

    Nodo* actual = lista;
    cout << "[ ";
    while (actual->siguiente) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << actual->dato;
	cout << " ]";
}



int main()
{
	srand(time(NULL));
    Nodo* lista = NULL;

    for (int i = 0; i < 6*3; i++) {
        insertarAlFinal(lista, rand() % 100);
    }
	
	cout << "Mi codigo es 2210056. La lista inicial generada es:\n\n";
    print(lista);
    
    cout << "\n\nLa lista al agregar al inicio el penultimo digito del codigo (5) * 16, es decir, el numero 80 es:\n\n";
    insertarAlInicio(lista, 5*16);
    print(lista);
    
    cout << "\n\nLa lista al agregar al final el quinto digito del codigo (0) * 8, es decir, el numero 0 es:\n\n";
    insertarAlFinal(lista, 0*8);
    print(lista);
    
    cout << "\n\nLa lista al agregar el tercer digito del codigo (1) * 40, es decir, el numero 40,  despues del nodo con valor 80 es:\n\n";
    insertarDespuesDe(lista, 40, 80);
	print(lista);
	
	cout << "\n\nLa lista al agregar el cuarto digito del codigo (0) * 3, es decir, el numero 0,  antes del nodo con valor 0 es:\n\n";
    insertarAntesDe(lista, 0, 0);
	print(lista);
	
}

