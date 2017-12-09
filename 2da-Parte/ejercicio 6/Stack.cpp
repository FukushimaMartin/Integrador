#include "Stack.h"
#include<iostream>

void push (Stack& s,std::string y, unsigned x){
	Nodo *p = new Nodo;
	p->agroup = y;
	p->votosTotales = x;
	p->next = s.first;
	s.first = p;
	++s.nivel;
}
unsigned pop (Stack& s){
	if (s.nivel != 0){
		std::cout<<"Agrupacion: "<<s.first->agroup<<" Votos Totales: ";
		Nodo *p = s.first;
		s.first = s.first->next;
		--s.nivel;
		return p->votosTotales;
	}
	std::cout<<"Stack vacio!";
}
unsigned top(const Stack& s){
	if (s.nivel != 0){
		return s.first->votosTotales;
	}
	std::cout<<"Stack vacio!";
}
unsigned length(const Stack& s){
	return s.nivel;
}
void vaciarStack(Stack& s){
	s.first = nullptr;
	s.nivel = 0;
}
