/*	Created by Anil Kag (anilkagak2@gmail.com)

	Priorty Queue
	Using a binary max heap tree for implementation
*/

#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H

/* Size of the priority queue */
#define SIZE 15

/* Structure of the node of a binary heap  */
struct tNode {
	int data;		// data contained in the node
	int key;		// priority for the node
};

typedef struct tNode Node;

/* Interface defining the organization of Priority Queue */
class PriorityQueue {
	private:
		Node pq[SIZE];
		int numOfNodes;

	public:
		PriorityQueue() { numOfNodes = 0; }

		void insert(int data, int key);
		Node delMax();
		void print();

	// helper functions
	private:
		void swap(int i,int j);
		int isMorePrior(int i,int j);
};

#endif
