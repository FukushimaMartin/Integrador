#include<iostream>
#include<string>


struct Nodo{
	std::string agroup;
	unsigned votosTotales;
	Nodo *next = nullptr;
};

struct Stack{
	Nodo *first = nullptr;
	unsigned nivel=0;
};

void push(Stack&,std::string, unsigned);
unsigned pop(Stack&);
unsigned top(const Stack&);
unsigned length(const Stack&);
void vaciarStack(Stack&);
