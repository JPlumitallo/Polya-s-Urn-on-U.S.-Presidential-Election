/*
 * J Plumitallo
 * Node Program
 * --------------
 * driver File
 *****************
*/

#include "node2.cpp"
#include "list2.cpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

int main(){

ifstream is;
ofstream os;

	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;
	int votecounth = 109;
	int votecountt = 150;

	cout << "Votes for Hillary Clinton: ";
	//cin >> votecounth;
	cout << endl << endl;
	
	cout << "Votes for Donald Trump: ";
	//cin >> votecountt;
	cout << endl << endl;

	Node *hill[votecounth];
        Node *trump[votecountt];

	List Hillary;
	List Trump;


	while(counter < votecounth){

		hill[counter] = new Node("hillary");
		Hillary.append(hill[counter]);
		counter++;

	}

	while(counter2 < votecountt){
	
		trump[counter2] = new Node("trump");
                Trump.append(trump[counter2]);
                counter2++;
	}

	cout << endl << endl << endl << endl << endl;
	cout << "BUILDING A CONCATENATED LIST OF BOTH CANDIDATES' STATISTICS TO PERFORM POLYA'S URN OPERATION....." << endl << endl << endl << endl << endl;

	string nof = "polya";
	nof+=".dat";

	 os.open(nof);


		Node*curr = Hillary.getHead();
               	Node*curr2 = Trump.getHead();

		if(votecounth > votecountt){

			while(curr!=NULL){
                	
				os << curr->getCand();
				os << endl;
				curr=curr->getNext();	
			
					if(curr2!=NULL){
			
						os << curr2->getCand();
						os << endl;
						curr2=curr2->getNext();
				
					}
                	}
		}else if(votecountt > votecounth){

			 while(curr2!=NULL){

                                os << curr2->getCand();
                                os << endl;
                                curr2=curr2->getNext();

                                        if(curr!=NULL){

                                                os << curr->getCand();
                                                os << endl;
                                                curr=curr->getNext();

                                        }
                        }


		}

		os.close();


	cout << " EXTRACTING FABRICATED LIST AND PERFORMING POLYA'S URN OPERATION.....";
	cout << endl << endl << endl << endl << endl;

	string name;
	int votesforHill = 0;
	int votesforTrump = 0;
	List both;

	 srand(time(0));

	int totalvotes = votecountt+votecounth;

	 is.open(nof);
	
		for(int i = 0;i<5000;i++){

			while(is >> name){

			int x;
			x = rand() % 3;
			
				if(x == 2){
					Node *nPtr = new Node(name);
					Node *nPtr2 = new Node(name);
					both.append(nPtr);
					both.append(nPtr2);
					if(name == "hillary"){
						votesforHill+=2;
					}else if(name == "trump"){
						votesforTrump+=2;
					}
				}
                       }

		}

	is.close();
	
	cout << "COUNTING RESULTS..........";
	cout << endl << endl << endl << endl << endl;

	//cout << "and..................";
	cout << endl << endl << endl << endl << endl;

	if(votesforHill<votesforTrump){

		cout << endl << endl;
		cout << "TRUMP";
		cout << endl << endl;

	}else{
	
		cout << endl << endl;
		cout << "CLINTON";
		cout << endl << endl;

	}

}
