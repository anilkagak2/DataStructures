#include <iostream>
#include <deque>

using namespace std;

int main () {
	deque<int> q;

	for (int i=0; i<10; i++) q.push_back (i);
	//for (int i=0; i<10; i++) q.push_front (i);

	// two ways of traversing the deque
	for (int i=0; i<10; i++) cout << q[i] << " ";
	cout << endl;

	deque<int>::iterator it;
	deque<int>::reverse_iterator rit;
	cout << "Forward iteration of the deque\n";
	for (it = q.begin (); it != q.end (); it++) {
		cout << *it << " ";
	}

	cout << "\nReverse iteration of the deque\n";
	for (rit = q.rbegin (); rit < q.rend (); rit++) {
		cout << *rit << " ";
	}

	cout << endl;

	return 0;
}
