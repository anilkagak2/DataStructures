#include <iostream>
#include <list>

using namespace std;

template <class T>
class unique_check {
	public:
	bool operator() (const T& a, const T& b) {
		return a == b;
	}
};

bool unk (int a, int b) {
	return a == b;
}

int main () {
	list<int> q;

	for (int i=0; i<10; i++) q.push_back (i);
	for (int i=0; i<10; i++) q.push_front (i);

	list<int>::iterator it;
	list<int>::reverse_iterator rit;
	cout << "Forward iteration of the list\n";
	for (it = q.begin (); it != q.end (); it++) {
		cout << *it << " ";
	}

	cout << endl;
	q.sort ();

	for (it = q.begin (); it != q.end (); it++) cout << *it << " ";
	q.unique ();
	// uniqueness not working in case of binary predicate function, TODO 
//	q.unique (unique_check<int>());
//	q.unique (unk);

	cout << "\nReverse iteration of the list\n";
	for (rit = q.rbegin (); rit != q.rend (); rit++) {
		cout << *rit << " ";
	}

	cout << endl;

	return 0;
}
