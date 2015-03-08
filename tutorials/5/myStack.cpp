#ifndef __stack__
#define __stack__

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack {
	private:
		struct Node {
			T val;
			Node* next;
		};
		Node* _head;
		int _size;
	public:
		Stack() { _head = NULL; _size = 0; }
		~Stack() {
			while(!isEmpty()) {
				pop();
			}
		}
		void push(T v) {
			// Create Node:
			Node* temp = new Node;
			temp->val  = v;
			temp->next = _head;

			// Adjust head
			_head = temp;
			_size++;
		}
		T pop() {
			// POP:
			Node* temp = _head;
			_head = _head->next;

			// Adjust next pointer
			temp->next = NULL;

			// Free memory
			T res = temp->val;
			delete temp;

			// Return result
			_size--;
			return res;
		}
		T peek() {
			return _head->val;
		}
		bool isEmpty() {
			return _head == NULL;
		}
		void printStack() {
			Node* curr = _head;
			while(curr != NULL) {
				cout << curr->val << " ";
				curr = curr->next;
			}
			cout << endl;
		}
		int size() { return _size; }
};

#endif
