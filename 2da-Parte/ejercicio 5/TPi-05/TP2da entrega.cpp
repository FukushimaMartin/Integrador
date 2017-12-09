#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <array>
#include "Queue.h"


using std::array;
using std::cout;

array<array<double,9>,9> matrizAdy, matrizDist;
array<double,8> a;
double velocidadPromedio;
Queue t;

void inicMatrizAdy(array<array<double,9>,9>&);
double getVelocidadPromedio(double&);
double calcularDemora();
void inicMatrizDist(array<array<double,9>,9>&, const array<array<double,9>,9>&, const double&);
void caminoMasOptimo(array<double,8>&, array<array<double,9>,9>&, Queue&);
void mostrarCaminoOptimo(Queue&);

int main(){
	srand(time(NULL));
	
	getVelocidadPromedio(velocidadPromedio);
	inicMatrizAdy(matrizAdy);
	inicMatrizDist(matrizDist, matrizAdy, velocidadPromedio);
	caminoMasOptimo(a, matrizDist, t);
	mostrarCaminoOptimo(t);
}

double getVelocidadPromedio(double& velocidadPromedio){
	cout<<"Ingrese la velocidad promedio del vehiculo (en km/h): ";
	std::cin>>velocidadPromedio;
	
	return velocidadPromedio;
}

void inicMatrizAdy(array<array<double, 9>,9>& matrizAdy){
	matrizAdy.at(0).at(1) = 5;
	matrizAdy.at(0).at(2) = 7;
	matrizAdy.at(1).at(2) = matrizAdy.at(2).at(1) = 4;
	matrizAdy.at(1).at(3) = matrizAdy.at(3).at(1) = 8;
	matrizAdy.at(2).at(3) = matrizAdy.at(3).at(2) = 2;
	matrizAdy.at(2).at(4) = 6;
	matrizAdy.at(3).at(4) = matrizAdy.at(4).at(3) = 7;
	matrizAdy.at(3).at(5) = 11;
	matrizAdy.at(4).at(5) = 12;
	matrizAdy.at(5).at(6) = 15;
	matrizAdy.at(5).at(7) = 16;
	matrizAdy.at(6).at(7) = matrizAdy.at(7).at(6) = 9;
	matrizAdy.at(6).at(8) = 4;
	matrizAdy.at(7).at(8) = 3;
}

double calcularDemora(){
	double demora; //guardamos el random en una variable
	demora = (double)rand() / RAND_MAX;
	return demora;
}


void inicMatrizDist(array<array<double, 9>,9>& matrizDist, const array<array<double, 9>,9>& matrizAdy, const double& velocidadPromedio){
	
	matrizDist.at(0).at(1) = matrizAdy.at(0).at(1) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(0).at(2) = matrizAdy.at(0).at(2) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(1).at(2) = matrizDist.at(2).at(1) = matrizAdy.at(1).at(2) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(1).at(3) = matrizDist.at(3).at(1) = matrizAdy.at(1).at(3) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(2).at(3) = matrizDist.at(3).at(2) = matrizAdy.at(2).at(3) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(2).at(4) = matrizAdy.at(2).at(4) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(3).at(4) = matrizDist.at(4).at(3) = matrizAdy.at(3).at(4) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(3).at(5) = matrizAdy.at(3).at(5) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(4).at(5) = matrizAdy.at(4).at(5) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(5).at(6) = matrizAdy.at(5).at(6) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(5).at(7) = matrizAdy.at(5).at(7) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(6).at(7) = matrizDist.at(7).at(6) = matrizAdy.at(6).at(7) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(6).at(8) = matrizAdy.at(6).at(8) + (calcularDemora() * velocidadPromedio);
	matrizDist.at(7).at(8) = matrizAdy.at(7).at(8) + (calcularDemora() * velocidadPromedio);
}



