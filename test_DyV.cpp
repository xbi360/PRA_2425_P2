#include "DyV.h"
#include <vector>
#include <iostream>
#include<chrono> //para medir el tiempo que tarda Quicksort en ordenar un array, en este caso para un array de enteros 

using namespace std;
//para imprimir los elementos del array
template <typename T>
void printVec(const std::vector<T>& vec);

int main(){
	//vectores para BúsquedaBinaria
	vector<int> a{1,4,6,9};
	vector<float> b{1.5,2.6,3.8,5.0};
	vector<double> c{1.7,4.5,8.9,10.1};
	int posin=BusquedaBinaria(a,4,0,a.size()-1);//buscamos el 4
	int posf=BusquedaBinaria(b,2.6f,0,b.size()-1);//buscamos el 2.6
	int posd=BusquedaBinaria(c,10.0,0,c.size()-1);//buscamos el 10.0
	
	if(posin!=-1){
	cout<<"Posición del elemento buscado del array de ints: "<<posin<<endl;
	}else{
		cout<<"No se ha encontrado elemento busacado del array de ints"<<endl;
	}
	
	if(posf!=-1){	
		cout<<"Posición del elemento buscado del array de floats: "<<posf<<endl;
	}else{
		cout<<"No se ha encontrado elemento buscado del array de floats"<<endl;
	}
	
	if(posd!=-1){

	cout<<"Posición del elemento buscado del array de doubles: "<<posd<<endl;
	}else{
		cout<<"No se ha encontrado elemento buscado del array de doubles"<<endl;
	}

	std::cout<<endl;
	//QUICKSORT
	//vector de enteros
	std::vector<int> intVec = {10, 7, 8, 9, 1, 5};
	std::cout << "Array de enteros original: ";
    	printVec(intVec);
	auto start = std::chrono::system_clock::now();
	quicksort(intVec, 0, intVec.size() - 1);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;
    	std::cout << "Array de enteros ordenado: ";
    	printVec(intVec);
	std::cout << " Time: " << duration.count() <<" s "<< std::endl;
  	
	std::cout<<endl;	
	//vector de flotantes
	std::vector<float> floatVec = {3.1, 2.4, 5.6, 1.2, 4.8};
    	std::cout << "Array de flotantes original: ";
    	printVec(floatVec);
    	quicksort(floatVec, 0, floatVec.size() - 1);
    	std::cout << "Array de flotantes ordenado: ";
    	printVec(floatVec);
	
	std::cout<<endl;
	//vector de doubles
    	std::vector<double> doubleVec = {3.14, 2.71, 1.41, 1.62, 4.67};
    	std::cout << "Array de dobles original: ";
    	printVec(doubleVec);
    	quicksort(doubleVec, 0, doubleVec.size() - 1);
    	std::cout << "Array de dobles ordenado: ";
    	printVec(doubleVec);
	return 0;
}
//método para imprimir los elementos del array
template <typename T>
void printVec(const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

