#include <iostream>
#include <string>
using namespace std;

class LinkedStackOfStrings {

private:
	
	class Node {

	public:
		string 	item;
		Node* 	next;
	};

	Node* first = NULL;		//have to use pointer when pointing to NULL!

public:
	bool isEmpty();
	void push(string);
	string pop();
};

int main() {
	string inputstack = "to be or - not to - - be - that - - is the - -"
	LinkedStackOfStrings things;
	
	return 0;
}

bool LinkedStackOfStrings::isEmpty() {
	if (first == NULL) 
		return true;
	return false;
}

void LinkedStackOfStrings::push(string newitem) {
	first = new Node;	//node should be created!
	Node* oldfirst;
	oldfirst = first;
	first->item = newitem;
	first->next = oldfirst;
}

string LinkedStackOfStrings::pop() {
	string item = first->item;
	first = first->next;
	return item;

}