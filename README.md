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
using namespace std;```
# variables
definimos las variables que usaremos
```typedef vector<pair<int, double>> Polinomio;
#Función para ingresar un polinomio desde el teclado