void caminoMasOptimo(array<double, 8>& a, array<array<double, 9>,9>& matrizDist, Queue& t){
	
	
	a.at(0) = matrizDist.at(0).at(1)+matrizDist.at(1).at(2)+matrizDist.at(2).at(3)+matrizDist.at(3).at(4)+matrizDist.at(4).at(5)+matrizDist.at(5).at(6)+matrizDist.at(6).at(7)+matrizDist.at(7).at(8);
	a.at(1) = matrizDist.at(0).at(1)+matrizDist.at(1).at(2)+matrizDist.at(2).at(3)+matrizDist.at(3).at(4)+matrizDist.at(4).at(5)+matrizDist.at(5).at(7)+matrizDist.at(7).at(6)+matrizDist.at(6).at(8);
	a.at(2) = matrizDist.at(0).at(1)+matrizDist.at(1).at(2)+matrizDist.at(2).at(4)+matrizDist.at(4).at(3)+matrizDist.at(3).at(5)+matrizDist.at(5).at(6)+matrizDist.at(6).at(7)+matrizDist.at(7).at(8);
	a.at(3) = matrizDist.at(0).at(1)+matrizDist.at(1).at(2)+matrizDist.at(2).at(4)+matrizDist.at(4).at(3)+matrizDist.at(3).at(5)+matrizDist.at(5).at(7)+matrizDist.at(7).at(6)+matrizDist.at(6).at(8);
	a.at(4) = matrizDist.at(0).at(1)+matrizDist.at(1).at(3)+matrizDist.at(3).at(2)+matrizDist.at(2).at(4)+matrizDist.at(4).at(5)+matrizDist.at(5).at(6)+matrizDist.at(6).at(7)+matrizDist.at(7).at(8);
	a.at(5) = matrizDist.at(0).at(1)+matrizDist.at(1).at(3)+matrizDist.at(3).at(2)+matrizDist.at(2).at(4)+matrizDist.at(4).at(5)+matrizDist.at(5).at(7)+matrizDist.at(7).at(6)+matrizDist.at(6).at(8);
	a.at(6) = matrizDist.at(0).at(2)+matrizDist.at(2).at(1)+matrizDist.at(1).at(3)+matrizDist.at(3).at(4)+matrizDist.at(4).at(5)+matrizDist.at(5).at(6)+matrizDist.at(6).at(7)+matrizDist.at(7).at(8);
	a.at(7) = matrizDist.at(0).at(2)+matrizDist.at(2).at(1)+matrizDist.at(1).at(3)+matrizDist.at(3).at(4)+matrizDist.at(4).at(5)+matrizDist.at(5).at(7)+matrizDist.at(7).at(6)+matrizDist.at(6).at(8);
	
	unsigned j=0;
	for (unsigned i=0; i<7; i++){
		if (a.at(j) > a.at(i+1)){
			j = i+1;
		}
	}
	
	cout<<"Orden de escuelas a visitar: \n";
	switch (j){
		case 0:
			enQueue(t,"escuela 1");
			enQueue(t,"escuela 2");
			enQueue(t,"escuela 3");
			enQueue(t,"escuela 4");
			enQueue(t,"escuela 5");
			enQueue(t,"escuela 6");
			enQueue(t,"escuela 7");
			break;
		case 1:
			enQueue(t,"escuela 1");
			enQueue(t,"escuela 2");
			enQueue(t,"escuela 3");
			enQueue(t,"escuela 4");
			enQueue(t,"escuela 5");
			enQueue(t,"escuela 7");
			enQueue(t,"escuela 6");
			break;
		case 2:
			enQueue(t,"escuela 1");
			enQueue(t,"escuela 2");
			enQueue(t,"escuela 4");
			enQueue(t,"escuela 3");
			enQueue(t,"escuela 5");
			enQueue(t,"escuela 6");
			enQueue(t,"escuela 7");
			break;
		case 3:
			enQueue(t,"escuela 1");
			enQueue(t,"escuela 2");
			enQueue(t,"escuela 4");
			enQueue(t,"escuela 3");
			enQueue(t,"escuela 5");
			enQueue(t,"escuela 7");
			enQueue(t,"escuela 6");
			break;
		case 4:
			enQueue(t,"escuela 1");
			enQueue(t,"escuela 3");
			enQueue(t,"escuela 2");
			enQueue(t,"escuela 4");
			enQueue(t,"escuela 5");
			enQueue(t,"escuela 6");
			enQueue(t,"escuela 7");
			break;
		case 5:
			enQueue(t,"escuela 1");
			enQueue(t,"escuela 3");
			enQueue(t,"escuela 2");
			enQueue(t,"escuela 4");
			enQueue(t,"escuela 5");
			enQueue(t,"escuela 7");
			enQueue(t,"escuela 6");
			break;
		case 6:
			enQueue(t,"escuela 2");
			enQueue(t,"escuela 1");
			enQueue(t,"escuela 3");
			enQueue(t,"escuela 4");
			enQueue(t,"escuela 5");
			enQueue(t,"escuela 6");
			enQueue(t,"escuela 7");
			break;
		case 7:
			enQueue(t,"escuela 2");
			enQueue(t,"escuela 1");
			enQueue(t,"escuela 3");
			enQueue(t,"escuela 4");
			enQueue(t,"escuela 5");
			enQueue(t,"escuela 7");
			enQueue(t,"escuela 6");
			break;
		default:
			break;
	}
}
void mostrarCaminoOptimo(Queue& t){
	
	for (unsigned u=0; u<7; u++){
		cout<<deQueue(t)<<"\n";
	}

	cout<<"\nDirijase al Centro de Computos\n";
}
