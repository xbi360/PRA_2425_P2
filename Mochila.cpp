#include <iostream>
#include <vector>
#include <algorithm> // Para std::max

using namespace std;

int Mochila(int N, const vector<int>& p, const vector<int>& b, int M) {
    // Caso base: si no hay objetos o capacidad es 0
    if (N == 0 || M == 0) {
        return 0;
    }

    // Si el peso del objeto N-1 es mayor que la capacidad M
    if (p[N - 1] > M) {
        return Mochila(N - 1, p, b, M);
    } else {
        return max(Mochila(N - 1, p, b, M), b[N - 1] + Mochila(N - 1, p, b, M - p[N - 1]));
    }
}

int main() {
    int M = 5; // Peso máximo
    vector<int> p = {1, 3, 2, 4}; // Pesos de los objetos
    vector<int> b = {10, 20, 15, 20}; // Beneficios de los objetos
    int N = p.size(); // Número de objetos

    int maxBenefit = Mochila(N, p, b, M);
    cout << "El beneficio máximo que se puede obtener es: " << maxBenefit << endl;

    return 0;
}
