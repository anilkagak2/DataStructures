#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main (int argc,char *argv[]) {
	queue<string> q;
	q.push ("hellow");
	q.push ("wow");
	q.push ("bakar");
	q.push ("no work");
	q.push ("flow");

	// back element
	cout << q.back () << endl;

	// traverse the queue with front
	while (!q.empty ()) {
		cout << q.front () << endl;
		q.pop ();
	}

	return 0;
}
