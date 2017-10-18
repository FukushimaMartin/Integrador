#include<iostream>
#include<string>
#include<fstream>

/*


*/



int main(){
	//prototipo
	void escribir5ActasDeMesa();
	
	//invocacion
	escribir5ActasDeMesa();
}

//definicion de funciones

void escribir5ActasDeMesa(){
	//prototipo
	void escribirActaDeMesa(std::string);
	
	//invocacion
	escribirActaDeMesa("4568");
	escribirActaDeMesa("4569");
	escribirActaDeMesa("4579");
	escribirActaDeMesa("4580");
	escribirActaDeMesa("4581");
}


std::ofstream escrutinio;

void escribirActaDeMesa(std::string m){
	//prototipos
	std::string getNombreDeArchivo(std::string);
	void escribirMesa(std::string);
	void escribirCargos(std:: string);
	void escribirTitulo();
	void escribirDetalles();
	void escribirVotosEnBlanco();
	void escribirVotosImpugnados();
	void escribirSeparador();
	
	
	//abrimos el flujo
	escrutinio.open(getNombreDeArchivo(m));
	
	//invocacion
	escribirMesa(m);
	
	escribirCargos("Senadores");
	escribirTitulo();
	escribirDetalles();
	
	escribirVotosEnBlanco();
	escribirVotosImpugnados();
	
	escribirSeparador();
	
	escribirCargos("Diputados");
	escribirTitulo();
	escribirDetalles();
	
	escribirVotosEnBlanco();
	escribirVotosImpugnados();
	
	//cierre de flujo
	escrutinio.close();
}

std::string getNombreDeArchivo(std::string mesa){
	return ("Mesa_"+mesa+".txt");
}

void escribirMesa(std::string mesa){
	std::cout<<"Acta de la Mesa "<<mesa<<"\n";
	escrutinio<<"Acta de la Mesa "<<mesa<<"\n\n";
}	

	
void escribirCargos(std::string sd){
	std::cout<<sd<<"\n";
	escrutinio<<sd<<"\n";
}


void escribirTitulo(){
	std::cout<<"Agrupacion Politica - Numero de Lista - Nombre del Candidato - Cantidad de Votos\n";
	escrutinio<<"Agrupacion Politica - Numero de Lista - Nombre del Candidato - Cantidad de Votos\n";
}


void escribirSeparador(){
	std::cout<<"\n-----------------------------------------------------------------------------\n";
	escrutinio<<"\n-----------------------------------------------------------------------------\n";
}


void escribirDetalles(){
	std::string detalles;
	std::string partido;
	
	for(unsigned i=0; i<10; i++){ // pregunta partido politico
		std::cout<<"\nIngrese Agrupacion Politica: \t";
		std::cin>>partido;
		
        for(unsigned j=0; j<3; j++){ //preguntar lista - candidato - votos
			escrutinio<<partido<<"\t";
			
			std::cout<<"\nIngrese Numero de Lista: \t";
			std::cin>>detalles;
			escrutinio<<detalles<<"\t";
			
			std::cout<<"Ingrese Nombre del Candidato: \t";
			std::cin>>detalles;
			escrutinio<<detalles<<"\t";
			
			std::cout<<"Ingrese Cantidad de Votos: \t";
			std::cin>>detalles;
			escrutinio<<detalles<<"\n";
        }
	}
}


void escribirVotosEnBlanco(){
	unsigned b=0;
	std::cout<<"\nIngrese cantidad de Votos en Blanco: \t";
	std::cin>>b;
	escrutinio<<"\nVotos en Blanco \tCantidad de Votos: "<<b;
}


void escribirVotosImpugnados(){
	unsigned i=0;
	std::cout<<"\nIngrese cantidad de Votos Impugnados: \t";
	std::cin>>i;
	escrutinio<<"\nVotos Impugnados \tCantidad de Votos: "<<i;
}
