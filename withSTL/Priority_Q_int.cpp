#include <iostream>
#include <queue>
#include <string>

using namespace std;

template <class T>
class string_cmp {
	public:
	bool operator()(const T& a, const T& b) const {
		return a.length () > b.length ();
	}
};

template <class T>
struct more {
	bool operator()(const T& a, const T& b) const {
		return a.length () > b.length ();
	}
};

int main (int argc,char *argv[]) {
	//priority_queue<string, vector<string>, more<string> > q;
	priority_queue<string, vector<string>, string_cmp<string> > q;
	q.push ("hellow");
	q.push ("wow");
	q.push ("bakar");
	q.push ("no work");
	q.push ("flow");

	// traverse the queue with front
	while (!q.empty ()) {
		cout << q.top () << endl;
		q.pop ();
	}

	return 0;
}
