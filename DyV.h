#include <vector>

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

