#pragma once
#include <iostream>
#include <vector>
template <typename T>
class LinkedList {
	public:
		LinkedList() {
			llHead = nullptr;
			llTail = nullptr;
			_nodeCount = 0;
		}
		LinkedList(const LinkedList<T>& list) {
			_nodeCount = 0;
			while (_nodeCount < list._nodeCount) {
				AddTail(list[_nodeCount]);
			}
		}
		LinkedList<T>& operator=(const LinkedList<T>& rhs) {
			Clear();
			_nodeCount = 0;
			while(_nodeCount < rhs._nodeCount) {
				AddTail(rhs[_nodeCount]);
			}
			return *this;
		}
		~LinkedList() {
			Clear();
		}
		void Clear() {
			Node* rmNode = llTail;
			Node* nextRemoval = nullptr;
			while (rmNode != nullptr) {
				nextRemoval = rmNode->prev;
				delete rmNode;
				rmNode = nextRemoval;
			}
			llHead = nullptr;
			llTail = nullptr;
			_nodeCount = 0;
		}
		class Node {
			private:
			public:
				T data;
				Node* prev;
				Node* next;
		};
		void AddHead(const T& data) {
			Node* newHead = new Node();
			newHead->data = data;
			if (_nodeCount == 0) {
				llHead = newHead;
				llTail = newHead;
			}
			else {
				llHead->prev = newHead;
				newHead->next = llHead;
				newHead->prev = nullptr;
				llHead = newHead;
			}
			_nodeCount++;
		}
		void AddTail(const T& data) {
			Node* newTail = new Node();
			newTail->data = data;
			if (_nodeCount == 0) {
				llTail = newTail;
				llHead = newTail;
			}
			else {
				llTail->next = newTail;
				newTail->prev = llTail;
				newTail->next = nullptr;
				llTail = newTail;
			}
			_nodeCount++;
		}
		void AddNodesHead(const T* data, unsigned int count) {
			for (int i = count - 1; i > -1; i--) {
				AddHead(data[i]);
			}
		}
		void AddNodesTail(const T* data, unsigned int count) {
			for (unsigned int i = 0; i < count; i++) {
				AddTail(data[i]);
			}
		}
		void PrintForward() const {
			Node* printNode = llHead;
			while (printNode != nullptr) {
				std::cout << printNode->data << std::endl;
				printNode = printNode->next;
			}
		}
		void PrintReverse() const {
			Node* printNode = llTail;
			while (printNode != nullptr) {
				std::cout << printNode->data << std::endl;
				printNode = printNode->prev;
			}
		}
		unsigned int NodeCount() const {
			return _nodeCount;
		}
		Node* Head() {
			return llHead;
		}
		const Node* Head() const {
			return llHead;
		}
		Node* Tail() {
			return llTail;
		}
		const Node* Tail() const {
			return llTail;
		}
		const Node* GetNode(unsigned int index) const {
			if (index >= _nodeCount) {
				throw std::out_of_range("Error: Out of Range");
			}
			else {
				Node* getNode = llHead;
				for (unsigned int i = 0; i < index; i++) {
					getNode = getNode->next;
				}
				return getNode;
			}
		}
		Node* GetNode(unsigned int index) {
			if (index >= _nodeCount) {
				throw std::out_of_range("Error: Out of Range");
			}
			else {
				Node* getNode = llHead;
				for (int i = 0; i < index; i++) {
					getNode = getNode->next;
				}
				return getNode;
			}
		}
		const T& operator[](unsigned int index) const {
			if (index >= _nodeCount) {
				throw std::out_of_range("Error: Out of Range");
			}
			else {
				Node* getData = llHead;
				for (unsigned int i = 0; i < index; i++) {
					getData = getData->next;
				}
				return getData->data;
			}
		}
		T& operator[](unsigned int index) {
			if (index >= _nodeCount) {
				throw std::out_of_range("Error: Out of Range");
			}
			else {
				Node* getData = llHead;
				for (int i = 0; i < index; i++) {
					getData = getData->next;
				}
				return getData->data;
			}
		}
		const Node* Find(const T& data) const {
			Node* findNode = llHead;
			while (data != findNode->data) {
				if (findNode->next != nullptr) {
					findNode = findNode->next;
				}
				else {
					findNode = nullptr;
					break;
				}
			}
			return findNode;
		}
		Node* Find(const T& data) {
			Node* findNode = llHead;
			while (data != findNode->data) {
				if (findNode->next != nullptr) {
					findNode = findNode->next;
				}
				else {
					findNode = nullptr;
					break;
				}
			}
			return findNode;
		}
		void FindAll(std::vector<Node*>& outData, const T& value) const {
			std::vector<Node*> foundNodes;
			Node* foundNode = llHead;
			for (unsigned int i = 0; i < _nodeCount; i++) {
				if (foundNode->data == value) {
					foundNodes.push_back(foundNode);
				}
				foundNode = foundNode->next;
			}
			outData = foundNodes;
		}
	private:
		Node* llHead;
		Node* llTail;
		unsigned int _nodeCount;
};
