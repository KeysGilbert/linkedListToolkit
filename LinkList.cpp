#include "List.h"
#include <cstdlib>
#include <cassert>

size_t listLength(Node* headPtr) {
	Node* cursor;
	cursor = headPtr;
	size_t answer = 0;

	for (cursor = headPtr; cursor != NULL; cursor = cursor->link) {
			
		answer++;
	}
	return answer;
}

void listHeadInsert(Node*& headPtr, const Node::Item& entry) {
	Node* newHead = new Node;
	newHead->data = entry;
	newHead->link = headPtr;
	headPtr = newHead;


}

void listInsert(Node* previousPtr, const Node::Item& entry) {

	Node* temp = new Node;
	temp->data = entry;
	temp->link = previousPtr->link;
	previousPtr->link = temp;

}

Node* listSearch(Node* headPtr, const Node::Item& target) {
	Node* cursor;

	for (cursor = headPtr; cursor != NULL; cursor = cursor->link) {

		if (target == cursor->data) {
			return cursor;
		}

	}
	return NULL;
}
	
Node* listLocate(Node* headPtr, size_t position) {
	Node* cursor;
	cursor = headPtr;
	assert(0 < position);
	for (size_t i = 1; (i < position) && (cursor != NULL); i++) {
		cursor = cursor->link;
	}
	return cursor;
}

void listCopy(Node* sourcePtr, Node*& headPtr, Node*& tailPtr) {

	headPtr = NULL;
	tailPtr = NULL;

	for (sourcePtr = sourcePtr->link; sourcePtr != NULL; sourcePtr = sourcePtr->link) {
		listInsert(tailPtr, sourcePtr->data);
		tailPtr = tailPtr->link;
	}

}

void listPiece(Node* startPtr, Node* endPtr, Node*& headPtr, Node*& tailPtr) {
	headPtr = NULL;
	tailPtr = NULL;
	for (startPtr = startPtr->link; startPtr != endPtr; startPtr = startPtr->link) {
		listInsert(tailPtr, startPtr->data);
		tailPtr = tailPtr->link;
	 }


}

void listHeadRemove(Node*& headPtr) {
	assert(headPtr != NULL);
	Node* remove;
	remove = headPtr;
	headPtr = headPtr->link;
	delete remove;

}

void listRemove(Node* previousPtr) {
	assert(previousPtr != NULL);
	Node* remove;
	remove = previousPtr->link;
	previousPtr = previousPtr->link;
	delete remove;
}