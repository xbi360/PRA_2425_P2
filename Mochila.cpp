#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función recursiva para resolver el problema de la mochila
int Mochila(int N, const vector<int>& p, const vector<int>& b, int M, vector<int>& x) {
    // Caso base: si no hay objetos o capacidad es 0
    if (N == 0 || M == 0) {
        return 0;
    }

    // Si el peso del objeto N-1 es mayor que la capacidad M
    if (p[N - 1] > M) {
        return Mochila(N - 1, p, b, M, x); // No se incluye el objeto
    } else {
        // Retornar el máximo entre no incluir el objeto y incluirlo
        x[N - 1] = 1; // Marcar como incluido
        int incluir = b[N - 1] + Mochila(N - 1, p, b, M - p[N - 1], x); // Incluir
        x[N - 1] = 0; // Desmarcar

        // No incluir
        int noIncluir = Mochila(N - 1, p, b, M, x); // No incluir

        // Retornar el máximo de incluir y no incluir
        return max(noIncluir, incluir);
    }
}

int main() {
    int M = 5; // Peso máximo
    vector<int> p = {1, 3, 2, 4}; // Pesos de los objetos
    vector<int> b = {10, 20, 15, 20}; // Beneficios de los objetos
    int N = p.size(); // Número de objetos
    vector<int> x(N, 0); // Inicializar vector de solución

    int maxBenefit = Mochila(N, p, b, M, x); // Llamada a la función Mochila

    // Mostrar resultados
    cout << "El beneficio máximo que se puede obtener es: " << maxBenefit << endl;
    cout << "Vector solución: ";
    for (int item : x) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}

