#include <iostream>
#include <string>

/*
TPintegrador - Ejercicio 1
Grupo 2
28/06/2017
*/




int main (){
	//prototipos
	void evaluarPrecandidatura();
	void evaluarVotoNoNulo();
	
	evaluarPrecandidatura();
	evaluarVotoNoNulo();
}

//prototipo externo para que pueda ser invocado por todas las funciones siguientes.
bool pregunta(std::string a);


//evaluar la precandidatura
void evaluarPrecandidatura(){
	//prototipos
	bool perteneceAlPartido();
	bool avalDosPorcientoAfiliados();
	
	if (perteneceAlPartido() && avalDosPorcientoAfiliados()){
		std::cout<<"\n**Puede ser precandidato**\n\n";
	} else {
		std::cout<<"\n*NO* posee los requisitos para ser precandidato!!\n\n";
	}
}
//evaluar la nulidad del voto
void evaluarVotoNoNulo(){
	//prototipos
	bool boletaNoOficializada();
	bool papelDeColorConImagenes();
	bool dosOMasBoletas();
	
	if(boletaNoOficializada() || papelDeColorConImagenes() || dosOMasBoletas()){
		std::cout<<"\nEl voto es considerado NULO!!\n";
	} else {
		std::cout<<"\n**El voto es Valido**\n";
	}
}
//pertenece al partido politico
bool perteneceAlPartido(){
	return pregunta("Pertenece al partido politico? (si/no)\n");
}
//cuenta con el aval del 2% de los afiliados a dicho partido
bool avalDosPorcientoAfiliados(){
	return pregunta("cuenta con el aval del 2% de los afiliados a dicho partido? (si/no)\n");
}
//el voto es emitido mediante boleta no oficializada
bool boletaNoOficializada(){
	return pregunta("el voto es emitido mediante boleta no oficializada? (si/no)\n");
}
//el voto es emitido con papel de cualquier color con inscripciones o imagenes de cualquier naturaleza
bool papelDeColorConImagenes(){
	return pregunta("el voto es emitido con papel de cualquier color con inscripciones o imagenes de cualquier naturaleza? (si/no)\n");
}
//el voto es emitido mediante dos o mas boletas de la misma categoria de candidatos y diferente agrupacion politica
bool dosOMasBoletas(){
	return pregunta("el voto es emitido mediante dos o mas boletas de la misma categoria de candidatos y diferente agrupacion politica? (si/no)\n");
}
bool pregunta(std::string a){
	std::cout<<a;
	std::string r;
	std::cin>>r;
	if (r == "si" || r == "SI" || r == "yes" || r == "YES" || r == "S" || r == "s"){
		return true;
	} else {
		return false;
	}
}

