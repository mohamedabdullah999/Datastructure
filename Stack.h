#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
	struct Node {
		T data;
		Node* next;
	};
	Node* top;
	long long size;
	
public:
	Stack() {
		size = 0;
		top = nullptr;
	}

	void push(T item) {
		Node* newnode = new Node;
		if (!newnode) {
			cout << "Stack cannot allocate memory to push element\n";
		}
		newnode->data = item;
		newnode->next = top;
		top = newnode;
		newnode = nullptr;
		size++;
	}

	bool Empty() {
		return top == nullptr;
	}

	void pop_last(T& last) { // saving last element before pop(call by  refrence)
		if (Empty()) {
			cout << "stack is empty\n";
		}
		else {
			last = top->data;
			Node* temp = top;
			top = top->next;
			delete temp;
			temp = nullptr;
			size--;
		}
	}

	//remove top elemnt directly
	void pop() {
		if (Empty()) {
			cout << "stack is empty\n";
		}
		else {
			Node* temp = top;
			top = top->next;
			delete temp;
			temp = nullptr;
			size--;
		}
	}

	//this fn to return data you know the type of it (call by refrence)
	void gettop(T& last) {
		if (Empty()) cout << "stack is empty\n";
		else last = top->data;
	}

	//this fn to return data you donnot know the type of it
	T Top() {
		if (!Empty()) {
			return top->data;
		}
	}

	void display() {
		Node* temp = top;
		if (!Empty()) cout << '[';
		while (temp) {
			if (!temp->next) {
				cout << temp->data;
				break;
			}
			cout << temp->data << ",";
			temp = temp->next;
		}
		cout << ']' << endl;
	}

};


