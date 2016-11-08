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
	LinkedStackOfStrings stack;
	stack.push("SAMAN");
	stack.push("SAHAR");
	cout << stack.pop() << endl;
	stack.push("NIAZ");
	stack.push("SOUUDABEH");
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	return 0;
}

bool LinkedStackOfStrings::isEmpty() {
	if (first == NULL) 
		return true;
	return false;
}

void LinkedStackOfStrings::push(string newitem) {
	Node* oldfirst = first;
	first = new Node;	//node should be created!
	first->item = newitem;
	first->next = oldfirst;
}

string LinkedStackOfStrings::pop() {
	string item = first->item;
	first = first->next;
	return item;

}