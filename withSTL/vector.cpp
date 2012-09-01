#include <iostream>
#include <vector>

using namespace std;

int main () {
	vector<int> q(10);

	cout << "Size " << q.size () << " Capacity " << q.capacity () << "\n";
	for (int i=0; i<30; i++) q.push_back (i);
	//for (int i=0; i<30; i++) q[i] = i;
	//for (int i=0; i<10; i++) q.push_front (i);

	// two ways of traversing the deque
	for (int i=0; i<30; i++) cout << q[i] << " ";
	cout << endl;

	vector<int>::iterator it;
	vector<int>::reverse_iterator rit;
	cout << "Forward iteration of the vector\n";
	for (it = q.begin (); it != q.end (); it++) {
		cout << *it << " ";
	}

	cout << "\nReverse iteration of the vector\n";
	for (rit = q.rbegin (); rit < q.rend (); rit++) {
		cout << *rit << " ";
	}

	cout << endl;
	cout << "Size " << q.size () << " Capacity " << q.capacity () << "\n";

	return 0;
}
