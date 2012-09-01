#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>

#ifndef _GRAPH_H_
#define _GRAPH_H_

using namespace std;

// states of a node in BFS or DFS
enum node_state {
	WHITE,
	GRAY,
	BLACK
};

// a vertex structure in graph
template <class T>
struct tNode {
	T data;							// data associated with the node
	enum node_state state;					// state of the node, in a searching algo
	size_t distance;					// distance from source
	struct tNode<T> *predecessor;				// predecessor in path from source
	vector<struct tNode<T>* > adjList;				// adjacency list of the node
};

template <class T>
struct tEdge {
	struct tNode<T> *orig;
	struct tNode<T> *dest;
	size_t weight;
};

// interface of a graph from programming perspective
// undirected graph
template <class T>
class Graph {
	public:
//		Graph ();
		~Graph ();

		void takeInput ();				// takes the input from the user

		vector<struct tNode<T>* > vertices;		// all the vertices in the graph
		vector<struct tEdge<T>* > edges;		// all the edges in the graph
		bool BFS_data (T data);			// search the node with t data

	private:
		//bool BFS (Graph<T> *G,tNode<T> *source, tNode<T> *t);
		struct tNode<T>* BFS (Graph<T> *G,tNode<T> *source, tNode<T> *t);
		bool isEdgePresent (struct tEdge<T> *e);
		void showPath (tNode<T> *source, tNode<T> *t);
};

//template <class T>
//bool BFS (Graph<T> *G,tNode<T> *source, tNode<T> *t);

#endif	// _GRAPH_H_
