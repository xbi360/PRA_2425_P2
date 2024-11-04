#include <vector>


//BUSQUEDA BINARIA
template <typename T>
int BusquedaBinaria(std::vector<T>&v,T x,int ini, int fin){
	if(ini > fin){
		return -1; //no se ha encontrado el elemento
	}
	int medio= (ini + fin)/2;
	if(v[medio]==x){
		return medio;
	}
	else if(v[medio]>x){
		return BusquedaBinaria(v,x,ini,medio-1);
	}
	else{
		return BusquedaBinaria(v,x,medio+1,fin);
	}
}	
//Partition
template <typename T>
int partition(std::vector<T>&V, int ini, int fin) {
    int pivot = V[fin];
    int i = ini;

    for (int j = ini; j < fin; j++) {
        if (V[j] <= pivot) {
            std::swap(V[i], V[j]);
            i++;
        }
    }
    std::swap(V[i], V[fin]);
    return i;
}
//QUICKSORT
template <typename T>
void quicksort(std::vector<T>& V, int ini, int fin) {
    if (ini < fin) {
        // Particionar el array y obtener el índice del pivote
        int pivotIndex = partition(V, ini, fin);

        // Ordenar los elementos antes y después del pivote
        quicksort(V, ini, pivotIndex - 1);
        quicksort(V, pivotIndex + 1, fin);
    }
}
