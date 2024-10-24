#include "DyV.h"
#include <vector>
#include <iostream>

using namespace std;

int main(){
	vector<int> a{1,4,6,9};
	vector<float> b{1.5,2.6,3.8,5.0};
	vector<double> c{1.7,4.5,8.9,10.1};
	
	//iniciar busqueda para vector de enteros
	int posin=BusquedaBinaria(a,4,0,a.size()-1);//buscamos el 4
	//iniciar busqueda para vector de floats
	int posf=BusquedaBinaria(b,2.6f,0,b.size()-1);//buscamos el 2.6
	//iniciar busqueda para vector de doubles
	int posd=BusquedaBinaria(c,10.0,0,c.size()-1);//buscamos el 10.0
	
	if(posin!=-1){//si se encuentra el elemento
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
	return 0;
}
