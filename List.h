#ifndef LIST_H
#define LIST_H
struct Node
{
	typedef double Item;
	Item data;
	Node* link; //For pointing to a node
	
	Node* cursor;
	


};

size_t listLength(Node* headPtr);
//Precondition: head_ptr is the head pointer of linked list.
//Postcondition: The value returned is the number of nodes in list.



void listHeadInsert(Node*& headPtr, const Node::Item& entry);
//precondition: headPtr is the head pointer of list
//postcondition: new node containing given entry is added
//at the head, headPtr now points to the head of the 
//new longer linked list

void listInsert(Node* previousPtr, const Node::Item& entry);
//     Precondition: previous_ptr points to a node in a linked list.
//     Postcondition: A new node containing the given entry has been added
//     after the node that previous_ptr points to.

Node* listSearch(Node* headPtr, const Node::Item& target);
//   See the note (above) about the const version and non-const versions:
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The pointer returned points to the first node containing
//     the specified target in its data member. If there is no such node, the
//     null pointer is returned.

Node* listLocate(Node* headPtr, size_t position);
//   See the note (above) about the const version and non-const versions:
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0.
//     Postcondition: The pointer returned points to the node at the specified
//     position in the list. (The head node is position 1, the next node is
//     position 2, and so on). If there is no such position, then the null
//     pointer is returned.

void listCopy(Node* sourcePtr, Node*& headPtr, Node*& tailPtr);
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new list that contains the same items as the list pointed to by
//     source_ptr. The original list is unaltered.

void listPiece(Node* startPtr, Node* endPtr, Node*& headPtr, Node*& tailPtr);
//    Precondition: start_ptr and end_ptr are pointers to nodes on the same
//    linked list, with the start_ptr node at or before the end_ptr node
//    Postcondition: head_ptr and tail_ptr are the head and tail pointers for a
//    new list that contains the items from start_ptr up to but not including
//    end_ptr.  The end_ptr may also be NULL, in which case the new list
//    contains elements from start_ptr to the end of the list.

void listHeadRemove(Node*& headPtr);
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one node.
//     Postcondition: The head node has been removed and returned to the heap;
//     head_ptr is now the head pointer of the new, shorter linked list.

void listRemove(Node* previousPtr);
//     Precondition: previous_ptr points to a node in a linked list, and this
//     is not the tail node of the list.
//     Postcondition: The node after previous_ptr has been removed from the
//     linked list.


void listClear(Node*& headPtr);
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All nodes of the list have been returned to the heap,
//     and the head_ptr is now NULL.


#endif