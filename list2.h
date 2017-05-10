/**********************
 * J Plumitallo
 ---------------------
 * Linked List Program
 * header file
**********************/

#ifndef LIST_H
#define LIST_H

#include "node2.h"
#include <iostream>
using namespace std;

class List{

	//
	//gloabal methods
	//
	//overloaded cin and cout operators
	friend istream &operator>>(istream &in, List &x);
	friend ostream &operator<<(ostream &out, List &x);

	private: 
		int numNodes;
		Node *head;

		//
		//input and display functions
		void input(istream &in);
                void display(ostream &out);

	public:
		//
		//constructors
		List();
		List(List *x);
	
		//
		//method that returns a boolean value to indicate whether a list is empty or populated
		bool isEmpty();

		//
		//method to return the number of nodes that have been constructed
		int getNodes();

		//
		//method to return the head of the list
		Node *getHead();
		
		//
		//methods to increment and decrement the number of nodes
		int incrementNumNodes();
		int decrementNumNodes();

		//
		//function to append the list
		Node *append(Node *nPtr);

		//
		//function to insert a node in an appropriate position
		Node *insert(Node *nPrt);
		
		//
		//function to delete a given node
		Node *remove(Node *x);

};
#endif
