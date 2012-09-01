#include <iostream>
#include <string>
#include "Graph.cpp"

using namespace std;

int main (int argc, char *argv[]) {
	Graph<string> *G = new Graph<string>;

	G->takeInput ();
	bool result =  G->BFS_data ("home");
	cout << "Result  is " << result << endl;

	delete G;
	return 0;
}
