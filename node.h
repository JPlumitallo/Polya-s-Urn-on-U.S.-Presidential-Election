/*
 * J Plumitallo
 * Node Program
 * --------------
 * Header File
 *****************
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node{

	friend istream &operator>>(istream &in, Node &x);
	friend ostream &operator<<(ostream &out, const Node &x);

	private:
		string Candidate;
		Node *next;

		//
		//input and display functions
		void input(istream &in);
                void display(ostream &out) const;


	public:
		//
		//constructors
		Node();
		Node(string cand);

		//
		//overloaded equality method to indicate whether two nodes are equivalent
		bool operator==(const Node &x);

		//
		//accessor and mutator methods
		Node *getNext();
		void setNext(Node *nPtr);

		//
		//accessor methods to access the student's information
		string getCand() const;
};
#endif
