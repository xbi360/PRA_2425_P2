#include <iostream>
#include <vector>
#include <algorithm> // Para usar std::max
#include <climits>  // Para usar INT_MAX

using namespace std;

int Cambio (const vector<int>& d, int tot, int m, vector<vector<int>>& M) {
    // Caso base: si la cantidad total es negativa o el índice de moneda es negativo, retorno un valor muy alto
    if (tot < 0 || m < 0) {
        return INT_MAX;  // Infinito (no es posible hacer el cambio)
    }
    
    // Si ya se ha calculado el resultado para este subproblema, retornamos el valor almacenado
    if (M[tot][m] != -1) {
        return M[tot][m];
    }

    // Si no se necesita más dinero, no se requieren más monedas
    if (tot == 0) {
        M[tot][m] = 0;
        return M[tot][m];
    }

    int option1 = Cambio(d, tot, m - 1, M);  // No usamos la moneda d[m]
    int option2 = Cambio(d, tot - d[m], m, M);  // Usamos la moneda d[m]

    if (option2 != INT_MAX) {
        option2 += 1;  // Añadimos 1 porque hemos usado una moneda d[m]
    }

    // Tomamos el mínimo entre las dos opciones
    M[tot][m] = min(option1, option2);

    return M[tot][m];
}

int main() {
    vector<int> monedas = {1, 2, 5};  // Monedas disponibles
    int cantidad = 11;  // Cantidad a devolver

    int N = monedas.size();  // Número de monedas
    vector<vector<int>> M(cantidad + 1, vector<int>(N, -1));  // Inicializamos la memoria con -1

    // Llamamos a la función Change para resolver el problema
    int resultado = Cambio(monedas, cantidad, N - 1, M);

    // Mostramos el resultado
    if (resultado == INT_MAX) {
        cout << "No es posible hacer el cambio." << endl;
    } else {
        cout << "El número mínimo de monedas es: " << resultado << endl;
    }

    return 0;
}

