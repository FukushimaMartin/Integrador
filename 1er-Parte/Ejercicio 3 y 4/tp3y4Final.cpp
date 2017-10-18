
/* Ejercicio 3 y 4.cpp
* Grupo #2 - K1051
* 31-07-2017
*/


#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <cstring>


using std::cout;
using std::array;
using std::string;
std::fstream in;

struct Resultado{
	string agrupacion;
	unsigned lista;
	string candidato;
	unsigned votos;
}r;


const unsigned int MAX = 10*3; 
Resultado Aux;
array <Resultado,MAX> senadores, diputados,ganadorSenadores, ganadorDiputados, ganadorAgrupacionSenadores, ganadorAgrupacionDiputados;
unsigned votosTotalesSenadores = 0, votosTotalesDiputados = 0;


int main(){
	void sumarLosVotos();
	sumarLosVotos();
	
	void menuListados();
	menuListados();
	
}



void sumarLosVotos(){
	void ponerEnCeroLosVotosDeSenadoresYDiputados();
	void sumarLosVotosDeLosArchivos();
	
	ponerEnCeroLosVotosDeSenadoresYDiputados();
	sumarLosVotosDeLosArchivos();
}


void ponerEnCeroLosVotosDeSenadoresYDiputados(){
	void ponerEnCeroLosVotos(array <Resultado,MAX>&);

	ponerEnCeroLosVotos(senadores);
	ponerEnCeroLosVotos(diputados);
}
void ponerEnCeroLosVotos(array <Resultado,MAX>& a){
	for(int i=0; i<MAX; ++i){
		a.at(i).votos=0;
	}
}

void sumarLosVotosDeLosArchivos(){
	void sumarLosVotosDeUnArchivo(string);
	
	sumarLosVotosDeUnArchivo("Mesa_4568.txt");
	sumarLosVotosDeUnArchivo("Mesa_4569.txt");
	sumarLosVotosDeUnArchivo("Mesa_4579.txt");
	sumarLosVotosDeUnArchivo("Mesa_4580.txt");
	sumarLosVotosDeUnArchivo("Mesa_4581.txt");
}
void sumarLosVotosDeUnArchivo(string archivo){

	void avanzarHastaSenadores();
	void sumarVotosDeSenadores();
	void avanzarHastaDiputados();
	void sumarVotosDeDiputados();
	
	in.open(archivo);
	
	avanzarHastaSenadores();
	sumarVotosDeSenadores();
	avanzarHastaDiputados();
	sumarVotosDeDiputados();
	
	in.close();

}
void avanzarHastaSenadores(){
	void saltearLineas(unsigned);
	
	saltearLineas(4);
}
void sumarVotosDeSenadores(){
	void sumarVotosDeUnCargo(array <Resultado,MAX>&, unsigned&);
	
	sumarVotosDeUnCargo(senadores, votosTotalesSenadores);
}
void avanzarHastaDiputados(){
	void saltearLineas(unsigned);
	
	saltearLineas(2);
}
void sumarVotosDeDiputados(){
	void sumarVotosDeUnCargo(array <Resultado,MAX>&, unsigned&);
	
	sumarVotosDeUnCargo(diputados, votosTotalesDiputados); 
}

