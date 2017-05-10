/**********************
 * J Plumitallo
---------------------
 * Linked List Program
 * cpp file
***********************/

#include "list2.h"
#include <cstdlib>
#include <ctime>

	//////////////////
	//global methods//
	//////////////////
	
	//
	//overloaded istream method
	istream &operator>>(istream &in, List &x){
	
		x.input(in);

		return in;

	}

	//
	//overloaded ostream method
	ostream &operator<<(ostream &out, List &x){
	
		x.display(out);
	
	}

	/////////////////
	//class methods//
	/////////////////

	//
	//default constructor
	List::List(){
	
		head = NULL;
		numNodes = 0;

	}

	//
	//copy constructor
	List::List(List *x){
	
		if(x->head->getNext() == NULL){	
			head = x->head;
		}else{
			head = x->head;
			head->setNext(x->head->getNext());

			Node *curr = x->head;
			Node *curr2 = head;

			while(curr != NULL){
		
			curr2 = curr->getNext();

			}

		}

	}

	//
	//method that returns a boolean value indicating whether a list is populated or not
	bool List::isEmpty(){

		bool isEmpty = false;	

		if(head == NULL){
			isEmpty = true;
		}

		return isEmpty;

	}

	//
	//method to return nodeCount and monitor the quantity of nodes in a list
	int List::getNodes(){
	
		return numNodes;

	}

	//
	//method to increment numNodes
	int List::incrementNumNodes(){
		
		numNodes++;
		return numNodes;

	}

	//
	//method to decrement numNodes
	int List::decrementNumNodes(){
	
		numNodes--;
		return numNodes;

	}

	//
	//function to append the list
	Node* List::append(Node *nPtr){

		if(head == NULL){
			head = nPtr;
		}else{
			Node*curr = head;

			while(curr!=NULL){
				
				if(curr->getNext() == NULL){
					break;
				}else{
					curr = curr->getNext();
				}
			}
		curr->setNext(nPtr);
		}

	incrementNumNodes();

	return head;
	}

	//
	//function to delete a given node
	Node* List::remove(Node *x){

		Node *curr = head;
		Node *prev = NULL;

		while(curr!=NULL){
			if(*curr == *x){
				break;			
			}else{
				prev = curr;
				curr = curr->getNext();
			}
		}
		if(curr!=NULL){
			
			if(prev!=NULL){
				prev->setNext(curr->getNext());
			}else{
				head = curr->getNext();
			}

		curr->setNext(NULL);
		delete curr;
		curr = NULL;
		}

		decrementNumNodes();
		return head;
	}

	//
	//function to randomly input a node into the list
	Node* List::insert(Node *nPtr){
	
		int x;
		srand(time(0));
		x = rand() % 100;

		if(head == NULL){
                        head = nPtr;
                }else{
                        Node*curr = head;
                        Node*prev = NULL;

		
			for(int i=0;i<x;i++){
                        	
				while(curr!=NULL){

					prev = curr;
					curr = curr->getNext();
                        	
				}
			}

                        if(prev != NULL){
                                prev->setNext(nPtr);
                                nPtr->setNext(curr);
                        }else{
                                nPtr->setNext(curr);
                                head = nPtr;
                        }
                }

        incrementNumNodes();

        return head;

	

	}

	//
	//function to return the head of the list
	Node* List::getHead(){

		return head;

	}

	//
	//input function
	void List::input(istream &in){

		Node *nPtr = NULL;

		bool input = true;
	
		while(input){

                	char x;

                	cout << "Do you wish to add a candidate (Y/N)?";
                	in >> x;

                	if(x == 'n' || x == 'N'){

                        	input == false;
                        	break;

                	}else if(x == 'y' || x == 'Y'){
			
                        	Node *nPtr = new Node;
                        	in >> *nPtr;
				append(nPtr);
			}
        }


	}

	//
	//display function
	void List::display(ostream &out) {

		Node *curr = head;

		while(curr!=NULL){
			
			out << *curr << endl;
			curr = curr->getNext();

		}
		
		out << endl << "Number of votes: " << getNodes() << endl;
	}
