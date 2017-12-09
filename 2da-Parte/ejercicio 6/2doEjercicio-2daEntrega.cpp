#include "Stack.h"
#include<iostream>
#include<fstream>
#include <cstring>
#include <array>
#include <string>


using std::cout;
using std::array;
using std::string;
std::fstream in;

struct Resultado{
	string agrupacion;
	unsigned lista;
	string candidato;
	unsigned votos;
}r, Aux;

Stack s;

const unsigned int MAX = 30*2;
array <Resultado,MAX> resultadosGenerales;
array <Resultado,10> resultadosAgrupaciones;
unsigned promedio=0;


void ponerEnCeroLosVotosTotales(array <Resultado,10>&);
void lecturaDeResultados(array <Resultado,MAX>&);
Resultado leerRegistro();
void ordenarYSumarPorAgrupacion(array <Resultado,MAX>&, array <Resultado,10>&);
void ordenarPorVotosTotales(array <Resultado,10>&);
void enlazoResultados(Stack&, const array <Resultado,10>&);
void muestroResultados(Stack&);
void calcularPromedio(const array <Resultado,10>&, unsigned&);
void agrupacionesMayoresAlPromedio(const array <Resultado,10>&, const unsigned&);

int main(){
	
	ponerEnCeroLosVotosTotales(resultadosAgrupaciones);
	
	in.open("Resultados.txt");
	
	lecturaDeResultados(resultadosGenerales);
	
	in.close();
	
	cout<<"Estos son los resultados por cada candidato Ordenados por Agrupacion:\n\n";
	ordenarYSumarPorAgrupacion(resultadosGenerales, resultadosAgrupaciones);
	ordenarPorVotosTotales(resultadosAgrupaciones);
	cout<<"\nEstos son los resultados Totales por cada Agrupacion:\n\n";
	enlazoResultados(s, resultadosAgrupaciones);
	muestroResultados(s);
	
	calcularPromedio(resultadosAgrupaciones, promedio);
	cout<<"\nEstas son las agrupaciones que superan el promedio de los votos totales ("<<promedio<<"):\n";
	agrupacionesMayoresAlPromedio(resultadosAgrupaciones, promedio);
}



void ponerEnCeroLosVotosTotales(array <Resultado,10>& b){
	for(int i=0; i<10; ++i){
		b.at(i).votos=0;
	}
}
void lecturaDeResultados(array <Resultado,MAX>& a){
	Resultado leerRegistro();
		
	for(int i=0; i<MAX; ++i){
		r=leerRegistro();
		a.at(i).agrupacion = r.agrupacion;
		a.at(i).lista = r.lista;
		a.at(i).candidato = r.candidato;
		a.at(i).votos += r.votos;
	}
}
Resultado leerRegistro(){
string line;
	
	in>>r.agrupacion;
	in>>r.lista;
	in>>r.candidato;
	in>>r.votos;
	std::getline(in,line);
	
	return r;
}

void ordenarYSumarPorAgrupacion(array <Resultado,MAX>& a, array <Resultado,10>& b){
	void ordenarPorAgrupacion(array <Resultado,MAX>&);
	void sumarVotosPorAgrupacion(const array <Resultado,MAX>&, array <Resultado,10>&);
	
	ordenarPorAgrupacion(a);
	sumarVotosPorAgrupacion(a,b);
}

void ordenarPorAgrupacion(array <Resultado,MAX>& a){
	int j;
	
	//por insercion
	for (unsigned i=1; i<MAX; i++){
		
		Aux = a.at(i);
		
		j = i - 1;
		
		while ( (j >= 0) and (a.at(j).agrupacion > Aux.agrupacion) ){
			a.at(j+1) = a.at(j);
			j--;
		}
		
		a.at(j+1) = Aux;
	}
}

void sumarVotosPorAgrupacion(const array <Resultado,MAX>& a, array <Resultado,10>& b){
	for(int i=0; i<MAX; i++){
		cout<<a.at(i).agrupacion<<"\t";
		cout<<a.at(i).lista<<"	\t";
		cout<<a.at(i).candidato<<"	\t";
		cout<<a.at(i).votos<<"	\t\n";
	}
	unsigned i=0;
	b.at(0).agrupacion = a.at(i).agrupacion;
	for(i; i<6; i++){
			b.at(0).votos += a.at(i).votos;
	}
	b.at(1).agrupacion = a.at(i).agrupacion;
	for(i; i<12; i++){	
			b.at(1).votos += a.at(i).votos;
	}
	b.at(2).agrupacion = a.at(i).agrupacion;
	for(i; i<18; i++){	
			b.at(2).votos += a.at(i).votos;
	}
	b.at(3).agrupacion = a.at(i).agrupacion;
	for(i; i<24; i++){	
			b.at(3).votos += a.at(i).votos;
	}
	b.at(4).agrupacion = a.at(i).agrupacion;
	for(i; i<30; i++){	
			b.at(4).votos += a.at(i).votos;
	}
	b.at(5).agrupacion = a.at(i).agrupacion;
	for(i; i<36; i++){	
			b.at(5).votos += a.at(i).votos;
	}
	b.at(6).agrupacion = a.at(i).agrupacion;
	for(i; i<42; i++){	
			b.at(6).votos += a.at(i).votos;
	}
	b.at(7).agrupacion = a.at(i).agrupacion;
	for(i; i<48; i++){	
			b.at(7).votos += a.at(i).votos;
	}
	b.at(8).agrupacion = a.at(i).agrupacion;
	for(i; i<54; i++){	
			b.at(8).votos += a.at(i).votos;
	}
	b.at(9).agrupacion = a.at(i).agrupacion;
	for(i; i<60; i++){	
			b.at(9).votos += a.at(i).votos;
	}
}

void ordenarPorVotosTotales(array <Resultado,10>& b){
	for (unsigned i=1; i<10; i++){
		for (unsigned j=0; j<10 - 1; j++){
          	if (b.at(j).votos > b.at(j+1).votos){
                
				Aux = b.at(j);
                b.at(j) = b.at(j+1);
                b.at(j+1) = Aux;
                                
            }
		}
	}
}

void enlazoResultados(Stack& s, const array <Resultado,10>& b){
	for(unsigned i=0; i<10; i++){
		push(s, b.at(i).agrupacion, b.at(i).votos);
	}
}
void muestroResultados(Stack& s){
	for(unsigned i=0; i<10; i++){
		cout<<pop(s)<<"\n";
	}
}

void calcularPromedio(const array <Resultado,10>& b, unsigned& promedio){
	unsigned Total=0;
	
	for(unsigned i=0; i<10; i++){
		Total += b.at(i).votos;
	}
	
	promedio = Total / 10;
}

void agrupacionesMayoresAlPromedio(const array <Resultado,10>& b, const unsigned& promedio){
	for (unsigned i=0; i<10; i++){
		if (b.at(i).votos > promedio){
			cout<<b.at(i).agrupacion<<"\t"<<b.at(i).votos<<"\n";
		}
	}
}