void saltearLineas(unsigned n){
	string line;
	/* Obtiene de in una linea y la guarda	en line. La descarta porque se invoca solo para avanzar. */
	for (unsigned i=0; i<n; i++){
		std::getline(in,line);
	}
}
void sumarVotosDeUnCargo(array <Resultado,MAX>& a, unsigned& n){
	void saltearVotosEnBlancoEImpugnados();
	
	Resultado leerRegistro();
		
	for(int i=0; i<MAX; ++i){
		r=leerRegistro();
		a.at(i).agrupacion = r.agrupacion;
		a.at(i).lista = r.lista;
		a.at(i).candidato = r.candidato;
		a.at(i).votos += r.votos;
		n += r.votos;
	}
	saltearVotosEnBlancoEImpugnados();
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
void saltearVotosEnBlancoEImpugnados(){
	saltearLineas(4);
}







void menuListados(){
	unsigned leerOpcion();
	void menu();
	unsigned opcion = 0;
	
	while (opcion != 9){
		menu();
		opcion = leerOpcion();
		
		switch (opcion){
			case 1:
				void mostrarListado1(array <Resultado,MAX>&);
				cout<<"\n\tSENADORES\n";
				mostrarListado1(senadores);
				cout<<"\n\tDIPUTADOS\n";
				mostrarListado1(diputados);
				break;
			case 2:
				void mostrarListado2(array <Resultado,MAX>&);
				cout<<"\n\tSENADORES\n";
				mostrarListado2(senadores);
				cout<<"\n\tDIPUTADOS\n";
				mostrarListado2(diputados);
				break;
			case 3:
				void mostrarListado3(array <Resultado,MAX>&);
				cout<<"\n\tSENADORES\n";
				mostrarListado3(senadores);
				cout<<"\n\tDIPUTADOS\n";
				mostrarListado3(diputados);
				break;
			case 4:
				void mostrarListado4(array <Resultado,MAX>&);
				cout<<"\n\tSENADORES\n";
				mostrarListado4(senadores);
				cout<<"\n\tDIPUTADOS\n";
				mostrarListado4(diputados);
				break;
			case 5:
				void mostrarListado5(array <Resultado,MAX>&);
				cout<<"\n\tSENADORES\n";
				mostrarListado5(senadores);
				cout<<"\n\tDIPUTADOS\n";
				mostrarListado5(diputados);
				break;
			case 6:
				void mostrarListado6(array <Resultado,MAX>&);
				cout<<"\n\tSENADORES\n";
				mostrarListado6(senadores);
				cout<<"\n\tDIPUTADOS\n";
				mostrarListado6(diputados);
				break;
			case 7:
				void mostrarListado7(array <Resultado,MAX>&);
				cout<<"\n\tSENADORES\n";
				mostrarListado7(senadores);
				cout<<"\n\tDIPUTADOS\n";
				mostrarListado7(diputados);
				break;
			case 8:
				void ordenarListado8(array <Resultado,MAX>&, array <Resultado,MAX>&);
				void ordenarListado9(array <Resultado,MAX>&, array <Resultado,MAX>&);
				void calcularEInformarLasEstadisticas();
				ordenarListado8(senadores, ganadorAgrupacionSenadores);
				ordenarListado8(diputados, ganadorAgrupacionDiputados);
				ordenarListado9(senadores, ganadorSenadores);
				ordenarListado9(diputados, ganadorDiputados);
				
				calcularEInformarLasEstadisticas();
				break;
		}
	}
}
void menu(){

    cout<<"\n\n\t   Menu:\n";
    cout<<"\n\t1) Ordenar por Voto (burbujeo)";
    cout<<"\n\t2) Ordenar por Agrupacion (insercion)";
    cout<<"\n\t3) Ordenar por Lista (seleccion)";
    cout<<"\n\t4) Ordenar por Candidato";
    cout<<"\n\t5) Ordenar por Agrupacion y por Voto";
    cout<<"\n\t6) Ordenar por Candidato y por Voto";
    cout<<"\n\t7) Ordenar por Agrupacion, por Candidato y por Voto";
    cout<<"\n\t8) Estadisticas";
    cout<<"\n\t9) Salir";
    cout<<"\n\n\t   Ingrese su opcion por favor: ";
}
unsigned leerOpcion(){
	unsigned option;
	
	do {
		std::cin>>option;
	} while (option < 1 and option > 9);
	return option;
}







void mostrarListado1(array <Resultado,MAX>& b){ //burbujeo
	void ordenarPorVoto(array <Resultado,MAX>&);
	void imprimirArreglo(const array <Resultado,MAX>&);
	
	ordenarPorVoto(b);	
	imprimirArreglo(b);
}
void mostrarListado2(array <Resultado,MAX>& b){ //por insercion
	void ordenarPorAgrupacion(array <Resultado,MAX>&);
	void imprimirArreglo(const array <Resultado,MAX>&);
	
	ordenarPorAgrupacion(b);
	imprimirArreglo(b);
}
void mostrarListado3(array <Resultado,MAX>& b){ //por seleccion
	void ordenarPorLista(array <Resultado,MAX>&);
	void imprimirArreglo(const array <Resultado,MAX>&);
	
	ordenarPorLista(b);
	imprimirArreglo(b);
}	
void mostrarListado4(array <Resultado,MAX>& b){ //por insercion
	void ordenarPorCandidato(array <Resultado,MAX>&);
	void imprimirArreglo(const array <Resultado,MAX>&);
	
	ordenarPorCandidato(b);
	imprimirArreglo(b);
}
void mostrarListado5(array <Resultado,MAX>& b){ //burbujeo
	void ordenarPorAgrupacionYVotos(array <Resultado,MAX>&);
	void imprimirArreglo(const array <Resultado,MAX>&);
	
	ordenarPorAgrupacionYVotos(b);
	imprimirArreglo(b);
}
void mostrarListado6(array <Resultado,MAX>& b){ //burbujeo
	void ordenarPorCandidatoYVotos(array <Resultado,MAX>&);
	void imprimirArreglo(const array <Resultado,MAX>&);
	
	ordenarPorCandidatoYVotos(b);
	imprimirArreglo(b);
}
void mostrarListado7(array <Resultado,MAX>& b){ //burbujeo
	void ordenarPorAgrupacionYCandidatoYVotos(array <Resultado,MAX>&);
	void imprimirArreglo(const array <Resultado,MAX>&);
	
	ordenarPorAgrupacionYCandidatoYVotos(b);
	imprimirArreglo(b);
}


void ordenarListado8(array <Resultado,MAX>& b, array <Resultado,MAX>& d){ //burbujeo
	void ordenarPorAgrupacionYVotos(array <Resultado,MAX>&);
	
	ordenarPorAgrupacionYVotos(b);
	for (unsigned i=0; i<MAX; i++){
		d.at(i) = b.at(i);
	}	
}
void ordenarListado9(array <Resultado,MAX>& b, array <Resultado,MAX>& c){ //burbujeo
	void ordenarPorVoto(array <Resultado,MAX>&);
	
	ordenarPorVoto(b);
	for (unsigned i=0; i<MAX; i++){
		c.at(i) = b.at(i);
	}	
}

void imprimirArreglo(const array <Resultado,MAX>& a){
	for(int i=0; i<MAX; i++){
		cout<<a.at(i).agrupacion<<"\t";
		cout<<a.at(i).lista<<"	\t";
		cout<<a.at(i).candidato<<"	\t";
		cout<<a.at(i).votos<<"	\t\n";
	}
	
}

//ORDENAMIENTO: LISTADO 1
void ordenarPorVoto(array <Resultado,MAX>& a){

	//burbujeo
	for (unsigned i=1; i<MAX; i++){
		for (unsigned j=0; j<MAX - 1; j++){
          	if (a.at(j).votos < a.at(j+1).votos){
                
				Aux = a.at(j);
                a.at(j) = a.at(j+1);
                a.at(j+1) = Aux;
                                
            }
		}
	}
}

//ORDENAMIENTO: LISTADO 2
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

//ORDENAMIENTO: LISTADO 3
void ordenarPorLista(array <Resultado,MAX>& a){
	unsigned menor (array <Resultado,MAX>, unsigned);
	
	unsigned pos_menor;
	
	//por Seleccion
	for (unsigned i=0; i<MAX - 1; i++){
        // Buscamos el elemento menor
        pos_menor = menor(a, i);
		
        // Lo colocamos en el lugar que le corresponde
        Aux = a.at(i);
        a.at(i) = a.at(pos_menor);
        a.at(pos_menor) = Aux;
        
    }
}
unsigned menor(array <Resultado,MAX> a, unsigned desde){
	//busca el indice del menor valor del array
    unsigned  m = desde;

    for (unsigned j=desde; j<MAX; j++){
     	if (a.at(j).lista < a.at(m).lista){
     		m = j;
		}
	}
    return m;
}

//ORDENAMIENTO: LISTADO 4
void ordenarPorCandidato(array <Resultado,MAX>& a){
	int j;
	
	//por insercion
	for (unsigned i=1; i<MAX; i++){
		
		Aux = a.at(i);
		
		j = i - 1;
		
		while ( (j >= 0) and (a.at(j).candidato > Aux.candidato) ){
			a.at(j+1) = a.at(j);
			j--;
		}
		
		a.at(j+1) = Aux;
	}
}

//ORDENAMIENTO: LISTADO 5
void ordenarPorAgrupacionYVotos(array <Resultado,MAX>& a){
	
	//burbujeo
	for (unsigned i=1; i<MAX; i++){
		for (unsigned j=0; j<MAX - i; j++){
          	if (a.at(j).agrupacion > a.at(j+1).agrupacion){
                
                Aux = a.at(j);
                a.at(j) = a.at(j+1);
                a.at(j+1) = Aux;
                
            } else {
            	if ((a.at(j).agrupacion == a.at(j+1).agrupacion) and (a.at(j).votos < a.at(j+1).votos)){
					
					Aux = a.at(j);
					a.at(j) = a.at(j+1);
					a.at(j+1) = Aux;
				}
			}
		}
	}
}

//ORDENAMIENTO: LISTADO 6
void ordenarPorCandidatoYVotos(array <Resultado,MAX>& a){
	
	//burbujeo
	for (unsigned i=1; i<MAX; i++){
		for (unsigned j=0; j<MAX - i; j++){
            if (a.at(j).candidato > a.at(j+1).candidato){
            	
            	Aux = a.at(j);
				a.at(j) = a.at(j+1);
				a.at(j+1) = Aux;
                		
			} else {
				if ((a.at(j).candidato == a.at(j+1).candidato) and (a.at(j).votos < a.at(j+1).votos)){
						
					Aux = a.at(j);
					a.at(j) = a.at(j+1);
					a.at(j+1) = Aux;
				}
			}
		}
	}
}

//ORDENAMIENTO: LISTADO 7
void ordenarPorAgrupacionYCandidatoYVotos(array <Resultado,MAX>& a){
	unsigned auxVotos, auxLista;
	string auxAgrupacion, auxCandidato;
	
	//burbujeo
	for (unsigned i=1; i<MAX; i++){
		for (unsigned j=0; j<MAX - i; j++){
          	if (a.at(j).agrupacion > a.at(j+1).agrupacion){
                
                Aux = a.at(j);
				a.at(j) = a.at(j+1);
				a.at(j+1) = Aux;
            } else {
            	if ((a.at(j).agrupacion == a.at(j+1).agrupacion) and (a.at(j).candidato > a.at(j+1).candidato)){
            			
            		Aux = a.at(j);
					a.at(j) = a.at(j+1);
					a.at(j+1) = Aux;
				} else {
					if ((a.at(j).candidato == a.at(j+1).candidato) and (a.at(j).votos < a.at(j+1).votos)){
								
						Aux = a.at(j);
						a.at(j) = a.at(j+1);
						a.at(j+1) = Aux;	
					}
            	}
			}
		}
	}
}




//------------------------------------------------------------------------------------------
//INICIA PARTE 4

void calcularEInformarLasEstadisticas(){
	void mostrarCandidatosConBuenaEleccion(const array <Resultado,MAX>&, const unsigned&);
	void mostrarGanadores3PrimerasAgrupaciones(const array <Resultado,MAX>&);
	void mostrarGanadoresDeCadaAgrupacion(const array <Resultado,MAX>&);

	cout<<"\nCandidatos Senadores con buena eleccion (entre 17% y 30%):\n";
	cout<<"Votos Totales Senadores: "<<votosTotalesSenadores<<"\n";
	mostrarCandidatosConBuenaEleccion(senadores, votosTotalesSenadores);
	cout<<"\nCandidatos Diputados con buena eleccion (entre 17% y 30%):\n";
	cout<<"Votos Totales Diputados: "<<votosTotalesDiputados<<"\n";
	mostrarCandidatosConBuenaEleccion(diputados, votosTotalesDiputados);
	
	cout<<"\nGanadores de las 3 primeras agrupaciones (senadores):\n";
	mostrarGanadores3PrimerasAgrupaciones(ganadorSenadores);
	cout<<"\nGanadores de las 3 primeras agrupaciones (diputados):\n";
	mostrarGanadores3PrimerasAgrupaciones(ganadorDiputados);
	
	cout<<"\nGanadores de cada agrupacion (senadores):\n";
	mostrarGanadoresDeCadaAgrupacion(ganadorAgrupacionSenadores);
	cout<<"\nGanadores de cada agrupacion (diputados):\n";
	mostrarGanadoresDeCadaAgrupacion(ganadorAgrupacionDiputados);
}

void mostrarCandidatosConBuenaEleccion(const array <Resultado,MAX>& a, const unsigned& n){
	unsigned cont=0;
	for (unsigned i=0; i<MAX; i++){
		if ((a.at(i).votos >= (17 * n / 100)) and (a.at(i).votos <= (30 * n / 100))){
			cout<<"\t"<<a.at(i).candidato<<"\n";
			cont++;
		}
	}
	if (cont == 0){
		cout<<"No hay candidatos con Buena Eleccion\n";
	}
}
void mostrarGanadores3PrimerasAgrupaciones(const array <Resultado,MAX>& c){
	string aux = c.at(0).agrupacion;
	
	cout<< c.at(0).agrupacion << "\t";
	cout<< c.at(0).candidato << "\t";
	cout<< c.at(0).votos << "\t\n";
	unsigned ganador = 1, i = 1;
			
	while (ganador < 3){
		if (c.at(i).agrupacion != aux){
			cout<< c.at(i).agrupacion << "\t";
			cout<< c.at(i).candidato << "\t";
			cout<< c.at(i).votos << "\t\n";
				
			ganador++;
		}
	i++;
	}		
}
void mostrarGanadoresDeCadaAgrupacion(const array <Resultado,MAX>& d){
		
	for (unsigned i=0; i<MAX; i+=3){
		cout<< d.at(i).agrupacion << "\t";
		cout<< d.at(i).candidato << "\t";
		cout<< d.at(i).lista << "\t";
		cout<< d.at(i).votos << "\t\n";
	}
}
