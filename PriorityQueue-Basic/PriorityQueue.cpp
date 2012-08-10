/*	Created by Anil Kag (anilkagak2@gmail.com)

	Priorty Queue
	Using a binary max heap tree for implementation
*/

#include <iostream>
#include "PriorityQueue.h"

using namespace std;

// swaps the elements present in the two array positions
void
PriorityQueue::swap(int i,int j) {
	Node tmp = pq[i];
	pq[i] = pq[j];
	pq[j] = tmp;
}

// returns the index of the position whose node is more prior
int 
PriorityQueue::isMorePrior(int i,int j) {
	return pq[i].key > pq[j].key? i : j ;
}

void
PriorityQueue::insert(int data, int key) {
	if ( numOfNodes == SIZE ) {
		cout << "Queue Overflown\n";
		return;
	}

	pq[numOfNodes].data = data;
	pq[numOfNodes].key  = key;
	numOfNodes++;

	int i = numOfNodes - 1;		// position of the inserted node

	// heapify the tree bottom-up
	while( i>0 && pq[i].key > pq[i/2].key ) {
		swap(i , i/2);
		i = i/2;
	}
}

Node
PriorityQueue::delMax() {
	if (numOfNodes == 0) {
		cout << "Queue Underflown\n";
		return pq[0];
	}

	Node toReturn = pq[0];
	pq[0] = pq[numOfNodes - 1];
	numOfNodes--;

	int i = 0;

	// heapify from top to bottom
	while(i <= numOfNodes) {
		int child1 = 2*i+1;
		if(child1 >= numOfNodes ) break;

		if(child1 == numOfNodes -1 && pq[i].key < pq[child1].key ) {
			swap(i, child1);
			break;
		}

		int j = isMorePrior(child1, child1 + 1);
		if( pq[i].key < pq[j].key ) {
			swap(i,j);
			i = j;
		}
	}

	cout << "Data = " << toReturn.data << " & Key = " << toReturn.key << "\n";
	return toReturn;
}

void
PriorityQueue::print() {
	for(int i=0; i< numOfNodes; i++)
		cout << "\'" << pq[i].data << " " << pq[i].key << "\'";

	cout << "\n";
}
