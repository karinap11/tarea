#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef vector<pair<int, double>> Polinomio;

// Función para ingresar un polinomio desde el teclado
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

    // Ordenar por grado de manera descendente
    sort(polinomio.begin(), polinomio.end(), [](auto &a, auto &b) {
        return a.first > b.first;
    });

    return polinomio;
}

// Función para imprimir un polinomio en pantalla
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

// Función para sumar dos polinomios
Polinomio sumarPolinomios(const Polinomio &p1, const Polinomio &p2) {
    map<int, double> coeficientes;

    for (auto &termino : p1) coeficientes[termino.first] += termino.second;
    for (auto &termino : p2) coeficientes[termino.first] += termino.second;

    Polinomio resultado;
    for (auto &[grado, coeficiente] : coeficientes) {
        if (coeficiente != 0) resultado.push_back({grado, coeficiente});
    }

    // Ordenar de forma decreciente
    sort(resultado.begin(), resultado.end(), [](auto &a, auto &b) {
        return a.first > b.first;
    });

    return resultado;
}

// Función para multiplicar dos polinomios
Polinomio multiplicarPolinomios(const Polinomio &p1, const Polinomio &p2) {
    map<int, double> coeficientes;

    for (auto &t1 : p1) {
        for (auto &t2 : p2) {
            int nuevoGrado = t1.first + t2.first;
            double nuevoCoef = t1.second * t2.second;
            coeficientes[nuevoGrado] += nuevoCoef;
        }
    }

    Polinomio resultado;
    for (auto &[grado, coeficiente] : coeficientes) {
        if (coeficiente != 0) resultado.push_back({grado, coeficiente});
    }

    // Ordenar de forma decreciente
    sort(resultado.begin(), resultado.end(), [](auto &a, auto &b) {
        return a.first > b.first;
    });

    return resultado;
}

// Función principal
int main() {
    cout << "Ingrese el primer polinomio:\n";
    Polinomio p1 = ingresarPolinomio();

    cout << "\nIngrese el segundo polinomio:\n";
    Polinomio p2 = ingresarPolinomio();

    cout << "\nPolinomio 1: ";
    imprimirPolinomio(p1);

    cout << "Polinomio 2: ";
    imprimirPolinomio(p2);

    // Suma de polinomios
    Polinomio suma = sumarPolinomios(p1, p2);
    cout << "\nSuma de polinomios: ";
    imprimirPolinomio(suma);

    // Producto de polinomios
    Polinomio producto = multiplicarPolinomios(p1, p2);
    cout << "\nProducto de polinomios: ";
    imprimirPolinomio(producto);

    return 0;
}
