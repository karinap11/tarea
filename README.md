# tarea
Realizar un programa que pida al usuario dos polinomios y muestre como resultados su suma y su producto.
Se debe utilizar una estructura tipo lista, donde cada elemento sea una tupla del tipo (grado,coeficiente).
El almacenamiento de los términos en la lista debe hacerse de manera decreciente por grado.
Se deben programar los procedimientos o funciones que realicen cada operación, así como las correspondientes para ingresar el polinomio (desde el teclado o desde un archivo) y para imprimirlo en pantalla.
Hacer una prueba con un par de polinomios cualesquiera.
# se usan las sig paqueterias

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
```
# variables
definimos las variables que usaremos
```cpp
typedef vector<pair<int, double>> Polinomio;
```

# Funciónes
 Función para ingresar un polinomio desde el teclado
```cpp
Polinomio ingresarPolinomio() {
    Polinomio polinomio;
    int grado;
    double coeficiente;

    cout << "Ingrese los términos del polinomio (grado coeficiente). Ingrese un grado negativo para terminar:\n";
    while (true) {
        cout << "Grado: ";
        cin >> grado;
        if (grado < 0) break;  // Condición de salida

        cout << "Coeficiente: ";
        cin >> coeficiente;

        polinomio.push_back({grado, coeficiente});
    }
```
     Ordenar por grado de manera descendente
```cpp
 sort(polinomio.begin(), polinomio.end(), [](auto &a, auto &b) {
        return a.first > b.first;
    });

    return polinomio;
}
```
Función para imprimir un polinomio en pantalla
```cpp
void imprimirPolinomio(const Polinomio &polinomio) {
    if (polinomio.empty()) {
        cout << "0\n";
        return;
    }

    cout << "Polinomio: ";
    for (size_t i = 0; i < polinomio.size(); ++i) {
        int grado = polinomio[i].first;
        double coeficiente = polinomio[i].second;

        if (i > 0 && coeficiente >= 0) cout << " + ";
        cout << coeficiente << "x^" << grado;
    }
    cout << endl;
}
```cpp
Función para sumar dos polinomios
```
Polinomio sumarPolinomios(const Polinomio &p1, const Polinomio &p2) {
    map<int, double> coeficientes;

    for (auto &termino : p1) coeficientes[termino.first] += termino.second;
    for (auto &termino : p2) coeficientes[termino.first] += termino.second;

    Polinomio resultado;
    for (auto &[grado, coeficiente] : coeficientes) {
        if (coeficiente != 0) resultado.push_back({grado, coeficiente});
    }
```
 Ordenar de forma decreciente
```cpp
 sort(resultado.begin(), resultado.end(), [](auto &a, auto &b) {
        return a.first > b.first;
    });

    return resultado;
```

     
