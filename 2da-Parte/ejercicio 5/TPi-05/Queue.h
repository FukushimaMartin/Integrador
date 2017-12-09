#include<iostream>
#include<array>
#include<string>

struct Node{
	std::string value;
	Node *next = nullptr;
};

struct Queue{
	Node *front = new Node;
	Node *rear = front;
	unsigned nivel=0;
};

void enQueue(Queue&, std::string);
std::string deQueue(Queue&);
std::string first(const Queue&);
unsigned length(const Queue&);
