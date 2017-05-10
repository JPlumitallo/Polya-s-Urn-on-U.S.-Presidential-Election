/*
 * J Plumitallo
 * Node Program
 * --------------
 * cpp File
 *****************
 */

#include "node2.h"

	//
	//overloaded ostream and istream operators
	istream &operator>>(istream &in, Node &x){
	
		x.input(in);

		return in;

	}

	//
	//overloaded ostream operator
	ostream &operator<<(ostream &out, const Node &x){

		x.display(out);

		return out;

	}


	//
	//default constructor
	Node::Node(){
	
		Candidate = "NULL";
		next = NULL;
	
	}

	//
	//custom constructor
	Node::Node(string cand){
		
		next = NULL;
		Candidate = cand;

	}


	//
	//overloaded equality method to indicate whether two nodes are equivalent
	bool Node::operator==(const Node &x){
		
		bool isEqual = false;


		if(Candidate == x.getCand()) {
			
			isEqual = true;
	
		}

		return isEqual;

	}

	//
	//mutator method to assign the next pointer
	void Node::setNext(Node *nPtr){
		
		next = nPtr;

	}

	//
	//accessor method to return the next pointer
	Node *Node::getNext(){
	
		return next;

	}

	//
	//accessor method to return a student's age
	string Node::getCand() const{
		
		return Candidate;

	}


	//
	//input function
	void Node::input(istream &in){

		in >> Candidate;

	}

	//
	//display
	void Node::display(ostream &out) const{
	
		out << Candidate;
	
	}
