#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

template <class T>
bool Graph<T>::isEdgePresent (struct tEdge<T> *e) {
	for (int i=0; i< edges.size (); i++) {
		if (e->orig == edges[i]->dest && e->dest == edges[i]->orig)
			return true;
	}

	return false;
}

template <class T>
void Graph<T>::takeInput () {
	int numOfVertices = 0;
	cout << "Enter the number of vertices \n";
	cin >> numOfVertices;

	if (numOfVertices == 0) {
		cout << "Invalid number of vertices\n";
		exit (1);
	}

	cout << "I have numbered the vertices starting from 1 onwards..\n";
	cout << "Enter the row in adjacency matrix corresponding to the vertex no.\n";

	for (int i=0; i < numOfVertices; i++) {
		struct tNode<T> *t = new (struct tNode<T>);
		cout << "Data in node:\n";
		cin >> t->data;
		vertices.push_back (t);
	}

	int j = 0;
	for (int i=0; i < numOfVertices; i++) {
		cout << "Enter row " << i << "\n";
		cout.flush ();

		for (int k=0; k<numOfVertices; k++) {
			cin >> j;
			if(j < 0) {
				cout << "Negative input\n";
				exit (1);
			}

			else if (j != 0) {
				(vertices[i]->adjList).push_back (vertices[k]);
//				struct tEdge<T> *e = new (sizeof(struct tEdge<T>));
				struct tEdge<T> *e = new (struct tEdge<T>);
				e->orig = vertices[i];
				e->dest = vertices[k];
				e->weight = j;

				if (!isEdgePresent (e))
					edges.push_back (e);

				else delete e;
			}
		}
	}
}

template <class T>
Graph<T>::~Graph () {
	// clear the vectors in the vertices & then clear vertices
	for (int i = 0; i < vertices.size (); i++) {
		vertices[i]->adjList.clear ();
		delete vertices[i];
	}
	vertices.clear ();

	// clear the edges list
	edges.clear();
}

template <class T>
bool Graph<T>::BFS_data (T data) {
	struct tNode<string> *node = new (struct tNode<string>);
	node->data = data;
	return BFS (this,vertices[0],node);
}

// searches node t in the graph
template <class T>
bool Graph<T>::BFS (Graph<T> *G,tNode<T> *source, tNode<T> *t) {
	queue<struct tNode<T>* > bfsQ;
	bool foundT = false;

	// initialize all the nodes with state WHITE, distance 0 & predecessor = NULL
	for (int i = 0; i != G->vertices.size (); i++) {
		if (G->vertices[i] == source) continue;

		G->vertices[i]->state = WHITE;
		G->vertices[i]->distance = -1;
		G->vertices[i]->predecessor = NULL;
	}
	
	// initialize the source node
	source->state = BLACK;
//	source->state = GRAY;
	source->distance = 0;
	source->predecessor = NULL;

	bfsQ.push (source);
	while (!bfsQ.empty ()) {
		struct tNode<T> *u = bfsQ.front ();
		bfsQ.pop ();

		if (u->data == t->data) foundT = true;

		for (int i = 0; i != u->adjList.size (); i++) {
			struct tNode<T> *v = u->adjList[i];

			if (v->state == WHITE) {
//				v->state = GRAY;
				v->state = BLACK;
				v->distance = u->distance + 1;
				v->predecessor = u;
				bfsQ.push (v);
			}
		}
//		u->state = BLACK;
	}
	return foundT;
}
